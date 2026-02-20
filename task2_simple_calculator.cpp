#include <iostream>
#include <string>

using namespace std;

int main() {
    double num1, num2;
    char operators;
    string choice;

    cout << "Welcome to Simple Calculator!\n";

    do {
        cout << "\n Enter first number: ";
        cin >> num1;

        cout << "Enter operator (+, -, *, /): ";
        cin >> operators;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "------------------------\n";

        switch (operators) {
            case '+':
                cout << "Result: " << num1 + num2 << "\n";
                break;
            case '-':
                cout << "Result: " << num1 - num2 << "\n";
                break;
            case '*':
                cout << "Result: " << num1 * num2 << "\n";
                break;
            case '/':
               
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed.\n";
                } else {
                    cout << "Result: " << num1 / num2 << "\n";
                }
                break;
            default:
                cout << "Invalid operator!\n";
        }

        cout << "------------------------\n";

        cout << "Do you want to calculate again? (Yes/No): ";
        cin >> choice;

    
    } while (choice == "Yes" || choice == "No");

    cout << "Calculator closed. Have a great day!\n";

    return 0;
}