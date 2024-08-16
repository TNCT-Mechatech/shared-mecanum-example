#include "mbed.h"

#include "Mbed_MD.h"
#include "Mecanum_4.h"

Mbed_MD lf_md(D1, D2); //  Pinは各自で設定して下さい
Mbed_MD lb_md(D3, D4); //  Pinは各自で設定して下さい
Mbed_MD rb_md(D5, D6); //  Pinは各自で設定して下さい
Mbed_MD rf_md(D7, D8); //  Pinは各自で設定して下さい

Mecanum_4 mecanum(&lf_md, &lb_md, &rb_md, &rf_md);

// main() runs in its own thread in the OS
int main() {
  //  x: 左右方向
  //  y: 上下方向
  //  yaw: 回転
  double x = 0, y = 0, yaw = 0;

  while (true) {
    //  ここら辺にx, y, yawの更新プログラム書いて下さい...

    //  ロボットのいどう
    mecanum.move(x, y, yaw);

    //  周期固定 10hz
    wait_ms(100);
  }
}
