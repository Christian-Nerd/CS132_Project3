#include "CS132_Project3.h"
#include "Quicksort.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "utf-8");
	ifstream Text;
	BST<Word> List[26];
	GetFile(Text);
	InitializeList(List, Text);
	while (ChooseOperation(List, Text))
		;
	Text.close();
	return 0;
}