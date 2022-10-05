/**********************************************************************************        
**********************************************************************************/

#include "GeoWars.h"
#include "Magenta.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h" 

Magenta::Magenta(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(BasicAI::magenta);
    BBox(new Circle(18.0f));
    
    speed.RotateTo(0);
    speed.ScaleTo(2.0f);
    
    MoveTo(pX, pY);
    type = MAGENTA; 
    ++Hud::magentas;
} 

Magenta::~Magenta()
{
    delete sprite; 
    --Hud::magentas;
} 

void Magenta::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
} 

void Magenta::Update()
{ 
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
    Rotate(200 * gameTime); 
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
} 