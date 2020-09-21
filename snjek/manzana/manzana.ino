#include"LedControl.h"
LedControl lc=LedControl(12,10,11,1); // we create an instance of type LedControl
byte manzana[2];

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
    lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);

}

void loop() 
{

  manzana[0]= random(8);
  manzana[1]= random(8);
  Serial.print(manzana[0]);
  Serial.print("\n");
  Serial.print(manzana[1]);
  Serial.print("\n");
  Serial.print("\n");
  lc.setLed(0,manzana[0],manzana[1],1);
  delay(50);
}
