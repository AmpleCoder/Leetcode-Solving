/*
need of the problem is just char so we need to figure out way to store all diff char present in the given string 
this can be done via bitwise
*/

class Solution {
public:
    int maxProduct(vector<string>& arr) {
        int ans=0,size=arr.size();
        vector<int> val(size,0);
        
        for(int i=0;i<size;i++)
        {
            string currStr = arr[i];
            
            for(char &currChar:currStr)
            {
                val[i]|=(1<<(currChar-'a'));
            }
        }
        
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                bool flag = 1;
                
                for(int k=0;k<26;k++)
                {
                    if(((val[i]>>k)&1) && ((val[j]>>k)&1)){
                        flag=0;
                        break;
                    }
                }
                
                if(flag==1){
                    ans=max(ans,(int)arr[i].size()*(int)arr[j].size());
                }
            }
        }
        
        return ans;
    }
};