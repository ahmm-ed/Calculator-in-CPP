#include <iostream>
#include <iomanip>
#include <cmath> // Required for pow() and sqrt()

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
         << "6. Power (^)\n"
         << "7. Square Root (√)\n"
         << "8. Exit\n"
         << "------------------------------\n"
         << "Enter your choice (1-8): ";
}

int main() {
    int choice;
    double num1, num2;

    cout << fixed << setprecision(2);

    do {
        showMenu();
        cin >> choice;

        if (choice == 8) {
            cout << "\nThank you for using the calculator. Goodbye!\n\n";
            break;
        }

        if (choice < 1 || choice > 8) {
            cout << "\n[Error] Invalid choice! Please select between 1 and 8.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        
        // Only ask for second number if the operation isn't square root
        if (choice != 7) {
            cout << "Enter second number: ";
            cin >> num2;
        }

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
            case 6: // New Function: Power
                cout << "\nResult: " << num1 << " ^ " << num2 << " = " << pow(num1, num2) << "\n";
                break;
            case 7: // New Function: Square Root
                if (num1 < 0) {
                    cout << "\n[Error] Cannot calculate square root of a negative number!\n";
                } else {
                    cout << "\nResult: √" << num1 << " = " << sqrt(num1) << "\n";
                }
                break;
        }

    } while (true);

    return 0;
}