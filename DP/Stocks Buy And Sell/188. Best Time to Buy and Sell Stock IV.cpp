/*

Easy to understand explanation for the above solution

dp[i][j] = maximum profit from at most i transactions using prices[0..j]

A transaction is defined as one buy + sell.

Now on day j, we have two options

Do nothing (or buy) which doesn't change the acquired profit : dp[i][j] = dp[i][j-1]

Sell the stock: In order to sell the stock, you must've bought it on a day t=[0..j-1]. Maximum profit that can be attained is t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) where prices[j]-prices[t] is the profit from buying on day t and selling on day j. dp[i-1][t-1] is the maximum profit that can be made with at most i-1 transactions with prices prices[0..t-1].

Time complexity of this approach is O(n2k).

In order to reduce it to O(nk), we must find t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) this expression in constant time. If you see carefully,

t:0->j-1 max(prices[j]-prices[t]+dp[i-1][t-1]) is same as

prices[j] + t:0->j-1 max(dp[i-1][t-1]-prices[t])

Second part of the above expression maxTemp = t:0->j-1 max(dp[i-1][t-1]-prices[t]) can be included in the dp loop by keeping track of the maximum value till j-1.

Base case:

dp[0][j] = 0; dp[i][0] = 0

DP loop:

for i : 1 -> k
    maxTemp = -prices[0];
    for j : 1 -> n-1
        dp[i][j] = max(dp[i][j-1], prices[j]+maxTemp);
        maxTemp = max(maxTemp, dp[i-1][j-1]-prices[j]);
return dp[k][n-1];

*/

class Solution {
public: 
    int maxProfit(int k, vector<int>& a) {
        int size=a.size();
        if(size==0 || k==0)
        {
            return 0;
        }
        
        int dp[size][k+1];
        // memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<size;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<=k;i++)
        {
            dp[0][i]=0;
        }
        
        for(int j=1;j<=k;j++)
        {
            int localmax=-a[0];
            
            for(int i=1;i<size;i++)
            {
                dp[i][j]=max(dp[i-1][j] , localmax + a[i]);
                
                localmax=max(localmax,dp[i-1][j-1]-a[i]);
            }
        }
        
        
        return dp[size-1][k];
    }
};




class Solution {
public: 
    int maxProfit(int k, vector<int>& a) {
        int size=a.size();
        if(size==0 || k==0)
        {
            return 0;
        }
        
        int dp[size][k+1];
        // memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<size;i++)
        {
            dp[i][0]=0;
        }
        
        for(int i=0;i<=k;i++)
        {
            dp[0][i]=0;
        }
        
        for(int j=1;j<=k;j++)
        {
            for(int i=1;i<size;i++)
            {
                dp[i][j]=dp[i-1][j];
                
                for(int t=0;t<=i;t++)
                {
                    // cout<<dp[t-1][j-1]+a[i]-a[t]<<endl;
                    dp[i][j]=max(dp[i][j],(t-1<0?0:dp[t-1][j-1])+a[i]-a[t]);
                }
            }
        }
        
//         for(int i=0;i<size;i++)
//         {
//             for(int j=0;j<=k;j++)
//             {
//                 cout<<dp[i][j]<<" ";
//             }
            
//             cout<<endl;
//         }
        
        return dp[size-1][k];
    }
};