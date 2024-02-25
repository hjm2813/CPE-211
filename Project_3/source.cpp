#include <iostream>
#include <iomanip>
#include<string>

using namespace std;


int main() {

	string Stock;  
	int number;  
	float buy;   
	float sell;  

	

	cout << string(25, '*' ) << endl;
	cout << "Stock Calculations" << endl;
	cout << string(25, '*') << endl;


	

	cout << "Enter the name of the stock: ";
	cin >> Stock;
	cout << Stock << endl;
	
	cout << "Enter the number of shares purchased: ";
	cin >> number;
	cout << left  << number << endl;

	cout << "Enter the buy price per share: ";
	cin >> buy;
	cout << left <<fixed << showpoint << setprecision(2) << buy << endl;


	cout << "Enter the sell price per share: ";
	cin >> sell;
	cout << left << fixed << showpoint << setprecision(2) << sell << endl;

	cout << "Results for " << left<< fixed << number  << " shares of " << Stock << ":" <<endl;
	cout << string (35, '-') << endl;


	float buycommission = (buy * number) * (2.00 / 100);        
	float total = (buy*number) + buycommission;                 
	float sellcommission = (sell * number) * (1.50 / 100);     
	float returning = (sell * number) - sellcommission;         
	float net = returning - total;                            
	float tax = net * (25.0 / 100);                             

	cout << "Buy Commission......" << "$" <<buycommission << endl;
	cout << "Total cost" << string(10, '.') << "$" << total << endl;
	cout << "Sell Commission" << string(5, '.') << "$" << sellcommission << endl;
	cout << "Total return" << string(8, '.') << "$" << returning << endl;
	cout << "Net Profit/Loss" << string(5, '.') << "$" << net << endl;
	cout << "Tax/Credit" << string(10, '.') << "$" << tax << endl;

}
