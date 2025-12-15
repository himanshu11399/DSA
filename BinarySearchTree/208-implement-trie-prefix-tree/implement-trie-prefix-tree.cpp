class Trie {
public:
    Trie* children[26];
    bool eow;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        eow = false;
    }

    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == NULL) {
                curr->children[idx] = new Trie();
            }
            if (i == word.size() - 1) {
                curr->children[idx]->eow = true;
            }
            curr = curr->children[idx];
        }
    }

    bool search(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            if (i == word.size() - 1 && curr->children[idx]->eow == false) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }

    bool startsWith(string prefix) {
        Trie* curr = this;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (curr->children[idx] == NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */