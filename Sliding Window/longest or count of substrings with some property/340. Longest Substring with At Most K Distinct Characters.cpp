/*
we need to first find out the maximum length substring at each index having atmost k distinct charecters
then we can make a choice to pick the max one simple 
so for that we need to mainatain a freq of charecters
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start=0,end,size=s.size(),ans=0,distinct=0;
        unordered_map<char,int> mp;
        
        for(end=0;end<size;end++){
            if(mp[s[end]]==0)
            {
                distinct++;
            }
            
            mp[s[end]]++;
            
            while(distinct > k){
                mp[s[start]]--;
                
                if(mp[s[start]]==0){
                    distinct--;
                }
                
                start++;
            }
            
            ans = max(ans,end-start+1);
        }
        
        return ans;
    }
};