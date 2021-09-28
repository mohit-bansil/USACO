/*
ID: paradox4
PROG: heritage
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string f(string pre, string in)
{
	if (in.length() <= 1)
		return in;
	
	int root_loc = in.find_first_of(pre[0]);
	
	string a (in.begin(), in.begin() + root_loc);
	string b (in.begin() + root_loc + 1, in.end());

	string c (pre, 1, a.length());
	string d (pre, a.length() + 1, b.length());

	return f(c, a) + f(d, b) + pre[0];
}

int main()
{
	ifstream Input("heritage.in");
	ofstream Output("heritage.out");
	
	string in_or, pre_or, post_or;

	Input >> in_or >> pre_or;

	post_or = f(pre_or, in_or);

	Output << post_or << endl;
	
	return 0;
}