#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        vector<long long> distance(vector<int>& nums) {
            int size = nums.size();
            unordered_map<int, vector<int>> equalValIndexList;
            vector<long long> distanceList(size,0);

            for(int i = 0; i < size; i++){
                equalValIndexList[nums[i]].push_back(i);
            }        

            for(auto &currIndexList: equalValIndexList){
                vector<int> currIndexes = currIndexList.second;
                int currSize = currIndexes.size();
                if(currSize == 1){
                    continue;
                }

                vector<long long> prefixSum(currSize,0);
                prefixSum[0] = currIndexes[0];

                for(int i = 1; i < currSize; i++){
                    prefixSum[i] = prefixSum[i-1] + currIndexes[i];
                }

                distanceList[currIndexes[0]] = (currSize - 1)*prefixSum[1];

                for(int i = 0; i < currSize; i++){
                    long long leftSize = 0, rightSize = 0, leftSum = 0, rightSum = 0;
                    leftSize = i;
                    rightSize = (currSize - 1 - i);
                    if(i > 0){
                        leftSum = prefixSum[i-1];
                    }

                    if(i < currSize - 1){
                        rightSum = prefixSum[currSize - 1] - prefixSum[i];
                    }

                    distanceList[currIndexes[i]] = leftSize * currIndexes[i] - leftSum + rightSum - rightSize * currIndexes[i];
                }
            }

            return distanceList;
        }

};

int main(){
    cout << "![Screenshot](2615.png)" << endl;
}