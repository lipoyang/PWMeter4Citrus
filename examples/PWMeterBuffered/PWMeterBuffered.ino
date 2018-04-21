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
    delay(10);
    analogWrite(4,0);
    
    if(pwmeter0.available()){
        Serial.print("PW0 = ");
        while((pw = pwmeter0.get()) != 0xFFFF){
            Serial.print(pw);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
    if(pwmeter1.available()){
        Serial.print("PW1 = ");
        while((pw = pwmeter1.get()) != 0xFFFF){
            Serial.print(pw);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
    if(pwmeter2.available()){
        Serial.print("PW2 = ");
        while((pw = pwmeter2.get()) != 0xFFFF){
            Serial.print(pw);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
    if(pwmeter7.available()){
        Serial.print("PW7 = ");
        while((pw = pwmeter7.get()) != 0xFFFF){
            Serial.print(pw);
            Serial.print("\t");
        }
        Serial.print("\n");
    }
    delay(100);
}

