/*
ID: paradox4
PROG: contact
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int A, B, N;

int freq[13][4100];

int ranker(string in_code)
{
	int answer = 0;

	int power = 1;

	for (int i = in_code.length() - 1; i >= 0; i--)
	{
		if (in_code[i] == '1')
			answer += power;

		power *= 2;
	}

	return answer;
}

string unranker(int in_num, int length)
{
	string answer = "";

	for (int i = 0; i < length; i++)
	{
		if (in_num % 2 == 0)
			answer = "0" + answer;
		else
			answer = "1" + answer;

		in_num /= 2;
	}

	return answer;
}

int main()
{
	ifstream Input;
	ofstream Output;

	Input.open("contact.in");
	Output.open("contact.out");

	Input >> A >> B >> N;

	string message = "";

	string current;

	while (!Input.eof())
	{
		Input >> current;

		if (Input.eof())
			break;

		message += current;
	}

	int length = message.length();

	for (int i = A; i <= B; i++)
	{
		if (length < i)
			break;

		current = message.substr(0, i);

		for (int j = i; j < length; j++)
		{
			freq[i][ranker(current)]++;
			current.erase(current.begin());
			current += message[j];
		}

		freq[i][ranker(current)]++;
	}

	int max , counter, total;

	for (int i = 0; i < N; i++)
	{
		max = 0;
		counter = 0;
		total = 0;

		for (int j = A; j <= B; j++)
		{
			for (int k = 0; k < 4100; k++)
			{
				if (freq[j][k] > max)
					max = freq[j][k];
			}
		}

		for (int j = A; j <= B; j++)
		{
			for (int k = 0; k < 4100; k++)
			{
				if (freq[j][k] == max)
					total++;
			}
		}

		if (max == 0)
			break;

		Output << max << endl;

		for (int j = A; j <= B; j++)
		{
			for (int k = 0; k < 4100; k++)
			{
				if (freq[j][k] == max)
				{
					if (counter % 6 == 0 && counter != 0)
						Output << endl;

					if (counter == total - 1 || counter % 6 == 5)
						Output << unranker(k, j);
					else
						Output << unranker(k, j) << " ";

					freq[j][k] = 0;

					counter++;
				}
			}
		}

		Output << endl;
	}

	return 0;

}