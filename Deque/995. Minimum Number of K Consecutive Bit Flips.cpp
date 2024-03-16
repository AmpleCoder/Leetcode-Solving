/*
if we're at a certain element to figure out how many times it has been flipped along the way will be decided by size of 
queue and accordingly we can take the action
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int size=nums.size(),minFlips=0,currFlips;
        queue<int> q;

        for(int i=0;i<size;i++){
            if(q.size() && q.front()<i){
                q.pop();
            }

            currFlips=q.size()%2;
            if((currFlips==0 && nums[i]==0) || (currFlips==1 && nums[i]==1)){
                if(i+k-1>=size){
                    return -1;
                }

                minFlips++;
                q.push(i+k-1);
            }
        }

        return minFlips;
    }
};