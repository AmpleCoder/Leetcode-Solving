class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> duplicatesList;
        
        for(int i = 0; i < size; i++){
            int currentValue = abs(nums[i]);
            if(nums[currentValue - 1] < 0){
                duplicatesList.push_back(currentValue);
            }

            else{
                nums[currentValue - 1] *= -1;
            }
        }

        return duplicatesList;
    }


};