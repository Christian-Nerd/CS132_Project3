﻿// CS132_Project3.cpp : Defines the entry point for the application.
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

void Word::IncrementCount() 
{
	this->count += 1;
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

bool operator< (Word term1, Word term2) 
{
	return term1.GetWord() < term2.GetWord();
}

bool operator> (Word term1, Word term2)
{
	return term1.GetWord() > term2.GetWord();
}

bool operator<= (Word term1, Word term2) 
{
	return term1.GetWord() <= term2.GetWord();
}

bool operator>= (Word term1, Word term2) 
{
	return term1.GetWord() >= term2.GetWord();
}

bool operator== (Word term1, Word term2) 
{
	return term1.GetWord() == term2.GetWord();
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


bool InWord(char Current, char Next) 
{
	return (isspace(Current) && !isspace(Next)) || (!isspace(Current) && !isspace(Next));
}

ostream& operator<<(std::ostream& out, Word& word) 
{
	out << word.MyWord << "    " << word.FirstOccurance << "    " << word.count;
	return out;
}


istream& operator>>(std::istream& in, Word& word) 
{
	char CurrentStreamCharacter = in.get();
	string NewWord = "";
	while (true) 
	{
		NewWord.push_back(CurrentStreamCharacter);
		if (!isspace(CurrentStreamCharacter) && isspace(in.peek()) || !in /* Checks if in.peek() returns eof since associativity is left to right*/) 
		{
			word.SetWord(NewWord);
			if (!in)
			{
				in.clear();
				in.seekg(ios::beg);
			}
			else if (in.peek() == '\n')
			break;
		}
		CurrentStreamCharacter = in.get();
	}
	return in;
}



void IntializeList(BST<Word> list[], ifstream file)
{
	int Count = 0, CurrentLine = 0;
	while (file)
	{
		Word NextWord;
		NextWord.SetFirstFind(CurrentLine);
		file >> NextWord;
		if(!list->search(NextWord))
			list->insert(NextWord);
		else
		{
			list->get(NextWord).IncrementCount();
		}
	}
	file.clear();
	file.seekg(ios::beg);
}

void DisplayList(BST<Word> list[], ostream& out) 
{
	list->inorder(out);
}

void ChooseOperation(BST<Word> list[], ostream& in) 
{
	cout << "Do you want to display all the words in the list or ";
	DisplayList(list, cout);
}

bool DoesUserWantToContinue() { return false; }
