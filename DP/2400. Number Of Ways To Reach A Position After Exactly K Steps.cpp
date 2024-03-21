class Solution {
public:
    long long numberOfWays(long long cache[3001][1001], int currPos, int endPos, int steps, int mod){
        //base case 
        if(steps == 0){
            return (currPos == endPos);
        }

        if(cache[currPos + 1000][steps] != -1){
            return cache[currPos + 1000][steps];
        }


        long long left, right, currNumberOfWays;
        left = numberOfWays(cache, currPos - 1, endPos, steps - 1, mod);
        right = numberOfWays(cache, currPos + 1, endPos, steps - 1, mod);

        currNumberOfWays = (left + right) % mod;
        return cache[currPos + 1000][ steps] = currNumberOfWays;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int mod = (int)1e9 + 7;
        long long cache[3001][1001];

        memset(cache, -1, sizeof(cache));

        return	numberOfWays(cache, startPos, endPos, k, mod);
    }
};