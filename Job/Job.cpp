/*
ID: paradox4
PROG: job
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<assert.h>

using namespace std;

const int LARGE = 1147483647;

int N, M1, M2;

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

struct B_mac
{
	int p_time;

	int queue;

	int n_com_time;

	int time_till_loss;

	bool can_use;
};

int A[32];
B_mac B[32];

int timea = 0;
int A_count = 0;
int B_count = 0;

void updateB(int i)
{
	if (B[i].time_till_loss > 0)
		B[i].time_till_loss--;
	else
		B[i].time_till_loss = B[i].p_time - 1;

	if (B[i].queue == 0)
		return;

	if (B[i].n_com_time == timea)
	{
		B_count++;
		B[i].queue--;

		if (B[i].queue > 0)
		{
			B[i].n_com_time = timea + B[i].p_time;
		}
	}
}

int minB()
{
	int mina = LARGE;
	int min_index = 0;

	for (int i = 0; i < M2; i++)
	{
		if (!B[i].can_use)
			continue;

		if (B[i].time_till_loss < mina)
		{
			mina = B[i].time_till_loss;
			min_index = i;
		}
	}

	return min_index;
}

void doStuff()
{
	int in = minB();

	B[in].time_till_loss += B[in].p_time;
	B[in].queue++;

	if (B[in].queue == 1)
	{
		B[in].n_com_time = timea + B[in].p_time;
	}
}

void intilizeB(int test_timea)
{
	A_count = 0;
	B_count = 0;

	for (int i = 0; i < M2; i++)
	{
		B[i].queue = 0;
		B[i].n_com_time = 0;

		B[i].time_till_loss = test_timea % B[i].p_time;

		if (test_timea >= B[i].p_time)
			B[i].can_use = true;
		else
			B[i].can_use = false;
	}
}

int main()
{
	ifstream Input("job.in");
	ofstream Output("job.out");

	Input >> N >> M1 >> M2;

	for (int i = 0; i < M1; i++)
		Input >> A[i];

	for (int i = 0; i < M2; i++)
	{
		Input >> B[i].p_time;
	}

	bool A_done = false;

	int test_time = 1;

	int sum;

	while (true)
	{
		sum = 0;

		for (int j = 0; j < M2; j++)
			sum += (int)(test_time / B[j].p_time);

		if (sum >= N)
			break;

		test_time++;
	}

	for (test_time; test_time < 100000; test_time++)
	{
		intilizeB(test_time);
		
		for (timea = 0; timea < test_time; timea++)
		{
			for (int j = 0; j < M2; j++)
				updateB(j);

			for (int j = 0; j < M1; j++)
			{
				if (timea % A[j] == 0 && timea != 0)
				{
					A_count++;

					doStuff();
				}

				if (A_count >= N && !A_done)
				{
					Output << timea << " ";
					A_done = true;
				}
			}
		}

		if (B_count >= N)
			break;
	}
	
	Output << test_time - 1 << endl;

	return 0;
}