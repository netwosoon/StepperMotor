#include<StepperMotor.h>

StepperMotor motor(2,3,4,5);

void setup() {
  motor.setSteps(4096);
  Serial.begin(9600);
}

void loop() {
  if(!motor.run()){
    boolean reverse = motor.direction();
    motor.setDirection(!reverse);
    motor.rotate(180);
    delay(1000);
    Serial.println(motor.stepsLeft());
  }
}
