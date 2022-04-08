/*
kth sorted ele ke liye 
*/
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minPq;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        for(auto &currNum:nums){
            if(minPq.size()<k){
                minPq.push(currNum);
            }
            
            else if(currNum > minPq.top()){
                minPq.pop();
                minPq.push(currNum);
            }
        }
        
        this->k=k;
    }
    
    int add(int val) {
        if(minPq.size()<k){
            minPq.push(val);
        }
        
        else if(val>minPq.top()){
            minPq.pop();
            minPq.push(val);
        }
        
        return minPq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */