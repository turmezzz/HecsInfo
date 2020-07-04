#include <iostream>
#include <queue>

using namespace std;

class Queue {
public:
    void Push(int n) {
        data.push(n);
    }

    void Pop() {
        data.pop();
    }

    int Front() const {
        return data.front();
    }

    size_t Size() const {
        return data.size();
    }

    void Clear() {
        data = queue<int>();
    }

private:
    queue <int> data;
};

int main() {

    string cmd;
    cin >> cmd;
    Queue q;
    while (cmd != "exit") {
        if (cmd == "push") {
            int n;
            cin >> n;
            q.Push(n);
            cout << "ok" << endl;
        } else if (cmd == "pop") {
            cout << q.Front() << endl;
            q.Pop();
        } else if (cmd == "front") {
            cout << q.Front() << endl;
        } else if (cmd == "size") {
            cout << q.Size() << endl;
        } else if (cmd == "clear") {
            q.Clear();
            cout << "ok" << endl;
        }
        cin >> cmd;
    }
    cout << "bye";

    return 0;
}
