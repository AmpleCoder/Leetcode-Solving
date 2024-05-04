/*
    approach:
        take all pair of two number and keep on forming upto largest possible fibonacci value and track and maximise len

    follow up:
        figuring out TC is key here
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int size = arr.size(), longestFibSubSeq = 0;
        unordered_set<int> s(arr.begin(), arr.end());

        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int firstVal = arr[i];
                int secondVal = arr[j];
                int currFibSubSeqLen = 2;
                int nextNum = firstVal + secondVal;

                while(s.find(nextNum) != s.end()){
                    firstVal = secondVal;
                    secondVal = nextNum;
                    nextNum = firstVal + secondVal;
                    currFibSubSeqLen++;
                }

                if(currFibSubSeqLen > 2){
                    longestFibSubSeq = max(longestFibSubSeq, currFibSubSeqLen);
                }
            }
        }

        return longestFibSubSeq;
    }
};