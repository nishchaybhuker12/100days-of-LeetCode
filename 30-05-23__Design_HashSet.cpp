class Solution{
    public:
    vector<int> data;

    MyHashSet(){
        data.resize(1e6+7,0);
    }
    void add(int key){
        data[key] = 1;
    }
    void remove(int key){
        data[key] = 0;
    }
    bool contains(int key){
        return data[key];
    }
};