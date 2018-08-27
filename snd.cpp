
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

// Cumulative distribution function ----->>>>CFD
double normalCFD(double);
double SND();
void _3alpha();

int main() {
	_3alpha();
	SND(); // standardization normal distribution
	getchar();
	return 0;
}


double normalCFD(double value)
{
	return   0.5 * erfc(-value / sqrt(2));
}

double SND() {
	string value = "";
	cout << "\n\t\tRemember, enter non-numeric to exit";
	while (1) {
		cout << "\nvalue: ";
		cin >> value;
		for (auto c :value) {
			if (c == '-' || c == '+')continue;
			if (!isdigit(c))exit(0);
		}
		cout << "\noutput value:" << normalCFD(stoi(value)) << endl;
	}
}


void _3alpha() {
	cout << "\n\t\t1 alpha: " << normalCFD(1) - normalCFD(-1) << endl;
	cout << "\t\t1 alpha: " << normalCFD(2) - normalCFD(-2) << endl;
	cout << "\t\t1 alpha: " << normalCFD(3) - normalCFD(-3) << endl;
}
