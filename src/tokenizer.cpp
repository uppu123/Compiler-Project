// Expression into Tokens

#include "../include/tokenizer.h"
#include <sstream>

vector<string> tokenize(string input) {
    vector<string> tokens;
    stringstream ss(input);
    string temp;

    while (ss >> temp) {
        tokens.push_back(temp);
    }
    return tokens;
}