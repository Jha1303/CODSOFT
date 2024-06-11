#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.emplace_back(taskDescription);
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].completed ? "x" : " ") << "] " 
                      << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task " << taskNumber << " marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            cout << "Task removed: " << tasks[taskNumber - 1].description << endl;
            tasks.erase(tasks.begin() + taskNumber - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    size_t taskNumber;

    do {
        cout << "\nTo-Do List Menu:\n";
       cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
               cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
