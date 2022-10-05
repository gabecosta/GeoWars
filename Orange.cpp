

#include "GeoWars.h"
#include "Orange.h"
#include "Random.h" 
#include "Explosion.h" 

Orange::Orange(float pX, float pY, float ang)
{
    sprite = new Sprite(BasicAI::orange); 
    speed.RotateTo(ang);
    speed.ScaleTo(400);
    RotateTo(-speed.Angle());
    BBox(new Circle(20.0f));
    MoveTo(pX, pY);
    type = ORANGE; 
    Generator emitter;
    emitter.imgFile = "Resources/Spark.png"; 
    emitter.angle = speed.Angle() + 180; 
    emitter.spread = 5; 
    emitter.lifetime = 0.4f; 
    emitter.frequency = 0.010f; 
    emitter.percentToDim = 0.8f; 
    emitter.minSpeed = 100.0f; 
    emitter.maxSpeed = 200.0f; 
    emitter.color.r = 1.0f; 
    emitter.color.g = 0.5; 
    emitter.color.b = 0.0f; 
    emitter.color.a = 1.0f;  
    tail = new Particles(emitter);
    tailCount = 0; 
    ++Hud::oranges;
} 

Orange::~Orange()
{
    delete sprite;
    delete tail; 
    Hud::particles -= tailCount;
    --Hud::oranges;
} 

void Orange::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);        
    }
} 

void Orange::Update()
{ 
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime); 
    if (x < 50 || y < 50 || x > game->Width() - 50 || y > game->Height() - 50)
    {
        Rotate(180);
        speed.Rotate(180);        
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    } 
    tail->Config().angle = speed.Angle();
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);

    Hud::particles -= tailCount;
    tailCount = tail->Size();
    Hud::particles += tailCount;
} 

void Orange::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
    tail->Draw(Layer::LOWER, 1.0f);
} 