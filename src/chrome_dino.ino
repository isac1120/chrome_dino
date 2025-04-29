#include <Servo.h>
Servo servo;
bool isJump=0;
bool prevJump=0;
int jumpDelay=0;
bool isJumping=0;
int count=0;
unsigned long previousPrintTime = 0;  // 마지막 Serial 출력 시간
const unsigned long printInterval = 250;  // 출력 간격 (0.5초)

void setup() {  
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
  servo.write(0);
}

void loop() {
  unsigned long currentTime = millis();
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);

  // 0.1초마다 light 값 출력
  if (currentTime - previousPrintTime >= printInterval) {
    Serial.println(light);
    previousPrintTime = currentTime;
  }
  if(light<760)
  {
    isJump = 1;
  }
  else
  {
    isJump = 0;
  }
  
  if(prevJump==0 && isJump==1)
  {
    count++;

    if(count<=4)
    {
      delay(200);
      servo.write(20);
      delay(400);
    }
    else if(count<10)
    {
      delay(200);
      servo.write(20);
      delay(400);
    }
    else if(count<20)
    {
      delay(50);
      servo.write(20);
      delay(200);
    }
    else
    {      
      delay(20);
      servo.write(20);
      delay(200);
    }
    servo.write(0);

  }
  
  prevJump = isJump;
  delay(30);

}
