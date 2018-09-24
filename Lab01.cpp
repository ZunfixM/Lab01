// Lab01.cpp
// Trevor Dine
// COCS 2030
// 17 September 2018
// Lab 01

#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;

using std::string;

int countPlusFirstAndLast(ifstream& file, int length, double& first, double& second, double& secondToLast, double& last);

string fileName;
ifstream readFile;
int listLength = 0;


int main()
{
	double first=0, second=0, secondToLast=0, last=0;
	// Prompt the user for a file including the file type.
	cout << "Type a file name to read from including the file type (example.txt): " << endl;
	getline(cin, fileName);

	// Open the file and find the number of doubles in the file and the first and last two doubles.
	readFile.open(fileName);
	listLength = countPlusFirstAndLast(readFile, listLength, first, second, secondToLast, last);

	// Displays the results of the program. The number of doubles in the file and the two first and last numbers in the file.
	cout << "The number of doubles in the file is: " << listLength << endl;
	cout << "The first two numbers are: " << first << " and " << second << "\nThe last two numbers are: " << secondToLast << " and " << last << endl;
	readFile.close();
	system("pause");
	return 0;
}

// firstAndLast() used to find the first two and last two numbers in the file and stores the numbers in their specified arrays (firstTwo and lastTwo).
int countPlusFirstAndLast(ifstream& file, int length, double& first, double& second, double& secondToLast, double& last)
{
	double buff = 0;
	double buf1 = 0;
	double buf2 = 0;
	int count = 0;
	while (file >> buff)
	{
		buf2 = buf1; // stores the previous number to be used later in second to last number.
		if (!readFile.fail())
		{
			count++; // counts the amount of doubles in the files.
			buf1 = buff;
		}

		if (count == 1)
		{
			first = buff;
		}

		else if (count == 2)
		{
			second = buff;
		}
	}

	// If there are less than 4 numbers then the last two numbers will not be used. The second number is already accounted for above within the while loop.
	if (count > 2)
	{
		last = buff;
	}
	else if (count > 3)
	{
		secondToLast = buf2;
	}
	
	return count;
}