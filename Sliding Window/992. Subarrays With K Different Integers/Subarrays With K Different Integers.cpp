class Solution {
public:
    int atleast(vector<int> &nums, int k){
        int size = nums.size(), result = 0, start = 0;
        unordered_map<int, int> freq;


        for(int end = 0; end < size; end++){
            freq[nums[end]]++;
            
            while(start <= end && freq.size() >= k){
                freq[nums[start]]--;

                if(freq[nums[start]] == 0){
                    freq.erase(nums[start]);
                }

                start++;
            }

            result += start;
        }

        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int size = nums.size(), start = 0, numOfSubArr = 0;
        return atleast(nums, k) - atleast(nums, k + 1); 
    }
};