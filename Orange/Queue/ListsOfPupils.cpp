// problem with encoding
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream fin("input.txt");
    int form;
    string name;
    queue <string> ninth;
    queue <string> tenth;
    queue <string> eleventh;
    while (!fin.eof()) {
        fin >> form >> name;
        if (form == 9) {
            ninth.push(name);
        } else if (form == 10) {
            tenth.push(name);
        } else {
            eleventh.push(name);
        }
    }
    ofstream fout("output.txt");
    while (not ninth.empty()) {
        cout << 9 << ' ' << ninth.front() << '\n';
        ninth.pop();
    }
    while (not tenth.empty()) {
        cout << 10 << ' ' << tenth.front() << '\n';
        tenth.pop();
    }
    while (not eleventh.empty()) {
        cout << 11 << ' ' << eleventh.front() << '\n';
        eleventh.pop();
    }
    fout.close();
    return 0;
}