class Item {
    public:
    int key;
    int value;
    Item* next;
    Item* prev;
    Item(int key, int value) {
        this -> key = key;
        this -> value = value;
        this -> next = NULL;
        this -> prev = NULL;
    }
};
class LRUCache {
    Item* front = NULL;
    Item* back = NULL;
    unordered_map<int,Item*> cache;
    int cap;
    int size = 0;
public:
    void moveFront(Item* curr,int value) {
        curr -> value = value;
        if (curr == front) {
            return;
        }
        if(curr == back) {
            back = curr->prev;
        }
        Item* prev1 = curr->prev;
        if(prev1!=NULL) {
        prev1->next = curr->next;
        }
        if(curr->next!=NULL) {
            curr->next->prev = prev1;
        }
        curr->next = front;
        front->prev = curr;
        curr->prev = NULL;
        front = curr;
    }

    void pop_back() {
            Item* node = back;

    cache.erase(node->key);

    back = back->prev;

    if (back != NULL) {
        back->next = NULL;
    } else {
        front = NULL;
    }

    size--;
    }

    void push_front(Item* curr) {
        size++;
        if(front == NULL) {
            front = curr;
            back = curr;
            return;
        }
        front -> prev = curr;
        curr -> next = front;
        front = curr;
    }

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        bool contains = false;
        if(it != cache.end()) {
            contains = true;
        }
        if(contains) {
            moveFront(it -> second, it -> second -> value);
            return it -> second -> value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        bool contains = false;
        if(it != cache.end()) {
            contains = true;
        }        
        if(contains) {
            moveFront(it->second, value);
            return;
        }
        if(size >= cap) {
            pop_back();
        }
        Item* curr = new Item(key,value);
        cache[key] = curr;
        push_front(curr);
    }
};
