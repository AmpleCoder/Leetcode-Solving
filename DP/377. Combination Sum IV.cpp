/*
comb(target)=comb(target-a[0])+comb(target-a[1])+comb(target-a[2])+.....+comb(target-a[size-1])
*/

class Solution {
public:
    int f(vector<int> &a,int target,int dp[1001])
    {
        if(target==0)
        {
            return 1;
        }
        
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        
        int size=a.size(),ans=0;
        
        for(int i=0;i<size;i++)
        {
            if(target>=a[i])
            {
                ans+=f(a,target-a[i],dp);
            }
        }
        
        return dp[target]=ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int dp[1001];
        memset(dp,-1,sizeof(dp));
        return f(nums,target,dp);
    }
};