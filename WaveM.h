/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_WAVEM_H_
#define _GEOWARS_WAVEM_H_ 

#include "Object.h"
#include "Timer.h"
#include "Random.h" 

class WaveM : public Object
{
private:
    float pX, pY; 
    RandF posX; 
    RandF posY; 
    RandF secs; 
    Timer timer; 
    float delay; 

public:
    WaveM(); 
    ~WaveM(); 

    void Update(); 
    void Draw(); 
}; 

#endif
