# 4輪メカナムロボット

[shared](https://github.com/TNCT-Mechatech/shared)にある`Mecanum_4`の使い方です。

## プログラム解説

### 全体
```c++
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
```

### 必要ファイルの読み込み

```c++
#include "mbed.h"


#include "Mbed_MD.h"
#include "Mecanum_4.h"
```

### MD初期化

`Mbed_MD`クラスを使用してMDを用意します。
左前(lf)、左後(lb)、右後(rb)、右前(rf)です。

```c++
Mbed_MD lf_md(D1, D2); //  Pinは各自で設定して下さい
Mbed_MD lb_md(D3, D4); //  Pinは各自で設定して下さい
Mbed_MD rb_md(D5, D6); //  Pinは各自で設定して下さい
Mbed_MD rf_md(D7, D8); //  Pinは各自で設定して下さい
```

### メカナム初期化

左前(lf)、左後(lb)、右後(rb)、右前(rf)の順番で、コンストラクタに渡して下さい。

```c++
Mecanum_4 mecanum(&lf_md, &lb_md, &rb_md, &rf_md);
```

### メイン処理

先ほど作成したメカナムの`move()`関数を使用することで制御できます。
`x`,`y`,`yaw`は、通信で取得した値を入れるなどして更新して下さい。

```c++
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
```