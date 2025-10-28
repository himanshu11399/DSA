class LRUCache {
public:
    class node {
    public:
        int key;
        int value;
        node* prev;
        node* next;

        node(int k, int val) {
            key = k;
            value = val;
            next = NULL;
            prev = NULL;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int limits;
    unordered_map<int, node*> mpp;

    void deleteNode(node* temp) {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
    }

    void insertNode(node* newNode) {
        node* temp = head->next;

        head->next = newNode;
        temp->prev = newNode;

        newNode->next = temp;
        newNode->prev = head;
    }

    LRUCache(int capacity) {
        limits = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        node* curr = mpp[key];
        int ans = curr->value;

        deleteNode(mpp[key]);
        insertNode(mpp[key]);

        return ans;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            deleteNode(mpp[key]);
            mpp.erase(key);
        }

        if(mpp.size()==limits){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        node* newnode = new node(key, value);
        insertNode(newnode);
        mpp[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */