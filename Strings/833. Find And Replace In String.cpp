/*
    approach:
        first mark all the legit indexes where source can be replaced by target then replace it using another string result
*/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int strSize = s.size();
        int size = indices.size();
        vector<int> validIndex(strSize, -1);
        string result;

        for(int i = 0; i < size; i++){
            int idx = indices[i];
            string srcStr = sources[i];
            int srcStrSize = srcStr.size();

            // check if from idx to srcStrSize srcStr == given string from [idx....srcStr] or we not we can do this using compare as well in cpp
            if(s.compare(idx, srcStrSize, srcStr) == 0){
                validIndex[idx] = i;
            }
        }

        int i = 0;

        while(i < strSize){
            if(validIndex[i] >= 0){
                result += targets[validIndex[i]];
                i += sources[validIndex[i]].size();
            }

            else{
                result.push_back(s[i++]);
            }
        }

        return result;
    }
};