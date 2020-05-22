#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;
    stack <char> data;
    for (auto v : line) {
        if (v == '(' or v == '{' or v == '[') {
            data.push(v);
        } else {
            char openBracket = 'a';
            if (not data.empty()) {
                openBracket = data.top();
                data.pop();
            }
            if (openBracket == 'a') {
                cout << "no";
                return 0;
            }
            if (openBracket == '(' and v != ')') {
                cout << "no";
                return 0;
            }
            if (openBracket == '{' and v != '}') {
                cout << "no";
                return 0;
            }
            if (openBracket == '[' and v != ']') {
                cout << "no";
                return 0;
            }
        }
    }
    if (data.empty()) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}