/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_BLUE_H_
#define _GEOWARS_BLUE_H_ 

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h" 

class Blue : public Object
{
private:
    Sprite * sprite; 
    Player * player; 
    Vector speed; 
    float factor; 
    
public:
    Blue(float pX, float pY, Player * p); 
    ~Blue(); 
    
    void OnCollision(Object* obj); 
    void Update(); 
    void Draw(); 
}; 

inline void Blue::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); } 


#endif