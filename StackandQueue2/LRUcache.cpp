class LRUCache {
    class node{
        public:
        int _key;
        int _val;
        node* prev;
        node* next;
        node(int key, int val){
            _key = key;
            _val = val;
            prev = NULL;
            next = NULL;
        }
    };

    node* head = new node(-1, -1), *tail = new node(-1, -1);
    unordered_map<int, node*> ump;
    int cap;

    node* insertNode(int key, int value){
        node* newbie = new node(key, value);
        node* temp = head->next;
        head->next = newbie;
        newbie->next = temp;
        newbie->prev = head;
        temp->prev = newbie;
        return newbie;
    }
    void deleteNode(node* deleteMe){
        node* before = deleteMe->prev;
        node* afterr = deleteMe->next;
        delete(deleteMe);
        before->next = afterr;
        afterr->prev = before;
    }
public:
    LRUCache(int capacity)
    {

        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if(ump.find(key)==ump.end()) return -1;
        node* deleteMe = ump[key];
        ump[key] = insertNode(key, ump[key]->_val);
        deleteNode(deleteMe);
        return ump[key]->_val;
    }

    void put(int key, int value)
    {
        if(ump.find(key)!=ump.end()){
            ump[key]->_val = value;
            get(key);
            return;
        }
        if(ump.size()>=cap){
            ump.erase(tail->prev->_key);
            deleteNode(tail->prev);
        }
        node *temp = insertNode(key, value);
        ump[key] = temp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */