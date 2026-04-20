#include <iostream>
#include "../include/tokenizer.h"
#include "../include/parser.h"
#include "../include/ast.h"
#include "../include/optimizer.h"
#include "../include/codegen.h"

using namespace std;

int main() {
    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    auto tokens = tokenize(input);

    string var = tokens[0];
    vector<string> expr(tokens.begin() + 2, tokens.end());

    auto postfix = infixToPostfix(expr);

    Node* root = buildAST(postfix);

    cout << "\nAST:\n";
    printAST(root);

    root = optimize(root);

    cout << "\nOptimized AST:\n";
    printAST(root);

    cout << "\nIntermediate Code:\n";
    string result = generateIR(root);

    cout << var << " = " << result << endl;

    return 0;
}