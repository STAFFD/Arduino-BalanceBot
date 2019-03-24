// **************************
// Calculate the pwm
// **************************
void pwm_calculate()
{
   unsigned long  now = millis();
   int Time = now - lastTime;

  int range_error;
  range+=(Lduration+Rduration)*0.5;
  range*=0.9;
  range_error=Lduration-Rduration;
  range_error_all+=range_error;

  wheel_speed=range-last_wheel;
  last_wheel=range;

  /*************** Calculate the PID for the stick**************/
//  float stickPID = balanceStick();
  
  pwm=angle*k1 + angleSpeed*k2 + range*k3 + wheel_speed*k4;    //use PID tho calculate the pwm
 
  if(pwm > 255) pwm = 255;                            //Maximum Minimum Limitations
  else if(pwm < -255) pwm=-255;
    
      //Serial.print(pwm);Serial.print("\t");
      Serial.print(Lduration);Serial.print("\t");
      Serial.print(Rduration);Serial.print("\t\n");
/*    if(turn_flag==0)
    {
     pwm_R=pwm+range_error_all;
     pwm_L=pwm-range_error_all;
    }
    else
    {
        pwm_R=pwm-turn_flag*68;  //Direction PID control
        pwm_L=pwm+turn_flag*68;
        range_error_all=0;     //clean
    }
 */   
     Lduration = 0;//clean
     Rduration = 0;
}

/************************************************************/
void PWM_output()
{  
  if(pwm>0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);    
  }
  else if(pwm<0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  analogWrite(ENB, abs(pwm));
  analogWrite(ENA, abs(pwm) );
}

// **************************
// To balance the stick, we have to maintain the A0 port at value 545.
// **************************

float balanceStick(){
  int dt = millis() - sticklastTime;
  int stickPosition = analogRead(stick);
  PositionError = stickPosition - balancePosition;
  accumulateError += PositionError;
  float P = Kp * PositionError;
  float I = Ki * accumulateError;
  float D = Kd * (PositionError - previousError)/dt;
  return P + I + D;
}

void control()
{
  if(Serial.available()){
    int val;
    val=Serial.read();
    switch(val){
      case 'F':
        if(move_flag<5)
          move_flag+=0.1;
        Serial.println("forword");
        break;
      case 'B':
        if(move_flag>-5)move_flag-=0.1;
        Serial.println("back");
        break;
      case 'S':
        move_flag=0;
        turn_flag=0;
        Serial.println("stop");
        break;
      default:
        break;

    }
    }
}
