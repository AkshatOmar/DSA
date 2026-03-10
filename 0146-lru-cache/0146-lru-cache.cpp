struct Node {
    int key;
    int value;
    Node *next;
    Node*prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
  private:
    int capacity;
    unordered_map<int, Node*>cacheMap;
    Node *head;
    Node*tail;
    void add(Node *node) {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }
    void remove(Node *node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
  public:
    // Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int capacity) {
        // code here
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        Node *node =cacheMap[key];
        remove(node);
        add(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(cacheMap.find(key) != cacheMap.end()) {
            Node *oldNode = cacheMap[key];
            remove(oldNode);
            delete oldNode;
        }
        Node *node = new Node(key, value);
        cacheMap[key] = node;
        add(node);
        if(cacheMap.size() > capacity) {
            Node *nodeToDelete = tail->prev;
            remove(nodeToDelete);
            cacheMap.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */