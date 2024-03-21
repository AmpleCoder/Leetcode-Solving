class Solution {
public:
    int minCostToMakeItPalindrom(string &s, int start, int end){
        int minCost = 0;
        
        while(start < end){
            if(s[start] != s[end]){
                minCost++;
            }

            start++;
            end--;
        }

        return minCost;
    }

    int  palindromePartitionUtil(string &s, int currIndex,int  k, int cache[1001][1001], int minCostPalindrom[1001][1001]){
        //base case
        if(k == 0 && currIndex != -1){
            return (int)1e9;
        }

        //base case
        if(currIndex < 0){
            if(k == 0){
                return 0;
            }

            return (int)1e9;
        }

        if(cache[currIndex][k] != -1){
            return cache[currIndex][k];
        }

        int minCost = INT_MAX, currMinCost;

        for(int i=currIndex; i>=0; i--){
            currMinCost = palindromePartitionUtil(s, i-1, k-1, cache, minCostPalindrom) + minCostPalindrom[i][currIndex];
            minCost = min(minCost, currMinCost);
        }

        return cache[currIndex][k] = minCost;
    }

    int palindromePartition(string s, int k) {
        int size = s.size();
        int minCostPalindrom[1001][1001];
        int cache[1001][1001];
        
        memset(cache, -1, sizeof(cache));

        for(int i=0; i<size; i++){
            for(int j=i; j<size; j++){
                minCostPalindrom[i][j] = minCostToMakeItPalindrom(s, i, j);
            }
        }
        
        return palindromePartitionUtil(s, size - 1, k, cache, minCostPalindrom);
    }
};