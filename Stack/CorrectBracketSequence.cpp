#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack <char> data;
    string line;
    cin >> line;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == ')') {
            if (data.empty() or data.top() != '(') {
                cout << "no" << endl;
                return 0;
            } else {
                data.pop();
            }
        } else if (line[i] == ']') {
            if (data.empty() or data.top() != '[') {
                cout << "no" << endl;
                return 0;
            } else {
                data.pop();
            }
        } else if (line[i] == '}') {
            if (data.empty() or data.top() != '{') {
                cout << "no" << endl;
                return 0;
            } else {
                data.pop();
            }
        } else {
            data.push(line[i]);
        }
    }
    cout << (data.empty() ? "yes" : "no");
    return 0;
}