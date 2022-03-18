class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int size=q.size(),i;
        long long dp[200001];
        memset(dp,0,sizeof(dp));
        
        for(i=size-1;i>=0;i--)
        {
            dp[i]=max(dp[i+1],dp[i+q[i][1]+1]+q[i][0]);
        }
        
        return dp[0];
    }
};