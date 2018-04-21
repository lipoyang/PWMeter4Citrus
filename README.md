# PWMeter for GR-CITRUS
Pulse width meter class library for GR-CITRUS

## Target
This class is just for GR-CITRUS.

## Input pin
Pin 0,1,2,3,4,7,8,10,11,12,13 are supported for pulse input. They are divided into following groups. Same resolution setting is applied to same group pins. Just the last setting is effective.

- 0,1 (using MTU1)
- 2,3,4,10,11,12,13 (using MTU3)
- 4 (using MTU4)
- 7,8  (using MTU0)

Following pins can not be used together due to resource conflict.

- 2 and 11 (using MTIOC3C)
- 3 and 12 (using MTIOC3A)

## Polarity
Pulse polarity (positive or negative) is selectable.

## Resolution
The meter resolution is selectable from the following:

- 1/48usec :Max  1365usec
- 1/12usec :Max  5461usec
- 1/3usec  :Max 21845usec
- 1usec    :Max 21845usec (default)
- 4/3usec  :Max 87380usec

## Notes
This class uses MTUs (Multi function timer pulse units). Therefore, it conflicts with Servo library, and PWM output(analogWrite).

***
# PWMeter for GR-CITRUS (日本語)
GR-CITRUS用のパルス幅計測クラスライブラリです。

## ターゲット
このクラスは、GR-CITRUS専用です。

## 入力ピン
ピン 0,1,2,3,4,7,8,10,11,12,13 がパルス入力に対応しています。これらのピンは下記のグループに分かれます。同じグループのピンには同じ計測制度が適用されます。最後に設定した計測制度が有効です。

- 0,1 (MTU1を使用)
- 2,3,4,10,11,12,13 (MTU3を使用)
- 4 (MTU4を使用)
- 7,8 (MTU0を使用)

下記のピンはリソース競合のため同時に使うことはできません。

- 2 と 11 (MTIOC3Cを使用)
- 3 と 12 (MTIOC3Aを使用)

## 極性
パルス極性(正論理か負論理か)は選択できます。

## 計測精度
計測精度は下記から選択できます。

- 1/48usec :最大  1365usec
- 1/12usec :最大  5461usec
- 1/3usec  :最大 21845usec
- 1usec    :最大 21845usec (デフォルト)
- 4/3usec  :最大 87380usec

## 注意点
このクラスはMTU(マルチファンクションタイマパルスユニット)を使用しています。そのため、ServoライブラリおよびピンPWM出力(analogWrite)と競合します。
