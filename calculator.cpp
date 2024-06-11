#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    double result;


    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
//operation choosing
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 1; 
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            return 1; //error
    }

    cout << "Result: " << result << endl;

    return 0;
}
