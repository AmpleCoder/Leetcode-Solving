/*
    solving this via iterative dp is easier as it leads to more sense to define it this way
    dp[i][j] = maximum length common sub-array ending at a[i] and b[j]
*/

class Solution {
public:
    int maxRepeatedLength(vector<int> &nums1,vector<int> &nums2, int dp[1001][1001], int index1, int index2, int size1, int size2, int &maxCommonLen){
        if(index1 >= size1 || index2 >= size2){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        int currResult = 0;

        if(nums1[index1] == nums2[index2]){
            currResult = 1 + maxRepeatedLength(nums1, nums2, dp, index1 + 1, index2 + 1, size1, size2, maxCommonLen);
            maxCommonLen = max(maxCommonLen, currResult);
        }

        maxRepeatedLength(nums1, nums2, dp, index1 + 1, index2, size1, size2, maxCommonLen);
        maxRepeatedLength(nums1, nums2, dp, index1, index2 + 1, size1, size2, maxCommonLen);

        return dp[index1][index2] = currResult;
}



    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        int maxCommonLen = 0;
        maxRepeatedLength(nums1, nums2, dp, 0, 0, nums1.size(), nums2.size(), maxCommonLen);
        return maxCommonLen;
    }
};