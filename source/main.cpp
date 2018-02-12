#include "ADXL345.h"
#include "PCA9685.h"
#include <unistd.h>

using namespace std;
using namespace exploringRPi;

void PCA9685test1(PCA9685 &);
void PCA9685test2(PCA9685 &);
void PCA9685test3(PCA9685 &);
void PCA9685test4(PCA9685 &);

int main()
{
	PCA9685 test(1,0x40);
	ADXL345 sensor(1,0x53);

	PCA9685test1(test);



	return 0;
}

void PCA9685test1(PCA9685 &a1)
{

    a1.SetPWMFreq(50);

    for(int i = 0; i < 10; i++)
    {
        a1.SetPWM(0,0,150);
        usleep(1000000);
        a1.SetPWM(0,0,600);
        usleep(1000000);
    }

    a1.AllStop();

}

void PCA9685test2(PCA9685 &a2)
{
    /*
    a2.SetPWMFreq(50);

    a2.SetPWM(4,0,150);
    usleep(1000000);
    a2.AllStop();
    */


}

void PCA9685test3(PCA9685 &a3)
{


}

void PCA9685test4(PCA9685 &a4)
{


}
