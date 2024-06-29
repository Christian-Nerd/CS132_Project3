#include "CS132_Project3.h"
#include "Quicksort.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "");
	wifstream Text;
	// Change buffer of input stream from char to wchar_t
	wchar_t* buffer = new wchar_t[500];
	Text.rdbuf()->pubsetbuf(buffer, 500);
	BST<Word> List[26];
	GetFile(Text);
	InitializeList(List, Text);
	while (ChooseOperation(List, Text))
		;
	Text.close();
	return 0;
}