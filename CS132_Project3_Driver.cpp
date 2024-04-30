#include "CS132_Project3.h"
#include "Quicksort.h"
using namespace std;

int main() 
{
	ifstream Text;
	BST<Word> List[26];
	GetFile(Text);
	InitializeList(List, Text);
	while (true)
	{
		ChooseOperation(List, Text);
	}
	Text.close();
	return 0;
}