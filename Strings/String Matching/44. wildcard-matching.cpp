/*
    approach:
        nice problem lot of cases to consider and overall it's a good problem
*/


class Solution {
public:
    bool isMatchUtil(vector<vector<int>> &dp, string &s, string &p, int i, int j, int &size1, int &size2){
        if(j == size2){
            return i == size1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(p[j] == '*'){
            return dp[i][j] = ((i < size1 && isMatchUtil(dp, s, p, i + 1, j, size1, size2))
             || isMatchUtil(dp, s, p, i, j + 1, size1, size2));
        }

        else if(i < size1 && (p[j] == '?' || s[i] == p[j])){
            return dp[i][j] = isMatchUtil(dp, s, p, i + 1, j + 1, size1, size2);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int size1, size2;
        size1 = s.size();
        size2 = p.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1));
        return isMatchUtil(dp, s, p, 0, 0, size1, size2);
    }
};