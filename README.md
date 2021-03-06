# PWMeter for GR-CITRUS

NOTE: This library is a old version and now deprecated. [PWMeter4GR](https://github.com/lipoyang/PWMeter4GR) is recommended.

<br>

[Japanese README (和文ドキュメント)](README-ja.md)

Pulse width meter class library for GR-CITRUS

<br>

## PWMeter::begin(pin)
## PWMeter::begin(pin, polarity)
## PWMeter::begin(pin, polarity, resolution)
Begins measurement of pulse width.

### pin: pulse input pin
Pin 0, 1, 2, 3, 4, 7, 8, 10, 11, 12, 13 are supported for pulse input. They are divided into following groups. Same resolution setting is applied to same group pins. Just the last setting is effective.

- 0, 1 (using MTU1)
- 2, 3, 4, 10, 11, 12, 13 (using MTU3)
- 4 (using MTU4)
- 7, 8  (using MTU0)

Following pins can not be used together due to resource conflict.

- 2 and 11 (using MTIOC3C)
- 3 and 12 (using MTIOC3A)

### polarity: polarity of pulse (optional)
Pulse polarity (positive or negative) is selectable. If omitted, the default is positive.
- PWMETER_POSITIVE: positive logic (default)
- PWMETER_NEGATIVE: negative logic

### resolution: resolution of measurement (optional)
The meter resolution is selectable from the following. If omitted, the default is 1usec.

- PWMETER_48TH_USEC: 1/48usec / Max  1365usec
- PWMETER_12TH_USEC: 1/12usec / Max  5461usec
- PWMETER_3RD_USEC: 1/3usec / Max 21845usec
- PWMETER_1USEC: 1usec / Max 21845usec (default)
- PWMETER_4_3RD_USEC: 4/3usec / Max 87380usec

<br>

## PWMeter::available()
Checks whether or not new pulses are detected.

### returns: true or false

<br>

## PWMeter::get()
Gets the measured pulse width. Measurement values are buffered up to 32 items.

### returns: pulse width
LSB is equivalent to the resolution specified by PWMeter::begin(). If no new measurement value, it returns 0xFFFF.

<br>

## PWMeter::getLast()
Gets the last measured pulse width. Bufferd measurement values are discarded.

### returns: pulse width
LSB is equivalent to the resolution specified by PWMeter::begin(). If no new measurement value, it returns 0xFFFF.

<br>

## PWMeter::stop()

Stops mesurement.

<br>

## PWMeter::restart()

Restarts mesurement.

<br>

## Notes
This class uses MTUs (Multi function timer pulse units). Therefore, it conflicts with PWM output (Servo library and analogWrite) of pin 0 and 11. Timer resouces used by Servo library and analogWrite are shown below.
- 0: MTU1 (conflicts with pulse width meter of pin 0, 1)
- 1: TPU3
- 5: TPU4
- 7: TPU0
- 8: TPU0
- 11: MTU3 (conflicts with pulse width meter of pin 2, 3, 4, 10, 11, 12, 13)
- others: TPU2
