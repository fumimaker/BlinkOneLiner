# 【Arduino】まだLチカで4行も書いてるの？1行でLチカを記述する

> 「まだLチカで4行も書いてるの？」

Arduinoに始まるプロトタイピングボードはハードウェアに近い部分を理解せずともやりたいことを書くだけで使えるため、現在では広く普及しています。思いついたらサッとカバンからArduinoを取り出してすぐに試せるのはとても魅力的です。ラピッドプロトタイピングなんて呼ばれたりもします。

Arduinoなどのマイコンをいじる上で初心者上級者かかわらず必ずやることがあります。そう、Lチカですね。マイコンにLEDを接続し、点滅させることで正常にプログラムが動作することを確認します。Lチカができなければ回路がおかしい、プログラムが書き込めていないなど様々なことを探ることとなります。

前、マックにいたら女子高生が「まだLチカで4行も使ってるの？あんなの1行でかけるじゃん」と言っていま~~した~~せんでした。確かにONーwaitーOFFーwaitと馬鹿正直に書くのは少しスマートではないように見えます。ここで一つかっこよくLチカを書いてみようというわけです。~~…というのは言い訳でただの備忘録です。~~

なお、本稿ではArduino Unoを題材にして記述されています。

## 従来のLチカ

従来のLチカはこんな感じです。これはArduinoのサンプルスケッチBlinkです。

```c++
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

LED_BUILTINはボードごとの内蔵LEDのマクロです。Unoの場合はD13なので13と書き換えても動作します。直接ポート書かなくても動くのすごいよね…。

このコードでも問題なく動作しますが、少し野暮ったい印象を受けませんか？もっとスマートに書いてみます。

## ワンライナーでLチカ

Lチカをよりスマートに書くとこのようになります。

```c++
const int LED = 13; //D13に接続されている内蔵LEDを使用

void setup() {
  pinMode(LED, OUTPUT使用 //出力に設定
}
          
void loop() {
  digitalWrite(LED,!digitalRead(LED)); //出力を反転
  delay(1000); //1000ms遅延
}
```



はい、1行じゃないですねすみません。delayがある分行数が増えてしまいしました。~~点滅のロジックは1行だから許して~~

やっていることは大して難しくありません。digitalWriteの中でLED=D13の状態を読みとり、反転させたものをポートに出力することでLチカを実現しています。これ自体は普通に行われていることで、なんならdigitalWriteの中身でもポートのレジスタ反転してHIGHとLOWを切り替えていたりします。PICやAVRやっている人ならお馴染みかもしれないです。

## まとめ

というかんじで、よりスマートなLチカを書いてみました。コーナーで差をつけたくなるのはオタクの心理なので仕方ない。他のArduino使いに差をつけろ！

今回はそんな感じです。

