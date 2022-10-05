/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_MISSILE_H_
#define _GEOWARS_MISSILE_H_ 

#include "Vector.h"
#include "Object.h"
#include "Sprite.h"
#include "Player.h" 

class Missile : public Object
{
private:
    static Player* & player; 
    Sprite * sprite; 
    Vector speed; 
    
public:
    Missile(float angle); 
    ~Missile(); 

    Vector& Speed(); 
    void Update(); 
    void Draw(); 
}; 

inline Vector& Missile::Speed()
{ return speed; }

inline void Missile::Draw()
{ sprite->Draw(x, y, Layer::UPPER, scale, rotation); } 

#endif