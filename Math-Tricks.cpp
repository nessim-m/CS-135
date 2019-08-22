#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int tenthousand= 10000; // A constant that hold a value of ten thousand throughout the whole code.
const int hundredthousand= 100000; // A constant tha hold a value of hundred thousand throughout the whole code.


int main()
{
	int num; // variable that contains the selected number.
	int onedigit; // variable that contains the right most digit of the selected number.
	int sum=0; // variable that contains the sum of every digit to the power of fifth of the selected number's digit.

	// the follwoing loop is the range of the possible numbers that can be selected.
	for ( int i= tenthousand; i< hundredthousand; i++)
	{
		// the following preforms a calculation seperating each digit by itself and power it to the fifth and assign it to the variable sum.
		onedigit= i%10;
		sum = pow(onedigit,5);
		num= i/10;

		/* the following preform the same calculation as above but it keeps calculating each digit from the selected number
		 untill it reaches the last digit of the given number*/
		for( int counter=0; counter < 4; counter++)
		{
		onedigit = num%10;
		sum= sum+ pow(onedigit,5);
		num=num/10;
		}

		/* the following checks if the sum was identical to the selected number, if so it prints out the the sums that
		are identical to the number selected*/
		if( sum == i)
		{
			cout<< sum << endl;
		}

	}


	return 0;

}
