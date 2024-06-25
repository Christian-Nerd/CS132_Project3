// CS132_Project3.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <istream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cwctype>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "BST.h"
#include "uni-algo\include\uni_algo\all.h"
// TODO: Reference additional headers your program requires here.
struct Word
{
	// Data
	private:
		int FirstOccurance;
		int count = 0;
		std::wstring MyWord;
	// Functions
public:
	void toUpper();
	void toLower();
	void SetWord(std::wstring);
	void SetFirstFind(int);
	void SetCount(int);
	void IncrementCount();
	std::wstring GetWord();
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
	friend std::wostream& operator<<(std::wostream& out, Word& word);
	friend std::wistream& operator>>(std::wistream& in, Word& word);
	Word operator= (Word);
	std::wstring operator= (std::wstring);
};
// Operators
bool operator< (Word, Word);
bool operator> (Word, Word);
bool operator<= (Word, Word);
bool operator>= (Word, Word);
bool operator== (Word, Word);
// Function Headers
bool IsAscii(wchar_t);
void GetFile(std::wifstream&);
bool InWord(char Current, char Next); // Checks two characters to see if you're in a word  
void TruncateNonAlphaChars(Word&);
void InitializeList(BST<Word>[], std::wifstream& in);
void DisplayList(BST<Word>[], std::wostream& out);
bool ChooseOperation(BST<Word>[], std::wistream& in);
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
