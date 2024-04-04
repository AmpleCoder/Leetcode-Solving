/*
    mota mota hisab ye hei if current index element ko min le rhe hein then use case mei 
    left smallest index aur right smallest index ka track rkhne par we can figure out if the 
    curr element is candidate or not how? leftSmallestIndex < k && rightSmallestIndex > k
    bas aise hi har candidate ke corrsponding score nikal kr maximize kr diya 
*/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int size = nums.size(), maxScore = 0;
        stack<int> lse,rse;
        vector<int> leftSmallestIndex(size, -1);
        vector<int> rightSmallestIndex(size, size);

        for(int i = 0; i < size; i++){
            while(!lse.empty() && nums[i] <= nums[lse.top()]){
                lse.pop();
            }

            if(!lse.empty()){
                leftSmallestIndex[i] = lse.top();
            }

            lse.push(i);
        }

        for(int i = size -1; i >= 0; i--){
            while(!rse.empty() && nums[i] <= nums[rse.top()]){
                rse.pop();
            }

            if(!rse.empty()){
                rightSmallestIndex[i] = rse.top();
            }

            rse.push(i);
        }

        
        for(int i = 0; i < size; i++){
            int currScore = nums[i] * (rightSmallestIndex[i] - leftSmallestIndex[i] -1);

            if(leftSmallestIndex[i] < k && rightSmallestIndex[i] > k){
                maxScore = max(maxScore, currScore);
            }
        }

        return maxScore;
    }
};