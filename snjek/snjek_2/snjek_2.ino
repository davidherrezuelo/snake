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
int count = 0;



void setup() {

// Set baud rate
  Serial.begin(9600);

// Joystick setup
  pinMode(SW_pin, INPUT);     	// pin for joystick
  digitalWrite(SW_pin, HIGH); 	// pin for joystick

// Matrix setup
  lc.shutdown(0,false);			// The MAX72XX is in power-saving mode on startup, we have to do a wakeup call
  lc.setIntensity(0,4);			// Set the brightness to a medium values
  lc.clearDisplay(0);			// and clear the display

// Random numbers
  randomSeed(analogRead(5));  	// Generate Seed for random numbers

// Apple init
  manzana[0]=random(8);
  manzana[1]=random(8);

// Snake setup
  snake_vector[0][0] = 0; // La seripiente se encuentra en coordenadas (0,0)
  snake_vector[0][1] = 0;
  for(int i=1; i<matrixSize; i++)
    {
      snake_vector[i][0] = 255; // El resto de la serpiente está vacío
      snake_vector[i][1] = 255;
    }

}


void loop() { 

    /* Leer joystick */
    int lec_joy = leer_joystick();

    /*mover serpiente */

    /*representar serpiente */
  
    lc.setLed(0,snake_vector[i][0],snake_vector[i][1],1);
   
}

int leer_joystick(){
  

}
}
