class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int size = nums.size(), mod = (int)1e9 + 7, sum = 0, count = 1;
        long res = 1; 

        for(int i=0; i<size; i++){
            sum += nums[i];
            if(sum > 0){
                if(nums[i] == 0){
                    count++;
                }

                else{
                    res = (res * count)%mod;
                    count = 1;
                }
            }
        }

        if(sum == 0){
            return 0;
        }

        return res;
    }
};