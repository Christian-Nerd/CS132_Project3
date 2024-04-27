// CS132_Project3.cpp : Defines the entry point for the application.
//

#include "CS132_Project3.h"

using namespace std;

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

fstream GetFile() 
{
	ifstream in;
	cout << "Input File path: ";
	string path;
	cin >> path;
	in.open(path, ios::out);
}

void IntializeList(vector<string>);

void DisplayList(vector<string> list, ostream& out);

void ChooseOperation(vector<Word>& list, ostream& in) 
{
	cout << "Do you want to display all the words in the list or"
	DisplayList(list, cout);
}

bool DoesUserWantToContinue();
