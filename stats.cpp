#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<vector<double> > summarize(vector<double> v) {
	assert(!v.empty());
	double repeat = 1;
	vector <vector<double>> summary;
	for (size_t x = 1; x < v.size(); x++)
	{
		if (x == v.size() - 1)
		{
			if (v[x - 1] == v[x])
			{
				summary.push_back({v[x], repeat+1});
			}
			else
			{
				summary.push_back({ v[x - 1], repeat });
				summary.push_back({v[x], 1});
			}
		}
		else if (v[x - 1] == v[x])
		{
			repeat++;
		}
		else
		{
			summary.push_back({ v[x - 1], repeat });
			repeat = 1;
		}
	}
	return summary;  // avoid Visual Studio error "function must return a value"
}

int count(vector<double> v) {
	assert(!v.empty());
	return v.size();  // avoid Visual Studio error "function must return a value"
}

double sum(vector<double> v) {
	assert(!v.empty());
	double sum = 0;
	for (size_t x = 0; x < v.size(); x++)
	{
		sum += v[x];
	}
	return sum;  // avoid Visual Studio error "function must return a value"
}

double mean(vector<double> v) {
	assert(!v.empty());
	double mean = sum(v) / count(v);
	return mean;  // avoid Visual Studio error "function must return a value"
}

double median(vector<double> v) {
	assert(!v.empty());
	int len = v.size();
	double mid = 0;
	if (len % 2 == 0)
	{
		mid = (v[(len / 2) - 1] + v[len / 2]) / 2;
	}
	else
	{
		mid = v[(len - 1) / 2];
	}
	return mid;  // avoid Visual Studio error "function must return a value"
}

double mode(vector<double> v) {
	assert(!v.empty());
	double common = v[0];
	int times;
	int record = 0;
	for (size_t x = 0; x < v.size(); x++)
	{
		times = 0;
		for (size_t y = 0; y < v.size(); y++)
		{
			if (v[x] == v[y])
			{
				times++;
			}
		}
		if (times > record)
		{
			record = times;
			common = v[x];
		}
	}
	return common;  // avoid Visual Studio error "function must return a value"
}

double min(vector<double> v) {
	assert(!v.empty());
	double small = v[0];
	for (size_t x = 0; x < v.size(); x++)
	{
		if (v[x] < small)
		{
			small = v[x];
		}
	}
	return small;  // avoid Visual Studio error "function must return a value"
}

double max(vector<double> v) {
	assert(!v.empty());
	double big = v[0];
	for (size_t x = 0; x < v.size(); x++)
	{
		if (v[x] > big)
		{
			big = v[x];
		}
	}
	return big;  // avoid Visual Studio error "function must return a value"
}

double stdev(vector<double> v) {
	assert(v.size() >= 2);
	double average = mean(v);
	vector <double> diffMean;
	for (size_t x = 0; x < v.size(); x++)
	{
		diffMean.push_back(pow(v[x] - average, 2));
	}
	return sqrt(sum(diffMean)/(diffMean.size()-1)); // avoid Visual Studio error "function must return a value"
}

double percentile(vector<double> v, double p) {
	assert(!v.empty());

	return 0;  // avoid Visual Studio error "function must return a value"
}