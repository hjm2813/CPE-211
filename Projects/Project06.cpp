#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cctype>

using namespace std;

const int COL1 = 3;
const int COL2 = 12;
const int COL3 = 7;
const int COL4 = 6;
const int COL5 = 6;
const int COL6 = 6;
const int COL7 = 7;
const int COL8 = 7;

int main(int argc, char* argv[])
{
	if (argc != 3) {

		cout << endl << string(9, '*') << "Command Line Argument Error" << string(9, '*') << endl;
		cout << "==> Incorrect number of Command Line Arguments!\n";
		cout << "==> Command for running the program is:\n";
		cout << "==>./Project_06 InputFileName OutputFileName\n";
		cout << string(47, '*') << endl << endl;
		return 1;
	}

	ifstream inFile;
	ofstream outFile;

	string filename;

	// variables for data
	string last;
	string first;
	int holder = 0;
	int quiz = 0; //sum
	int hw = 0; //sum
	int exam = 0; //sum
	int total = 0; //sum
	float avg = 0;
	float class_avg = 0;
	int quizcount = 0;
	int hwcount = 0;
	int examcount = 0;



	char ch;          //single character read from the input file

	filename = argv[1];
	cout << "\nOpening Input File...\n\n";
	inFile.open(filename);

	while (inFile.fail()) {
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << " ==> Input file failed to open properly!!\n";
		cout << " ==> Attempted to open file " << filename << endl;
		cout << "Please try again..." << endl;
		cout << string(47, '*') << endl << endl;

		inFile.clear();
		cout << "Enter in the name of the input file: ";
		cin >> filename;
		cout << filename << endl << endl;

		inFile.open(filename);
	}

	filename = argv[2];
	cout << "Opening the outputfile...\n\n";

	outFile.open(filename);

	while (outFile.fail()) {
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "== > Output file failed to open properly!!\n";
		cout << "==> Attempted to open file : " << filename << endl;
		cout << "==> Please try again..." << endl;
		cout << string(47, '*') << endl << endl;

		outFile.clear();
		cout << "Enter in the name of the output file: ";
		cin >> filename;
		cout << filename << endl << endl;

		outFile.open(filename);
	}

	if (inFile.eof()) {
		cout << string(13, '*') << " Input File is Empty " << string(13, '*') << endl;
		cout << "==> The input file is empty.\n";
		cout << "==> Terminating the program.\n";
		cout << string(47, '*') << endl << endl;

		outFile << string(13, '*') << " input File is Empty " << string(13, '*') << endl;
		outFile << "==> The input file is empty.\n";
		outFile << "==> Terminating the program.\n";
		outFile << string(47, '*') << endl << endl;
		return 1;
	}


	outFile << left << setw(COL1) << "#" << setw(COL2) << "Last" << setw(COL3) << "First" << setw(COL4) << "Quiz"
		<< setw(COL5) << "HW" << setw(COL6) << "EXAM" << setw(COL7) << "Total" << setw(COL8) << "Average" << endl;

	outFile << setw(COL1) << "_" << setw(COL2) << "__________" << setw(COL3) << "_____" << setw(COL4) << "____"
		<< setw(COL5) << "___" << setw(COL6) << "____" << setw(COL7) << "_____" << setw(COL8) << "_______" << endl;

	if (!inFile.fail()) {

		cout << "file error" << endl;
		inFile >> quizcount >> hwcount >> examcount;
		cout << quizcount << " " << hwcount << " " << examcount << endl;
		inFile >> last >> first;

		for (int i = 0; i < quizcount; i++)
		{
			inFile >> holder;
			quiz += holder;
		}

		for (int i = 0; i < hwcount; i++)
		{
			inFile >> holder;
			hw += holder;
		}

		for (int i = 0; i < examcount; i++)
		{
			inFile >> holder;
			exam += holder;
		}

		total = quiz + exam + hw;
		avg = float(total) / float(quiz + hw + exam);

		outFile << left << setw(COL1) << " " << setw(COL2) << last << setw(COL3) << first << setw(COL4) << quiz
			<< setw(COL5) << hw << setw(COL6) << exam << setw(COL7) << total << setw(COL8) << setprecision(2) << avg << endl;

		outFile << setw(COL1) << "_" << setw(COL2) << "__________" << setw(COL3) << "_____" << setw(COL4) << "____"
			<< setw(COL5) << "___" << setw(COL6) << "____" << setw(COL7) << "_____" << setw(COL8) << "_______";

		int linecount = 0;

		while (!inFile.eof())
		{
			// resetting for each time the while loops
			int quiz = 0; //sum
			int hw = 0; //sum
			int exam = 0; //sum
			int total = 0; //sum
			float avg = 0;

			linecount++;

			inFile >> last >> first;

			if (last.length() > COL1)
			{
				// make the name into an array, and output a name array instead of a string
			}

			if (first.length() > COL2)
			{
				// make the name into an array, and output a name array instead of a string
			}

			for (int i = 0; i < quizcount; i++)
			{
				inFile >> holder;
				quiz += holder;
			}

			for (int i = 0; i < hwcount; i++)
			{
				inFile >> holder;
				hw += holder;
			}

			for (int i = 0; i < examcount; i++)
			{
				inFile >> holder;
				exam += holder;
			}

			total = quiz + exam + hw;
			avg = float(total) / float(quiz + hw + exam);

			class_avg += avg;

			outFile << endl << left << fixed << setw(COL1) << linecount << setw(COL2) << last << setw(COL3) << first << setw(COL4) << quiz
				<< setw(COL5) << hw << setw(COL6) << exam << setw(COL7) << total << setw(COL8) << setprecision(2) << avg;
		}

		class_avg /= float(linecount);

		outFile << endl << setw(COL1) << "_" << setw(COL2) << "__________" << setw(COL3) << "_____" << setw(COL4) << "____"
			<< setw(COL5) << "___" << setw(COL6) << "____" << setw(COL7) << "_____" << setw(COL8) << "_______" << endl << endl;

		outFile << "Class Average = " << setprecision(2) << class_avg << endl;
	}

	return 0;
}
