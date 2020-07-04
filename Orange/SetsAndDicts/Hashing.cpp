#include <iostream>
#include <string>

using namespace std;

class StringHashSet {
public:
    struct Node {
        string value;
        Node* next = nullptr;

        Node* Add(string newValue) {
            Node* newHead = new Node();
            newHead->value = move(newValue);
            newHead->next = this;
            return newHead;
        }

        ~Node() {
            delete next;
        }
    };

    bool Is(const string& key) const {
        auto hash = Hash(key);
        const auto* chunkBegin = chunks[hash];
        while (chunkBegin) {
            if (chunkBegin->value == key) {
                return true;
            }
            chunkBegin = chunkBegin->next;
        }
        return false;
    }

    // true - already
    // false - added
    bool Add(string key) {
        auto hash = Hash(key);
        auto* chunkBegin = chunks[hash];
        while (chunkBegin) {
            if (chunkBegin->value == key) {
                return true;
            }
            chunkBegin = chunkBegin->next;
        }
        if (not chunks[hash]) {
            auto* box = new Node();
            box->value = move(key);
            chunks[hash] = box;
        } else {
            chunks[hash] = chunks[hash]->Add(move(key));
        }
        return false;
    }

    ~StringHashSet() {
        if (chunks) {
            for (int i = 0; i < MAX_SIZE; ++i) {
                delete chunks[i];
            }
        }
        delete[] chunks;
    }
private:
    size_t Hash(const string& key) const {
        size_t hash = 0;
        size_t p = 71;
        for (auto letter : key) {
            size_t code = letter;
            hash *= p;
            hash += code;
        }
        return hash % MAX_SIZE;
    }

    size_t MAX_SIZE = 2 * 1e6;
    Node** chunks = new Node*[MAX_SIZE];
};

int main() {

    StringHashSet data;

    string cmd, line;
    cin >> cmd;
    while (cmd != "#") {
        if (cmd == "+") {
            cin >> line;
            data.Add(line);
        } else if (cmd == "?") {
            cin >> line;
            cout << (data.Is(line) ? "YES" : "NO") << endl;
        }
        cin >> cmd;
    }
    return 0;
}