/**********************************************************************************        
**********************************************************************************/

#include "Missile.h"
#include "WallHit.h"
#include "GeoWars.h"
#include "Hud.h" 

Player* & Missile::player = BasicAI::player;  

Missile::Missile(float angle)
{ 
    sprite = new Sprite(Player::missile); 
    BBox(new Circle(8)); 
    speed.RotateTo(angle);
    speed.ScaleTo(15.0f); 
    MoveTo(player->X() + 40 * cos(speed.Radians()), player->Y() - 40 * sin(speed.Radians()));
    RotateTo(-speed.Angle() + 90.0f); 
    type = MISSILE; 
    ++Hud::missiles;
} 

Missile::~Missile()
{
    delete sprite; 
    --Hud::missiles;
} 

void Missile::Update()
{ 
    Translate(speed.XComponent() * 90.0f * gameTime, -speed.YComponent() * 90.0f * gameTime); 
    if (x > game->Width() - 50 || x < 50 || y > game->Height() - 50 || y < 50)
    { 
        const float MaxDistance = 4406;
        const float BaseVolume = 0.8f;
        float distance = Point::Distance(Point(x, y), Point(player->X(), player->Y()));
        float level = (MaxDistance - distance) / MaxDistance;
        BasicAI::audio->Volume(HITWALL, level * BaseVolume);
        BasicAI::audio->Play(HITWALL); 
        BasicAI::scene->Add(new WallHit(x,y), STATIC); 
        BasicAI::scene->Delete();
    }
} 
