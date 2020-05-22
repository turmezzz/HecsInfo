#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:

    void Push(int n_i) {
        data_d.push_back(n_i);
    }

    void Pop(bool& ok_i) {
        ok_i = !data_d.empty();
        if (!ok_i) {
            return;
        }
        data_d.pop_back();
    }

    int Back(bool& ok_i) {
        ok_i = !data_d.empty();
        if (!ok_i) {
            return 0;
        }
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
    bool ok;
    Stack stack;

    while (true) {
        ok = true;
        cin >> cmd;
        if (cmd == "push") {
            cin >> n;
            stack.Push(n);
            cout << "ok\n";
        } else if (cmd == "pop") {
            int box = stack.Back(ok);
            if (ok) {
                stack.Pop(ok);
                cout << box << "\n";
            } else {
                cout << "error\n";
            }
        } else if (cmd == "back") {
            int box = stack.Back(ok);
            if (ok) {
                cout << box << "\n";
            } else {
                cout << "error\n";
            }
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