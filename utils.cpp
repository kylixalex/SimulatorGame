#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"

void	displayFile(string filepath)
{
	fstream	fs;
	char		c;

	fs.open(filepath);
	if (!fs)
	{
		cout << "Unable to open file \"" << filepath << "\"." << endl;
		return ;
	}
	while (!fs.eof())
	{
		cout << c;
		fs.get(c);
	}
	fs.close();
}

string	getOption(vector<string> options)
{
	string option;

	while (1)
	{
		cout << "Your option: ";
		cin >> option;
		if (find(options.begin(), options.end(),  option) != options.end())
			return (option);
		else
			cout << "Please insert a valid option!" << endl;
	}
}

int		getNumberBetween(int a, int b)
{
	string	number_string;
	int	number;

	while (1)
	{
		cout << "Your number: ";
		cin >> number_string;
		stringstream ss(number_string);
		ss >> number;
		if (!ss.fail() && (a <= number && number <= b))
			return (number);
		else
			cout << "Please insert a number between " << a << " and " << b << endl;
	}
}