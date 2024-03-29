/*
    pretty problem ek mistake ye ki thi ki only considered iterating when element = maximum
    sab mei krenge tbhi to pichla result concatenate hoga 
    
    follow ups
        1) num of subarrays with #(arr ka max) < k
        2) num of subarrays with #(arr ka min) >= k
        3) num of subarrays with #(us sub-arr ka min/max) >= k
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int size = nums.size(), start = 0, end, maximum = 0, maxiCount = 0;
        long long result = 0;

        for(int i = 0; i < size; i++){
            maximum = max(maximum, nums[i]);
        }

        for(end = 0; end < size; end++){
            if(nums[end] == maximum){
                maxiCount++;
            }

            while(start <= end && maxiCount >= k){
                if(nums[start] == maximum){
                    maxiCount--;
                }

                start++;
            }

            result += start;
        }

        return result;        
    }


};