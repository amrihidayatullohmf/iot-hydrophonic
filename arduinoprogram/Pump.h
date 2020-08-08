
const int pumpPin = 5;

void pumpSetup(){  
  pinMode(pumpPin,OUTPUT);
}

void pumpLoop(){
  digitalWrite(pumpPin, HIGH);
  _delay(5000);
  digitalWrite(pumpPin, LOW);
}
