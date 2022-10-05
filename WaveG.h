/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_WAVEG_H_
#define _GEOWARS_WAVEG_H_ 

#include "Object.h"
#include "Timer.h"
#include "Random.h" 

class WaveG : public Object
{
private: 
    RandF secs; 
    Timer timer; 
    float delay; 

public:
    WaveG(); 
    ~WaveG(); 

    void Update(); 
    void Draw(); 
}; 

#endif
