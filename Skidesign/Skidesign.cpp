/*
ID: paradox4
PROG: skidesign
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int errorMeasure(int height, int x)
{
	int thing = abs(height - x);

	if (x <= height && height <= x + 17)
		return 0;
	else if (height < x)
		return (x - height) * (x - height);
	else
		return (height - x - 17) * (height - x - 17);
}

int main()
{
	ifstream Input("skidesign.in");
	ofstream Output("skidesign.out");
	
	int N;
	Input >> N;

	int hills[1000];

	for (int i = 0; i < N; i++)
		Input >> hills[i];

	int minError = 999999999;
	int currentError = 0;

	for (int i = 1; i <= 100; i++)
	{
		for (int k = 0; k < N; k++)
			currentError += errorMeasure(hills[k], i);
		
		if (currentError < minError)
			minError = currentError;

		currentError = 0;
	}

	Output << minError << endl;

	return 0;
}