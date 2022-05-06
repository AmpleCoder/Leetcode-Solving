/*
very sexy problem 
methods to solve 
1)brute force
2)using count array
3)stack
4)stack with reconstruction
5)two pointer

ps : one of the new learnings
    int count = x.first;
    char c = x.second;

    for(i=0;i<count;i++){
        ans.push_back(c);
    }

    can be replaced by 
    ans+=string(count,c)
*/

class Solution {
public:
    string removeDuplicates(string str, int k) {
        vector<pair<int,char>> s;
        int size=str.size(),i;
        
        for(i=0;i<size;i++){
            if(s.empty() || str[i]!=s.back().second){
                s.push_back({1,str[i]});
            }
            
            else{
                s.back().first++;
                if(s.back().first==k){
                    s.pop_back();
                }
            }
        }
        
        string ans;
        
        for(auto &x:s){
            int count = x.first;
            char c = x.second;
            
            for(i=0;i<count;i++){
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};