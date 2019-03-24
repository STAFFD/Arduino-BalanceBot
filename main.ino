
/***************************** main loop ****************************************************/

void loop() 
{
  control();
  get_MPU_data();
  double dt = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();
  
  double pitch  = atan2(accY, accZ) * RAD_TO_DEG - move_flag;
  double gyroXrate = gyroX / 131.0; // Convert to deg/s
  double gyroYrate = -gyroY / 131.0; // Convert to deg/s
  
  angle = kalmanBody.getAngle(pitch, gyroXrate, dt);
  angleSpeed = kalmanBody.getRate();
  
 if(abs(angle)<35){

  pwm_calculate();
  PWM_output();
  
  }
  else{
    analogWrite(ENB, 0); //PWM调速a==0-255
    analogWrite(ENA,0 ); //PWM调速a==0-255
  }  
  delay(2);
}
