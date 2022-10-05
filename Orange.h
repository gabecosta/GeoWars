/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_ORANGE_H_
#define _GEOWARS_ORANGE_H_ 

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h" 

class Orange : public Object
{
private:
    Sprite * sprite; 
    Particles * tail; 
    uint tailCount; 
    Vector speed; 
    
public:
    Orange(float pX, float pY, float ang); 
    ~Orange(); 
    
    void OnCollision(Object* obj); 
    void Update(); 
    void Draw(); 
}; 


#endif