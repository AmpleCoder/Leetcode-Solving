/*
iski time complexity O(NlogK) hei
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minPq;
        int i;
        vector<int> result;
        
        for(auto &x:nums){
            freq[x]++;
        }
        
        for(auto &x:freq)
        {
            int ele=x.first;
            int frequency=x.second;
            
            if(frequency==0){
                continue;
            }
            
            if(minPq.size()<k){
                minPq.push({frequency,ele});
            }
            
            else{
                vector<int> topEle=minPq.top();
                
                //if current freq i.e freq[i]>topEle's frequency
                if(frequency>topEle[0]){
                    minPq.pop();
                    minPq.push({frequency,ele});
                }
            }
        }
        
        while(!minPq.empty()){
            vector<int> topEle=minPq.top();
            result.push_back(topEle[1]);
            minPq.pop();
        }
        
        return result;
    }
};