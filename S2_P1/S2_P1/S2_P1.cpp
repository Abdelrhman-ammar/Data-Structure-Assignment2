// S2_P1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isBinary(string number)
{
	int dot = 0;
	for (int counter = 0; counter < number.length(); counter++)
	{
		if (number[counter] == '.' && dot == 0)
		{
			dot++;
			continue;
		}
		else if (isdigit(number[counter]) && (number[counter] == '0' || number[counter] == '1'))
		{
			continue;
		}
		return false;
	}
	return true;
}
double binaryToDicimal(string Binary)
{
	stack<int> setWeight, setWeightDecimal;
	int weight = 0, counter = 0;
	double result = 0;
	for (counter = 0; counter < Binary.length(); counter++)
	{
		if (Binary[counter] == '.')
		{
			counter++;
			break;
		}
		setWeight.push(Binary[counter]);
	}
	for (; counter < Binary.length(); counter++)
	{
		setWeightDecimal.push(Binary[counter]);
	}
	while (!setWeight.empty())
	{
		if (setWeight.top() == '1')
		{
			result += pow(2, weight);
		}
		weight++;
		setWeight.pop();
	}
	weight = setWeightDecimal.size()*-1;
	while (!setWeightDecimal.empty())
	{
		if (setWeightDecimal.top() == '1')
		{
			cout << weight << endl;
			result += pow(2, weight);
		}
		weight++;
		setWeightDecimal.pop();
	}
	return result;
}
int main()
{
	string number;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tConvert Binary To Dicimal" << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "Enter Binary Number:__";
	getline(cin,number);
	while (empty(number) || !isBinary(number))
	{
		cout << "Error: Enter Binary Number Only." << endl;
		getline(cin, number);
	}
	cout << "Decimal Number Equal:__" << binaryToDicimal(number) << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
    return 0;
}