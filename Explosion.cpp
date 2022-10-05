/**********************************************************************************        
**********************************************************************************/

#include "GeoWars.h"
#include "Explosion.h"
#include "Random.h"
#include "Hud.h" 

Explosion::Explosion(float pX, float pY)
{ 
    RandF color{ 0, 1 }; 
    Generator explosion;
    explosion.imgFile   = "Resources/Explo.png"; 
    explosion.angle     = 0.0f; 
    explosion.spread    = 360.0f; 
    explosion.lifetime  = 1.5f; 
    explosion.frequency = 0.000f; 
    explosion.percentToDim = 0.8f; 
    explosion.minSpeed  = 25.0f; 
    explosion.maxSpeed  = 250.0f; 
    explosion.color.r   = color.Rand(); 
    explosion.color.g   = color.Rand(); 
    explosion.color.b   = color.Rand(); 
    explosion.color.a   = 1.0f;  
    sparks = new Particles(explosion); 
    sparks->Generate(pX, pY, 50);
    type = EXPLOSION; 
    Hud::particles += 50;
} 

Explosion::~Explosion()
{
    delete sparks; 
    Hud::particles -= 50;
} 

void Explosion::Update()
{ 
    sparks->Update(gameTime); 
    if (sparks->Inactive())
        BasicAI::scene->Delete();
} 