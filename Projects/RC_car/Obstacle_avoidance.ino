#define Line_Following 3
#define Obstacle_Avoiding 5

//Macro to choose between the 2 modes of operation
#define mode  Obstacle_Avoiding


//Duty cycles of the pwm signals for both motors
//The right motor's duty cylce is higher because it is a less powerful motor
#define pwm_R 20 * mode
#define pwm_L 19 * mode

//Enum to indicate the robot's direction
enum move
{
	STOP	      = 0,
	FORWARD     = 1,
	BACKWARD    = 2,
	RIGHT	      = 3,
	LEFT        = 4
};

//Right motor enable pin
int ENa  = 2;

//Left motor enable pin
int ENb  = 3;

//Right motor control pins
int out1 = 4;
int out2 = 5;

//Left motor control pins
int out3 = 8;
int out4 = 9;

//IR sensors pins
int pinIR_R = 6;
int pinIR_L = 7;

//Variables to indicate the output of the IR sensors
int IRvalue_R = 0;
int IRvalue_L = 0;

//Ultrasonic sensor Trigger pin
int trigPin = 11;

//Ultrasonic sensor Echo pin
int echoPin = 12;

//Variable to indicate the duration taken by the ultrasonic wave to reach the object
int duration;

//Variable to indicate the distance beteen the robot and the object
int distance;

//A flag to help in controlling the robot in the obstacle avoiding mode
int flag = 0;

//Prototype for MoveRobot function
void MoveRobot (char moveCommand);

void setup() 
{
  //Specify the 2 outputs of the IR sensors as inputs to the microcontroller
  pinMode(pinIR_R,INPUT);
  pinMode(pinIR_L,INPUT);

  //Specify the Trigger pin of the ultrasonic sensor as output from the microcontroller
  pinMode(trigPin, OUTPUT);
  //Specify the Echo pin of the ultrasonic sensor as input to the microcontroller
  pinMode(echoPin, INPUT);

  //Specify the Enable pins of the motor driver as outputs from the microcontroller
  pinMode(ENa, OUTPUT);
  pinMode(ENb, OUTPUT);
  //Specify the Control pins of the motor driver as outputs from the microcontroller
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);

  //Enable the 2 motors
  digitalWrite(ENa, HIGH);
  digitalWrite(ENb, HIGH);
}
 
void loop() 
{
  #if (mode == Obstacle_Avoiding)

  //Obstacle avoiding code

  //Send a pulse of width 100 microseconds to the Trigger pin of the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  //Calculate the duration in microseconds for the pulse recieved on the Echo pin of the ultrasonic sensor
  duration = pulseIn(echoPin, HIGH);
 
  //Calculate the distance in cm between the robot and the obstacle by diving the duration by 2 then multiplying it by the sound velocity
  //The duration is divided by 2 as it is for the ultrasonic waves to be sent and then recieved
  distance = (duration / 2) / 29.1;     // Divide by 29.1 or multiply by 0.0343 (the velocity of sound in air in cm/microsecond)

  //If the obstacle is too far, continue moving forward
  if (distance > 50)
  {
    MoveRobot(FORWARD);
  }
  //If there is an obstacle move to the right for three times and if there is still an obstacle move to the left
  else if (flag < 3)
  {
    MoveRobot(STOP);
    delay(50);
    MoveRobot(BACKWARD);
    delay(400);
    MoveRobot(RIGHT);
    delay(600);
    MoveRobot(FORWARD);
  }
  else
  {
    MoveRobot(STOP);
    delay(50);
    MoveRobot(BACKWARD);
    delay(400);
    MoveRobot(LEFT);
    delay(600);
    MoveRobot(FORWARD);
  }

  //Move forward for 250 ms every time
  delay(250);

  #else

  //line following code

  //read the outputs of the 2 IR sensors
  //1 indicates the presence of a black line, 0 indicates the absence of black line
  IRvalue_R = digitalRead(pinIR_R);
  IRvalue_L = digitalRead(pinIR_L);

  //If there is no black line detected, then move forward
  if (IRvalue_R == 0 && IRvalue_L == 0)
  {
    MoveRobot(FORWARD);
  }

  //If the right sensor detects a black line, then turn right
  else if (IRvalue_R == 1 && IRvalue_L == 0)
  {
    MoveRobot(RIGHT);
    delay(25);
    MoveRobot(FORWARD);
  }

  //If the left sensor detects a black line, then turn left
  else if (IRvalue_R == 0 && IRvalue_L == 1)
  {
    MoveRobot(LEFT);
    delay(25);
    MoveRobot(FORWARD);
  }

  //If both sensors detect black line, then stop for 1 minute (it means you reached the end line)
  else if (IRvalue_R == 0 && IRvalue_L == 0)
  {
    MoveRobot(STOP);
    delay(60000);
  }

  #endif
}

//Function to move the robot in the specified direction
//Motors' speed are controlled using pwm signals
void MoveRobot (char moveCommand)
{
	switch (moveCommand)
	{
		case STOP:
      digitalWrite(out1, LOW);
      digitalWrite(out2, LOW);
      digitalWrite(out3, LOW);
      digitalWrite(out4, LOW);
		  break;
		case BACKWARD:
			analogWrite(out1, pwm_R);
      digitalWrite(out2, LOW);
      digitalWrite(out3, LOW);
      analogWrite(out4, pwm_L);
  		break;
		case FORWARD:
			digitalWrite(out1, LOW);
      analogWrite(out2, pwm_R);
      analogWrite(out3, pwm_L);
      digitalWrite(out4, LOW);
  		break;
		case RIGHT:
			digitalWrite(out1, LOW);
      digitalWrite(out2, LOW);
      analogWrite(out3, pwm_L);
      digitalWrite(out4, LOW);
      flag++;
  		break;
		case LEFT:
			digitalWrite(out1, LOW);
      analogWrite(out2, pwm_R);
      digitalWrite(out3, LOW);
      digitalWrite(out4, LOW);
      flag = 0;
  		break;
	}
}