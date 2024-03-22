/*
    isme dp optimisation lagana hei 
        - prefix sum wala jisse tc kam hogi
        - space optimisation
*/

class Solution {
public:
    long long numPermsDISequenceUtil(long long dp[201][201], int currIndex, int prevValue, bool visited[201], string &s, int &n, int &mod){
        //base case 
        if(currIndex > n){
            return 1;
        }

        if(dp[currIndex][prevValue] != -1){
            return dp[currIndex][prevValue];
        }

        long long currNumberOfWays, totalNumberOfWays = 0;

        for(int i=0; i<=n; i++){
            currNumberOfWays = 0;

            if(visited[i] == false){
                visited[i] = true;

                if(s[currIndex - 1] == 'D' && i < prevValue){
                    currNumberOfWays = numPermsDISequenceUtil(dp, currIndex + 1, i, visited, s, n, mod);
                }

                else if(s[currIndex - 1] == 'I' && i > prevValue){
                    currNumberOfWays = numPermsDISequenceUtil(dp, currIndex + 1, i, visited, s, n, mod);
                }

                visited[i] = false;
            }

            totalNumberOfWays = (totalNumberOfWays + currNumberOfWays) % mod;
        }

        return dp[currIndex][prevValue] = totalNumberOfWays;
    }

    int numPermsDISequence(string s) {
        int mod = (int)1e9 + 7, size = s.size();
        bool visited[201];
        long long dp[201][201];
        long long numOfPerms = 0;
        
        memset(visited, false, sizeof(visited));
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i <= size; i++){
            visited[i] = true;
            numOfPerms = (numOfPerms + numPermsDISequenceUtil(dp, 1, i, visited, s, size, mod)) % mod;
            visited[i] = false;
        }

        return numOfPerms;
    }
};