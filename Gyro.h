#ifndef Gyro_h
#define Gyro_h
    
#include <Wire.h>

class Gyro
{
public:

void begin();
int getX();
int getY();

};

#endif
