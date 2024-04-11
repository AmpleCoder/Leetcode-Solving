/*
    approach:
        mono stack maintain rkha with increasing order ab curr ele i.e if ele at ith index is < stack/deque top ele 
        we can remove current stack top only in one condition that count of elements that are yet to be pushed + stackSize - 1 >= k' 
        k' = number of elements we're willing to keep in our solution 
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> res;
        int size = num.size();
        k = size - k;

        for(int i = 0; i < size; i++){
            while(!res.empty() && res.back() > num[i] && (size - i) + (res.size() - 1) >= k){
                res.pop_back();
            }

            if(res.size() < k){
                res.push_back(num[i]);
            }
        }

        while(!res.empty() && res.front() == '0'){
            res.pop_front();
        }

        string result;

        while(!res.empty()){
            result.push_back(res.front());
            res.pop_front();
        }

        return ((result == "") ? "0" : result);
    }
};