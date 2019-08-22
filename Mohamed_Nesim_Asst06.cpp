#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>


using namespace std;

const  double threehundred= 300.00; //A constant unchangeable variable that contains a value of three-hundred throughout the coding
const  double fivehundred= 500.00;  //A constant unchangeable variable that contains a value of five-hundred throughout the coding
const  double zero= 0.00;  //A constant unchangeable variable that contains a value of zero throughout the coding
const  double twentyfive= 25.00; //A constant unchangeable variable that contains a value of twenty-five throughout the coding
const  double pointzerofour= 0.04; //A constant unchangeable variable that contains a value of point-zero-four throughout the coding


int main()
{
  
  char usercontinue;
  double withdrawal = zero; //variable represents the amount that was widhtrawal from the account
  double deposit = zero; //variable represents the amount that was deposited into the account, also the new balance
  double fees = zero; //variable represents the fees that was applied to the account

  cout<< " Deposit initial amount: ";


  while ( !(cin>>deposit) || deposit < zero) //check the validation of deposit input and reprompt the user if its invalid
  {

    cout<< " Deposit initial amount: ";

    cin.clear();
    cin.ignore(100,'\n');

  }


  //If the deposit input was valid it will enter the following while loop and prompt the user amount to withdrawal

  while (  withdrawal <= threehundred and deposit > zero  or usercontinue =='Y' or usercontinue == 'y' )
  {


    /* If the withdrawal input was greater than the deposit it will enter the following loop and prompt the user that there will be twenty-five dollar
     extra charge plus the searvice charge of 4%. It also check the input validation. */

    while (withdrawal <= fivehundred and withdrawal >= threehundred and deposit < withdrawal)
    {

            cout<< " Enter an amount to withdrawal: ";

    while ( !(cin>>withdrawal) or withdrawal < zero)
    {
      cout<< " Enter an amount to withdrawal: ";

      cin.clear();
      cin.ignore(100,'\n');

    } 


      cout << " Insufficient funds for this withdrawal" << endl;
      cout << " There Will be a $25.00 service charge" << endl;
      cout << " Would you like to continue? (Y/N): ";
      cin >> usercontinue;

      while (usercontinue == 'N' or usercontinue == 'n')
      {

      if (usercontinue == 'N' or usercontinue == 'n')
      {

        break;
      }
      }

      if (usercontinue == 'Y' or usercontinue == 'y')
      {

        fees= twentyfive + (withdrawal * pointzerofour);
        deposit = deposit - (fees + withdrawal);

      //output the appropriate account status after the withdrawal                                                                                                                                                

        cout << " Amount withdrawn: " << std:: fixed << std:: setprecision(2)<<  withdrawal << endl;
        cout << " Amount of fees: " << fees << endl;
        cout << " Balance: " << deposit << endl;

        return 0;

      }


        // The follwoing while loop checks the input valdiation of the user to continue or not.

        while ( usercontinue != 'Y' or usercontinue != 'y' or usercontinue != 'N' or usercontinue != 'n' and deposit > zero)
    {

    cout << " Continue? (Y/N): ";
    cin >> usercontinue;


    if(usercontinue == 'Y' or usercontinue == 'y')
    {

      break;

    }

    if (usercontinue == 'N' or usercontinue == 'n')
    {

      exit (EXIT_FAILURE);
    }


    }
  }




      cout<< " Enter an amount to withdrawal: ";

    while ( !(cin>>withdrawal) or withdrawal < zero)
    {
      cout<< " Enter an amount to withdrawal: ";

      cin.clear();
      cin.ignore(100,'\n');

    } 


    /* If the withdrawal amount was less than three-hundred and the deposit is greater than zerp it perform the following calculation 
    and output the balance and goes back prompt the user to continue and withdrawal more amount. */

    if ( withdrawal < threehundred and deposit > zero)
    {

      deposit = deposit - withdrawal;


      cout<< " Amount withdrawn: "<< std:: fixed << std:: setprecision(2)<<  withdrawal << endl;
      cout<< " Amount of fees: "<< "0.00" << endl;
      cout<< " Balance: "<< deposit<< endl;

    }

    /* If the withdrawal amount was greaterthan or equal to three-hundred, less than five-hundred, less than the deposit, 
    and the deposit is greater than zero it will perform the following calculation and output the balance and goes back and promt the user
    to contnue and withdrawal more amount. */

    if ( withdrawal >= threehundred and withdrawal < fivehundred and deposit > zero and withdrawal < deposit)
    {


      fees = withdrawal * pointzerofour;
      deposit = deposit - (withdrawal + fees);  


      cout<< " Amount withdrawn: "<< std:: fixed << std:: setprecision(2)<<  withdrawal << endl;
      cout<< " Amount of fees: "<< fees << endl;
      cout<< " Balance: "<< deposit<< endl;
    }

    // if the deposit is less than zero it will go out from this while loop.

    if ( deposit < zero)
    {

      break;


    }

    /* if the withdrawal amount is greater than five-hundred than it will output the following quote and prompt user to continue and withdrawal
    more amount. */

    if ( withdrawal > fivehundred)
    {

      cout << " Cannot withdraw this amount" << endl;


    }
 


    // The follwoing while loop checks the input valdiation of the user to continue or not.

  while ( usercontinue != 'Y' or usercontinue != 'y' or usercontinue != 'N' or usercontinue != 'n' and deposit > zero)
  {

    cout << " Continue? (Y/N): ";
    cin >> usercontinue;


    if(usercontinue == 'Y' or usercontinue == 'y')
    {

      break;

    }

    if (usercontinue == 'N' or usercontinue == 'n')
    {

      exit (EXIT_FAILURE);
    }

  }

}








return 0;
}