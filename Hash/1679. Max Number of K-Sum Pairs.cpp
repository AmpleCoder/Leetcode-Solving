/*
problem is to find the number of pairs having sum = k
so it can be done in many ways some ways are 
1)sort + 2 pointer simple hei as ek bar pair bana liya to un ele ko use krke dusra pair nhi banaya jaa skta 
2)using map (code dekhlo feel aa jayegi)
*/

class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        unordered_map<int,int> m;
        int size=a.size(),i,ans=0,c1,c2;
        
        for(i=0;i<size;i++){
            m[a[i]]++;
        }
        
        for(auto &x:m){
            int ele=x.first;
            int count=x.second;
            
            if(ele==k-ele){
                ans+=count/2;
            } 
            
            else if(m.count(k-ele)){
                int mini=min(m[ele],m[k-ele]);
                ans+=mini;
                m[ele]-=mini;
                m[k-ele]-=mini;
                
            }
        }
        
        return ans;
    }
};