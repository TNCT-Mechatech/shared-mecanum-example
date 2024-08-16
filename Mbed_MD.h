#ifndef MBED_MD_H_
#define MBED_MD_H_

#include <MD.h>
#include <mbed.h>

class Mbed_MD : public MD {
public:
  Mbed_MD(PinName pwmPin, PinName dirPin);
  virtual void drive(double);
  virtual void brake(double);
  virtual void free();

private:
  PwmOut _pwmOut;
  DigitalOut _dirOut;
};

#endif
