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
const int X_pin = 1; // analog pin connected to X output
const int Y_pin = 2; // analog pin connected to Y output
unsigned long delaytime1=500;
unsigned long delaytime2=50;
byte snake_vector[64][2];
byte matrixSize=64;
byte joystickReturn;
byte manzana[2];
int longitud = 10;
byte capturaJoystick();
byte printSnake(byte vector[64][2]);
byte prevJoystickValue;
long animacion();



void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  /*genera la semilla para las coordenadas de la manzana*/
  randomSeed(analogRead(0));
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
  for(int i=1; i<matrixSize; i++)
    {
      snake_vector[i][0] = 255;
      snake_vector[i][1] = 255;
    }
    
    snake_vector[0][0] = 0;
    snake_vector[0][1] = 0;
      

  prevJoystickValue = 0;

/*animacion de inicio to wapa*/
  animacion();
  


  
  while(1){
  

  /*invocamos a capturaJoystick*/
   joystickReturn = capturaJoystick();

   /* movemos serpiente */
    /*la serpiente se sigue moviendo hacia su ultima direccion*/
      if(joystickReturn != 5)
      {
          prevJoystickValue = joystickReturn;
      }
      else
      {
          joystickReturn = prevJoystickValue;
      }

      
      /*la cola*/
      for(int i=62; i>=0; i--)
      {
        snake_vector[i+1][0] = snake_vector[i][0];
        snake_vector[i+1][1] = snake_vector[i][1];
      }
      snake_vector[longitud][0] = 255;
      snake_vector[longitud][1] = 255;
      
     /**/
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
      /*si llega a un borde vuelve a empezar la partida*/
      if(snake_vector[0][0]>7 || snake_vector[0][1]>7) break;
      
      printSnake(snake_vector);

  }
}



  
