/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_PLAYER_H_
#define _GEOWARS_PLAYER_H_ 

#include "Object.h" 
#include "Sprite.h" 
#include "Vector.h" 
#include "Particles.h" 
#include "Controller.h" 
#include "Timer.h"  

class Player : public Object
{
private:
    Sprite * sprite; 
    Particles * tail; 
    uint tailCount; 
    
    Controller * gamepad; 
    bool gamepadOn; 
    
    Timer timer; 
    llong start; 
    bool axisCtrl; 
    bool keysCtrl; 
    bool keysPressed; 
    float firingAngle; 

public:
    static Image * missile; 
    Vector speed; 

    Player(); 
    ~Player(); 
    
    bool AxisTimed(int axisX, int axisY, float time);
    bool KeysTimed(bool pressed, float time);

    void Move(Vector && v); 
    void Update(); 
    void Draw(); 
}; 

#endif