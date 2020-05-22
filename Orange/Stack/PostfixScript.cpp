#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    istringstream sin(line);
    string box;

    stack <int> numbers;
    while (sin >> box) {
        if (box[0] == '+') {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b + a);
        } else if (box[0] == '-' and box.length() == 1) {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b - a);
        } else if (box[0] == '*') {
            int a = numbers.top(); numbers.pop();
            int b = numbers.top(); numbers.pop();
            numbers.push(b * a);
        } else {
            numbers.push(stoi(box));
        }
    }
    cout << numbers.top() << endl;
    return 0;
}