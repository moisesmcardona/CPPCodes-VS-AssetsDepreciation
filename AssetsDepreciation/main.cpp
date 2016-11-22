#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char choice; //saves the user choice to use a specific method or exit the program
	double p, s, n; //p = purchase price of the asset, s = the salvage value for the asset, n = years over which the asset is to be depreciated
	double depreciation; //anual depreciation value.
	double yearendValue; //Year-end Value after N years.
	int yearsum = 0; //sum of years for the sum-of-year method, initialized to 0 in order for the sum to work
	do // runs the program indefinitely until the user enters the letter c
	{
		cout << "MENU" << endl;
		cout << "\ta. Calculate the depreciation of an asset using the straight line method" << endl;
		cout << "\tb. Calculate the depreciation of an asset using the sum of digits method" << endl;
		cout << "\tc. End program" << endl;;
		cin >> choice;
		if (choice == 'a' || choice == 'A') // if the user enters a or A, use the straight line method
		{
			//Data entry
			cout << "Enter the purchase price of the asset: $";
			cin >> p;
			while (p < 0.0)
			{
				cout << "Price of the asset cannot be negative. Please enter it again: ";
				cin >> p;
			}
			cout << "Enter the salvage value for the asset: $";
			cin >> s;
			while (s < 0.0)
			{
				cout << "salvage value for the asset cannot be negative. Please enter it again: ";
				cin >> s;
			}
			cout << "Enter the term in years over which the asset is to be depreciated: ";
			cin >> n;
			while (n < 0.0)
			{
				cout << "term in years cannot be negative. Please enter it again: ";
				cin >> n;
			}
			//Ends data Entry
			//Starts depreciation math
			depreciation = (p - s) / n;
			yearendValue = p; //assigns depreciation value to yearendValue variable to substract between each year.
			cout << "Year\tDepreciation\tYear-end Value" << endl; // shows table headers
			for (int i = 1; i <= n; i++) // for each year, calculate the Year-end value and display
			{
				yearendValue = yearendValue - depreciation; //calculates each year-end value
				cout << setprecision(2) << fixed << showpoint; // number formatting to 2 decimal places
				cout << i << "\t$" << depreciation << "\t$" << yearendValue << endl; // shows the values for each year
			}
		}
		else if (choice == 'b' || choice == 'B') // if the user enters b or B, use the Sum of Digits method
		{
			//Data entry
			cout << "Enter the purchase price of the asset: $";
			cin >> p;
			while (p < 0.0)
			{
				cout << "Price of the asset cannot be negative. Please enter it again: ";
				cin >> p;
			}
			cout << "Enter the salvage value for the asset: $";
			cin >> s;
			while (s < 0.0)
			{
				cout << "salvage value for the asset cannot be negative. Please enter it again: ";
				cin >> s;
			}
			cout << "Enter the term in years over which the asset is to be depreciated: ";
			cin >> n;
			while (n < 0.0)
			{
				cout << "term in years cannot be negative. Please enter it again: ";
				cin >> n;
			}
			//Ends data Entry
			//Starts sum of years
			for (int i = 0; i <= n; i++)
				yearsum = yearsum + i;
			//Ends sum of years
			yearendValue = p; //assigns depreciation value to yearendValue variable to substract between each year.
			cout << "Year\tDepreciation\tYear-end Value" << endl; // shows table headers
			for (double i = 1; i <= n; i++) // for each year, calculate the Year-end value and display
			{
				depreciation = ((n + 1 - i) / yearsum) * (p - s); //calculates the depreciation for each year
				yearendValue = yearendValue - depreciation; //calculates each year-end value
				cout << setprecision(2) << fixed << showpoint; // number formatting to 2 decimal places
				cout << i << "\t$" << depreciation << "\t$" << yearendValue << endl; // shows the values for each year
			}
		}
	} while (choice != 'c' && choice != 'C'); // exits if the user enters c or C.
}
/* OUTPUT 
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
a
Enter the purchase price of the asset: $20000
Enter the salvage value for the asset: $5000
Enter the term in years over which the asset is to be depreciated: 5
Year    Depreciation    Year-end Value
1       $3000.00        $17000.00
2       $3000.00        $14000.00
3       $3000.00        $11000.00
4       $3000.00        $8000.00
5       $3000.00        $5000.00
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
b
Enter the purchase price of the asset: $20000
Enter the salvage value for the asset: $5000
Enter the term in years over which the asset is to be depreciated: 5
Year    Depreciation    Year-end Value
1.00    $5000.00        $15000.00
2.00    $4000.00        $11000.00
3.00    $3000.00        $8000.00
4.00    $2000.00        $6000.00
5.00    $1000.00        $5000.00
MENU
a. Calculate the depreciation of an asset using the straight line method

b. Calculate the depreciation of an asset using the sum of digits method

c. End program
c

*/