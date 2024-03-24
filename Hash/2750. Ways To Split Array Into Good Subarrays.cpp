/*
    follow ups:
    1) number of ways to partition the binary array so that every part will be having a sum = k
    2) number of ways to partition the array so that every part will be having a equal sum
    3) number of ways to partition the array so that every part will be having a sum = k
*/

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