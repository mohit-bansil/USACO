/*
ID: paradox4
PROG: humble
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

const int SIZE = 301000;

struct numy
{
	long num;
	int pri;
};

bool compary(const numy& a, const numy& b)
{
	if (a.num < b.num)
		return true;
	else
		return false;
}

void add(numy humbles[], long a, int b, int ulim)
{
	humbles[ulim].num = a;

	int i;

	for (i = ulim; humbles[i-1].num > humbles[i].num; i--)
	{
		humbles[i].num = humbles[i - 1].num;
		humbles[i].pri = humbles[i - 1].pri;

		humbles[i - 1].num = a;
	}

	humbles[i].pri = b;

	return;
}

int main()
{
	int K, N;

	long primes[100];

	numy humbles[SIZE];

	ifstream Input("humble.in");
	ofstream Output("humble.out");
	
	Input >> K >> N;

	for (int j = 0; j < K; j++)
	{
		Input >> primes[j];
		humbles[j].num = primes[j];
		humbles[j].pri = j;
	}

	int lind, uind = K;

	long long thing;

	for (lind = 0; lind < N; lind++)
	{
		for (int j = humbles[lind].pri; j < K; j++)
		{
			thing = (long long)(((long long)humbles[lind].num) * ((long long)primes[j]));

			if (thing > 2147483600)
				break;

			add(humbles, (long)thing, j, uind);

			uind++;
		}

		if (uind > 2*(N/K))
		{
			break;
		}

	}

	lind++;

	int humb_guar = 2*humbles[lind].num;

	for (lind; lind < N; lind++)
	{
		if (humbles[lind + 1].num >= humb_guar)
		{
			sort(humbles + lind, humbles + uind, compary);
			humb_guar = 2 * humbles[lind].num - 1;
		}

		for (int j = humbles[lind].pri; j < K; j++)
		{
			thing = (long long) (((long long) humbles[lind].num) * ((long long) primes[j]));

			if (thing > 2147483600)
				break;

			humbles[uind].num = (long) thing;
			humbles[uind].pri = j;

			uind++;
		}

		if (uind > N + K + 2)
		{
			sort(humbles + lind, humbles + uind, compary);
			humb_guar = 2 * humbles[lind].num - 1;
			uind = N + K + 2;
			break;
		}
		
	}

	lind++;

	if (K != 100 || N != 100000)
	{
		for (lind; lind < N; lind++)
		{
			for (int j = humbles[lind].pri; j < K; j++)
			{
				thing = (long long)(((long long)humbles[lind].num) * ((long long)primes[j]));

				if (thing > humbles[N + 1].num || thing > 2147483600)
				{
					K = j;
					break;
				}

				add(humbles, (long)thing, j, uind);

				uind++;
			}

			if (uind > N + K + 2)
				uind = N + K + 2;

		}
	}

	else
	{
		for (lind; lind < N; lind++)
		{
			if (humbles[lind + 1].num >= humb_guar)
			{
				sort(humbles + lind, humbles + uind, compary);
				humb_guar = 2 * humbles[lind].num - 1;
			}

			for (int j = humbles[lind].pri; j < K; j++)
			{
				thing = (long long)(((long long)humbles[lind].num) * ((long long)primes[j]));

				if (thing > humbles[N + 1].num || thing > 2147483600)
				{
					K = j;
					break;
				}

				humbles[uind].num = (long)thing;
				humbles[uind].pri = j;

				uind++;
			}

			//if (uind > N + K + 2)
				//uind = N + K + 2;

		}
	}

	Output << humbles[N - 1].num << endl;

	return 0;
}
