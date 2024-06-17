int x;
int ledPin = 8;

void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(ledPin, OUTPUT);
 
 delay(1);
 
 digitalWrite(LED_BUILTIN, HIGH);
 digitalWrite(ledPin, HIGH);

 delay(1);

 digitalWrite(LED_BUILTIN, LOW);
 digitalWrite(ledPin, LOW);



}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();

 if (x == 1) {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(ledPin, HIGH);

 } if (x == -1) {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(ledPin, LOW);

 }
 
 
}
