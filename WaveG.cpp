/**********************************************************************************        
**********************************************************************************/

#include "WaveG.h"
#include "GeoWars.h"
#include "Green.h"
#include "Hud.h" 

WaveG::WaveG() : secs(10.0f, 15.0f)
{ 
    delay = secs.Rand();
} 

WaveG::~WaveG()
{

} 

void WaveG::Update()
{ 
    static uint counter = 8; 
    if (timer.Elapsed(delay) && Hud::greens < 16)
    {
        if (counter > 0)
        { 
            BasicAI::audio->Play(GREEN); 
            BasicAI::scene->Add(new Green(50, 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Green(game->Width() - 50, 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Green(game->Width() - 50, game->Height() - 50, BasicAI::player), MOVING);
            BasicAI::scene->Add(new Green(50, game->Height() - 50, BasicAI::player), MOVING);

            delay = 0.450f;
            timer.Start();
            --counter;
        }
        else
        { 
            counter = 8;
            delay = secs.Rand();
            timer.Start();
        }
    }
} 

void WaveG::Draw()
{
    
} 
