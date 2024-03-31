class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0, size = nums.size(), start = 0, minKIdx, maxKIdx, minIdx, lastBadIdx = -1;
        bool currMinFound = false, currMaxFound = false;

        for(int end = 0; end < size; end++){
            if(nums[end] < minK || nums[end] > maxK){
                currMinFound = currMaxFound = false;
                lastBadIdx = end;
            }

            if(nums[end] == minK){
                currMinFound = true;
                minKIdx = end;
            }

            if(nums[end] == maxK){
                currMaxFound = true;
                maxKIdx = end;
            }

            if(currMinFound && currMaxFound){
                minIdx = min(minKIdx, maxKIdx);
                result += (minIdx - lastBadIdx);
            }
        }

        return result;
    }
};