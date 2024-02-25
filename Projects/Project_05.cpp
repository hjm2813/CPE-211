#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* argv[])
{
	double a, b, c;
	double S = a + b + c;
	double A = (a + b + b) / 3;
	char label;

	string High;
	string Medium;
	string Low;

	string inFileName;
	string outFileName;

	ifstream infile;
	ofstream outfile;

	



	if (argc != 3)
	{
		cout << endl;
		cout << string(9, '*') << " Command Line Argument Error "
			<< string(9, '*') << endl;
		cout << " ==> Incorrect number of Command Line Arguments!\n";
		cout << "  ==> Command for running the program is : \n";
		cout << " ==> . / Project_05 inputFileName outputFileName\n";
		cout << string(47, '*') << endl << endl;
		return 1;
	}

	inFileName = argv[1];
	cout << "Opening Input file: " << inFileName << endl << endl;



	infile.open(inFileName.c_str());

	if (infile)
	{

		outFileName = argv[2];
		cout << "Opening Output file:" << outFileName << endl << endl;

	}

	infile >> label;
	if (label == 'a')
		infile >> a;
	else if (label == 'b')
		infile >> b;
	else if (label == 'c')
		infile >> c;
	
	else {
		if(outfile.fail())
		{
			cout << string(15, '*' ) << " File Open Error "
				<< string(15, '*') << endl;
			cout << "==> Input file failed to open properly!!\n";
			cout << "==> Attempted to open file: " << inFileName << endl;
			cout << "==> Terminating program!!!\n";
			cout << string(47, '*' ) << endl << endl;
			return 1;
		}

	}
	

	cout << string(45, '*') << endl;
	outfile << "The numbers read are: " << a << b << c << endl;
	outfile << "The sum of the number is: " << S << endl;
	outfile << "The average of these numers is" << A << endl;

	if ((a + b + c) / 3 >= 75) {
		outfile << "The average is " << High << endl;
	}
	else if ((a + b + c) / 3 < 75 || (a + b + c) / 3 >= 75) {
		outfile << "The average is " << Medium << endl;

	}
	else if ((a + b + c) / 3 < 25) {
		outfile << "The average is" << Low << endl;
	}











}