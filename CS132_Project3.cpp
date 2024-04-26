// CS132_Project3.cpp : Defines the entry point for the application.
//

#include "CS132_Project3.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}

void Word::toUpper() 
{
	transform(this->MyWord.begin(), this->MyWord.end(), this->MyWord.begin(), toUpper);
}

void Word::toLower() 
{
	transform(this->MyWord.begin(), this->MyWord.end(), this->MyWord.begin(), toLower);
}

bool Word::operator< (Word term) 
{
	return this->MyWord < term.MyWord;
}

bool Word::operator> (Word term)
{
	return this->MyWord > term.MyWord;
}

bool Word::operator<= (Word term) 
{
	return this->MyWord <= term.MyWord;
}

bool Word::operator>= (Word term) 
{
	return this->MyWord >= term.MyWord;
}

bool Word::operator== (Word term) 
{
	return this->MyWord == term.MyWord;
}

fstream getFile();

void IntializeList(vector);

void DisplayList(ostream& out);
