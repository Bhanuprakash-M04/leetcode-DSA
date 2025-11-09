class Node {
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        value=v;
        next=prev=NULL;
    }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mymap;
    int size;
    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        mymap.clear();
        size=capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)==mymap.end())
            return -1;
        Node* nn=mymap[key];
        deleteNode(nn);
        insertAfterHead(nn);
        return nn->value;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end()){
            Node* nn=mymap[key];
            nn->value=value;
            mymap[key]=nn;
            deleteNode(nn);
            insertAfterHead(nn);
            return ;
        }
        if(mymap.size()==size){
            Node* node=tail->prev;
            int lru_key=node->key;
            deleteNode(node);
            mymap.erase(lru_key);
            delete(node);
        }
        Node* newNode=new Node(key,value);
        insertAfterHead(newNode);
        mymap[key]=newNode;
    }
    void deleteNode(Node* node){
        Node* before=node->prev;
        Node* after=node->next;
        before->next=after;
        after->prev=before;
    }
    void insertAfterHead(Node* node){
        Node* cur=head->next;
        node->prev=head;
        node->next=cur;
        cur->prev=node;
        head->next=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */