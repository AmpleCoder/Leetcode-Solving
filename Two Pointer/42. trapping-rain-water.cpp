class Solution {
public:
    int trap(vector<int>& height) {
         int size=height.size(),lo=0,hi=size-1,i=0,trapWater=0,leftMax,rightMax;
         leftMax=rightMax=INT_MIN;

         while(lo<=hi){
            if(height[lo] <= height[hi]){
                if(leftMax <= height[lo]){
                    leftMax = height[lo];
                }

                else{
                    trapWater += leftMax - height[lo];
                }

                lo++;
            }

            else{
                if(rightMax <= height[hi]){
                    rightMax = height[hi];
                }

                else{
                    trapWater += rightMax - height[hi];
                }

                hi--;
            }

             i++;
         }

         return trapWater;
    }
};