void setup(){
  pinMode(LED_BUILTIN, OUTPUT); //出力に設定
}

void loop(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); //出力を反転
  delay(1000);                          //1000ms遅延
}
