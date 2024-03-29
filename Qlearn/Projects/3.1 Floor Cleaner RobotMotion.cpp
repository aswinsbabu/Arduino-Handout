//3.11 Vaccum Cleaner project
/*Adding motor motion Function
Displayed all ultrasonic sensor values

*/
//#include <NewPing.h> //for ultrasonic sensor
//Ultrasonic Sensor Pins
#define R_TRIG_PIN   2 // Trig pin of Right sensor 
#define R_ECHO_PIN   3    // Echo pin of Right sensor 
#define F_TRIG_PIN   4 // Trig pin of Front sensor 
#define F_ECHO_PIN   5    // Echo pin of Front sensor 
#define L_TRIG_PIN   6 // Trig pin of left sensor 
#define L_ECHO_PIN   7    // Echo pin of left sensor 

//Robot wheels
#define LeftMtrInput1
#define LeftMtrInput2
#define RightMtrInput1
#define RightMtrInput2
#define LeftMtrEnable
#define RightMtrEnable

#define MAX_DISTANCE 200 // Maximum distance to consider (in cm)
#define OBSTACLE_DISTANCE 20 // Distance to consider an obstacle (in cm)

int Dist2ObstacleFront;
int Dist2ObstacleRight;
int Dist2ObstacleLeft;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
pinMode(LeftMtrInput1, Output);
pinMode(LeftMtrInput2 , Output);

pinMode(RightMtrInput1, Output);
pinMode(RightMtrInput2, Output);


pinMode(LeftMtrEnable, Output);
pinMode(RightMtrEnable, Output);


digitaWrite(LeftMtrInput1, High);}

/////////////////////////////     MAIN    /////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  //display_ObstaceleDistance();// To display all ultrasonic sensor values
  Dist2ObstacleFront=calculate_distance(F_TRIG_PIN,F_ECHO_PIN);
  Dist2ObstacleRight=calculate_distance(R_TRIG_PIN,R_ECHO_PIN);
  Dist2ObstacleLeft=calculate_distance(L_TRIG_PIN,L_ECHO_PIN);
  if(Dist2ObstacleFront>20){ // Move forward
    move_robotFrwd();
delay(500);
  }
  else if (Dist2ObstacleFront<20 &&  Dist2ObstacleRight>20 ){ // Move right
    move_robotRight();
delay(500);
  
  }
  else if (Dist2ObstacleFront<20 &&  Dist2ObstacleLeft>20 ){ // Move Left
    move_robotLeft();
}
//////////////////////////////////  Main End Here ///////////////////////////


// Function to calculated distance to obstacle
int calculate_distance(int trigPin, int echoPin) {
  //int trigPin =
  long duration, distance; //long integer
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;//2: up and down travel
  return(distance);
}

//void display_distance(int distance, char myArray[]){
void display_distance(int distance){
  //Serial.print(myArray);
  //Serial.print(myArray);
  Serial.print(distance);
  Serial.println("CM:");
  delay(10);
}

void display_ObstaceleDistance(){ // Displays all ultrasonic sensor values
  
  Dist2ObstacleFront=calculate_distance(F_TRIG_PIN,F_ECHO_PIN);
    display_distance(Dist2ObstacleFront);Serial.print("Front \n");
  
  Dist2ObstacleRight=calculate_distance(R_TRIG_PIN,R_ECHO_PIN);
    display_distance(Dist2ObstacleRight);Serial.print("Right \n ");
    
  Dist2ObstacleLeft=calculate_distance(L_TRIG_PIN,L_ECHO_PIN);
    display_distance(Dist2ObstacleLeft);Serial.print("Left \n ");
  
}
////////////// Functions For Robot motion
void move_robotFrwd(){
digitaWrite(LeftMtrInput1, High);
digitaWrite(LeftMtrInput2, Low);

digitaWrite(RightMtrInput1, High);
digitaWrite(RightMtrInput2, Low);
analogWrite(LeftMtrEnable, 150);
analogWrite(RightMtrEnable,150);
}

void move_robotRight(){

digitaWrite(LeftMtrInput1, High);
digitaWrite(LeftMtrInput2, Low);  
}
void move_robotLeft(){
  
}


//////////////////////////////
