/*Lacombe quentin exemple getAngle
 * http://quentin.hebfree.org
 * quentlace2g@gmail.com
*/

#include <Gyro.h>

Gyro gyro;

void setup() {
  Serial.begin(9600);
  
  gyro.begin();
}

void loop() {
  Serial.print("Angle X: ");  
  Serial.print(gyro.getX());
  Serial.println(" degre");
  Serial.print("Angle Y: ");  
  Serial.print(gyro.getY());
  Serial.println(" degre");
  Serial.println();
  delay(1000);

}
