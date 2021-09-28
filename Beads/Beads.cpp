/*
ID: paradox4
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void permuteString(string& necklace)
{
	char a = necklace[0];

	necklace.erase(necklace.begin());

	necklace += a;
}

int main()
{
	ifstream Input("beads.in");
	ofstream Output("beads.out");
	
	int size;
	string necklaceInput, necklace;

	Input >> size >> necklaceInput;

	necklace = necklaceInput + necklaceInput;

	int currentIndex = 0;
	int currentSize = 1;
	int maxSize = 0;

	char a = 'a';
	
	for (int searchIndex = 2; searchIndex < size; searchIndex++)
	{
		currentSize = 1;
		currentIndex = searchIndex;

		a = necklace[currentIndex];

		if (a == 'w')
		{
			for (int i = currentIndex + 1; i < size * 2; i++)
			{
				if (necklace[i] != 'w')
				{
					a = necklace[i];
					break;
				}
			}
		}

		while (true)
		{
			if (currentIndex - searchIndex == size - 1)
				break;

			if (necklace[currentIndex + 1] == a || necklace[currentIndex + 1] == 'w')
			{
				currentSize++;
				currentIndex++;
			}
			else
				break;
		}

		while (true)
		{
			if (currentIndex - searchIndex == size - 1)
				break;

			if (necklace[currentIndex + 1] != a)
			{
				currentSize++;
				currentIndex++;
			}
			else
				break;
		}

		if (currentSize > maxSize)
			maxSize = currentSize;
	}

	Output << maxSize << endl;

	return 0;
}