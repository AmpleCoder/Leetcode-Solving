/*
good problem involving concept of prefix sum + sliding window 

ps : solve more problems from ps+sw to get a sexy grasp
*/

class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int size=a.size(),i,ans=0,j;
        vector<int> suffix(k),prefix(k);
        prefix[0]=a[0];
        suffix[0]=a[size-1];
        
        for(i=1;i<k;i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        
        for(i=size-2;i>=size-k;i--){
            suffix[size-1-i]=suffix[size-i-2]+a[i];
        }
        
        // for(i=0;i<k;i++)
        // {
        //     cout<<prefix[i]<<" "<<suffix[i]<<endl;
        // }
        
        // cout<<endl;
        
        for(i=-1;i<k;i++){
            int leftVal,rightVal;
            if(i==-1){
                leftVal=0;
            }
            
            else {
                leftVal=prefix[i];
            }
            
            if(i==k-1){
                rightVal=0;
            }
            
            else {
                rightVal=suffix[k-i-2];
            }
            
            ans=max(ans,leftVal+rightVal);
        }
        
        return ans;
    }
};