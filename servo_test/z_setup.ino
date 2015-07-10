
IServo servo_left(3);
IServo servo_right(9);

bool calibration_mode = false;

void setup(){
  Serial.begin(9600);

  servo_left.init(motor7);
  servo_right.init(motor11);
}

int target = 0;
int current = 0;
int vel = 10;

void loop()
{
  String s = "";
  while(Serial.available()>0){
    s+=(char)Serial.read();
  }
  if(s.length()>0){
    if(s=="cal"){
      calibration_mode = !calibration_mode;
      if(calibration_mode){
        Serial.println("Calibration mode ON!");
      }else{
        Serial.println("calibration_mode OFF");
      }
    }else{

      Serial.print("Received: ");
      Serial.println(s.toInt());
      if(calibration_mode){
        servo_left.setMicroseconds(s.toInt());
        servo_right.setMicroseconds(s.toInt());
      }else{
        target = s.toInt();
        
        
        
        
       
      }
    }
    
  }
  if(abs(current-target)>0){
          current += vel * (target-current)/abs(current-target);
        }else{
          current = target;
          }
  Serial.println(current);
    servo_left.setAngle(current);
    servo_right.setAngle(current);

  delay(100);
}
