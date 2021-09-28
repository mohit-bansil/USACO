/*
ID: paradox4
PROG: fc
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int N;

struct vect
{
	double x, y;

	double angle;

	vect()
	{
		x = 0;
		y = 0;
	}

	vect(double a, double b)
	{
		x = a;
		y = b;
	}

	double mags()
	{
		return x*x + y*y;
	}

	vect operator-(const vect& A)
	{
		vect ans;

		ans.x = x - A.x;
		ans.y = y - A.y;

		return ans;
	}
};

double dists(vect a, vect b)
{
	return (a-b).mags();
}

double sAng(vect a, vect b, vect c)
{
	vect aa = b - a;
	vect cc = c - a;

	if (aa.x*cc.y > aa.y*cc.x)
		return 1;
	else if (aa.x*cc.y == aa.y*cc.x)
		return 0;
	else
		return -1;
}

bool comp(vect a, vect b)
{
	if (a.angle > b.angle)
		return true;
	else
		return false;
}

vector<vect> points;

int main()
{
	ifstream Input("fc.in");
	ofstream Output("fc.out");
	
	Input >> N;

	if (N < 2)
	{
		Output << fixed << setprecision(2) << 0 << endl;
		return 0;
	}
	
	points.reserve(10005);

	for (int i = 0; i < N; i++)
	{
		points.push_back(vect());
		Input >> points[i].x >> points[i].y;
	}

	vect center = vect();

	for (int i = 0; i < N; i++)
	{
		center.x += points[i].x / N;
		center.y += points[i].y / N;
	}

	for (int i = 0; i < N; i++)
		points[i].angle = atan2(points[i].y - center.y, points[i].x - center.x);
	
	sort(points.begin(), points.end(), comp);

	vector <vect> hull;

	hull.reserve(10005);

	hull.push_back(points[0]);
	hull.push_back(points[1]);

	for (int i = 2; i < N; i++)
	{
		while (hull.size() >= 2 && sAng(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) >= 0)
		{
			hull.pop_back();
		}

			hull.push_back(points[i]);
	}

	bool flag;

	do
	{
		if (hull.size() <= 2)
		{
			if (hull.size() == 2)
			{
				Output << fixed << setprecision(2) << sqrt((hull[1] - hull[0]).mags()) << endl;
				break;
			}

			else
			{
				Output << fixed << setprecision(2) << 0 << endl;
				return 0;
			}
		}

		flag = false;

		if (sAng(hull[hull.size() - 1], hull[0], hull[1]) >= 0)
		{
			hull.erase(hull.begin());
			flag = true;
		}

		if (sAng(hull[hull.size() - 2], hull[hull.size() - 1], hull[0]) >= 0)
		{
			hull.pop_back();
			flag = true;
		}


	} while (flag);

	double length = 0;

	for (int i = 0; i < hull.size() - 1; i++)
		length += sqrt((hull[i + 1] - hull[i]).mags());

	length += sqrt((hull[0] - hull[hull.size() - 1]).mags());

	Output << fixed << setprecision(2) << length << endl;

	return 0;
}