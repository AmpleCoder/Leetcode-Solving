class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), qSize = queries.size();
        long long sum = 0;
        vector<long long> prefix(size, 0);
        vector<long long> resultVec(qSize);

        for(int i = 0; i < size; i++){
            sum += nums[i];
            prefix[i] = sum;
        }

        for(int i = 0; i < qSize; i++){
            int currQ = queries[i];
            int idx = upper_bound(nums.begin(), nums.end(), currQ) - nums.begin();
            long long lCount = 0, rCount = 0, lSum = 0, rSum = 0, result;

            if(idx > 0){
                lSum = prefix[idx - 1];
            }

            lCount = idx;
            rSum = sum - lSum;
            rCount = size - lCount;

            // cout << idx << endl;

            result = (lCount * currQ - lSum) + (rSum - rCount * currQ);
            resultVec[i] = result;
        }

        return resultVec;
    }
};