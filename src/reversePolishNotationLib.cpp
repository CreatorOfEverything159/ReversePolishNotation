#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> parse(const string &equation) {
    const array<char, 7> operators = {'+', '-', '*', '/', '^', '(', ')'};

    map<char, int> precedence;
    precedence.insert(pair<char, int>('+', 1));
    precedence.insert(pair<char, int>('-', 1));
    precedence.insert(pair<char, int>('*', 2));
    precedence.insert(pair<char, int>('/', 2));
    precedence.insert(pair<char, int>('^', 3));

    vector<string> postfix;
    stack<char> operands;
    string buffer;

    for (char i : equation) {
        if (find(operators.begin(), operators.end(), i) == operators.end())
            buffer += i;

        else if (i == '(')
            operands.push('(');

        else if (i == ')') {
            if (buffer.length() > 0) {
                postfix.push_back(buffer);
                buffer = "";
            }

            while (operands.empty() || operands.top() != '(') {
                buffer = operands.top();
                postfix.push_back(buffer);
                operands.pop();
                buffer = "";
            }

            operands.pop();
        } else {
            if (buffer.length() > 0) {
                postfix.push_back(buffer);
                buffer = "";
            }

            while (!operands.empty() && operands.top() != '(' && [&](char a, char b) -> bool {
                return precedence.at(a) >= precedence.at(b);
            }(operands.top(), i)) {
                buffer = operands.top();
                postfix.push_back(buffer);
                operands.pop();
                buffer = "";
            }

            operands.push(i);
        }
    }

    if (!buffer.empty())
        postfix.push_back(buffer);

    while (!operands.empty()) {
        buffer = operands.top();
        postfix.push_back(buffer);
        operands.pop();
        buffer = "";
    }

    return postfix;
}

int evaluate(const vector<string> &postfix) {
    const array<string, 5> operators = {"+", "-", "*", "/", "^"};

    stack<int> operands;
    int a, b, buf;

    for (auto V: postfix) {
        if (find(operators.begin(), operators.end(), V) != operators.end()) {
            a = operands.top();
            operands.pop();
            b = operands.top();
            operands.pop();

            if (V == "+") buf = a + b;
            else if (V == "-") buf = b - a;
            else if (V == "*") buf = a * b;
            else if (V == "/") buf = b / a;
            else if (V == "^") buf = pow(b, a);

            operands.push(buf);
        } else {
            stringstream convert;
            convert << V;
            convert >> buf;

            operands.push(buf);
        }
    }

    return operands.top();
}