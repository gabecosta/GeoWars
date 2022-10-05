/**********************************************************************************        
**********************************************************************************/

#include "WaveO.h"
#include "GeoWars.h"
#include "Orange.h"
#include "Hud.h" 

WaveO::WaveO() : position(0,3), delay (1.0f, 5.0f)
{ 
    numX = 8;
    numY = 8; 
    posX = 0;
    posY = 0; 
    newWave = false;
    waveDelay = delay.Rand();
} 

WaveO::~WaveO()
{

} 

void WaveO::Update()
{ 
    if (newWave)
    { 
        if (timer.Elapsed(waveDelay))
        { 
            BasicAI::audio->Play(ORANGE); 
            switch (position.Rand())
            {
            case 0: 
                posY = 100;
                for (int i = 0; i < numY; ++i)
                {
                    BasicAI::scene->Add(new Orange(50, posY, 0), MOVING);
                    posY += 50;
                }
                break;
            case 1: 
                posX = 100;
                for (int i = 0; i < numX; ++i)
                {
                    BasicAI::scene->Add(new Orange(posX, 50, 270), MOVING);
                    posX += 50;
                }
                break;
            case 2: 
                posY = game->Height() - 100;
                for (int i = 0; i < numY; ++i)
                {
                    BasicAI::scene->Add(new Orange(game->Width() - 50, posY, 180), MOVING);
                    posY -= 50;
                }
                break;
            case 3: 
                posX = game->Width() - 100;
                for (int i = 0; i < numX; ++i)
                {
                    BasicAI::scene->Add(new Orange(posX, game->Height() - 50, 90), MOVING);
                    posX -= 50;
                }
                break;
            } 
            newWave = false;
        }
    }
    else
    { 
        if (Hud::oranges < 10)
        {
            waveDelay = delay.Rand();
            timer.Start();
            newWave = true;
        }
    }
} 

void WaveO::Draw()
{
    
} 
