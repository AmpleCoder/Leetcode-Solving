/*
    approach1 :- 
        as we know if in a subarray the diff between the max and min val is <= limit then each and every pair will 
        satisfy the same condition hence we can use multiset to store and fetch the max and min and keep on popping ele 
        which are of no use for us from start 
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int size = nums.size(), start = 0, maxSize = 1;

        for(int end = 0; end < size; end++){
            m.insert(nums[end]);

            while(start <= end && (*(m.rbegin()) - *(m.begin()) > limit)){
                m.erase(m.find(nums[start]));
                start++;
            }

            maxSize = max(maxSize, end - start + 1);
        }
        
        return maxSize;
    }
};