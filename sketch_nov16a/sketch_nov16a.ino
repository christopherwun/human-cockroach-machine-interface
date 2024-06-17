int x;

void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
 pinMode(LED_BUILTIN, OUTPUT);
 
 delay(1);

 digitalWrite(LED_BUILTIN, HIGH);
 delay(1);

 digitalWrite(LED_BUILTIN, LOW);


}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();

 if (x == 1) {
  digitalWrite(LED_BUILTIN, HIGH);
 } else {
  digitalWrite(LED_BUILTIN, LOW);
 }
 
 
}
