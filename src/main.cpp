#include <M5Atom.h>

// put function declarations here:
void p21_task(void *arg);

void setup()
{
  // put your setup code here, to run once:
  M5.begin(true, false, true);
  M5.dis.drawpix(0, CRGB::Red);

  delay(10);

  // GPIO21, 25を出力に設定
  digitalWrite(21, LOW);
  digitalWrite(25, LOW);

  // 1秒ごとにGPIO21をHIGH/LOWにするタスクをコア0で実行
  xTaskCreatePinnedToCore(
      p21_task,   // タスクの関数
      "p21_task", // タスクの名前
      1024,       // スタックサイズ
      NULL,       // 関数に渡す引数
      1,          // 優先度
      NULL,       // タスクハンドル
      0           // コア番号
  );
}

// メインループはコア1で実行されている
void loop()
{
  // put your main code here, to run repeatedly:
  static int state_p25 = LOW;

  M5.update();

  if (M5.Btn.wasPressed())
  {
    // ボタン押下時にトグル
    state_p25 = !state_p25;
    digitalWrite(25, state_p25);
  }
}

// 1秒ごとにGPIO21をHIGH/LOWにするタスクをコア0で実行
void p21_task(void *arg)
{
  while (1)
  {
    M5.dis.drawpix(0, CRGB::Plum);
    digitalWrite(21, HIGH);
    delay(1000);

    M5.dis.drawpix(0, CRGB::Black);
    digitalWrite(21, LOW);
    delay(1000);
  }
}