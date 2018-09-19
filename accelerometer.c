/*****************************************************************************
Write a code in mbed compiler to detect the motion in X, Y and Z axis 
by blinking the individual LEDs on the FRDM - KL25Z.
For example, if the board is moving in X-direction then RED should be 
displayed on the board and so on. If board is not in motion, then the 
LED should be turned off.
******************************************************************************/

#include "mbed.h"
#include "MMA8451Q.h"

PinName const SDA = PTE25;
PinName const SCL = PTE24;
  
#define MMA8451_I2C_ADDRESS (0x1d<<1)
 
int main(void)
{
  MMA8451Q acc(SDA, SCL, MMA8451_I2C_ADDRESS);
  PwmOut rled(LED1);
  PwmOut gled(LED2);
  PwmOut bled(LED3);
  
  float x1, x2, xr, y1, y2, yr, z1, z2, zr;
  double res = 0.15;
  rled = 1;
  gled = 1;
  bled = 1;
  
  while (true) {
    x1 = abs(acc.getAccX());
    wait(0.1f);
    x2 = abs(acc.getAccX());
    xr = x2 - x1;
    y1 = abs(acc.getAccY());
    wait(0.1f);
    y2 = abs(acc.getAccY());
    yr = y2 - y1;
    z1 = abs(acc.getAccZ());
    wait(0.1f);
    z2 = abs(acc.getAccZ());
    zr = z2 - z1;
    
    if (abs(xr)>res) rled = 0; else rled = 1;
    if (abs(yr)>res) gled = 0; else gled = 1;
    if (abs(zr)>res) bled = 0; else bled = 1;
    wait(0.1f);
  }  
}

