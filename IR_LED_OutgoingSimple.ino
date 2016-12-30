#define BUTTON 8
#define IR_LED_PIN 11
#define BUTTON_BUFFERING_COUNT 1000
#define OUTGOING_COUNT 50

int buttonCount;
int outgoingNowCount;
boolean irLedFlag;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON, INPUT);
  pinMode(IR_LED_PIN, OUTPUT);
  buttonCount = 0;
  outgoingNowCount = OUTGOING_COUNT;
  digitalWrite(IR_LED_PIN, LOW);
  irLedFlag = false;
  delay(100);
}

void loop() {
  if (digitalRead(BUTTON)==1) { buttonCount++;   }
  if (digitalRead(BUTTON)==0) { buttonCount = 0; }
  
  if (BUTTON_BUFFERING_COUNT < buttonCount) {
    outgoingNowCount = 0;
    buttonCount = 0;
  }
  
  if (outgoingNowCount < OUTGOING_COUNT) {
    outgoingNowCount++;
    Serial.print("OutgoingNowCount: ");
    Serial.println(outgoingNowCount);
    if (irLedFlag) {
      digitalWrite(IR_LED_PIN, HIGH);
      irLedFlag = false;
    } else {
      digitalWrite(IR_LED_PIN, LOW);
      irLedFlag = true;
    }
  } else {
    digitalWrite(IR_LED_PIN, LOW);
    irLedFlag = true;
  }
}
