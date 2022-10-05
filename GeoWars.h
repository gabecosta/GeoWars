/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_H_
#define _GEOWARS_H_ 

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h" 

enum Ids 
{ 
    PLAYER, MISSILE, WALLHIT, BLUE, GREEN, MAGENTA, ORANGE, 
    THEME, START, FIRE, EXPLODE, HITWALL, EXPLOSION 
}; 

class BasicAI : public Game
{
private:
    Background * backg = nullptr; 
    Hud * hud = nullptr; 
    bool viewBBox = false; 

public:
    static Player * player; 
    static Audio * audio; 
    static Scene * scene; 

    static Image * blue; 
    static Image * green; 
    static Image * magenta; 
    static Image * orange; 
    
    static bool viewHUD; 

    void Init(); 
    void Update(); 
    void Draw(); 
    void Finalize(); 
}; 

#endif