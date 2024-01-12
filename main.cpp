/*
	Output
	Input
	Conditions
	Loops
	Functions
		Definition / Heading
		Prototype

	30 mins mark
*/

/*  Note:
		I'm not using "using namespace std;".
		I'm using Prototype Function
*/

/* Rules & Principles:
		Naming Conventions:
			constant variable - Upper Snake Case
				ex. const int VARIABLE_NAME = 0;
			variable - Camel Case
				ex. int variableName;
					int variableNameThisIs;
			user defined functions - Pascal Case
				ex. void FunctionName();
		Naming - Name should make sense on what it should do;
		DRY - Don't Repeat Yourself
		Single Responsibility Principle - One function must do one job
		Contruction of Code:
			return_type FunctionName()
			{
				contant variable

				variable

				code
			}
		Don't use Global Variable
*/

// The User can input 2 values then choice from MDAS.
// The user will check first what arithmetic to use before calculation.
// The user want to use the application continuesly without restarting the application at the same time can be 
//		exited anytime or after transaction
// Also due to users demand many user sometimes makes mistake and entering invalid number.
//		Application should catch error, remind user and loop back

// as practice you should divide the code in functions making the function main() as short as possible and readable
// also apply dry principle
// note: comments are not counted as line of code and readable oneliner is still one liner code

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

int MainMenu();
bool ExitMenu();
double InputValue();
void Result(double, std::string);
double Add(double, double);
double Division(double, double);
double Subraction(double, double);
double Multiplication(double, double);
void History(std::string action[5], std::string values[5][3]);

int main()
{
	std::string historyAction[5];
	std::string historyValues[5][3];
	int counter = 0;

	do
	{
		switch (MainMenu())
		{
		case 0:
			exit(0);
		case 1:
			historyAction[counter] = "Addition";

			historyValues[counter][0] = std::to_string(InputValue());
			historyValues[counter][1] = std::to_string(InputValue());
			historyValues[counter][2] = std::to_string(Add(
				std::stod(historyValues[counter][0]),
				std::stod(historyValues[counter][1])
			));


			Result(
				std::stod(historyValues[counter][2]),
				historyAction[counter]
			);
			break;
		case 2:
			historyAction[counter] = "Subtraction";
			Result(
				Subraction(
					InputValue(),
					InputValue()),
				"Subtraction"
			);
			break;
		case 3:
			historyAction[counter] = "Multiplication";
			Result(
				Multiplication(
					InputValue(),
					InputValue()),
				"Multiplication"
			);
			break;
		case 4:
			historyAction[counter] = "Division";
			Result(
				Division(
					InputValue(),
					InputValue()),
				"Division"
			);
			break;
		case 5:
			History(historyAction, historyValues);
			break;
		default:
			std::cout << "Please Follow Instruction";
			break;
		}

		system("pause");
		system("cls");

		if (!ExitMenu()) exit(0);

		counter++;

	} while (true);

}

double Add(double x, double y)
{
	return x + y;
}

double Subraction(double x, double y)
{
	return x - y;
}

double Multiplication(double x, double y)
{
	return x * y;
}

void History(std::string action[5], std::string values[5][3])
{
	std::cout << "History\n";
	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << ". " << action[i] << " with value " << values[i][0] << ", " << values[i][1] << " = " << values[i][2] << "\n";
	}
}

bool ExitMenu()
{
	int loopChoice;

	do
	{
		std::cout << "Want to do another transaction? [1. yes | 0. no]: ";
		std::cin >> loopChoice;
	} while (loopChoice != 1 && loopChoice != 0);

	system("cls");

	return loopChoice;
}

double Division(double x, double y)
{
	return x / y;
}

int MainMenu()
{
	int arithmeticChoice;

	std::cout
		<< "Welcome to Calculator\n"
		<< "\n"
		<< "1. Add\n"
		<< "2. Subraction\n"
		<< "3. Multiplication\n"
		<< "4. Division\n"
		<< "5. History\n"
		<< "0. Exit\n"
		<< "\n"
		<< "Enter Choice: ";
	std::cin >> arithmeticChoice;

	system("cls");

	return arithmeticChoice;
}

double InputValue()
{
	double val;

	std::cout << "Please input a value: \n";
	std::cin >> val;

	system("cls");

	return val;
}

void Result(double result, std::string action)
{
	std::cout
		<< "Arithmetic Compuation: " << action << "\n"
		<< "The total value is " << result << "\n\n";
}
