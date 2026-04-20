//constant folding

#include "../include/optimizer.h"
#include <string>

Node* optimize(Node* root) {
    if (!root) return root;

    root->left = optimize(root->left);
    root->right = optimize(root->right);

    if (root->left && root->right &&
        isdigit(root->left->value[0]) &&
        isdigit(root->right->value[0])) {

        int l = stoi(root->left->value);
        int r = stoi(root->right->value);
        int res;

        if (root->value == "+") res = l + r;
        else if (root->value == "-") res = l - r;
        else if (root->value == "*") res = l * r;
        else if (root->value == "/") res = l / r;

        return new Node(to_string(res));
    }

    return root;
}
