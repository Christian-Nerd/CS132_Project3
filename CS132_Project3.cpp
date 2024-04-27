// CS132_Project3.cpp : Defines the entry point for the application.
//

#include "CS132_Project3.h"
#include "Quicksort.h"

using namespace std;

void Word::toUpper() 
{
	transform(this->MyWord.begin(), this->MyWord.end(), this->MyWord.begin(), std::toupper);
}

void Word::toLower() 
{
	transform(this->MyWord.begin(), this->MyWord.end(), this->MyWord.begin(), std::tolower);
}

void Word::SetWord(string Word) 
{
	this->MyWord = Word;
}

void Word::SetFirstFind(int LineNumber) 
{
	this->FirstOccurance = LineNumber;
}

void Word::SetCount(int Tracker) 
{
	this->count = Tracker;
}

string Word::GetWord() 
{
	return this->MyWord;

}

int Word::GetFirstFind() 
{
	return this->FirstOccurance;
}

int Word::GetCount() 
{
	return this->count;
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

ifstream& GetFile() 
{
	ifstream in;
	cout << "Input File path: ";
	string path;
	cin >> path;
	in.open(path, ios::out);
	return in;
}	

ostream& operator<<(std::ostream& out, Word& word) 
{
	out << word.MyWord << "    " << word.FirstOccurance << "    " << word.count;
	return out;
}


istream& operator>>(std::istream& in, Word& word) 
{
	in >> word.MyWord >> word.FirstOccurance >> word.count;
	return in;
}



void IntializeList(vector<Word>);

void DisplayList(vector<Word>& list, ostream& out) 
{
	for (int i = 0; i < list.size(); i++)
	{
		out << list[0] << endl;
	}
}

void ChooseOperation(vector<Word>& list, ostream& in) 
{
	cout << "Do you want to display all the words in the list or ";
	DisplayList(list, cout);
}

bool DoesUserWantToContinue() { return false; }
