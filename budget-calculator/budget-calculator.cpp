// budget-calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

struct FixCosts
{
	std::string name;
	double cost;
};

void addFixCost(std::vector<FixCosts>& fixCosts, std::string name, double cost)
{
	FixCosts fixCost;
	fixCost.name = name;
	fixCost.cost = cost;
	fixCosts.push_back(fixCost);
}

void removeFixCost(std::vector<FixCosts>& fixCosts, std::string name)
{
	for (int i = 0; i < fixCosts.size(); i++)
	{
		if (fixCosts[i].name == name)
		{
			fixCosts.erase(fixCosts.begin() + i);
			break;
		}
	}
}

void displayFixCosts(std::vector<FixCosts>& fixCosts)
{
	for (int i = 0; i < fixCosts.size(); i++)
	{
		std::cout << fixCosts[i].name << " " << fixCosts[i].cost << std::endl;
	}
}

void editFixCost(std::vector<FixCosts>& fixCosts, std::string name, double cost)
{
	for (int i = 0; i < fixCosts.size(); i++)
	{
		if (fixCosts[i].name == name)
		{
			fixCosts[i].cost = cost;
			break;
		}
	}
}

double calculateFixCosts(std::vector<FixCosts>& fixCosts)
{
	double total = 0;
	for (int i = 0; i < fixCosts.size(); i++)
	{
		total += fixCosts[i].cost;
	}
	return total;
}

double calculateVar(double income, double expenses)
{
	return income - expenses;
}

double calculateInvest(double income, double expenses)
{
	return income - expenses;
}

double calulateSavings(double income, double expenses)
{
	return income - expenses;
}

double calculatePercentage(double income, int percent)
{
	return income * percent / 100;
}

int main()
{
	std::vector<FixCosts> fixCosts;
	double income;

	std::cout << "Enter your income: ";
	std::cin >> income;

	int auswahl;
	do
	{
		std::cout << "\n---Fix Costs Calculator---\n";
		std::cout << "1. Add Fix Costs\n";
		std::cout << "2. Remove Fix Costs\n";
		std::cout << "3. Display Fix Costs\n";
		std::cout << "4. Edit Fix Costs\n";
		std::cout << "5. Calculate Fix Costs\n";
		std::cout << "0. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> auswahl;

		switch (auswahl)
		{
		case 1:
		{
			std::string name;
			double cost;
			std::cout << "Enter the name of the fix cost: ";
			std::cin >> name;
			std::cout << "Enter the cost of the fix cost: ";
			std::cin >> cost;
			addFixCost(fixCosts, name, cost);
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "Enter the name of the fix cost you want to remove: ";
			std::cin >> name;
			removeFixCost(fixCosts, name);
			break;
		}
		case 3:
		{
			displayFixCosts(fixCosts);
			break;
		}
		case 4:
		{
			std::string name;
			double cost;
			std::cout << "Enter the name of the fix cost you want to edit: ";
			std::cin >> name;
			std::cout << "Enter the new cost of the fix cost: ";
			std::cin >> cost;
			editFixCost(fixCosts, name, cost);
			break;
		}
		case 5:
		{
			std::cout << "The total fix costs are: " << calculateFixCosts(fixCosts) << std::endl;
			break;
		}
		case 0:
		{
			break;
		}

		}
	} while (auswahl != 0);

	return 0;
}