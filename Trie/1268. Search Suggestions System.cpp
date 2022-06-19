/*
ye to binary search wala solution hei iska trie wala cover krenge
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        string str="";
        sort(products.begin(),products.end());
        auto it=products.begin();
        
        for(auto &c:searchWord)
        {
            str.push_back(c);
            vector<string> currList;
            
            it=lower_bound(it,products.end(),str);
            
            for(int i=0;i<3 && it+i!=products.end();i++)
            {
                string currStr=*(it+i);
                if(currStr.find(str))
                {
                    break;
                }
                
                currList.push_back(currStr);
            }
            
            ans.push_back(currList);
        }
        
        return ans;
    }
};