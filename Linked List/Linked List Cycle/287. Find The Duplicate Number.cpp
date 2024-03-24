/*
    here to figure out the starting point of the cirlce is really a cool step
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};