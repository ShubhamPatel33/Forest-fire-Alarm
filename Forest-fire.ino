
int const PINO_SGAS = A1;
int LED_VERDE = 7;
int LED_AMARELO = 6;
int LED_VERMELHO1 = 5;
int LED_VERMELHO2 = 4;
int LED_animal = 3;

// Ultrasonic 
int buzzerPin= 11;
int echoPin= 9;
int trigPin= 8;
int minDistance = 100;
int maxDistance = 300;

//Temperature


void setup(){
  	pinMode(LED_VERDE, OUTPUT);
  	pinMode(LED_animal, OUTPUT); 
  	pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERMELHO1, OUTPUT);
    pinMode(LED_VERMELHO2, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop(){
    int valor = analogRead(PINO_SGAS);
    valor = map(valor, 300, 750, 0, 100);
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_AMARELO, valor >= 20 ? HIGH : LOW);
      digitalWrite(LED_VERMELHO1, valor >= 40 ? HIGH : LOW);
      digitalWrite(LED_VERMELHO2, valor >= 80 ? HIGH : LOW);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    float duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    float distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    // Displays the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    if(distance <= maxDistance){
     digitalWrite(buzzerPin,HIGH);
     digitalWrite(LED_animal,HIGH);
    }
    else{
      digitalWrite(buzzerPin,LOW);
      digitalWrite(LED_animal,LOW);
    }

  
  
}
