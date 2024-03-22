class Solution {
public:
    long long numOfArraysUtil(long long dp[51][101][51], int currIndex, int lastMax, int searchCost, int size, int m, int k, int mod){
        //base case 
        if(currIndex == size){
            return searchCost == k;
        }

        if(dp[currIndex][lastMax][searchCost] != -1){
            return dp[currIndex][lastMax][searchCost];
        }

        long long currNumOfWays = 0, totalNumOfWays = 0;

        for(int i = 1; i <= m; i++){

            if(i <= lastMax){
                currNumOfWays = numOfArraysUtil(dp, currIndex + 1, lastMax, searchCost,  size, m, k, mod);
            }

            else{
                currNumOfWays = numOfArraysUtil(dp, currIndex + 1, i, searchCost + 1, size, m, k , mod);
            }

            totalNumOfWays = (totalNumOfWays + currNumOfWays) % mod;
        }

        return dp[currIndex][lastMax][searchCost] = totalNumOfWays;
    }

    int numOfArrays(int n, int m, int k) {
        int mod = (int)1e9 + 7, lastMax = 0, searchCost = 0;
        long long dp[51][101][51];
        memset(dp, -1, sizeof(dp));
        return numOfArraysUtil(dp, 0, lastMax, searchCost, n, m, k, mod);       
    }
};