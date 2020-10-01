int pump = 13;  
int pot = A2;
int trigPin = 6;
int echoPin = 7;
float duration, distance;
int pot1 = 0;
int pot2 = 1;


void setup() {
  pinMode(pot, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,HIGH);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
}

void loop() {
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pot1 = analogRead(pot); 
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;
    pot2 = pot1*10;
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println(pot1);
    Serial.println(pot2);
    delay(10);
  
if(distance<15){ 
    digitalWrite(pump,LOW);
    delay(pot2); //delay berdasarkan potensio
        
  }
  else{
    digitalWrite(pump,HIGH);
  }
}
