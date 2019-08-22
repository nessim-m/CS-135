#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>



const int size= 100; // constant maximum array potential size

using namespace std;



void swap (int & x , int & y ) // swaping int
{
	int temp = x ;
	x = y ;
	y = temp ;
	return ;
}

void bubbleSort (int arr [] , int size ) // sorting the array
{
	for (int i = 0; i < size - 1; i ++)
	{
		for (int j = 0; j < size - i - 1; j ++)
		{
			// if you flip the inequality , it will sort
			// the array from highest to lowest
			if ( arr [ j ] > arr [ j + 1])
			{
				swap ( arr [ j ] , arr [ j + 1]);
			}
		}
	}
	return;
}

void printArray (int arr[], int size) // printing the array
{

	int i;
	for (i=0; i< size; i++)
	{
		printf("%d ", arr[i]);
	}


}


int main()
{

/*decleared variables for the counts, sum, mean, median, standard deviation,
 number in the array, and list size */

	double sum;
	double mean;
	double median;
	double standard= 0;
	double deviation;
	int num;
	int list[size];
	int R0_24=0;
	int R25_49=0;
	int R50_74=0;
	int R75_99=0;
	int R100_124=0;
	int R125_149=0;
	int R150_174=0;
	int R175_200=0;
	int listSize = 0;


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


      // while in file count numbers in range

      while(!inFile.eof())
      {
      	inFile>>num;
      	list[listSize] = num;
      	listSize++;
      	sum= sum+num;

      	if (num >= 0 and num <= 24)
      	{
      		R0_24++;
      	}
      	else if(num >= 25 and num <= 49)
      	{
      		R25_49++;
      	}
      	else if(num >= 50 and num <= 74)
      	{
      		R50_74++;
      	}
      	else if(num >= 75 and num <= 99)
      	{
      		R75_99++;
      	}
      	else if(num >= 100 and num <= 124)
      	{
      		R100_124++;
      	}
      	else if(num >= 125 and num <= 149)
      	{
      		R125_149++;
      	}
      	else if(num >= 150 and num <= 174)
      	{
      		R150_174++;
      	}
      	else if(num >= 175 and num <= 200)
      	{
      		R175_200++;
      	}
      }


  } 



  /* output number of students and the whole array in order */

  cout << "Number of students: " << listSize << endl;

  bubbleSort(list, listSize);
  printf("Sorted List: \n");
  printArray(list, listSize);
  cout << endl;

 /*calculate the mean, the strandard deviation, and the median
  and output the the answers*/

  mean= sum/listSize;

  cout << "Mean: " << mean << endl;	

  for (int i=0; i < listSize; i++)
  {

  	standard += pow(list[i] - mean, 2);
  	deviation = sqrt(standard / listSize);


  }

  cout << "Standard deviation: " << deviation << endl;


  if ( listSize % 2==0)
  {
  	median= double(list[listSize/2] + list[listSize/2])/2.0+0.5;

  	cout << "Median: " << median << endl;

  }

  else
  {

  	median= list[listSize/2];

  	cout << "Median: " << median << endl;


  }


  // calculate the min in the array and output the answer

  int min = list[0];

  for (int i = 1; i < listSize; i++)
  {
  	if (min > list[i])
  	{

  		min = list[i];
  	}

  }

  cout << "Minimum: " << min << endl;

  // calculate the max in the array and output the answer

  int max = list[0];

  for (int i = 1; i < listSize; i++)
  {
  	if (max < list[i])

  		max = list[i];

  }

  cout << "Maximum: " << max << endl;

  // output the count of different ranges

  cout << "count of 0_24: " << R0_24 << endl;
  cout << "count of 25_49: " << R25_49 << endl;
  cout << "count of 50_74: " << R50_74 << endl;
  cout << "count of 75_99: " << R75_99 << endl;
  cout << "count of 100_124: " << R100_124 << endl;
  cout << "count of 125_149: " << R125_149 << endl;
  cout << "count of 150_174: " << R150_174 << endl;
  cout << "count of 175_200: " << R175_200 << endl;














  return 0;
}
