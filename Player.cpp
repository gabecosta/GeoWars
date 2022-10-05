/**********************************************************************************        
**********************************************************************************/

#include "Player.h" 
#include "Missile.h"
#include "GeoWars.h"
#include "Hud.h"

Image * Player::missile = nullptr; 

Player::Player()
{ 
    gamepad = new Controller();
    gamepadOn = gamepad->Initialize(); 
    sprite = new Sprite("Resources/Player.png");
    missile = new Image("Resources/Missile.png");
    speed.RotateTo(90.0f);
    speed.ScaleTo(0.0f);
    BBox(new Circle(18.0f));
    MoveTo(game->CenterX(), game->CenterY());
    type = PLAYER; 
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png"; 
    emitter.angle = 270.0f; 
    emitter.spread = 25; 
    emitter.lifetime = 0.3f; 
    emitter.frequency = 0.010f; 
    emitter.percentToDim = 0.6f; 
    emitter.minSpeed = 50.0f; 
    emitter.maxSpeed = 100.0f; 
    emitter.color.r = 1.0f; 
    emitter.color.g = 1.0f; 
    emitter.color.b = 1.0f; 
    emitter.color.a = 1.0f;  
    tail = new Particles(emitter);
    tailCount = 0; 
    firingAngle = 0.0f;
    keysPressed = false;
    axisCtrl = true;
    keysCtrl = true;
    start = 0;
    timer.Start();
} 

Player::~Player()
{
    delete sprite;
    delete missile;
    delete tail;
    delete gamepad;
} 

bool Player::KeysTimed(bool pressed, float time)
{ 
    if (keysCtrl)
    { 
        if (pressed)
        {
            keysCtrl = false;
            start = timer.Stamp();
            return true;
        }
    } 
    else if (timer.Elapsed(start, time))
    {
        keysCtrl = true;
    } 
    return false;
} 

bool Player::AxisTimed(int axisX, int axisY, float time)
{ 
    if (axisCtrl)
    { 
        float magnitude = Point::Distance(Point(0, 0), Point(float(gamepad->Axis(axisX)), float(gamepad->Axis(axisY)))); 
        if (magnitude > 0)
        {
            axisCtrl = false;
            start = timer.Stamp();
            return true;
        }
    } 
    else if (timer.Elapsed(start, time))
    {
        axisCtrl = true;
    } 
    return false;
} 

void Player::Move(Vector && v)
{ 
    speed.Add(v); 
    if (speed.Magnitude() > 10.0f)
        speed.ScaleTo(10.0f);
} 

void Player::Update()
{ 
    float accel = 40.0f * gameTime;   

    if (gamepadOn)
    { 
        gamepad->UpdateState(); 
        float ang = Line::Angle(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f));
        float mag = Point::Distance(Point(0, 0), Point(gamepad->Axis(AxisX) / 25.0f, gamepad->Axis(AxisY) / 25.0f)); 
        if (mag == 0)
        { 
            if (speed.Magnitude() < 0.1)
            { 
                speed.ScaleTo(0.0f);
            }
            else
            { 
                Move(Vector(speed.Angle() + 180.0f, 5.0f * gameTime));
            }
        }
        else
        { 
            Move(Vector(ang, mag * gameTime));
        } 
        if (AxisTimed(AxisRX, AxisRY, 0.150f))
        {
            float ang = Line::Angle(Point(0,0), Point(float(gamepad->Axis(AxisRX)), float(gamepad->Axis(AxisRY))));
            BasicAI::audio->Play(FIRE);
            BasicAI::scene->Add(new Missile(ang), STATIC);
        }
    }   

    else
    { 
        if (window->KeyDown('D') && window->KeyDown('W'))
            Move(Vector(45.0f, accel));
        else if (window->KeyDown('A') && window->KeyDown('W'))
            Move(Vector(135.0f, accel));
        else if (window->KeyDown('A') && window->KeyDown('S'))
            Move(Vector(225.0f, accel));
        else if (window->KeyDown('D') && window->KeyDown('S'))
            Move(Vector(315.0f, accel));
        else if (window->KeyDown('D'))
            Move(Vector(0.0f, accel));
        else if (window->KeyDown('A'))
            Move(Vector(180.0f, accel));
        else if (window->KeyDown('W'))
            Move(Vector(90.0f, accel));
        else if (window->KeyDown('S'))
            Move(Vector(270.0f, accel));
        else 
            if (speed.Magnitude() > 0.1f)
                Move(Vector(speed.Angle() + 180.0f, 5.0f * gameTime));
            else 
                speed.ScaleTo(0.0f); 
        if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 45.0f;
        } 
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 135.0f;
        }
        else if (window->KeyDown(VK_LEFT) && window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 225.0f;
        }
        else if (window->KeyDown(VK_RIGHT) && window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 315.0f;
        }
        else if (window->KeyDown(VK_RIGHT)) {
            keysPressed = true;
            firingAngle = 0.0f;
        }
        else if (window->KeyDown(VK_LEFT)) {
            keysPressed = true;
            firingAngle = 180.0f;
        }
        else if (window->KeyDown(VK_UP)) {
            keysPressed = true;
            firingAngle = 90.0f;
        }
        else if (window->KeyDown(VK_DOWN)) {
            keysPressed = true;
            firingAngle = 270.0f;
        }
        else
        {
            keysPressed = false;
        } 
        if (KeysTimed(keysPressed, 0.150f))
        {
            BasicAI::audio->Play(FIRE);
            BasicAI::scene->Add(new Missile(firingAngle), STATIC);
        }
    } 
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime); 
    tail->Config().angle = speed.Angle() + 180;
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);
    
    Hud::particles -= tailCount;
    tailCount = tail->Size();
    Hud::particles += tailCount; 
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
} 

void Player::Draw()
{
    sprite->Draw(x, y, Layer::MIDDLE, 1.0f, -speed.Angle() + 90.0f);
    tail->Draw(Layer::LOWER, 1.0f);
} 
