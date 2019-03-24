/*-------------Encoder---------------*/
#include <Encoder.h>

#define LeftInterruptPin 0
#define RightInterruptPin 1

boolean LcoderDir,RcoderDir;
const byte encoder0pinB = A1;
byte encoder0PinALast;
const byte encoder1pinB = A3;
byte encoder1PinALast;

int RotationCoder[2];
/*--------------------------------------*/

// **************************
// Init the Incoder
// **************************


void EnCoderInit()
{
  
  attachInterrupt(LeftInterruptPin, LwheelSpeed, RISING);
  attachInterrupt(RightInterruptPin, RwheelSpeed, RISING);
}



// *******************************
// Read the Speed from the Encoder
// *******************************
void LwheelSpeed(){
  if(digitalRead(encoder0pinB)){
    
    Lduration++;
    }else Lduration--;
/*  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW)&&Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && LcoderDir)  LcoderDir = false; //Lreverse
    else if(val == HIGH && !LcoderDir)  LcoderDir = true;  //Lforward
  } 
  encoder0PinALast = Lstate;

  if(!LcoderDir)  Lduration++;
  else  Lduration--;
*/   
}

void RwheelSpeed()
{
  if(digitalRead(encoder1pinB))
    Rduration--;
  else Rduration++;
/*  int Rstate = digitalRead(encoder1pinA);
  if((encoder1PinALast == LOW)&&Rstate==HIGH)
  {
    int val = digitalRead(encoder1pinB);
    if(val == LOW && RcoderDir)  RcoderDir = false; //Rreverse
    else if(val == HIGH && !RcoderDir)  RcoderDir = true;  //Rforward
  }
  encoder1PinALast = Rstate;

  if(!RcoderDir)  Rduration--;
  else  Rduration++;
*/  
}
