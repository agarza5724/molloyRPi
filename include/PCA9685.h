#ifndef PCA9685_H_
#define PCA9685_H_

#include "I2CDevice.h"
#include <armadillo>


#define DEVID 0x40 //why is this here if i'm gonna set this value in main? in case if i need to use more than 1 board
#define MODE1 0x00
#define MODE2 0x01
#define SUBADR1 0x02
#define SUBADR2 0x03
#define SUBADR3 0x04
#define ALLCALLADR 0x05


//led0
#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define	LED0_OFF_L 0x08
#define LED0_OFF_H 0x09

//led1
#define LED1_ON_L 0x0A
#define LED1_ON_H 0x0B
#define	LED1_OFF_L 0x0C
#define LED1_OFF_H 0x0D

//led2
#define LED2_ON_L 0x0E
#define LED2_ON_H 0x0F
#define	LED2_OFF_L 0x10
#define LED2_OFF_H 0x11

//led3
#define LED3_ON_L 0x12
#define LED3_ON_H 0x13
#define	LED3_OFF_L 0x14
#define LED3_OFF_H 0x15

//led4
#define LED4_ON_L 0x16
#define LED4_ON_H 0x17
#define	LED4_OFF_L 0x18
#define LED4_OFF_H 0x19

//led5
#define LED5_ON_L 0x1A
#define LED5_ON_H 0x1B
#define	LED5_OFF_L 0x1C
#define LED5_OFF_H 0x1D

//led6
#define LED6_ON_L 0x1E
#define LED6_ON_H 0x1F
#define	LED6_OFF_L 0x20
#define LED6_OFF_H 0x21

//led7
#define LED7_ON_L 0x22
#define LED7_ON_H 0x23
#define	LED7_OFF_L 0x24
#define LED7_OFF_H 0x25

//led8
#define LED8_ON_L 0x26
#define LED8_ON_H 0x27
#define	LED8_OFF_L 0x28
#define LED8_OFF_H 0x29

//led9
#define LED9_ON_L 0x2A
#define LED9_ON_H 0x2B
#define	LED9_OFF_L 0x2C
#define LED9_OFF_H 0x2D

//led10
#define LED10_ON_L 0x2E
#define LED10_ON_H 0x2F
#define	LED10_OFF_L 0x30
#define LED10_OFF_H 0x31

//led11
#define LED11_ON_L 0x32
#define LED11_ON_H 0x33
#define	LED11_OFF_L 0x34
#define LED11_OFF_H 0x35

//led12
#define LED12_ON_L 0x36
#define LED12_ON_H 0x37
#define	LED12_OFF_L 0x38
#define LED12_OFF_H 0x39

//led13
#define LED13_ON_L 0x3A
#define LED13_ON_H 0x3B
#define	LED13_OFF_L 0x3C
#define LED13_OFF_H 0x3D

//led14
#define LED14_ON_L 0x3E
#define LED14_ON_H 0x3F
#define	LED14_OFF_L 0x40
#define LED14_OFF_H 0x41

//led15
#define LED15_ON_L 0x42
#define LED15_ON_H 0x43
#define	LED15_OFF_L 0x44
#define LED15_OFF_H 0x45

//all led on/off
#define ALL_LED_ON_L 0xFA
#define ALL_LED_ON_H 0xFB
#define ALL_LED_OFF_L 0xFC
#define ALL_LED_OFF_H 0xFD

#define PRE_SCALE 0xFE
#define TESTMODE 0xFF

namespace exploringRPi
{

	class PCA9685 : protected I2CDevice
	{
		public:
			PCA9685(unsigned int , unsigned int);
			virtual ~PCA9685();
			void SoftwareReset();
			void SetPWMFreq(int);
			void SetPWM(int,int,int);
			void SetAllPWM(int,int);
			void AllStop();
		protected:
			void InitMatricies();
		private:
			arma::Mat<arma::uword> ledMatrix;
			arma::Mat<arma::uword> allLedOnOffMatrix;
			unsigned int I2CBus, I2CAddress;
			unsigned char* registers;

	};

}//end namespace

#endif
