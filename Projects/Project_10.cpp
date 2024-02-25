#ifndef P10_HEADER
#define P10_HEADER

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
private:
    int pennies;
    int nickels;
    int dimes;
    int quarters;


protected:

public:
    Money();
    Money(int, int, int, int);
    Money(int, int, int);
    Money(int, int);
    Money(int);

    void SetMoney(int, int, int, int);
    void AddMoney(int, int, int, int);
    void AddMoney(int, int, int);
    void AddMoney(int, int);
    void AddMoney(int);

    void WriteCoinTotals() const;
    void WriteDollarTotal() const;
};

#endif

// Project_10.cpp implementation file



Money::Money()
{
    pennies = nickels = dimes = quarters = 0;
}

Money::Money(int p, int n, int d, int q)
{
    pennies = p;
    nickels = n;
    dimes = d;
    quarters = q;
}

Money::Money(int p, int n, int d)
{
    pennies = p;
    nickels = n;
    dimes = d;
    quarters = 0;
}

Money::Money(int p, int n)
{
    pennies = p;
    nickels = n;
    dimes = quarters = 0;
}

Money::Money(int p)
{
    pennies = p;
    nickels = dimes = quarters = 0;
}

void Money::SetMoney(int p, int n, int d, int q)
{
    pennies = p;
    nickels = n;
    dimes = d;
    quarters = q;
}

void Money::AddMoney(int p, int n, int d, int q)
{
    pennies += p;
    nickels += n;
    dimes += d;
    quarters += q;
}

void Money::AddMoney(int p, int n, int d)
{
    pennies += p;
    nickels += n;
    dimes += d;
}

void Money::AddMoney(int p, int n)
{
    pennies += p;
    nickels += n;
}

void Money::AddMoney(int p)
{
    pennies += p;
}

void Money::WriteCoinTotals() const
{
    cout << "Number of Pennies: " << pennies << endl;
    cout << "Number of Nickles: " << nickels << endl;
    cout << "Number of Dimes: " << dimes << endl;
    cout << "Number of Quarters: " << quarters << endl;
}

void Money::WriteDollarTotal() const
{
    double total = pennies * 0.01 + nickels * 0.05 + dimes * 0.1 + quarters * 0.25;
    cout << fixed << setprecision(2);
    cout << "The dollar amount of the coins is: $" << total << endl;
}

// Project_10_main.cpp driver file



int main()
{

    // construct 5 objects of the class - one using 
    // default values, and the others using paramertized constructors
    //
    cout << "Constructor Test\n";
    cout << "----------------\n";
    cout << "      Default Constructor\n";
    Money purse1;
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    cout << "      Parameterized Constructor(4 arguments)\n";
    Money purse2(6, 5, 4, 3);
    purse2.WriteCoinTotals();
    purse2.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    cout << "      Parameterized Constructor(3 arguments)\n";
    Money purse3(16, 15, 14);
    purse3.WriteCoinTotals();
    purse3.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    cout << "      Parameterized Constructor(2 arguments)\n";
    Money purse4(26, 76);
    purse4.WriteCoinTotals();
    purse4.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    cout << "      Parameterized Constructor(1 argument)\n";
    Money purse5(90);
    purse5.WriteCoinTotals();
    purse5.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    // verifying SetMoney function
    cout << string(40, '*') << endl;
    cout << "Set Money Test\n";
    cout << "-------------\n";
    purse1.SetMoney(0, 6, 20, 10);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl << endl;

    // Test the output for correct purse and month
    // formatting

    cout << string(40, '*') << endl << endl;
    cout << "Testing Add Money Methods\n";
    cout << "-------------------------\n";

    cout << "    Initial Amount\n";
    purse1.SetMoney(0, 0, 0, 0);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;

    cout << "    add 10 pennies, 5 nickels, 7 dimes, 20 quarters\n";
    purse1.AddMoney(10, 5, 7, 20);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;

    cout << "    add 15 pennies, 15 nickels, 27 dimes\n";
    purse1.AddMoney(15, 15, 27);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;

    cout << "    add 33 pennies, 22 nickels\n";
    purse1.AddMoney(33, 22);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;

    cout << "    add 75 pennies\n";
    purse1.AddMoney(75);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;

    cout << "    add 0 pennies, 17 nickels, 0 dimes, 29 quarters\n";
    purse1.AddMoney(0, 17, 0, 29);
    purse1.WriteCoinTotals();
    purse1.WriteDollarTotal();
    cout << string(40, '*') << endl;


    return 0;
}