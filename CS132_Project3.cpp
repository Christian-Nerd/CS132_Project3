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

Word Word::operator= (Word term2) 
{
	this->SetWord(term2.GetWord());
	return term2;
}

string Word::operator= (string term2) 
{
	this->SetWord(term2);
	return term2;
}

void GetFile(ifstream& in)
{
	do
	{
		cout << "Input File path: ";
		string path;
		getline(cin, path);
		cout << endl; // For better formatting
		in.open(path, ios::in);
		cout << in.fail();
		if (!in)
		{
			cerr << endl << "Invalid file path please renter" << endl;
			in.clear();
		}
	} while (!in);
}	


bool InWord(char Current, char Next) 
{
	return (isspace(Current) && !isspace(Next)) || (!isspace(Current) && !isspace(Next));
}

ostream& operator<<(std::ostream& out, Word& word) 
{
	out << word.MyWord << "    " << word.FirstOccurance << "    " << word.count << endl;
	return out;
}


istream& operator>>(std::istream& in, Word& word) 
{
	char CurrentStreamCharacter = in.get();
	string NewWord = "";
	while (true) 
	{
		if (!(CurrentStreamCharacter >= -1 && CurrentStreamCharacter <= 255))
		{
			CurrentStreamCharacter = in.get();
			if (!in)
			{
				in.clear();
				break;
			}
			continue;
		}

		if (CurrentStreamCharacter == '\n')
		{
			word.IncrementCount(); // Increments count to indicate current line
		}
		NewWord.push_back(CurrentStreamCharacter);
		if (!isspace(CurrentStreamCharacter) && isspace(in.peek()) || !in /* Checks if in.peek() returns eof since associativity is left to right*/) 
		{
			word.SetFirstFind(word.GetFirstFind() + word.GetCount()); // Uses count to assign current line to
			word.SetWord(NewWord);
			if (!in)
			{
				return in;
			}
			else if (in.peek() == '\n')
			{
				word.IncrementCount(); // Increments count to indicate current line
			}
			break;
		}
		CurrentStreamCharacter = in.get();
	}
	return in;
}



void InitializeList(BST<Word> list[], ifstream& file)
{
	int Count = 0, CurrentLine = 0, AlphabetIndex = 0, LineNumber = 1;
	while (file)
	{
		Word NextWord;
		NextWord.SetFirstFind(CurrentLine);
		file >> NextWord;
		// Use count to find current line
		LineNumber += NextWord.GetCount();
		for (int i = 0; i < NextWord.GetWord().size(); i++)
		{
			char CurrentCharacter = NextWord.GetWord().at(i);
			// Find AlphabetIndex
			if (isalpha(CurrentCharacter))
			{
				AlphabetIndex = tolower(CurrentCharacter) - 97;
				//Get rid of non alphabet characters at beginning of word
				NextWord.SetWord(NextWord.GetWord().substr(i, NextWord.GetWord().size()-1 ));
			}
		}
		//Find non alphabet characters at end of word
		for (int i = NextWord.GetWord().size() - 11; i > -1; i--)
		{
			char CurrentCharacter = NextWord.GetWord().at(i), PreviousCharacter  = i - 1 >= 0? NextWord.GetWord().at(i - 1) : ' ';
			if (!isalpha(CurrentCharacter))
			{
				if (PreviousCharacter != ' ' && isalpha(PreviousCharacter)) 
				{
					NextWord.SetWord(NextWord.GetWord().substr(0, i-1));
					break;
				}
				else if (i == 0)
				{
					
				}
			}

		}
		// If not found insert the word if found increment the word's count
		if(!list[AlphabetIndex].search(NextWord))
			list[AlphabetIndex].insert(NextWord);
		else
		{
			list[AlphabetIndex].get(NextWord).IncrementCount();
		}
	}
	file.clear();
	file.seekg(ios::beg);
}

void DisplayList(BST<Word> list[], ostream& out) 
{
	for (int i = 0; i < 26; i++)
	{
		list[i].inorder(out);
		out << endl;
	}
}

void ChooseOperation(BST<Word> list[], istream& in)
{
	cout << "Do you want to display all the words in the list or retrive a specific one? ";
	string choice = "";
	cin >> choice;
	transform(choice.begin(), choice.end(), choice.begin(), tolower); // Convert string to lowercase 
	if (choice == "display" || choice == "display words" || choice == "show" || choice == "show words" || choice == "all")
	{
		ofstream out;
		out.open("List", ios::out);
		DisplayList(list, cout);
		DisplayList(list, out);
		out.close();
	}

	else if (choice == "get" || choice == "retrive word" || choice == "get words" || choice == "get word" || choice == "retrive words")
	{
		bool ValidWord = true;
		while(ValidWord)
		{
			cout << "Input word " << endl;
			string word = " ";
			cin >> word;
			Word CurrentWord;
			CurrentWord.SetWord(word);
			for (int i = 0; i < 26; i++)
			{
				if (list[i].search(CurrentWord))
					break;
				else
				{
					ValidWord = false;
					break;
				}
			}
		}
	DisplayList(list, cout);
	}


}

bool DoesUserWantToContinue() 
{
	string choice = "";
	cout << "Do you want to exit.";
	cin >> choice;
	if(choice == "yes" || "y")
		return true; 
	return false;
}
