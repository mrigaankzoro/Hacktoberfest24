#include <iostream>
#include <vector>
#include <string>

class Todo {
public:
    std::string task;
    bool completed;

    Todo(std::string t) : task(t), completed(false) {}
};

std::vector<Todo> todos;

void addTask(const std::string& task) {
    todos.push_back(Todo(task));
}

void showTasks() {
    for (size_t i = 0; i < todos.size(); ++i) {
        std::cout << i + 1 << ". " << todos[i].task << (todos[i].completed ? " [Completed]" : "") << std::endl;
    }
}

int main() {
    addTask("Learn C++");
    addTask("Build a project");
    showTasks();
    return 0;
}
