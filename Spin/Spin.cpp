/*
ID: paradox4
PROG: spin
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

struct wheel 
{
	int speed;
	bool wedge[360];
};

wheel wheels[5];

int main()
{
	ifstream Input;
	ofstream Output;

	Input.open("spin.in");
	Output.open("spin.out");

	int num, start, extent;

	for (int i = 0; i < 5; i++)
	{
		Input >> wheels[i].speed;

		Input >> num;

		for (int j = 0; j < num; j++)
		{
			Input >> start >> extent;

			for (int k = 0; k <= extent; k++)
					wheels[i].wedge[(k + start) % 360] = true;
		}
	}

	bool bad;
	int x;


	for (int i = 0; i < 360; i++)
	{
		for (int k = 0; k < 360; k++)
		{
			bad = false;

			for (int j = 0; j < 5; j++)
			{
				x = wheels[j].speed*i % 360;

				if (!wheels[j].wedge[((k - x + 720) % 360)])
				{
					bad = true;
					break;
				}
			}

			if (!bad)
			{
				Output << i << endl;

				return 0;
			}
		}
	}

	Output << "none" << endl;

	return 0;
}