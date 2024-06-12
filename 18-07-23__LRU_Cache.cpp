class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    int size;
    LRUCache(int capacity) {
           size=capacity;
            head->next=tail;
             tail->prev=head;
    }
    void deleteNode(Node*p){
       Node*pre=p->prev;
       Node*nex=p->next;
       pre->next=nex;
       nex->prev=pre;
    }
    void addNode(Node*newnode){
        Node*temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    int get(int key) {
        if(m.find(key)==m.end())
        return -1;
        Node*p=m[key];
        deleteNode(p);
        addNode(p);
        m[key]=head->next;
        return head->next->val;
    }
    
    void put(int key, int value) {
       if(m.find(key)!=m.end()){
            Node*c=m[key];
            deleteNode(c);
            c->val=value;
            addNode(c);
            m[key]=head->next;
        }
        else{
            if(m.size()==size){
                Node* prev=tail->prev;
                deleteNode(prev);
                Node*l=new Node(key,value);
                addNode(l);
                m.erase(prev->key);
                m[key]=head->next;
            }
            else{
                 Node*l=new Node(key,value);
                addNode(l);
                m[key]=head->next; 
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */