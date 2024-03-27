class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int currProduct = 1, size = nums.size(), numOfSubArr = 0, start = 0;

        for(int end = 0; end < size; end++){
            currProduct *= nums[end];

            while(start <= end && currProduct >= k){
                currProduct /= nums[start++];
            }

            numOfSubArr += (end - start + 1);
        }

        return numOfSubArr;
    }
};