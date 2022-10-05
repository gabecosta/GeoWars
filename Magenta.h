/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_MAGENTA_H_
#define _GEOWARS_MAGENTA_H_ 

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h" 

class Magenta : public Object
{
private:
    Sprite * sprite; 
    Player * player; 
    Vector speed; 
    
public:
    Magenta(float pX, float pY, Player * p); 
    ~Magenta(); 
    
    void OnCollision(Object * obj); 
    void Update(); 
    void Draw(); 
}; 

inline void Magenta::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); } 


#endif