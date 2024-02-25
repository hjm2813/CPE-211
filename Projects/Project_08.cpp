#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void InputFile(ifstream& inputFile);
void readValues(ifstream& inputFile, float arr[], int& numValues);
void sortArray(float arr[], int numValues);
void handleInterrupt(int signal);
float Mean(float arr[], int numValues);
float Median(float arr[], int numValues);
float Variance(float arr[], int numValues);

int main() {
    ifstream inputFile;
    InputFile(inputFile);

    const int MAX_VALUES = 50;
    float arr[MAX_VALUES];
    int numValues;

    readValues(inputFile, arr, numValues);

    inputFile.close();

    sortArray(arr, numValues);

    float mean = Mean(arr, numValues);
    float median = Median(arr, numValues);
    float variance = Variance(arr, numValues);
    float standardDeviation = sqrt(variance);

    cout << endl << endl << string (17, '*') << " File Statistics " << string (17, '*') << endl;
    cout << string (51, '*') << endl;
    cout << "Number of Values........." << numValues << endl;
    cout << "Average.................." << mean << endl;
    cout << "Median..................." << median << endl;
    cout << "Variance................." << variance << endl;
    cout << "Standard Deviation......." << standardDeviation << endl;

    return 0;
}

void handleInterrupt(int signal) {
    exit(1);
}

void InputFile(ifstream& inputFile) {
    string filename;
    int signal;
    

    do {
        cout << "Enter the name of the input file (ctrl-c to exit): ";

       
        cin >> filename;

        if (cin.eof()) {
            exit(1);
        }

        cout << filename;

        inputFile.clear();
        inputFile.open(filename);

 

        if (!inputFile.is_open()) {
            cerr << endl << endl << "************** File Open Error **************" << endl;
            cerr << " ==> Input file could not be opened" << endl;
            cerr << " ==> " << filename << " is an invalid file!!" << endl;
            cerr << " ==> Try Again." << endl;
            cerr << string(45, '*') << endl << endl;
        }

            
    } while (!inputFile.is_open());
}



void readValues(ifstream& inputFile, float arr[], int& numValues) {
    inputFile >> numValues;
    if (inputFile.fail() || numValues <= 0 || numValues > 50) {
        cerr << "Invalid input file format." << endl;
        exit(1);
    }
    for (int i = 0; i < numValues; i++) {
        inputFile >> arr[i];
        if (inputFile.fail()) {
            cerr << "Invalid input file format." << endl;
            exit(1);
        }
    }
}

void sortArray(float arr[], int numValues) {
    sort(arr, arr + numValues);
}

float Mean(float arr[], int numValues) {
    float sum = 0;
    for (int i = 0; i < numValues; i++) {
        sum += arr[i];
    }
    return sum / numValues;
}

float Median(float arr[], int numValues) {
    if (numValues % 2 == 0) {
        int mid1 = numValues / 2 - 1;
        int mid2 = numValues / 2;
        return (arr[mid1] + arr[mid2]) / 2;
    }
    else {
        int mid = numValues / 2;
        return arr[mid];
    }
}

float Variance(float arr[], int numValues) {
    float mean = Mean(arr, numValues);
    float sum = 0;
    for (int i = 0; i < numValues; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sum / numValues;
}
