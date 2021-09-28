/*
ID: paradox4
PROG: combo
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

void fixArray(int thing[], int N)
{
	for (int i = 0; i < 3; i++)
	{
		thing[i] = abs(thing[i]);

		if (thing[i] > abs(thing[i] - N))
			thing[i] -= N;

		thing[i] = abs(thing[i]);
	}
}

int main()
{
	ifstream Input("combo.in");
	ofstream Output("combo.out");
	
	int N;
	int comb1[3], comb2[3], lock[3];

	Input >> N;
	Input >> comb1[0] >> comb1[1] >> comb1[2];
	Input >> comb2[0] >> comb2[1] >> comb2[2];

	lock[0] = comb2[0] - comb1[0];
	lock[1] = comb2[1] - comb1[1];
	lock[2] = comb2[2] - comb1[2];

	fixArray(lock, N);

	int doubleCombos = 1;

	for (int i = 0; i < 3; i++)
		doubleCombos *= 5 - lock[i];
	
	if (doubleCombos < 0)
		doubleCombos = 0;

	int totalCombos = 125;
	
	if (N < 5)
		Output << N * N * N << endl;

	else
		Output << 2 * totalCombos - doubleCombos << endl;

	return 0;
}