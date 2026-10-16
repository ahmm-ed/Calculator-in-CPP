#include <iostream>
#include <iomanip> // <-- The one addition: required for decimal precision

using namespace std;

void showMenu() {
    cout << "\n==============================\n"
         << "      C++ SWITCH CALCULATOR   \n"
         << "==============================\n"
         << "1. Addition (+)\n"
         << "2. Subtraction (-)\n"
         << "3. Multiplication (*)\n"
         << "4. Division (/)\n"
         << "5. Modulus (%) [Integers]\n"
         << "6. Exit\n"
         << "------------------------------\n"
         << "Enter your choice (1-6): ";
}

int main() {
    int choice;
    double num1, num2;

    // The one addition: fixes all output to 2 decimal places
    cout << fixed << setprecision(2);

    do {
        showMenu();
        cin >> choice;

        if (choice == 6) {
            cout << "\nThank you for using the calculator. Goodbye!\n\n";
            break;
        }

        if (choice < 1 || choice > 6) {
            cout << "\n[Error] Invalid choice! Please select between 1 and 6.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "\nResult: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
                break;
            case 2:
                cout << "\nResult: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
                break;
            case 3:
                cout << "\nResult: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
                break;
            case 4:
                if (num2 == 0) {
                    cout << "\n[Error] Division by zero is undefined!\n";
                } else {
                    cout << "\nResult: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
                }
                break;
            case 5:
                if (static_cast<int>(num2) == 0) {
                    cout << "\n[Error] Modulus by zero is undefined!\n";
                } else {
                    int int1 = static_cast<int>(num1);
                    int int2 = static_cast<int>(num2);
                    cout << "\nResult: " << int1 << " % " << int2 << " = " << (int1 % int2) << "\n";
                }
                break;
        }

    } while (true);

    return 0;
}