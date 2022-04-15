/*
very easy
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& a) {
        vector<int> ans;
        int size=a.size(),i,mx=INT_MIN;
        
        for(i=size-1;i>=0;i--){
            if(mx==a[i]){
                continue;
            }
            
            mx=max(mx,a[i]);
            
            if(mx==a[i]){
                ans.push_back(i);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};