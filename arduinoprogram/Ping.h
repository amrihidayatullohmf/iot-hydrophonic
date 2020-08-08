int counter = 5;
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distance;
int finalDistance;

float timeCounter = 0;

void pingSetup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void _delay(float miliseconds){
  timeCounter += miliseconds;
  delay((int)miliseconds);
}

void _delayMicroseconds(float microseconds){
  timeCounter += microseconds / 1000;
  delayMicroseconds((int)microseconds);
}

void pingLoop(){
  Serial.println("Calculating Distance");
    digitalWrite(trigPin, HIGH);
    _delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= (0.0001*((float)duration*340.0)/2.0)+1;
    //Perubahan rumus mengikuti tinggi ember
    finalDistance = 12 - distance;
    Serial.print(finalDistance);
    Serial.println(" cm"); 
}
