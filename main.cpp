#include <iostream>
#include <vector>
#include "reversePolishNotationLib.h"

using namespace std;

int main() {
    string equation;

    cout << "Enter expression: ";
    cin >> equation; // enter expression without spaces

    vector<string> postfix = parse(equation);

    cout << "Reverse Polish Notation: ";
    for (int i = 0; i < postfix.size(); ++i) {
        cout << postfix[i] << ' ';
    }
    cout << endl;

    int result = evaluate(postfix);

    cout << "Result: " << result;
}
