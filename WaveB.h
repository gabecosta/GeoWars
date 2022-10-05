/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_WAVEB_H_
#define _GEOWARS_WAVEB_H_ 

#include "Object.h"
#include "Timer.h"
#include "Random.h" 

class WaveB : public Object
{
private:
    float pX, pY; 
    RandF posX; 
    RandF posY; 
    RandF secs; 
    Timer timer; 
    float delay; 

public:
    WaveB(); 
    ~WaveB(); 

    void Update(); 
    void Draw(); 
}; 

#endif
