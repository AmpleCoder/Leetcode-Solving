/*
easy one

ps : use mnIdx = min_element(a.begin(),a.end())-a.begin();
         mxIdx = max_element(a.begin(),a.end())-a.begin();
        to fetch out the indexes for min ele and max ele
*/

class Solution {
public:
    int minimumDeletions(vector<int>& a) {
        int size=a.size(),i,posmn,posmx,mx,mn,ans=100001;
        mx=INT_MIN;
        mn=INT_MAX;
        
        for(i=0;i<size;i++){
            if(a[i]>mx){
                posmx=i;
                mx=a[i];
            }
            
            if(a[i]<mn){
                posmn=i;
                mn=a[i];
            }
        }
        
        if(posmn>posmx){
            swap(posmn,posmx);
        }
        
        ans=min({ans,posmx+1,size-posmn,size-posmx+posmn+1});
        return ans;
    }
};