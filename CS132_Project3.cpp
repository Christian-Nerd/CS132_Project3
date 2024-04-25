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

}
bool Word::operator< (Word);
bool Word::operator> (Word);
bool Word::operator<= (Word);
bool Word::operator>= (Word);
bool Word::operator== (Word);
