# PWMeter for GR-CITRUS

注意：このライブラリは古いバージョンで今では非推奨です。[PWMeter4GR](https://github.com/lipoyang/PWMeter4GR)をお使いください。

<br>

[English README (英文ドキュメント)](README.md)

GR-CITRUS用のパルス幅計測クラスライブラリです。

<br>

## PWMeter::begin(pin)
## PWMeter::begin(pin, polarity)
## PWMeter::begin(pin, polarity, resolution)
パルス幅計測を開始します。

### pin: パルス入力ピン
ピン 0, 1, 2, 3, 4, 7, 8, 10, 11, 12, 13 がパルス入力に対応しています。これらのピンは下記のグループに分かれます。同じグループのピンには同じ計測制度が適用されます。最後に設定した計測制度が有効です。

- 0, 1 (MTU1を使用)
- 2, 3, 4, 10, 11, 12, 13 (MTU3を使用)
- 4 (MTU4を使用)
- 7, 8 (MTU0を使用)

下記のピンはリソース競合のため同時に使うことはできません。

- 2 と 11 (MTIOC3Cを使用)
- 3 と 12 (MTIOC3Aを使用)

### polarity: パルスの極性 (省略可)
パルス極性(正論理か負論理か)は選択できます。省略した場合は正論理になります。
- PWMETER_POSITIVE: 正論理 (デフォルト)
- PWMETER_NEGATIVE: 負論理

### resolution: 計測精度 (省略可)
計測精度は下記から選択できます。省略した場合は1usecになります。

- PWMETER_48TH_USEC: 1/48usec / 最大 1365usec
- PWMETER_12TH_USEC: 1/12usec / 最大 5461usec
- PWMETER_3RD_USEC: 1/3usec / 最大 21845usec
- PWMETER_1USEC: 1usec / 最大 21845usec (デフォルト)
- PWMETER_4_3RD_USEC: 4/3usec / 最大 87380usec

<br>

## PWMeter::available()
新しくパルスを検出したかを返します。

### 戻り値: true か false

<br>

## PWMeter::get()
計測したパルス幅を取得します。計測値は最大32個までバッファされます。

### 戻り値: パルス幅
最下位ビットがPWMeter::begin()で指定した解像度に相当します。新しい計測値がないときは0xFFFFを返します。

<br>

## PWMeter::getLast()
最後に計測したパルス幅を取得します。バッファされていた古い計測値は破棄されます。

### 戻り値: パルス幅
最下位ビットがPWMeter::begin()で指定した解像度に相当します。新しい計測値がないときは0xFFFFを返します。

<br>

## PWMeter::stop()

計測を停止します。

<br>

## PWMeter::restart()

計測を再開します。

<br>

## 注意点
このクラスはMTU(マルチファンクションタイマパルスユニット)を使用しています。そのため、ピン0および11のPWM出力 (ServoライブラリおよびanalogWrite) と競合します。ServoライブラリおよびanalogWriteで使用されるタイマリソースは下記の通りです。
- 0: MTU1 (ピン0, 1のパルス幅計測と競合)
- 1: TPU3
- 5: TPU4
- 7: TPU0
- 8: TPU0
- 11: MTU3 (ピン2, 3, 4, 10, 11, 12, 13のパルス幅計測と競合)
- それ以外: TPU2
