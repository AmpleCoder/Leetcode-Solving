/*
trickier dp + bitmasking problem here we're allowed to fill 1 slot with 2 diffrent values
so we'll consider mask with base 3 
and if we're checking ith bit it's possible values could be 0,1,2
if value = 2 then we 're not allowed to allocate 
*/

class Solution {
public:
    
    int f(vector<int> &a,int idx,int mask,int slot,vector<vector<int>> &dp)
    {
        if(idx==a.size())
        {
            return 0;
        }
        
        if(dp[idx][mask]!=-1)
        {
            return dp[idx][mask];
        }
        
        int curr,currMask=1,i,ans=0;
        
        for(i=1;i<=slot;i++,currMask*=3)
        {
            int currBit = (mask/currMask)%3;
            if(currBit==2)  continue;
            curr=(a[idx]&i)+f(a,idx+1,mask+currMask,slot,dp);
            ans=max(ans,curr);
        }
        
        return dp[idx][mask]=ans;
        
    }
    
    int maximumANDSum(vector<int>& a, int slot) {
        int mask=0,size=(int)pow(3,slot+2);
        vector<vector<int>> dp(20,vector<int>(size+1,-1));
        int ans=f(a,0,mask,slot,dp);
        return ans;
    }
};