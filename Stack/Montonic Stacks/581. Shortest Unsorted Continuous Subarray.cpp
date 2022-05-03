/*
good problem can be solved in multuple ways
1)using stack(try to implement on ypur own)
2)neeche wali method(LC ka solution revisit kr skte ho in case kuch smjhe nhi to)
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size(),mini=INT_MAX,maxi=INT_MIN,l,r,i;
        bool flag=false;
        
        for(i=1;i<n;i++){
            if(a[i-1]>a[i]){
                flag=true;
            }
            
            if(flag){
                mini=min(mini,a[i]);
            }
        }
        
        flag=false;
        
        for(i=n-2;i>=0;i--){
            if(a[i]>a[i+1]){
                flag=true;
            }
            
            if(flag){
                maxi=max(maxi,a[i]);
            }
        }
        
        for(l=0;l<n;l++){
            if(a[l]>mini){
                break;
            }
        }
        
        for(r=n-1;r>=0;r--){
            if(a[r]<maxi){
                break;
            }
        }
        
        return (r>l?r-l+1:0);
    }
};