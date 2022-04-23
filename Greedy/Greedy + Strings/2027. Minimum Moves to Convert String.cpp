/*
once we found x in s[i] then s[i],s[i+1],s[i+2] are anyway going to become 'O'
now things are very clear
*/

class Solution {
public:
    int minimumMoves(string s) {
        int ans=0,i=0,size=s.size();
        
        while(i<size){
            if(s[i]=='O'){
                i++;
            }
            
            else{
                ans++;
                i+=3;
            }
        }
        
        return ans;
    }
};