/*
similar to 525
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& a, int k) {
        int n=a.size(),i,currSum=0,ans=0;
        unordered_map<int,int> mp;
        
        for(i=0;i<n;i++){
            currSum+=a[i];
            if(currSum==k){
                ans=i+1;
            }
            
            else{
                if(mp.find(currSum-k)!=mp.end()){
                    int idx=mp[currSum-k];
                    ans=max(ans,i-idx);
                }
            }
            
            if(mp.find(currSum)==mp.end()){
                mp[currSum]=i;
            }
        }
        
        return ans;
    }
};