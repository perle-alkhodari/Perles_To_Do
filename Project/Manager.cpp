#include "Manager.h"
#include <fstream>
#include <string>

using namespace std;

void Manager::OpenToDo(vector<string>& tasks)
{
	string task;
	ifstream file("tasks.txt");
	while (getline(file, task)) {
		tasks.push_back(task);
	}
	file.close();
}

void Manager::ShowTasks(vector<string> tasks)
{
	for (int i = 0; i < tasks.size(); i++) {
		cout << "[" << i + 1 << "] " << tasks.at(i) << endl;
	}
}

void Manager::AddTask(string task, vector<string>& tasks)
{
	tasks.push_back(task);
	ofstream file("tasks.txt");
	for (string t : tasks) {
		file << t << endl;
	}
	file.close();
}

void Manager::DeleteTask(int index, vector<string>& tasks)
{
	index--;
	tasks.erase(tasks.begin() + index);
	ofstream file("tasks.txt");
	for (string t : tasks) {
		file << t << endl;
	}
	file.close();
}

void Manager::MarkCompleted(int index, vector<string>& tasks)
{
	if (!isCompleted(index, tasks)) {
		index--;
		string task = tasks.at(index);
		tasks.at(index) = "(completed) - " + task;
		ofstream file("tasks.txt");
		for (string t : tasks) {
			file << t << endl;
		}
		file.close();
	}
}

void Manager::DeleteCompleted(vector<string>& tasks)
{
	string prefix = "(completed)";
	string taskPref;
	for (int i = 0; i < tasks.size();) {
		taskPref = "";
		for (int j = 0; j < tasks.at(i).size(); j++)
		{
			taskPref += tasks.at(i).at(j);
			if (j == 10) break;
		}
		if (taskPref == prefix) {
			tasks.erase(tasks.begin() + i);
		}
		else {
			i++;
		}
	}

	ofstream file("tasks.txt");
	for (string t : tasks) {
		file << t << endl;
	}
	file.close();
}

bool Manager::isCompleted(int index, vector<string> tasks)
{
	bool result = false;
	index--;
	string prefix = "(completed)";
	string taskPref;
	
	for (auto letter : tasks.at(index))
	{
		taskPref += letter;
		if (taskPref == prefix) result = true;
	}

	return result;
}

