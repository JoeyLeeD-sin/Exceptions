/*
	Name: Joe Davidson
	Date: 7/28/2024
	Project Name: Exceptions
	Project Description: Write a function to calculate character offsets, throwing exceptions in error conditions
*/

#include <iostream>
#include <stdexcept>
#include <cctype>

using namespace std;

// Custom exceptions using the runtime_error class. Invalid character exception ensures the character is a valid letter. Invalid range exception ensures the result character is still within range and does
// not change cases. 

class InvalidCharacterException : public runtime_error
{
public:
	InvalidCharacterException() : runtime_error("Invalid character") {}
};

class InvalidRangeException : public runtime_error
{
public:
	InvalidRangeException() : runtime_error("Chracter is out of range") {}
};

// Function that will test whether the characters force the program to throw either exception

char character(char start, int offset);

int main()
{

	// First try/catch statement, expected to return b

	try
	{
		cout << "character('a',1) = " << character('a', 1) << endl;
	}
	catch (const exception& e)
	{
		cout << "character('a', 1) threw an exception: " << e.what() << endl;
	}

	// Second try/catch statement, expected to throw InvalidRangeException since a - 1 is not a valid letter. 

	try
	{
		cout << "character('a', -1) = " << character('a', -1) << endl;
	}
	catch (const exception& e)
	{
		cout << "character('a', -1) threw an exception: " << e.what() << endl;
	}

	// Third try/catch statement, expected to return Y

	try
	{
		cout << "character('Z', -1) = " << character('Z', -1) << endl;
	}
	catch (const exception& e)
	{
		cout << "character('Z', -1) threw an exception: " << e.what() << endl;
	}

}

char character(char start, int offset)
{
	// If the character is not a letter, throw the character exception

	if (!isalpha(start))
	{
		throw InvalidCharacterException();
	}

	char result = start + offset;

	// If the character is out of range, throw the range exception

	if (!isalpha(result) || (islower(start) && isupper(result) || (isupper(start) && islower(result))))
	{
		throw InvalidRangeException();
	}

	return result;
}