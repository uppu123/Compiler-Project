// AST structure
// Print tree

#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;

    Node(string val);
};

void printAST(Node* root, int space = 0);
Node* buildAST(vector<string> postfix);

#endif