// More info about the library: http://wayoda.github.io/LedControl/
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1); // we create an instance of type LedControl

/* we always wait a bit between updates of the display */
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
unsigned long delaytime1=500;
unsigned long delaytime2=50;
byte snake_vector[64][2];
byte matrixSize=64;
byte joystickReturn;
byte manzana[2];
int longitud = 1;
byte capturaJoystick();
byte printSnake(byte vector[64][2]);
byte prevJoystickValue;
long animacion();


void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  /*genera la semilla para las coordenadas de la manzana*/
  randomSeed(analogRead(5));
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,4);
  /* and clear the display */
  lc.clearDisplay(0);

  
  /*inicializamos la manzana*/
  manzana[0]=random(8);
  manzana[1]=random(8);
  
  /*Inicializamos la serpiente */
  for(int i=1; i<matrixSize; i++)
    {
      snake_vector[i][0] = 255;
      snake_vector[i][1] = 255;
    }
}





void loop()
{ 
   lc.clearDisplay(0);
  /*reinicializamos las variables*/
      snake_vector[0][0] = 0;
      snake_vector[0][1] = 0;
      
  for(int i=1; i<matrixSize; i++)
    {
      snake_vector[i][0] = 255;
      snake_vector[i][1] = 255;
    }
  prevJoystickValue = 0;

/*animacion de inicio to wapa*/
animacion();


  
  while(1){
  /*invocamos a capturaJoystick*/
   joystickReturn = capturaJoystick();

   /* movemos serpiente */
      if(joystickReturn != 5)
      {
          prevJoystickValue = joystickReturn;
      }
      else
      {
          joystickReturn = prevJoystickValue;
      }
      if(joystickReturn == 0)
      {}
      else if(joystickReturn == 1)
      {
        snake_vector[0][1]++;
      }
      else if(joystickReturn == 2)
      {
        snake_vector[0][0]--;
      }
      else if(joystickReturn == 3)
      {
        snake_vector[0][1]--;
      }
      else if(joystickReturn == 4)
      {
        snake_vector[0][0]++;
      }
      

      Serial.println(snake_vector[0][0]);
      Serial.println(snake_vector[0][1]);
      
      delay(250);
      if(snake_vector[0][0]>7 || snake_vector[0][1]>7) break;
      
      printSnake(snake_vector);

  }
}


byte capturaJoystick()
{
  if(digitalRead(SW_pin)==0)
      {
        return 0;
      }
    else if(analogRead(X_pin)>750)
      {
        Serial.println("X--");
        return 3;
      }
    else if(analogRead(X_pin)<250)
      {
        Serial.println("X++");  
        return 1;    
      }
    else if(analogRead(Y_pin)>750)
      {
        Serial.println("Y--");
        return 2;      
      }
    else if(analogRead(Y_pin)<250)
      {
        Serial.println("Y++");    
        return 4;  
      }
    else return 5;
}

byte printSnake(byte vector[64][2])
{
   lc.clearDisplay(0);
  for(int i=0;i<64;i++)
  {
    if(vector[i][0]==255 || vector[i][1]==255)
      {
        break;
      }
    lc.setLed(0,vector[0][0], vector[0][1],1);
  }
}
long animacion()
{
  /*animacion de inicio to wapa*/
/*parpadeo*/
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B11111111);
lc.setRow(0,2,B11111111);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B11111111);
lc.setRow(0,6,B11111111);
lc.setRow(0,7,B11111111);
delay(100);
lc.setRow(0,0,B00000000);
lc.setRow(0,1,B00000000);
lc.setRow(0,2,B00000000);
lc.setRow(0,3,B00000000);
lc.setRow(0,4,B00000000);
lc.setRow(0,5,B00000000);
lc.setRow(0,6,B00000000);
lc.setRow(0,7,B00000000);
delay(100);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B11111111);
lc.setRow(0,2,B11111111);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B11111111);
lc.setRow(0,6,B11111111);
lc.setRow(0,7,B11111111);
delay(100);
lc.setRow(0,0,B00000000);
lc.setRow(0,1,B00000000);
lc.setRow(0,2,B00000000);
lc.setRow(0,3,B00000000);
lc.setRow(0,4,B00000000);
lc.setRow(0,5,B00000000);
lc.setRow(0,6,B00000000);
lc.setRow(0,7,B00000000);
delay(100);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B11111111);
lc.setRow(0,2,B11111111);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B11111111);
lc.setRow(0,6,B11111111);
lc.setRow(0,7,B11111111);
delay(100);
lc.setRow(0,0,B00000000);
lc.setRow(0,1,B00000000);
lc.setRow(0,2,B00000000);
lc.setRow(0,3,B00000000);
lc.setRow(0,4,B00000000);
lc.setRow(0,5,B00000000);
lc.setRow(0,6,B00000000);
lc.setRow(0,7,B00000000);
delay(100);
lc.setRow(0,0,B11111111);
lc.setRow(0,1,B11111111);
lc.setRow(0,2,B11111111);
lc.setRow(0,3,B11111111);
lc.setRow(0,4,B11111111);
lc.setRow(0,5,B11111111);
lc.setRow(0,6,B11111111);
lc.setRow(0,7,B11111111);
delay(100);
lc.setRow(0,0,B00000000);
lc.setRow(0,1,B00000000);
lc.setRow(0,2,B00000000);
lc.setRow(0,3,B00000000);
lc.setRow(0,4,B00000000);
lc.setRow(0,5,B00000000);
lc.setRow(0,6,B00000000);
lc.setRow(0,7,B00000000);
delay(100);

lc.setRow(0,0,B11111111);
delay(100);
lc.setRow(0,1,B11111111);
delay(100);
lc.setRow(0,2,B11111111);
delay(100);
lc.setRow(0,3,B11111111);
delay(100);
lc.setRow(0,4,B11111111);
delay(100);
lc.setRow(0,5,B11111111);
delay(100);
lc.setRow(0,6,B11111111);
delay(100);
lc.setRow(0,7,B11111111);
delay(100);
lc.setRow(0,0,B00000000);
delay(100);
lc.setRow(0,1,B00000000);
delay(100);
lc.setRow(0,2,B00000000);
delay(100);
lc.setRow(0,3,B00000000);
delay(100);
lc.setRow(0,4,B00000000);
delay(100);
lc.setRow(0,5,B00000000);
delay(100);
lc.setRow(0,6,B00000000);
delay(100);
lc.setColumn(0,7,B00000000);
delay(100);
lc.setColumn(0,6,B00000000);
delay(100);
lc.setColumn(0,5,B00000000);
delay(100);
lc.setColumn(0,4,B00000000);
delay(100);
lc.setColumn(0,3,B00000000);
delay(100);
lc.setColumn(0,2,B00000000);
delay(100);
lc.setColumn(0,1,B00000000);
delay(100);
lc.setColumn(0,0,B00000001);
delay(100);
lc.setColumn(0,0,B00000010);
delay(100);
lc.setColumn(0,0,B00000100);
delay(100);
lc.setColumn(0,0,B00001000);
delay(100);
lc.setColumn(0,0,B00010000);
delay(100);
lc.setColumn(0,0,B00100000);
delay(100);
lc.setColumn(0,0,B01000000);
delay(100);
lc.setColumn(0,0,B10000000);
delay(100);
}
    




  
