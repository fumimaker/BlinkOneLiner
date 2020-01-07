const int LED = 13; //D13に接続されている内蔵LEDを使用

void setup(){
  pinMode(LED, OUTPUT); //出力に設定
}

void loop(){
  digitalWrite(LED, !digitalRead(LED)); //出力を反転
  delay(1000);                          //1000ms遅延
}