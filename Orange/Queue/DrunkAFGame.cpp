#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    queue <int> first;
    queue <int> second;
    for (int i = 0; i < 5; ++i) {
        int box;
        cin >> box;
        first.push(box);
    }
    for (int i = 0; i < 5; ++i) {
        int box;
        cin >> box;
        second.push(box);
    }
    for (int i = 0; i < (int)10e6; ++i) {
        if (first.empty()) {
            cout << "second " << i;
            return 0;
        }
        if (second.empty()) {
            cout << "first " << i;
            return 0;
        }

        int f = first.front(); first.pop();
        int s = second.front(); second.pop();
        f = f == 0 and s == 9 ? 10 : f;
        s = s == 0 and f == 9 ? 10 : s;

        if (f > s) {
            f = f == 10 and s == 9 ? 0 : f;
            s = s == 10 and f == 9 ? 0 : s;
            first.push(f);
            first.push(s);
        } else {
            f = f == 10 and s == 9 ? 0 : f;
            s = s == 10 and f == 9 ? 0 : s;
            second.push(f);
            second.push(s);
        }
    }
    cout << "botva";


    return 0;
}