#include "CS132_Project3.h"
#include "Quicksort.h"
using namespace std;

int main() 
{
	ifstream Text;
	BST<Word> List[26];
	while (true)
	{
		GetFile(Text);
		ChooseOperation(List, Text);
	}
	return 0;
}