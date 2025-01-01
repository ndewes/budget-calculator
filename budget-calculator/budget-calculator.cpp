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

int main() {
    bool exitProgram = false;
    std::vector<FixCosts> fixCosts; // Fixkosten auﬂerhalb der Schleifen deklarieren

    while (!exitProgram) {
        int mainChoice;

        std::cout << "--- Welcome to your Budget Calculator ---\n";
        std::cout << "1. See current data\n";
        std::cout << "2. Edit your data\n";
        std::cout << "3. Save your data\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;

        switch (mainChoice) {
        case 1: {
            std::cout << "Test\n"; // Testausgabe, hier sollten deine Daten angezeigt werden
            break;
        }
        case 2: {
            bool backToMain = false;

            while (!backToMain) {
                int secChoice;

                std::cout << "Your current income is: 1000\n"; // Variables Einkommen integrieren

                std::cout << "\n--- Fix Costs Calculator ---\n";
                std::cout << "1. Add Fix Costs\n";
                std::cout << "2. Remove Fix Costs\n";
                std::cout << "3. Display Fix Costs\n";
                std::cout << "4. Edit income\n"; // Diese Option ist noch nicht implementiert
                std::cout << "5. Edit Fix Costs\n";
                std::cout << "6. Calculate Fix Costs\n";
                std::cout << "0. Back\n";
                std::cout << "Enter your choice: ";
                std::cin >> secChoice;

                switch (secChoice) {
                case 1: {
                    std::string name;
                    double cost;
                    std::cout << "Enter the name of the fix cost: ";
                    std::cin >> name;
                    std::cout << "Enter the cost of the fix cost: ";
                    std::cin >> cost;
                    addFixCost(fixCosts, name, cost);
                    break;
                }
                case 2: {
                    std::string name;
                    std::cout << "Enter the name of the fix cost you want to remove: ";
                    std::cin >> name;
                    removeFixCost(fixCosts, name);
                    break;
                }
                case 3: {
                    displayFixCosts(fixCosts);
                    break;
                }
                case 4: {
                    double income;
                    std::cout << "Enter your new income: ";
                    std::cin >> income;
                    // Einkommen aktualisieren (noch nicht implementiert)
                    break;
                }
                case 5: {
                    std::string name;
                    double cost;
                    std::cout << "Enter the name of the fix cost you want to edit: ";
                    std::cin >> name;
                    std::cout << "Enter the new cost of the fix cost: ";
                    std::cin >> cost;
                    editFixCost(fixCosts, name, cost);
                    break;
                }
                case 6: {
                    std::cout << "The total fix costs are: " << calculateFixCosts(fixCosts) << std::endl;
                    break;
                }
                case 0: {
                    backToMain = true; // Zur¸ck ins Hauptmen¸
                    break;
                }
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            // Save functionality (noch nicht implementiert)
            std::cout << "Data saved (placeholder).\n";
            break;
        }
        case 0: {
            std::cout << "Exiting program...\n";
            exitProgram = true; // Programm beenden
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}