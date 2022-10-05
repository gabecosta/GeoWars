/**********************************************************************************        
**********************************************************************************/

#include "Hud.h"
#include "GeoWars.h"  
uint Hud::missiles = 0;
uint Hud::oranges = 0;
uint Hud::magentas = 0;
uint Hud::blues = 0;
uint Hud::greens = 0;
uint Hud::particles = 0; 

Hud::Hud()
{ 
    font = new Font("Resources/Tahoma14.png");
    font->Spacing("Resources/Tahoma14.dat");
    bold = new Font("Resources/Tahoma14b.png");
    bold->Spacing("Resources/Tahoma14b.dat"); 
    infoBox = new Sprite("Resources/InfoBox.png"); 
    frameCount = 0;
    totalTime = 0.0f;
    fps = 0;
} 

Hud::~Hud()
{
    delete font;
    delete bold;
    delete infoBox;
} 

void Hud::Update()
{ 
    totalTime += gameTime; 
    frameCount++; 
    if (totalTime >= 1.0f)
    {
        fps = frameCount;
        frameCount = 0;
        totalTime -= 1.0f;
    }
} 

void Hud::Draw()
{ 
    infoBox->Draw(game->viewport.left + 140, game->viewport.top + 100, Layer::FRONT); 
    Color textColor{ 0.7f, 0.7f, 0.7f, 1.0f }; 
    text.str("");
    text << "Geometry Wars";
    bold->Draw(40, 62, text.str(), textColor);

    text.str("");
    text << "FPS: " << fps;
    font->Draw(40, 92, text.str(), textColor);

    text.str("");
    text << "Partículas: " << particles;
    font->Draw(40, 112, text.str(), textColor);

    text.str("");
    text << "Inimigos: " << oranges + magentas + blues + greens;
    font->Draw(40, 132, text.str(), textColor);

    text.str("");
    text << "Mísseis: " << missiles;
    font->Draw(40, 152, text.str(), textColor);
} 
