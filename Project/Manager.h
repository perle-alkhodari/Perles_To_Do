#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
class Manager {
public:
	void OpenToDo(vector<string>& tasks);

	void ShowTasks(vector<string> tasks);

	void AddTask(string task, vector<string>& tasks);

	void DeleteTask(int index, vector<string>& tasks);

	void MarkCompleted(int index, vector<string>& tasks);

	void DeleteCompleted(vector<string>& tasks);

	bool isCompleted(int index, vector<string> tasks);
};