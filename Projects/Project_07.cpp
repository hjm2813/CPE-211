#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// Function prototypes
void printMenu();
int getMenuChoice();
bool openInputFile(ifstream& inFile);
void processFile(int choice, ifstream& inFile, int& numLines, int& numChars);

int main() {
    int choice, numLines, numChars;
    string fileName;
    ifstream inFile;

    do {
        printMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 0:
            cout << "Quit selected.   Terminating program now..." << endl;
            break;
        case 1:
        case 2:
            if (openInputFile(inFile)) {
                numLines = numChars = 0;
             
                processFile(choice, inFile, numLines, numChars);
                
                if (choice == 1) {
                    cout << endl << "Counting Number of Vowels" << endl;
                    cout << string(45, '*') << endl;
                    cout << "There are " << numChars << "vowels in the file" << endl;
                    cout << "There are " << numLines << " lines in the file" << endl;
                    cout << "This is an average of " << left << setprecision(3) << (numChars / numLines) << " wowels per line" << endl;
                    cout << string(45, '*') << endl << endl;

                    inFile.close();
                    break;
                }
                else
                    cout << endl << "Counting Number of Consonants" << endl;
                    cout << string(45, '*') << endl;
                    cout << "There are " << numChars << " consonants in the file" << endl;
                    cout << "There are " << numLines << " lines in the file" <<  endl;
                    cout << "This is an average of " << left << setprecision(3) << (numChars / numLines) << " consonants per line" << endl;
                    cout << string(45, '*') << endl << endl;
                    inFile.close();
                    break;
            }
            else {
                if (inFile.fail()) {
                    cout << endl << string(14, '*') << "File Open Error" << string(14, '*') << endl;
                    cout << "==> Input file failed to open properly!! " << endl;
                    cout << "==> Attempted to open file: " << fileName << endl;
                    cout << "==> Selected operation has been canceled " << endl;
                    cout << "***********************************************" << endl;
                }
                inFile.close();
                break;

                if (inFile.eof()) {
                    cout << endl << string(15, '*') << "  File Is Empty  " << string(15, '*') << endl;
                    cout << "==> Input file is empty" << endl;
                    cout << "==> No information to process" << endl;
                    cout << "***********************************************" << endl;
                }
                inFile.close();
                break;
            }
        default:
            if (choice > 2 ||  choice < 0) {

                cout << endl << string(13, '*') << " Invalid Selection" << string(13, '*') << endl;
                cout << "==> Invalid integer entered!!" << endl;
                cout << "==> Please enter 0, 1 or 2 " << endl;
                cout << "***********************************************" << endl << endl;
            }
            
        }
    } while (choice != 0);

    return 0;
}

// Function definitions

void printMenu() {
    cout << string(18, '*') << " Options " << string(18, '*') << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Count number of vowels" << endl;
    cout << "2. Count number of consonants" << endl;
    cout << string(45, '*') << endl << endl;
}

int getMenuChoice() {
    int choice;
    cout << "Input your selection: ";
    cin >> choice;
    cout << choice << endl;
    return choice;
}

bool openInputFile(ifstream& inFile) {
    string fileName;
    cout << "Enter the name of the input file now: ";
    cin >> fileName;
    cout << fileName << endl;
    inFile.open(fileName.c_str());
    return inFile.good();

}

void processFile(int choice, ifstream& inFile, int& numLines, int& numChars) {
    string line;
    char c;
    bool isVowel;

    while (getline(inFile, line)) {
        numLines++;
        for (int i = 0; i < line.length(); i++) {
            c = tolower(line[i]);
            if (isalpha(c)) {
                isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
                if (choice == 1 && !isVowel) {
                    numChars++;
                }
                else if (choice == 2 && isVowel) {
                    numChars++;
                }
            }
        }
    }
}
