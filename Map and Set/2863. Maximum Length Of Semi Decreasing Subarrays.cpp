/*
    approach:
        vector of pair bana liya such that (arr[i], i) ko store krke sort kr diya on the basis of first value 
        agar first value two ele ki same hei to jiska index small hei wo phle aayega now for a given element 
        ke liye best size dec subarray kon banayega ? jo uske rigth mei hoga aur jiska index min as possible hoga 
        and that index < currEleIndex 
        is approach se number of dec sub nikalna bhi easy hei

    follow up :
        try solving it in O(n) time and space
*/

class Solution {
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }

        return a.first < b.first;
    }

    int maxSubarrayLength(vector<int>& nums) {
        int size = nums.size(), maxSubLen = 0, currLen;
        vector<pair<int, int>> v;
        set<int> s;

        for(int i = 0; i < size; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), compare);
        s.insert(v[size-1].second);

        for(int i = size - 2; i >= 0; i--){
            int firstValueOfSet = *(s.begin());

            if(firstValueOfSet < v[i].second){
                currLen = v[i].second - firstValueOfSet + 1;
                maxSubLen = max(maxSubLen, currLen);
            }

            s.insert(v[i].second);
        }

        return maxSubLen;
    }
};