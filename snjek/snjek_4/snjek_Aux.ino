
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
    lc.setLed(0,vector[i][0], vector[i][1],1);
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
/*rellenar hacia derecha*/
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
/*vaciar hacia la derecha*/
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
/*vaciar linea*/
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
/*el punto se mueve*/
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
    




  
