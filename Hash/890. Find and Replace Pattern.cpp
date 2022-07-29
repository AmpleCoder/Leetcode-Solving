/*
map both and check if both matches or not
*/

class Solution {
public:
    bool isMatching(string str,string pattern)
    {
        unordered_map<char,char> m1,m2;
        string str1,str2;
        int size=str.size();
        
        for(int i=0;i<size;i++)
        {
            if(m1.find(pattern[i])==m1.end())
            {
                m1[pattern[i]]=str[i];
            }
            
            if(m2.find(str[i])==m2.end())
            {
                m2[str[i]]=pattern[i];
            }
        }
        
        for(int i=0;i<size;i++)
        {
            str1.push_back(m1[pattern[i]]);
            str2.push_back(m2[str[i]]);
        }
        
        return (str1==str && str2==pattern);
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(auto &currWord:words)
        {
            bool flag = isMatching(currWord,pattern);
            if(flag)
            {
                ans.push_back(currWord);
            }
        }
        
        return ans;
    }
};