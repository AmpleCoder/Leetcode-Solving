/*
isme check krne wala step ki kon sa segment [low,mid] ya [mid,hi] wala sorted hei wo easy hei 
bus ek case handle krna hei mid find krne ke phle hi wo saare lo aur high ko skip kr do jo duplicate hein 
worst case mei O(n) to jayega hi jayega  
*/

class Solution {
public:
    bool search(vector<int>& a, int target) {
        int lo=0,hi=a.size()-1,mid;
        
        while(lo<=hi)
        {
            while(lo<hi && a[lo]==a[lo+1]){
                lo++;
            }
            
            while(lo<hi && a[hi]==a[hi-1]){
                hi--;
            }
            
            mid=lo+(hi-lo)/2;
            
            if(a[mid]==target){
                return true;
            }
            
            if(a[lo]<=a[mid]){
                if(a[lo]<=target && target<a[mid]){
                    hi=mid-1;
                }
                
                else{
                    lo=mid+1;
                }
            }
            
            else{
                if(a[mid]<target && target<=a[hi]){
                    lo=mid+1;
                }
                
                else{
                    hi=mid-1;
                }
            }
        }
        
        return false;
    }
};