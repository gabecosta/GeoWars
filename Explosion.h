/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_EXPLOSION_H_
#define _GEOWARS_EXPLOSION_H_ 

#include "Object.h"    
#include "Types.h"
#include "Particles.h" 

class Explosion : public Object
{
private:
    Particles * sparks; 
    
public:
    Explosion(float pX, float pY); 
    ~Explosion(); 

    int Size(); 
    void Update(); 
    void Draw(); 
}; 

inline int Explosion::Size()
{ return sparks->Size(); }

inline void Explosion::Draw()
{ sparks->Draw(Layer::MIDDLE, 1.0f); } 


#endif