/*
good problem having lots of variations
*/

class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int currSum=0,n=a.size(),i,ans=0;
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++){
            currSum=currSum + (a[i]==1?1:-1);
            if(currSum==0){
                ans=i+1;
            }
            
            else{
                if(m.find(currSum)!=m.end()){
                    int prevInd=m[currSum];
                    ans=max(ans,i-prevInd);
                }
            }
            
            if(m.find(currSum)==m.end()){
                m[currSum]=i;
            }
        }
        
        return ans;
    }
};