/*
Some of the questions which can be asked to the interviewer before implementing the solution

For simplicity, are the keys integers only?
For collision resolution, can we use chaining?
Do we have to worry about load factors?
Can we assume inputs are valid or do we have to validate them?
Can we assume this fits memory?

ps : iska modulo wala solution seekho
*/

class MyHashMap {
public:
    int hash[1000001];
    int valid[1000001];
    
    MyHashMap() {
        memset(hash,-1,sizeof(hash));
        memset(valid,0,sizeof(valid));
    }
    
    void put(int key, int value) {
        hash[key]=value;
        valid[key]=1;
    }
    
    int get(int key) {
        if(valid[key]==1){
            return hash[key];
        }
        
        return -1;
    }
    
    void remove(int key) {
        hash[key]=-1;
        valid[key]=0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */