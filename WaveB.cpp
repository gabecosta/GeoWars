/**********************************************************************************        
**********************************************************************************/

#include "WaveB.h"
#include "GeoWars.h"
#include "Blue.h"
#include "Hud.h" 

WaveB::WaveB() : posX(0, window->Width()), posY(0, window->Height()), secs(8.0f, 12.0f)
{ 
    pX = posX.Rand();
    pY = posY.Rand(); 
    delay = secs.Rand();
} 

WaveB::~WaveB()
{

} 

void WaveB::Update()
{ 
    static uint counter = 8; 
    if (timer.Elapsed(delay) && Hud::blues < 15)
    {
        if (counter > 0)
        { 
            BasicAI::audio->Play(BLUE); 
            BasicAI::scene->Add(new Blue(pX, pY, BasicAI::player), MOVING);

            delay = 0.850f;
            timer.Start();
            --counter;
        }
        else
        { 
            pX = posX.Rand();
            pY = posY.Rand(); 
            counter = 8;
            delay = secs.Rand();
            timer.Start();
        }
    }
} 

void WaveB::Draw()
{
    
} 
