// The program asks the user for the name of a file that contains numbers and find 1.the highest number 2. the lowest number 3. average 4. total 5. median 6. mode
// The number analysis via the array
// Programmer: Panupong Leenawarat
// Last modified: 1/14/2016

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

double getLowest(double a[], int size);
double getHighest(double a[], int size);
double getTotal(double a[], int size);
double getMode(double a[], int size);
double getMedian(double numbers[], int size);

int main()
{
	const int SIZE_OF_ARRAY = 100;
	double numbers[SIZE_OF_ARRAY],
		   lowestNumber,
		   highestNumber,
		   totalNumber,
		   average,
		   temp,
		   mode,
		   median;
	string nameInput;
	int count = 0;
	ifstream nameFile;

	// Prints the introduction on the mornitor
	cout
		<< endl
		<< "\t      This program asks the user for the name of a file that     " << endl
		<< "\t                      contains numbers,                            " << endl
		<< "\t            and analysis the numbers within the array                 " << endl
		<< "\t                      By Lee. Panupong                             " << endl << endl;

	// Ask for a file name
	cout << "What file contains your data? ";
	
	// Get file name from a user
	getline(cin, nameInput);
	// Open the file.
	nameFile.open(nameInput);

	// If the file is not successfully opened, process it.
	if (nameFile.fail())
	{
		system("COLOR 3F");
		cout << "\tFailed to open file: \"" << nameInput << "\" Exiting the program." << endl << endl;
		system("pause");
		return 0;
		// where is the statement that exits the program
	}

	while (count < SIZE_OF_ARRAY && nameFile >> numbers[count])
		count++;

	nameFile.close();

	// It gets the lowest value from the function getLowest
	lowestNumber = getLowest(numbers, count);
	
	// It gets the hhighest value from the function getHighest
	highestNumber = getHighest(numbers, count);

	// It gets the total value from the function getTotal 
	totalNumber = getTotal(numbers, count);

	// Calculate to find the average
	average = totalNumber / count;
	
	// process to rearrange the numbers in the array
	for (int i = 0; i < count - 1; i++)
		for (int j = i + 1; j < count; j++)
			if (numbers[i] > numbers[j])
			{
				// These three lines swap the elements
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}

	// get the median value from the function getMedian
	median = getMedian(numbers, count);
	
	// get the mode value from the function getMode
	mode = getMode(numbers, count);

	// Prints out all those information to the monitor
	cout 
		<< "\nThe array certains with " << count << (count == 1 ? " number" : " numbers") << endl
		<< "The lowest number in the array is " << lowestNumber << endl
		<< "The highest number in the array is " << highestNumber << endl
		<< "The total of the numbers in the array is " << totalNumber << endl
		<< "The average of the numbers in the array is " << average << endl
		<< "The median of the numbers in the array is " << median << endl;

	// In case the set of numbers does not have mode value
	if (mode < 0)
		cout << "The array do not have mode" << endl;
	else
		cout << "The mode of the numbers in the array is " << mode << endl << endl;
	
	system("pause");
	return 0;
}

double getLowest(double numbers[], int size)
{
	double lowest;

	lowest = numbers[0];

	for (int count = 1; count < size; count++)
	{
		if (numbers[count] < lowest)
			lowest = numbers[count];
	}

	return lowest;
}

double getHighest(double numbers[], int size)
{
	double highest;

	highest = numbers[0];

	for (int count = 1; count < size; count++)
	{
		if (numbers[count] > highest)
			highest = numbers[count];
	}

	return highest;
}

double getTotal(double numbers[], int size)
{
	double total = 0;

	for (int count = 0; count < size; count++)
		total += numbers[count];

	return total;
}

double getMode(double numbers[], int size)
{
	double number = numbers[0];
	double mode = number;
	int count = 1;
	int countMode = 1;

	for (int i = 1; i < size; i++)
	{
		if (numbers[i] == number)
		{
			count++;
		}
		else
		{
			if (count > countMode)
			{
				countMode = count;
				mode = number;
			}
			count = 1;
			number = numbers[i];
		}
	}
	
	if (countMode == 1)
		return -1;

	return mode;
}

double getMedian(double numbers[], int size)
{
	double median;
	if (size % 2 != 0)
	{
		int temp = ((size + 1) / 2) - 1;
		median = numbers[temp];
		return median;
	}
	else
		median = (numbers[(size / 2) - 1] + numbers[size / 2]) / 2;
		return median;
}