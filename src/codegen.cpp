// IR Generation TAC

#include "../include/codegen.h"
#include <iostream>

int tempCount = 1;

string generateIR(Node* root) {
    if (!root->left && !root->right) {
        return root->value;
    }

    string left = generateIR(root->left);
    string right = generateIR(root->right);

    string temp = "t" + to_string(tempCount++);
    cout << temp << " = " << left << " " << root->value << " " << right << endl;

    return temp;
}