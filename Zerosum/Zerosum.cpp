/*
ID: paradox4
PROG: zerosum
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int N;

bool isZeroSum(const string operation)
{
	int sum = 0;
	int buffer = 1;

	for (int i = 2; i <= N; i++)
	{
		switch (operation[i-2]) 
		{
		case ' ':
			buffer *= 10;

			if (buffer > 0)
				buffer += i;
			else
				buffer -= i;
			break;
		case '+':
			sum += buffer;
			buffer = i;
			break;
		case '-':
			sum += buffer;
			buffer = -1 * i;
			break;
		default:
			cout << "ALERT! ALERT! An error occured! Error Code: 1." << endl;
		}
	}

	sum += buffer;

	if (sum == 0)
		return true;
	else
		return false;
}

void printSeq(const string printy, ofstream& Out)
{
	for (int i = 1; i < N; i++)
		Out << i << printy[i - 1];

	Out << N << endl;

	return;
}

void recurse(int current_length, string operations, ofstream& Out)
{
	if (current_length == N - 1)
	{
		if (isZeroSum(operations))
			printSeq(operations, Out);
		return;
	}

	recurse(current_length + 1, operations + ' ', Out);

	recurse(current_length + 1, operations + '+', Out);

	recurse(current_length + 1, operations + '-', Out);

	return;

}

int main()
{
	ifstream Input("zerosum.in");
	ofstream Output("zerosum.out");
	
	Input >> N;

	string ops;

	recurse(0, ops, Output);

	return 0;
}