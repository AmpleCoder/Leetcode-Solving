/*
    5 candidates
        1) number of digit in candididate is less 
        2) number of digit in candididate is more 
        3) number of digit in candididate is equal
            1) keeping the first half same 
            2) increasing the first half by 1
            3) decreasing the first half by 1

        among above 5 cases we'll get our result
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        int size = n.size();

        if(size == 1){
            return to_string(stol(n) - 1);
        }

        long nearestPalindromicStringValue;
        long strValue = stol(n), difference;
        long minDiff = LONG_MAX;
        vector<long> candidates;
        candidates.push_back(pow(10, size - 1) - 1); // case 1
        candidates.push_back(pow(10, size) + 1); // case 2

        int mid = (size + 1)/2;
        string prefixStr = n.substr(0, mid);
        long prefix = stol(prefixStr);
        vector<long> remainingCandidates = {prefix, prefix - 1, prefix + 1};

        for(auto &currCandidate: remainingCandidates){
            long suffix = currCandidate;
            string suffixStr = to_string(suffix);

            if(size % 2 != 0){
                suffixStr.pop_back();
            }

            reverse(suffixStr.begin(), suffixStr.end());

            string currCandidateStr = to_string(currCandidate) + suffixStr;
            candidates.push_back(stol(currCandidateStr));
        }

        for(long currCandidate: candidates){
            if(currCandidate == strValue){
                continue;
            }

            cout << currCandidate << " ";
            difference = abs(strValue - currCandidate);
            
            if(difference < minDiff){
                minDiff = difference;
                nearestPalindromicStringValue = currCandidate;
            }

            else if(difference == minDiff){
                nearestPalindromicStringValue = min(nearestPalindromicStringValue, currCandidate);
            }
        }

        return to_string(nearestPalindromicStringValue);
    }
};