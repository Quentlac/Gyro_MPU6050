#include "Gyro.h"
#include <Arduino.h>
#include <Wire.h>

void Gyro::begin(){
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);

}

int Gyro::getX(){
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);  //adresse pour l'axe Y
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,14,true);  
  int AcX=Wire.read()<<8|Wire.read(); 

  int x = map(AcX,-16900,16900,0,180);
  return x;

}

int Gyro::getY(){
  Wire.beginTransmission(0x68);
  Wire.write(0x3D);  //adresse pour l'axe Y
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,14,true);  
  int AcY=Wire.read()<<8|Wire.read(); 

  int y = map(AcY,-16500,16500,0,180);
  return y;

}

int Gyro::getTmp(){
  Wire.beginTransmission(0x68);
  Wire.write(0x41);  //adresse pour la temperature
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,14,true);  
  int tmp=Wire.read()<<8|Wire.read(); 

  int temperature = tmp/340.00+36.53;
  return temperature;

}
