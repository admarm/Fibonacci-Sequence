// Calculate Fibonacci Numbers
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <chrono>

using namespace std;
using namespace boost::multiprecision;
using namespace std::literals::chrono_literals;

void fib(int x, string ch) {

    if (x < 0) {
        throw "The starting number must be a positive integer.\n";
    }
    
    auto start = chrono::high_resolution_clock::now(); // Starts the timer
    
    cpp_int a, b, c;
    a = 0; b = 1;
    if (x == 0 || x == 1) {
        cout << "\nF0: " << a;
    }
    else if (x != 0 && x != 1) {
        if (ch == "seq" || ch == "sequence") { // Calculates and prints a sequence up to F(x)
            cout << "\nF0: " << a << "\n" << "F1: " << b;
            for (int i = 2; i < x; i++) {
                c = a + b; a = b; b = c;
                cout << "\nF" << i << ": " << c;
            }
        }
        else { // Prints only the x-th Fibonacci number
            for (int i = 2; i < x; i++) {
                c = a + b; a = b; b = c;
            }
            cout << "\nF" << (x - 1) << ": " << c;
        }
    }
    
    // Ends the timer, calculates the duration and prints it to the console
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "\n\nTime needed: " << duration.count() << "s\n(Press enter to exit)";
}


int main(int argc, char* argv[])
{
    int number;
    string choice;

    try {
        if (argc == 1) { // If no arguments are given: get input from the console

            cout << "Enter a positive intiger and a way of execution (sequence/single)\n: ";

            cin >> number;
            getline(cin >> ws, choice);

            if (choice.empty()) {

                choice = "single";
                fib(number, choice);
            }
            else {

                fib(number, choice);
            }
        }
        else if (argc == 2) { // If only 1 argument (number) is provided: ask for the other one

            number = atof(argv[1]);

            cout << "Enter a choice: ";
            getline(cin >> ws, choice);

            if (choice.empty()) {

                choice = "single";
                fib(number, choice);
            }
            else {

                fib(number, choice);
            }

        }
        else if (argc == 3) { // Both args (number and choice) are provided

            number = atof(argv[1]);
            choice = argv[2];

            if (choice.empty()) {

                choice = "single";
                fib(number, choice);
            }
            else {

                fib(number, choice);
            }
        }
    }
    catch (const char* msg) { // Catch and display the exception.
        cerr << "\nError: " << msg;
    }
    
    cin.get(); // Waits for user input before closing the window
    return 0;
}
