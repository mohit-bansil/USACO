/*
ID: paradox4
PROG: ride
LANG: C++
*/
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

int rankChar(char rawInput)
{
	int answer = rawInput - 'A' + 1;
	return answer;
}

int rankString(string rawInput)
{
	int size = rawInput.size();
	int answer = 1;

	for (int i = 0; i < size; i++)
	{
		answer *= rankChar(rawInput[i]);
	}

	return answer;
}

int main()
{
	ifstream Input("ride.in");
	ofstream Output("ride.out");
	
	string a, b;
	int c, d;
	
	Input >> a >> b;

	c = rankString(a) % 47;
	d = rankString(b) % 47;

	if (c == d)
		Output << "GO" << endl;
	else
		Output << "STAY" << endl;

	return 0;
}