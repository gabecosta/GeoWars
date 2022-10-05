/**********************************************************************************        
**********************************************************************************/

#ifndef _GEOWARS_WAVEO_H_
#define _GEOWARS_WAVEO_H_ 

#include "Object.h"
#include "Sprite.h"
#include "Timer.h"
#include "Random.h" 

class WaveO : public Object
{
private:
    int numX, numY; 
    float posX, posY; 
    RandI position; 
    RandF delay; 
    Timer timer; 
    float waveDelay; 
    bool newWave; 

public:
    WaveO(); 
    ~WaveO(); 

    void Update(); 
    void Draw(); 
}; 

#endif
