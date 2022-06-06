/*
one of the sexiest problem in Leetcode 
solution inspired from lee's logic
*/

class Solution {
public:
    int totalSteps(vector<int>& a) {
        int size=a.size(),ans=0;
        stack<int> s;
        vector<int> dp(size,0);
        
        for(int i=size-1;i>=0;i--)
        {
            while(!s.empty() && a[i] > a[s.top()])
            {
                dp[i]=max(dp[i]+1,dp[s.top()]);       
                s.pop();
            }
            
            ans=max(ans,dp[i]);
            s.push(i);
        }
        
        return ans;
    }
};