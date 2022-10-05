/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_DELAY_H_
#define _GEOWARS_DELAY_H_ 

#include "Object.h"
#include "Sprite.h"
#include "Timer.h" 

class Delay : public Object
{
private:
    Sprite * logo; 
    Timer timer; 
    
    bool notPlayed; 
    bool fase1; 
    bool fase2; 
    bool fase3; 
    bool fase4; 

public:
    Delay(); 
    ~Delay(); 

    void Update(); 
    void Draw(); 
}; 

#endif
