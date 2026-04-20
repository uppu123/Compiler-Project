// infix to postfix conversion

#include "../include/parser.h"
#include <stack>
#include <cctype>

int precedence(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

vector<string> infixToPostfix(vector<string> tokens) {
    stack<string> ops;
    vector<string> output;

    for (auto token : tokens) {
        // operand (number OR variable)
        if (isalnum(token[0])) {
            output.push_back(token);
        }
        // operator
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(token);
        }
        // ignore '='
    }

    while (!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }

    return output;
}