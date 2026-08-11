class TrieNode {
    public:
    char c;
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(char c) {
        this->c = c;
        this->isEnd = false;
    }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode('&');
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c:word) {
            vector<TrieNode*> children = curr->children;
            bool found = false;
            for(int i = 0;i<children.size();i++) {
                if(children[i]->c == c) {
                    curr = children[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                TrieNode* newNode = new TrieNode(c);
                curr->children.push_back(newNode);
                curr = newNode;
            }
        }
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }

    bool searchWord(TrieNode* curr, string word) {
        if (word.length() == 0 && curr->isEnd) {
            return true;
        } else {
            vector<TrieNode*> children = curr->children;
            for(int i = 0;i<children.size();i++) {
                if(children[i]->c == word[0]) {
                    if(searchWord(children[i], word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }
    }

    bool prefixWord(TrieNode* curr, string word) {
        if (word.length() == 0) {
            return true;
        } else {
            vector<TrieNode*> children = curr->children;
            for(int i = 0;i<children.size();i++) {
                if(children[i]->c == word[0]) {
                    if(prefixWord(children[i], word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        return prefixWord(root, prefix);
    }
};
