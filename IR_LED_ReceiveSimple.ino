#define RECEIVE_PIN 2
#define LED_PIN 11
#define RECEIVE_BUFFERING_COUNT 5

int lastReceive;
int receiveCount;

void setup() {
  Serial.begin(115200);
  pinMode(RECEIVE_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  lastReceive = 0;
  receiveCount = 0;
}

void loop() {
  int nowReceive = digitalRead(RECEIVE_PIN);
  //Serial.print(lastReceive);Serial.print(" -> ");Serial.println(nowReceive);
  if (nowReceive!=lastReceive) {
    Serial.print("ReceiveCount : ");Serial.println(receiveCount);
    receiveCount++;
  }
  lastReceive = nowReceive;
  
  if (receiveCount > RECEIVE_BUFFERING_COUNT) {
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    receiveCount = 0;
  }
}
