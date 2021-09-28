/*
ID: paradox4
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

void inputArray(char **array, int N, ifstream& Input)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			Input >> array[k][i];
		}
	}
}

void rotate90(char **pattern, char **patternBuffer, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			patternBuffer[N - 1 - k][i] = pattern[i][k];
		}
	}
}

void reflect(char **pattern, char **patternBuffer, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			patternBuffer[N - 1 - i][k] = pattern[i][k];
		}
	}
}

bool checkEquality(char **pattern, char **patternCheck, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			if (pattern[i][k] != patternCheck[i][k])
				return false;
		}
	}

	return true;
}

void printArray(char **array, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cout << array[k][i] << " ";
		}

		cout << endl;
	}
}

int main()
{
	ifstream Input("transform.in");
	ofstream Output("transform.out");

	int N;
	Input >> N;

	char** pattern = new char*[N];
	char** patternBuffer90 = new char*[N];
	char** patternBuffer180 = new char*[N];
	char** patternBuffer270 = new char*[N];
	char** patternBufferReflect = new char*[N];
	char** patternCheck = new char*[N];

	for (int i = 0; i < N; i++)
	{
		pattern[i] = new char[N];
		patternBuffer90[i] = new char[N];
		patternBuffer180[i] = new char[N];
		patternBuffer270[i] = new char[N];
		patternBufferReflect[i] = new char[N];
		patternCheck[i] = new char[N];
	}

	inputArray(pattern, N, Input);
	inputArray(patternCheck, N, Input);

	//printArray(patternCheck, N);

	rotate90(pattern, patternBuffer90, N);
	if (checkEquality(patternBuffer90, patternCheck, N))
	{
		Output << "1" << endl;
		return 0;
	}
	
	rotate90(patternBuffer90, patternBuffer180, N);
	if (checkEquality(patternBuffer180, patternCheck, N))
	{
		Output << "2" << endl;
		return 0;
	}

	rotate90(patternBuffer180, patternBuffer270, N);
	if (checkEquality(patternBuffer270, patternCheck, N))
	{
		Output << "3" << endl;
		return 0;
	}

	reflect(pattern, patternBufferReflect, N);
	if (checkEquality(patternBufferReflect, patternCheck, N))
	{
		Output << "4" << endl;
		return 0;
	}

	reflect(patternBuffer90, patternBufferReflect, N);
	reflect(patternBuffer180, patternBuffer90, N);
	reflect(patternBuffer270, patternBuffer180, N);
	if (checkEquality(patternBufferReflect, patternCheck, N) || checkEquality(patternBuffer90, patternCheck, N) || checkEquality(patternBuffer180, patternCheck, N))
	{
		Output << "5" << endl;
		return 0;
	}

	if (checkEquality(pattern, patternCheck, N))
	{
		Output << "6" << endl;
		return 0;
	}

	Output << "7" << endl;
	return 0;
}