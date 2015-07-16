#include <Servo.h>

//Servo Configuration
typedef struct IServoConfiguration{
  float min_us;
  float max_us;
  IServoConfiguration(float min,float max){
    this->min_us = min;
    this->max_us = max;
  }
} IServoConfiguration;

//Servo Extended Class
typedef struct IServo{
  Servo servo;
  int pin;
  float min_us;
  float max_us;
  float max_angle = 180.0f;
  float angle_ratio;

  IServo(int pin){
    this->pin = pin;
  }


  void init(float min_us,float max_us){
    this->servo.attach(this->pin);
    this->setMinMax(min_us,max_us);
  }

  void init(IServoConfiguration configuration){
    this->init(configuration.min_us,configuration.max_us);
  }

  void setMinMax(float min_us,float max_us){
    this->min_us = min_us;
    this->max_us = max_us;
    this->angle_ratio = (max_us - min_us) / max_angle;
  }

  void setMicroseconds(float us){
    this->servo.writeMicroseconds(us);
  }

  float setAngle(float angle){
    float us = angle * this->angle_ratio + this->min_us;
    this->setMicroseconds(us);
    return us;
  }

} IServo;



//Calbirated MOTORS
IServoConfiguration motor7(875.0f,2000.0f);
IServoConfiguration motor11(860.0f,1985.0f);
IServoConfiguration motor5(860.0f,2130.0f);
IServoConfiguration motor17(830.0f,2180.0f);
