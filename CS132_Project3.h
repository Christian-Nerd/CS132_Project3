// CS132_Project3.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "BST.h"
// TODO: Reference additional headers your program requires here.
struct Word
{
	// Data
	int FirstOccurance;
	std::string MyWord;
	// Functions
	void toUpper();
	void toLower();
	// Template Operators
	template<typename T>
	bool friend operator< (T, Word);
	template<typename T>
	bool friend operator> (Word, T);
	template<typename T>
	bool friend operator<= (T, Word);
	template<typename T>
	bool friend operator>= (Word, T);
	template<typename T>
	bool friend operator== (T, Word);
	template<typename T>
	bool friend operator== (Word, T);
	// Operators
	bool operator< (Word);
	bool operator> (Word);
	bool operator<= (Word);
	bool operator>= (Word);
	bool operator== (Word);
	ostream& friend operator<<(ostream& out, Word);
	istream& friend operator>>(istream& in, Word);
};
// Function Headers
fstream& GetFile();
void IntializeList(vector<string>&);
void DisplayList(vector<Word>&, ostream& out);
void ChooseOperation(vector<Word>&, ostream& in);
bool DoesUserWantToContinue();
// Implementation for template functions
	template<typename T>
	bool operator< (T var, Word word)
	{
		return var < word.MyWord;
	}
	template<typename T>
	bool operator< (Word word, T var)
	{
		return word.MyWord < var;
	}

	template<typename T>
	bool operator<= (T var, Word word) 
	{
		return var <= word.MyWord;
	}
	template<typename T>
	bool operator<= (Word word, T var) 
	{
		return word.MyWord <= var;
	}

	template<typename T>
	bool operator> (T var, Word word)
	{
		return var > word.MyWord;
	}
	template<typename T>
	bool operator> (Word word, T var)
	{
		return word.MyWord > var;
	}

	template<typename T>
	bool operator>= (T var, Word word)
	{
		return var >= word.MyWord;
	}

	template<typename T>
	bool operator>= (Word word, T var)
	{
		return word.MyWord >= var;
	}

	template<typename T>
	bool operator== (T var, Word word)
	{
		return var == word.MyWord;
	}

	template<typename T>
	bool operator== (Word word, T var)
	{
		return word.MyWord == var;
	}
