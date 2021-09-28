/*
ID: paradox4
PROG: msquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;

const int A_perm[8] = { 7, 6, 5, 4, 3, 2, 1, 0 };
const int B_perm[8] = { 3, 0, 1, 2, 5, 6, 7, 4 };
const int C_perm[8] = { 0, 6, 1, 3, 4, 2, 5, 7 };

struct state
{
	int color[8];

	string seq;

	void A()
	{
		int temp[8];

		for (int i = 0; i < 8; i++)
			temp[i] = color[i];

		for (int i = 0; i < 8; i++)
			color[i] = temp[A_perm[i]];

		seq += 'A';
	}

	void B()
	{
		int temp[8];

		for (int i = 0; i < 8; i++)
			temp[i] = color[i];

		for (int i = 0; i < 8; i++)
			color[i] = temp[B_perm[i]];

		seq += 'B';
	}

	void C()
	{
		int temp[8];

		for (int i = 0; i < 8; i++)
			temp[i] = color[i];

		for (int i = 0; i < 8; i++)
			color[i] = temp[C_perm[i]];

		seq += 'C';
	}

	int hash()
	{
		int answer = 0;

		for (int i = 0; i < 7; i++)
		{
			answer += color[i];
			answer *= 8;
		}

		return answer / 8;
	}
};

state dic[45000];

bool done[2100000];

int main()
{
	ifstream Input("msquare.in");
	ofstream Output("msquare.out");

	int target = 0, a;

	for (int i = 0; i < 7; i++)
	{
		Input >> a;

		target += a - 1;
		target *= 8;
	}

	target /= 8;

	if (target == 42798)
	{
		Output << 0 << endl << endl;
		return 0;
	}

	for (int i = 0; i < 8; i++)
		dic[0].color[i] = i;

	done[42798] = true;

	int lind = 0, uind = 1;

	state current;

	int hash_cur;

	while (true)
	{
		//first time
		current = dic[lind];

		current.A();
		hash_cur = current.hash();

		if (!(done[hash_cur]))
		{
			dic[uind] = current;
			uind++;
			done[hash_cur] = true;
		}

		if(hash_cur == target) 
			break;

		//second time
		current = dic[lind];

		current.B();
		hash_cur = current.hash();

		if (!(done[hash_cur]))
		{
			dic[uind] = current;
			uind++;
			done[hash_cur] = true;
		}

		if (hash_cur == target)
			break;

		//third time
		current = dic[lind];

		current.C();
		hash_cur = current.hash();

		if (!(done[hash_cur]))
		{
			dic[uind] = current;
			uind++;
			done[hash_cur] = true;
		}

		if (hash_cur == target)
			break;

		//repeat the above for B,C

		lind++;
	}

	Output << current.seq.length() << endl;
	Output << current.seq << endl;
	
	return 0;
}

/*
int hash()
{
bool stuff[8];

for (int i = 0; i < 8; i++)
stuff[i] = true;

int answer = 0;

int val = 0;

for (int i = 0; i < 8; i++)
{
answer *= i;

for (int j = 0; j < color[i]; j++)
{
if (stuff[j])
val++;
}

answer += val;

val = 0;
stuff[i] = false;
}

return answer;
}
*/

