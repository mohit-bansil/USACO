/*
ID: paradox4
PROG: lgame
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int LARGE = 1147483647;
const int MAXDICSIZE = 40000;

int charToInt(char a)
{
	return (int)(a - 'a');
}

int point(char a)
{
	switch(a)
	{
	case 'q':
		return 7;
	case 'w':
		return 6;
	case 'e':
		return 1;
	case 'r':
		return 2;
	case 't':
		return 2;
	case 'y':
		return 5;
	case 'u':
		return 4;
	case 'i':
		return 1;
	case 'o':
		return 3;
	case 'p':
		return 5;
	case 'a':
		return 2;
	case 's':
		return 1;
	case 'd':
		return 4;
	case 'f':
		return 6;
	case 'g':
		return 5;
	case 'h':
		return 5;
	case 'j':
		return 7;
	case 'k':
		return 6;
	case 'l':
		return 3;
	case 'z':
		return 7;
	case 'x':
		return 7;
	case 'c':
		return 4;
	case 'v':
		return 6;
	case 'b':
		return 5;
	case 'n':
		return 2;
	case 'm':
		return 5;
	}

}

struct word
{
	string wor;

	int letters[26];

	int points;

	int length;
};

word words[MAXDICSIZE + 1];

void intilizeWord(word& a)
{
	a.length = a.wor.size();

	a.wor.reserve(8);

	for (int i = 0; i < a.length; i++)
	{
		a.letters[charToInt(a.wor[i])]++;
		a.points += point(a.wor[i]);
	}

	return;
}

word in;
int dic_size = 1;

bool test(int a, int b)
{
	if (words[a].length + words[b].length > in.length)
		return false;

	for (int i = 0; i < 26; i++)
	{
		if (words[a].letters[i] + words[b].letters[i] > in.letters[i])
			return false;
	}

	return true;
}

int main()
{
	ifstream Input("lgame.in");
	ofstream Output("lgame.out");
	ifstream Dict("lgame.dict");

	string inp;

	intilizeWord(words[0]);

	while (true)
	{
		Dict >> inp;

		if (inp == ".")
			break;

		words[dic_size].wor = inp;
		intilizeWord(words[dic_size]);

		dic_size++;
	}

	Input >> in.wor;

	intilizeWord(in);

	int maxscore = 0;

	for (int i = 0; i < dic_size; i++)
	{
		if (!test(i, 0))
			continue;

		for (int j = i; j < dic_size; j++)
		{
			if (test(i, j))
			{
				if (words[i].points + words[j].points > maxscore)
					maxscore = words[i].points + words[j].points;
			}
		}
	}
	
	Output << maxscore << endl;

	for (int i = 1; i < dic_size; i++)
	{
		if (!test(i, 0))
			continue;

		if (words[i].points == maxscore)
		{
			Output << words[i].wor << endl;
			continue;
		}

		if (words[i].points > maxscore)
			continue;

		for (int j = i; j < dic_size; j++)
		{
			if (test(i, j))
			{
				if (words[i].points + words[j].points == maxscore)
				{
					Output << words[i].wor << " " << words[j].wor << endl;
				}					
			}
		}
	}

	return 0;
}


/*
void inti(int thingy[], int size, int val)
{
for (int i = 0; i <= 203; i++)
thingy[i] = val;

return;
}

void inti(bool thingy[], int size, int val)
{
for (int i = 0; i <= 203; i++)
thingy[i] = val;

return;
}
*/