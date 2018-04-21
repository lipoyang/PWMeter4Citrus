#ifndef _PWMETER_H_
#define _PWMETER_H_

#include <stdint.h>

#define PWMETER_BUFF_SIZE   32 // pulse width data buffer size

#define PWMETER_POSITIVE    0   // pulse polarity: positive
#define PWMETER_NEGATIVE    1   // pulse polarity: negative

#define PWMETER_48TH_USEC   0   // resolution: 1/48usec
#define PWMETER_12TH_USEC   1   // resolution: 1/12usec
#define PWMETER_3RD_USEC    2   // resolution: 1/3usec
#define PWMETER_1USEC       4   // resolution: 1usec
#define PWMETER_4_3RD_USEC  3   // resolution: 4/3usec


// Puse width meter class
// This class is just for GR-CITRUS.
class PWMeter
{
public:
    PWMeter();              // constructor
    void begin(int pin, int polarity = PWMETER_POSITIVE, int resolution = PWMETER_1USEC); // begin the PWMeter
    void stop();            // stop the PWMeter
    void restart();         // restart the PWMeter
    bool available();       // new value available?
    uint16_t get();         // get a buffered value [usec]
    uint16_t getLast();     // get the last value [usec]
    
    uint8_t isr(uint16_t cnt);  // input capture interrupt handler

private:
    void stop_restart(uint8_t start_stop);  // stop/restart the PWMeter (subroutine)
    
private:
    uint8_t pulse_edge;     // waiting for rising edge or falling edge?
    uint8_t start_edge;     // edge polarity of pulse start
    uint8_t end_edge;       // edge polarity of pulse end
    uint16_t cnt1;          // start time of pulse
    uint16_t cnt2;          // end time of pulse
    uint16_t buffer[PWMETER_BUFF_SIZE]; // pulse width data buffer (ring buffer)
    uint8_t rptr;           // read pointer of buffer
    uint8_t wptr;           // write pointer of buffer
    
    bool to1usec;           // adjust to 1usec resolution?
    
    uint8_t pin;            // input pin
    uint8_t polarity;       // pulse polarity
    uint8_t resolution;     // meter resolution
};

#endif
