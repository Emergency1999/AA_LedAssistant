#include <LedAssistant.h>

LedAssistant::LedAssistant(int pin, bool inverted = false) {
    _pin = pin;
    _inverted = inverted;
}
void LedAssistant::_setup() {
    pinMode(_pin, OUTPUT);
    _setState(_state);
}
void LedAssistant::_loop() {
    if (_T()) {
        _setState(!_state);
    }
}

void LedAssistant::setPermanent(bool ON) {
    _T.stop();
    _setState(ON);
}
void LedAssistant::setInterval(unsigned long time) {
    _T.start(time);
}

void LedAssistant::_setState(bool state) {
    _state = state;
    if (_state ^ _inverted)
        digitalWrite(_pin, HIGH);
    else
        digitalWrite(_pin, LOW);
}
