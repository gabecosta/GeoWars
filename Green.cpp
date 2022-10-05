/**********************************************************************************        
**********************************************************************************/

#include "Green.h"
#include "GeoWars.h"
#include "Random.h" 
#include "Explosion.h" 

Green::Green(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(BasicAI::green);
    BBox(new Circle(20.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);
    MoveTo(pX, pY);
    type = GREEN; 
    RandI dist{ 100, 400 };
    distance = dist.Rand(); 
    ++Hud::greens;
} 

Green::~Green()
{
    delete sprite; 
    --Hud::greens;
} 

void Green::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
} 

void Green::Update()
{ 
    Vector target = Vector(Line::Angle(Point(x, y), Point(player->X(), player->Y())), 20.0f * gameTime); 
    if (Point::Distance(Point(x, y), Point(player->X(), player->Y())) < distance)
    {
        target.Rotate(180.0f);
        target.ScaleTo(100.0f * gameTime);
    }

    speed.Add(target);  
    if (speed.Magnitude() > 8)
        speed.ScaleTo(8.0f); 
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime);
    Rotate(50 * gameTime); 
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
} 