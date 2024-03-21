class Solution {
public:
    long long numWaysUtil(int dp[501][501], int steps, int pos, int arrLen, int mod){
        if(steps == 0){
            return (pos == 0);
        }

        if(dp[steps][pos] != -1){
            return dp[steps][pos];
        }

        long long left = 0,right = 0,stay,numOfWays = 0;
        stay = numWaysUtil(dp, steps-1, pos, arrLen, mod);

        if(pos+1 < arrLen){
            right = numWaysUtil(dp, steps-1, pos+1, arrLen, mod);
        }

        if(pos-1 >= 0){
            left = numWaysUtil(dp, steps-1, pos-1, arrLen, mod);
        }

        numOfWays = left + right + stay;
        return dp[steps][pos] = numOfWays%mod;
    }

    int numWays(int steps, int arrLen) {
        int mod = (int)1e9 + 7;
        int dp[501][501];
        memset(dp,-1,sizeof(dp));
        return numWaysUtil(dp,steps,0,arrLen,mod);
    }
};