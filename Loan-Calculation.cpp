#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// declared constants variables that holds the same value throughout the coding.

const double zero = 0.0;
const double annually = 12.0;
const double hundred = 100.0;
int main()
{

// declared variables that might change in value throughout out the coding.

double loan;
double annuallyinterest;
double monthlyinterest;
double interest = zero;
double months;	
double payment;
double count;


// prompt user to input a value for the following declared variables: loan, annuallyinterest, and payment.

cout << "Loan amount, " << "Annually interest rate, " << "Monthly payment, ";
cin >> loan >> annuallyinterest >> payment;

// checking if the input by user was valid. Otherwise, reprompt user for a valid input.

while ( cin.fail() || interest < zero || payment < zero || loan < zero )
{

if (cin.fail())
{
	cin.clear();
	cin.ignore(hundred, '\n');
}
cout <<"Invalid input! Let's try this again...ahem" << endl;
cout << "Loan amount, " << "Annually interest rate, " << "Monthly payment, ";
cin >> loan >> annuallyinterest >> payment;

}

// conversion, calculating the monthly interest from the annually interest for a further calculation. As well as, initiating a counter.

monthlyinterest= ((annuallyinterest / annually ) / hundred);

count= zero;
	
double initial=loan;

// calculating the months needed to finish repaying the loan.

while (loan > zero)
{

if (payment > interest)
{

interest= loan * monthlyinterest;

months= payment - interest;

loan=  loan - months;

count++;

}

// if the interest rate is greater than the monthly payment then output the following.

else
{

	cout << " You will not be able to pay this loan. " << endl;

return 0;

}
}

// output the months need to finish repaying the loan, the loan amount, and the annually interst rate.

cout << "Loan amount: $" << fixed << setprecision(2) << initial << endl;
cout << "Interest: " << annuallyinterest << "%" << endl;
cout << "Months needed: " << fixed << setprecision(0) << count << endl;


	return 0;
}
