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
byte manzana[2];
int longitud = 1;
int X = 0;
int Y = 0;



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
  snake_vector[0][0] = 0;
  snake_vector[0][1] = 0;
  for(int i=1; i<matrixSize; i++)
    {
      snake_vector[i][0] = 255;
      snake_vector[i][1] = 255;
    }
}





void loop() { 
 
  
 /*representamos la manzana*/
 /*lc.setLed(0,manzana[0], manzana[1],1);
 
 
 
 /* Representamos la serpiente */
 
  for(int i=0; i<matrixSize; i++)
  { 
    
    /*se definen las coordenadas de la serpiente y se representa*/

    lc.setLed(0,snake_vector[i][0],snake_vector[i][1],1);
    /* elimina los puntos encendidos en la cola de la serpiente a partir del segundo bucle*/
    delay(delaytime1);
    if(i>0)
    {
      lc.setLed(0,snake_vector[i-longitud][0], snake_vector[i-longitud][1],0);
    }
    delay(delaytime1);
    /*si la cabeza de la serpiente esta en las mismas coordenadas que la manzana longitud aumenta por uno*/
    //if(manzana[0]==snake_vector[i][0] && manzana[1]==snake_vector[i][1])
    /*si la serpiente alcanza su longitud máxima se sale del bucle for*/
    if(snake_vector[i][0] > matrixSize)
    {
      break;
    }
  }
}
