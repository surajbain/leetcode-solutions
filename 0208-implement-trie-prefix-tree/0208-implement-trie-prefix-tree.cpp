class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;
public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode* current = root;
        for (char ch : word) {

            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    bool search(string word) {

        TrieNode* current = root;
        for (char ch : word) {

            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                return false;
            }

            current = current->children[index];
        }
        return current->isEnd;
    }
    bool startsWith(string prefix) {

        TrieNode* current = root;
        for (char ch : prefix) {

            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};