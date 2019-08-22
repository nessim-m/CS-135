#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>




using namespace std;

const int size= 10;// unchangeable size of the array
const int zero= 0; // unchangeable variable that carry the value of 0
const int row=10; // unchangeable variable of the two dimensional array's row
const int cols=10; // unchangeable variable of the two diemsnional array's column
const int one=1; // unchangeable variable that carry the value of 1




int main()
{
	//decleared varaibale for the two dimensional array. 

    int  board[row][cols];

	// input the file as a string
	ifstream inFile;
	string filename;

	// pmrompt user to input a valid flie
	do
	{

		cout<< "Enter a filename: ";
		cin>> filename;

 		//filename.c_str() returns a C style string version
		inFile.open(filename.c_str());

	}

	while(!inFile.is_open());



	while (!inFile.eof()) //if we do not reach end of file
	{
      if (inFile.fail()) //if input failure occurs in the file, skip over it
      {
      	inFile.clear();
      	inFile.ignore(100, '\n');
      }

      /* the following loop inputs the file in two dimensional array and outputs the whole two dimensional array.*/
      else
      {

    	for( int i=zero; i< row; i++)
    	{
    		for (int j=zero; j < cols; j++)
    		{
    			inFile>> board[i][j];
    			cout<< setw(2) << board[i][j] <<' '<<' ';
    		}
    		cout << '\n';
    	}
      }
 
	}

      cout << endl;

      	// decleared variables that are initialized and changes its value and contains the value of rows and columns's position
		int rowpositon=zero;
		int colspositon=zero;

		/*The following loop goes through every element in the two dimensional array and checks if the element is greater than its neighbor. 
		If the element is greater than its neighbor, then its a peak item, so it outputs its position in the array. */

    	for( int i=one; i< row; i++)
    	{
    		for (int j=one; j < cols; j++)
    		{
      	

    			while (board[i][j] > board[i-one][j] and board[i][j] > board[i][j-one] and board[i][j] > board[i+one][j] and board[i][j]and board[i][j+one])
    			{
    				rowpositon= i;
    				colspositon= j;

    				cout << "Itema at position "<< " ["<< rowpositon<<","<< colspositon<<"]"<<" is a peak item"<< endl;

    				break;


    			}
    		}


      }










      return 0;

  }
