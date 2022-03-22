/*
apne ko basically har us substring ko consider krna hei jisme size of that string - maxlen <=k ho  iski size ko maximize krna hei 
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(),start=0,end,ans=0,maxFreq=0;
        unordered_map<int,int> freq; 
        
        for(end=0;end<size;end++){
            maxFreq = max(maxFreq,++freq[s[end]-'A']);
            
            while(end - start + 1 - maxFreq > k){
                freq[s[start]-'A']--;
                start++;
            }
            
            ans = max(ans,end-start+1);
        }
        
        return ans;
    }
};