class WordDictionary {
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

    bool dfs(string& word, int index, TrieNode* node) {

        if (index == word.length()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch != '.') {

            int pos = ch - 'a';

            if (node->children[pos] == nullptr) {
                return false;
            }

            return dfs(word, index + 1, node->children[pos]);
        }

        for (int i = 0; i < 26; i++) {

            if (node->children[i] != nullptr) {

                if (dfs(word, index + 1, node->children[i])) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

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
        return dfs(word, 0, root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */