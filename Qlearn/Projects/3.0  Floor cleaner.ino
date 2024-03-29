// Vaccum Cleaner project
/*Displayed all ultrasonic sensor values

*/
//#include <NewPing.h> //for ultrasonic sensor
#define R_TRIG_PIN   2 // Trig pin of Right sensor 
#define R_ECHO_PIN   3    // Echo pin of Right sensor 
#define F_TRIG_PIN   4 // Trig pin of Front sensor 
#define F_ECHO_PIN   5    // Echo pin of Front sensor 
#define L_TRIG_PIN   6 // Trig pin of left sensor 
#define L_ECHO_PIN   7    // Echo pin of left sensor 

#define MAX_DISTANCE 200 // Maximum distance to consider (in cm)
#define OBSTACLE_DISTANCE 20 // Distance to consider an obstacle (in cm)

int Dist2ObstacleFront;
int Dist2ObstacleRight;
int Dist2ObstacleLeft;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //display_ObstaceleDistance();// To display all ultrasonic sensor values
  Dist2ObstacleFront=calculate_distance(F_TRIG_PIN,F_ECHO_PIN);
  Dist2ObstacleRight=calculate_distance(R_TRIG_PIN,R_ECHO_PIN);
  Dist2ObstacleLeft=calculate_distance(L_TRIG_PIN,L_ECHO_PIN);
  while(Dist2ObstacleFront>20){
    move_robotFrwd();
  }
}


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

