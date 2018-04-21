#include "PWMeter4Citrus.h"

PWMeter pwmeter0;
PWMeter pwmeter1;
PWMeter pwmeter2;
PWMeter pwmeter7;

void setup()
{
    Serial.begin(115200);
    
    pwmeter0.begin(0); // default: positive, 1usec
    pwmeter1.begin(1, PWMETER_NEGATIVE);
    pwmeter2.begin(2, PWMETER_POSITIVE, PWMETER_3RD_USEC);
    pwmeter7.begin(7, PWMETER_POSITIVE, PWMETER_12TH_USEC);
}

void loop()
{
    static uint8_t duty = 0;
    uint16_t pw;
    
    analogWrite(4,duty);
    duty++;
    
    if(pwmeter0.available()){
        uint16_t pw = pwmeter0.getLast();
        Serial.print("PW0 = ");
        Serial.println(pw);
    }
    if(pwmeter1.available()){
        uint16_t pw = pwmeter1.getLast();
        Serial.print("PW1 = ");
        Serial.println(pw);
    }
    if(pwmeter2.available()){
        uint16_t pw = pwmeter2.getLast();
        Serial.print("PW2 = ");
        Serial.println(pw);
    }
    if(pwmeter7.available()){
        uint16_t pw = pwmeter7.getLast();
        Serial.print("PW7 = ");
        Serial.println(pw);
    }
    delay(100);
}

