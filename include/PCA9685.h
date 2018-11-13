#ifndef PCA9685_H_
#define PCA9685_H_

#include "I2CDevice.h"
#include <armadillo>




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
			
		private:
			void InitMatricies();
			
			arma::Mat<arma::uword> ledMatrix;
			arma::Mat<arma::uword> allLedOnOffMatrix;
			arma::Mat<arma::uword> bitOps;
			
			const arma::uword PRE_SCALE = 0xFE;
			const arma::uword TESTMODE = 0xFF;
			const arma::uword DEVID = 0x40;
			const arma::uword MODE1 = 0x00;
			const arma::uword MODE2 = 0x01;
			const arma::uword SUBADR1 = 0x02;
			const arma::uword SUBADR2 = 0x03;
			const arma::uword SUBADR3 = 0x04;
			const arma::uword ALLCALLADR = 0x05;
			
			unsigned int I2CBus, I2CAddress;
			unsigned char* registers;

	};

}//end namespace

#endif
