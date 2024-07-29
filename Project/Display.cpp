#include "Display.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Display::DisplayOptions(vector<string> options, string prompt)
{
	string strUserInput;
	int userInput;
	bool invalid = true;

	for (int i = 0; i < options.size(); i++) {
		cout << "[" << i + 1 << "] " << options.at(i) << endl;
	}
	cout << endl;
	if (!prompt.empty()) cout << prompt << endl;

	do {
		cout << "> ";
		getline(cin, strUserInput);

		try {
			userInput = stoi(strUserInput);
			if (userInput >= 1 && userInput <= options.size()) {
				invalid = false;
			}
		}
		catch (...) {
			invalid = true;
		}
	} while (invalid);
	return userInput;
}

int Display::OnlyValidate(vector<string> options, string prompt)
{
	string strUserInput;
	int userInput;
	bool invalid = true;

	if (!prompt.empty()) cout << prompt << endl;

	do {
		cout << "> ";
		getline(cin, strUserInput);

		try {
			userInput = stoi(strUserInput);
			if (userInput >= 1 && userInput <= options.size()) {
				invalid = false;
			}
		}
		catch (...) {
			invalid = true;
		}
	} while (invalid);
	return userInput;
}

void Display::ClearScreen()
{
	cout << "\x1B[2J\x1B[H" << endl;
}
