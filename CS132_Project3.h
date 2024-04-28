// CS132_Project3.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "BST.h"
// TODO: Reference additional headers your program requires here.
struct Word
{
	// Data
	private:
		int FirstOccurance;
		int count = 0;
		std::string MyWord;
	// Functions
public:
	void toUpper();
	void toLower();
	void SetWord(std::string);
	void SetFirstFind(int);
	void SetCount(int);
	void IncrementCount();
	std::string GetWord();
	int GetFirstFind();
	int GetCount();
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
	friend std::ostream& operator<<(std::ostream& out, Word& word);
	friend std::istream& operator>>(std::istream& in, Word& word);
};
// Operators
bool operator< (Word, Word);
bool operator> (Word, Word);
bool operator<= (Word, Word);
bool operator>= (Word, Word);
bool operator== (Word, Word);
// Function Headers
void GetFile(std::ifstream&);
bool InWord(char Current, char Next); // Checks two characters to see if you're in a word  
void IntializeList(BST<Word>[], std::ifstream& in);
void DisplayList(BST<Word>[], std::ostream& out);
void ChooseOperation(BST<Word>[], std::ostream& in);
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
