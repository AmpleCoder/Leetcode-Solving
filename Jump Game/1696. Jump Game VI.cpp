/*
current index ko reach krne ke  liye humko {i-k,...,i} tak ki window ka best lena pdega 
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int size=nums.size();
        deque<int> q{0};
        vector<int> dp(size);
        dp[0]=nums[0];
        
        for(int i=1;i<size;i++)
        {
            if(q.front()<i-k)
            {
                q.pop_front();
            }
            
            dp[i]=nums[i]+dp[q.front()];
            
            while(!q.empty() && dp[q.back()]<=dp[i])
            {
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        return dp[size-1];
    }
};