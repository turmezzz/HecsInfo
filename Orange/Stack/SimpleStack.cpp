#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:

    void Push(int n_i) {
        data_d.push_back(n_i);
    }

    void Pop() {
        data_d.pop_back();
    }

    int Back() {
        return data_d.back();
    }

    size_t Size() const {
        return data_d.size();
    }

    void Clear() {
        data_d.clear();
    }

private:
    vector <int> data_d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    int n;

    Stack stack;

    while (true) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> n;
            stack.Push(n);
            cout << "ok\n";
        } else if (cmd == "pop") {
            int box = stack.Back();
            stack.Pop();
            cout << box << "\n";
        } else if (cmd == "back") {
            cout << stack.Back() << "\n";
        } else if (cmd == "size") {
            cout << stack.Size() << "\n";
        } else if (cmd == "clear") {
            stack.Clear();
            cout << "ok\n";
        } else if (cmd == "exit") {
            cout << "bye\n";
            break;
        }
    }

    return 0;
}