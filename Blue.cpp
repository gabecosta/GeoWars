/**********************************************************************************        
**********************************************************************************/

#include "GeoWars.h"
#include "Blue.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h" 

Blue::Blue(float pX, float pY, Player* p)
{
    player = p;
    sprite = new Sprite(BasicAI::blue);
    BBox(new Circle(20.0f));
    speed.RotateTo(0.0f);
    speed.ScaleTo(0.0f);
    MoveTo(pX, pY);
    factor = -0.25f;
    type = BLUE; 
    ++Hud::blues;
} 

Blue::~Blue()
{
    delete sprite; 
    --Hud::blues;
} 

void Blue::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
} 

void Blue::Update()
{  
    Vector target { Line::Angle(Point(x, y), Point(player->X(), player->Y())), 2.0f * gameTime };
    speed.Add(target);  
    if (speed.Magnitude() > 4.5)
        speed.ScaleTo(4.5f); 
    Translate(speed.XComponent() * 50.0f * gameTime, -speed.YComponent() * 50.0f * gameTime); 
    Scale(1.0f + factor * gameTime); 
    if (scale < 0.85f)
        factor = 0.25f;
    if (scale > 1.00f)
        factor = -0.25f; 
    if (x < 50)
        MoveTo(50, y);
    if (y < 50)
        MoveTo(x, 50);
    if (x > game->Width() - 50)
        MoveTo(game->Width() - 50, y);
    if (y > game->Height() - 50)
        MoveTo(x, game->Height() - 50);
} 