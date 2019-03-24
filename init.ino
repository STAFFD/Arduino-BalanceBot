void setup() {
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

  // initialize serial communication
  Serial.begin(9600);
  //Serial.println("AT+NAMEitead");

  /******** Initialize motor **********/
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  /************************************/
  
  pinMode(6, OUTPUT);  
  digitalWrite(6, LOW);//disable buzzer
  EnCoderInit();

  MPU_init();
  timer = micros();
}
