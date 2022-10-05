/**********************************************************************************        
**********************************************************************************/

#include "WaveM.h"
#include "GeoWars.h"
#include "Magenta.h"
#include "Hud.h" 

WaveM::WaveM() : posX(50, window->Width()-50), posY(50, game->Height()-50), secs(2.0f, 4.0f)
{ 
    pX = posX.Rand();
    pY = posY.Rand(); 
    delay = secs.Rand();
} 

WaveM::~WaveM()
{

} 

void WaveM::Update()
{ 
    if (timer.Elapsed(delay) && Hud::magentas < 5)
    { 
        BasicAI::audio->Play(MAGENTA); 
        BasicAI::scene->Add(new Magenta(pX, pY, BasicAI::player), MOVING); 
        pX = posX.Rand();
        pY = posY.Rand(); 
        timer.Start();
    }
} 

void WaveM::Draw()
{
    
} 
