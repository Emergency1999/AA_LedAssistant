#ifndef AA_LedAssistant
#define AA_LedAssistant

#include <Arduino.h>
#include <Assistant.h>
#include <Timer.h>

class LedAssistant: public Assistant {
   public:
    LedAssistant(int pin, bool inverted);
    void setPermanent(bool ON);
    void setInterval(unsigned long time);
    bool getState() { return _state; }


   private:
    void _setup() override;
    void _loop() override;
    int _pin;
    bool _state = false;
    bool _inverted;
    bool _looping = false;

    Timer _T = Timer();

    void _setState(bool state);
};

#endif