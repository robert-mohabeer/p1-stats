//main.cpp
#include "stats.h"
#include "p1_library.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Enter a filename:\n";
	string filename;
	cin >> filename;
	cout << "Enter a column:\n";
	string col;
	cin >> col;
	cout << "reading column " + col + " from " + filename + "\n";

	vector <double> data = extract_column(filename, col);
	sort(data);

	cout << "\nSummary (value: frequency)" << endl;
	for (size_t x = 0; x < summarize(data).size(); x++)
	{
		cout << summarize(data)[x][0] << ": " << summarize(data)[x][1] << endl;
	}
	cout << "\nCount = " << count(data) << endl;
	cout << "Sum = " << sum(data) << endl;
	cout << "Mean = " << mean(data) << endl;
	cout << "Standard Deviation = " << stdev(data) << endl;
	cout << "Median = " << median(data) << endl;
	cout << "Mode = " << mode(data) << endl;
	cout << "Min = " << min(data) << endl;
	cout << "Max = " << max(data) << endl;

}