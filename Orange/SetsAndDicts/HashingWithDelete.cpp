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
            chunks[hash] = new Node();
            chunks[hash]->value = move(key);
        } else {
            chunks[hash] = chunks[hash]->Add(move(key));
        }
        return false;
    }

    // true - there was a key elem
    // false - no elem key
    bool Erase(const string& key) {
        auto hash = Hash(key);
        auto* chunkBegin = chunks[hash];
        auto* prevNode = chunkBegin->next;
        while (chunkBegin) {
            if (chunkBegin->value == key) {
                if (chunkBegin == chunks[hash]) {
                    chunks[hash] = prevNode;
                } else {
                    prevNode->next = chunkBegin->next;
                    chunkBegin->next = nullptr;
                    delete chunkBegin;
                }
                return true;
            }
            prevNode = chunkBegin;
            chunkBegin = chunkBegin->next;
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
        } else if (cmd == "-") {
            cin >> line;
            data.Erase(line);
        }
        cin >> cmd;
    }
    return 0;
}