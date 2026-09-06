class Letter{
    public:
        char c;
        bool isLast;
        vector<Letter*> children;
        Letter(char ch = '\0') {
            c = ch;
            isLast = false;
        }
};
class WordDictionary {
    Letter* root;
public:
    WordDictionary() {
        root = new Letter();
    }
    
    void addWord(string word) {
        addWord(word, 0, root);
    }

    void addWord(string& word,int index,Letter* parent) {
        Letter* l;
        bool isFound = false;
        for(Letter* child:parent->children) {
            if(child->c == word[index]) {
                l = child;
                isFound = true;
                break;
            }
        }
        if(!isFound) {
            l = new Letter(word[index]);
            parent->children.push_back(l);
        }
        if(index == word.size() - 1) {
            l->isLast = true;
            return;
        }
        addWord(word, index+1, l);
    }
    
    bool search(string word) {
       return search(word, 0, root);
    }

    bool search(string& word,int index,Letter* parent) {
        if(index == word.size()) {
            if(parent->isLast) {
                return true;
            }
            return false;
        }
        for(Letter* child:parent->children) {
            if(child->c == word[index] || word[index]=='.') {
                if(search(word, index+1,child)) {
                    return true;
                }
            }
        }
        return false;
    }
};
