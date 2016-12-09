
#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
struct Train
{
	long long r, s, e;
};
bool compare2(Train a, Train b)
{
	if (a.r == b.r)
	{
		if (a.s == b.s)
		{
			return a.e > b.e;
		}
		return  a.s < b.s;
	}
	return a.r < b.r;
}
int main()
{
	long long n, m, k, count=0;
	Train t[1001], prevTrain;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> t[i].r >> t[i].s >> t[i].e;
	}	
	std::sort(t, t + k, compare2);
	prevTrain.r = -1;
	for (int i = 0; i < k; i++)
	{
		cout << t[i].r <<"  "<< t[i].s << "  "<<t[i].e << endl;
	}
	for (int i=0; i<k;i++)
	{
		int element = t[i].r;
		if (t[i].r == prevTrain.r)
		{
			if (t[i].s > prevTrain.e)
			{
				count += (t[i].e - t[i].s+1);
			}
			else if(t[i].e>prevTrain.e)
			{
				count += (t[i].e - prevTrain.e);
			}
			if(t[i].e>prevTrain.e)
				prevTrain.e = t[i].e;
		}
		else
		{
			count += (t[i].e - t[i].s+1);
			prevTrain = t[i];
		}
	}
	cout << m*n-count << endl;
}
