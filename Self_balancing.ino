// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include <Wire.h>
#include <Kalman.h>
#include <Encoder.h>
#include <PID_v1.h>
/******************************************************/

//UNO pin map
int ENA=6;
int ENB=9;

int IN1=5;
int IN2=4;
int IN3=8;
int IN4=7;

int MAS,MBS;


/* IMU Data */
double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
int16_t tempRaw;

double gyroXangle, gyroYangle; // Angle calculate using the gyro only
double compAngleX, compAngleY; // Calculated angle using a complementary filter
double kalAngleX, kalAngleY; // Calculated angle using a Kalman filter
uint8_t i2cData[14]; // Buffer for I2C data
uint32_t timer;
unsigned long lastTime;      

/********** Create the kalman filter for IMU **********/
Kalman kalmanBody;
double angle, angleSpeed; // Create the kalman filter params for IMU

int Lduration,Rduration;

// Adjust the body balance PID Parameters
float k1=93;//24.80;
float k2=2.1;//9.66;
float k3=4.88 ;//4.14;
float k4=-0.55;//0.99;

int turn_flag=0;
float move_flag=0;

int pwm;
int pwm_R,pwm_L;
float range;
float range_error_all;
float wheel_speed;
float last_wheel;
float error_a=0;

/********** The balance stick Params **********/
#define stick A0
//To balance the stick, we have to maintain the A0 port at value 545.
int balancePosition = 545;

// Params for partition
int PositionError;
float Kp = -100;
//Params for derivative
int previousError;
float Kd = 0.1;
//Params for intergrate
int accumulateError;
float Ki = 0.01;

unsigned long sticklastTime;
/********************************************************/
