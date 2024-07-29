#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Manager.h"
#include "Display.h"

using namespace std;

enum options {
	Add = 1,
	MarkCompleted,
	DeleteTask,
	DeleteAllCompleted,
	Quit
};

int main() {

	bool on = true;
	Manager m;
	Display d;
	int userInput;
	string task;
	int choice;
	vector<string> tasks;
	vector<string> choices = { "Add Task", "Mark Completed", "Delete Task", "Delete All Completed", "Quit" };
	m.OpenToDo(tasks);

	while (on)
	{
		d.ClearScreen();
		cout << "TO-DO:" << endl;
		m.ShowTasks(tasks);
		cout << "\n" << endl;
		cout << "OPTIONS: " << endl;
		userInput = d.DisplayOptions(choices);

		switch (userInput) {
		case Add:
			cout << "Add Task: " << endl;
			cout << "> ";
			getline(cin, task);
			m.AddTask(task, tasks);
			break;
		case MarkCompleted:
			choice = d.OnlyValidate(tasks, "Mark Completed:");
			m.MarkCompleted(choice, tasks);
			break;
		case DeleteTask:
			choice = d.OnlyValidate(tasks, "Delete Task:");
			m.DeleteTask(choice, tasks);
			break;
		case DeleteAllCompleted:
			m.DeleteCompleted(tasks);
			break;
		case Quit:
			on = false;
		}
	}

}