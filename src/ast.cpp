// AST structure
// Print tree

#include "../include/ast.h"
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;


Node* buildAST(vector<string> postfix) {
    stack<Node*> st;

    for (auto token : postfix) {
        if (isalnum(token[0])) {
            st.push(new Node(token));
        } 
        else {
            if (st.size() < 2) {
                cout << "Error: Invalid Expression\n";
                exit(1);
            }

            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* op = new Node(token);
            op->left = left;
            op->right = right;

            st.push(op);
        }
    }

    if (st.empty()) {
        cout << "Error: Empty AST\n";
        exit(1);
    }

    return st.top();
}

Node::Node(string val) {
    value = val;
    left = right = NULL;
}

void printAST(Node* root, int space) {
    if (!root) return;

    space += 5;
    printAST(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->value << "\n";

    printAST(root->left, space);
}