// スイッチの状態保存用変数
bool sw1 = false;
bool sw2 = false;
bool sw3 = false;

void setup() {
  // シリアル通信開始
  Serial.begin(115200);

  // ピン関係初期化
  digitalWrite(2, LOW);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  pinMode(2, INPUT);
  pinMode(12, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  // スイッチが押されていない状態から押されている状態に変化した時
  if(sw1 == false && digitalRead(2) == HIGH){
    delay(10);
	// チャタリング対応
    if(digitalRead(2) == HIGH){
	  // ゲーム開始の通知
      Serial.write("s");
      delay(50);				// Windows対応用(Macでは多分いらない)
      Serial.write("n");		// Windows対応用(Macでは多分いらない)

	  // スイッチ状態ON
      sw1 = true;
    }
  // スイッチがもともと押されている状態だった時
  }else if(sw1 == true){
    if(digitalRead(2) == HIGH){
	  // 継続してスイッチが押されていても何もしない
    }else{
	  // スイッチが押されていなかったらスイッチ状態OFFに変更
      sw1 = false;
    }
  }

  // 以下sw1と同様
  if(sw2 == false && digitalRead(12) == HIGH){
    delay(10);
    if(digitalRead(12) == HIGH){
	  // 弾発射の通知
      Serial.write("h");
      delay(50);
      Serial.write("n");
      sw2 = true;
    }
  }else if(sw2 == true){
    if(digitalRead(12) == HIGH){
    }else{
      sw2 = false;
    }
  }

  if(sw3 == false && digitalRead(9) == HIGH){
    delay(10);
    if(digitalRead(9) == HIGH){
	  // 得点ゲットの通知
      Serial.write("p");
      delay(50);
      Serial.write("n");
      sw3 = true;
    }
  }else if(sw3 == true){
    if(digitalRead(9) == HIGH){
    }else{
      sw3 = false;
    }
  }
}
