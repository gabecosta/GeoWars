/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_GREEN_H_
#define _GEOWARS_GREEN_H_ 

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h" 

class Green : public Object
{
private:
    Sprite * sprite; 
    Player * player; 
    Vector speed; 
    int distance; 
    
public:
    Green(float pX, float pY, Player * p); 
    ~Green(); 
    
    void OnCollision(Object* obj); 
    void Update(); 
    void Draw(); 
}; 

inline void Green::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); } 


#endif