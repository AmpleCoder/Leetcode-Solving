/*
nice problem here the max constraint on size will be only 2*5*10000 
hence only this thought gets clear then the problem can be thinkable like
we can consider the map of each index where we'll keep track of once they gets changed mapped with the current going snap shot
*/

class SnapshotArray {
public:
    map<int,map<int,int>> mp;
    int snapId;
    
    SnapshotArray(int length) {
        int i;
        snapId=0;
        for(i=0;i<length;i++){
            map<int,int> currMap;
            currMap[0]=0;
            mp[i]=currMap;
        }
    }
    
    void set(int index, int val) {
        mp[index][snapId]=val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        // map<int,int> currMap = mp[index];
        auto it = mp[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */