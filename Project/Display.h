#pragma once
#include <vector>
#include <string>
 
using namespace std;

class Display {
public:
	int DisplayOptions(vector<string> options, string prompt = "");

	int OnlyValidate(vector<string> options, string prompt = "");

	void ClearScreen();
};