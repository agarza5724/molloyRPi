#include "PCA9685.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <armadillo>
#include <iostream>

using namespace arma;

namespace exploringRPi
{

PCA9685::PCA9685(unsigned int I2CBus, unsigned int I2CAddress) : I2CDevice(I2CBus, I2CAddress)
{
    int mode1;


    this->I2CAddress = I2CAddress;
    this->I2CBus = I2CBus;
    I2CDevice(I2CBus,I2CAddress);

    InitMatricies();

    usleep(50);


    SetAllPWM(0,0);
    writeRegister(MODE2,0x04);
    writeRegister(MODE1,0x01);
    usleep(50);

    mode1 = readRegister(MODE1);
    mode1 = mode1 & ~0x10;
    writeRegister(MODE1,0x01);
    usleep(50);


    /*
    SoftwareReset();
    usleep(50);
    SetPWMFreq(1000);
    */




}

PCA9685::~PCA9685() {}

/*
void InitMatricies()
input: not applicable
output: not applicable

this function initializes two armadillo based matricies for use with
the led channels on the pca9685. instead of accessing a channel via a lengthy name
like LED0_ON_HIGH or by hardcoded number,0x06, you can access it by ledMatrix(0,0).
this makes it convienient for integer loops as well
*/
void PCA9685::InitMatricies()
{


    ledMatrix << 0x06 << 0x07 << 0x08 << 0x09 << endr
    << 0x0A << 0x0b << 0x0c << 0x0d << endr << 0x0e << 0x0f << 0x10 << 0x11 << endr
    << 0x12 << 0x13 << 0x14 << 0x15 << endr << 0x16 << 0x17 << 0x18 << 0x19 << endr
    << 0x1a << 0x1b << 0x1c << 0x1d << endr << 0x1e << 0x1f << 0x20 << 0x21 << endr
    << 0x22 << 0x23 << 0x24 << 0x25 << endr << 0x26 << 0x27 << 0x28 << 0x29 << endr
    << 0x2a << 0x2b << 0x2c << 0x2d << endr << 0x2e << 0x2f << 0x30 << 0x31 << endr
    << 0x32 << 0x33 << 0x34 << 0x35 << endr << 0x36 << 0x37 << 0x38 << 0x39 << endr
    << 0x3a << 0x3b << 0x3c << 0x3d << endr << 0x3e << 0x3f << 0x40 << 0x41 << endr
    << 0x42 << 0x43 << 0x44 << 0x45 << endr;

    allLedOnOffMatrix << 0xfa << 0xfb << 0xfc << 0xfd << endr;
	
    bitOps << 0xFF << 8 << endr;


}

/*
void SoftwareReset()
input: currently under research
output: not applicable

this is the function for software reset, as indicated by adafruit's python driver
and the documentation on the pca9685. i believe this resets the chip
*/
void PCA9685::SoftwareReset()
{


    //writeRegister(MODE1,0x06);
    writeRegister(MODE1,0x00);
    writeRegister(MODE2,0x04);

}



void PCA9685::SetPWMFreq(int frequency)
{
    int prescaleValue;

    prescaleValue = 25000000/(4096 * frequency) - 1;

    writeRegister(MODE1,0x10);
    writeRegister(PRE_SCALE,prescaleValue);
    writeRegister(MODE1,0x80);
    writeRegister(MODE2,0x04);



}

void PCA9685::SetPWM(int channel,int on, int off)
{
    writeRegister(ledMatrix(channel,0),on & 0xFF);
    writeRegister(ledMatrix(channel,1),on >> 8);
    writeRegister(ledMatrix(channel,2),off & 0xFF);
    writeRegister(ledMatrix(channel,3),off >> 8);

}

void PCA9685::SetAllPWM(int on,int off)
{
	/*
	writeRegister(ALL_LED_ON_L, on & 0xFF);
	writeRegister(ALL_LED_ON_H, on >> 8);
	writeRegister(ALL_LED_OFF_L, on & 0xFF);
	writeRegister(ALL_LED_OFF_H, on >> 8);
	*/
	//allLedOnOffMatrix << 0xfa << 0xfb << 0xfc << 0xfd << endr;
	
	writeRegister(allLedOnOffMatrix[0], on & 0xFF);
	writeRegister(allLedOnOffMatrix[1], on >> 8);
	writeRegister(allLedOnOffMatrix[2], on & 0xFF);
	writeRegister(allLedOnOffMatrix[3], on >> 8);
		
	
}

void PCA9685::AllStop()
{
    writeRegister(0xFD,0x10);
    usleep(500000);
}

}//end namespace
