class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* next;
        node* prev;

        node(int k, int v) {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int limit;

    unordered_map<int, node*> mpp;

    void addNode(node* newnode) {
        node* temp = head->next;

        head->next = newnode;
        temp->prev = newnode;

        newnode->next = temp;
        newnode->prev = head;
    }

    void deleteNode(node* oldnode) {
        oldnode->next->prev = oldnode->prev;
        oldnode->prev->next = oldnode->next;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        node* ansnode = mpp[key];
        int ans = ansnode->val;

        deleteNode(ansnode);
        addNode(ansnode);

        return ans;
    }

    void put(int key, int value) {

        if (mpp.find(key) != mpp.end()) {
            node* oldnode = mpp[key];
            deleteNode(oldnode);
            mpp.erase(key);
        }

        if (mpp.size() == limit) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        node* newnode = new node(key, value);
        addNode(newnode);
        mpp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */