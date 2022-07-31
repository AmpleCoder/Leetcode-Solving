/*
very unique sort of problem
*/
class Solution {
public:
    int maximumGroups(vector<int>& a) {
        int size=a.size();
        int currGrpSize=0,totalEleCount=0;
        
        while(currGrpSize+totalEleCount+1<=size)
        {
            currGrpSize++;
            totalEleCount+=currGrpSize;
        }
        
        return currGrpSize;
    }
};