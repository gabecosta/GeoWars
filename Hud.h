/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_HUD_H_
#define _GEOWARS_HUD_H_ 

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream; 

class Hud : public Object
{
private:
    Font * font = nullptr; 
    Font * bold = nullptr; 
    Sprite * infoBox = nullptr; 

    stringstream text; 
    uint frameCount; 
    float totalTime; 
    uint fps; 

public:
    static uint missiles; 
    static uint oranges; 
    static uint magentas; 
    static uint blues; 
    static uint greens; 
    static uint particles; 

    Hud(); 
    ~Hud(); 

    void Update(); 
    void Draw(); 
}; 

#endif

