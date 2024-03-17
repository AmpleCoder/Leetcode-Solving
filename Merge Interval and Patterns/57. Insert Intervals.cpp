class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int size=intervals.size(),i=0;
       vector<vector<int>> result;

       //add all the elements having start < newInterval.start i.e newInterval[0]
       while(i<size && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i++]);
       }

       //merge all mergable intervals with new interval
       while(i<size && intervals[i][0] <= newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
       }

       result.push_back(newInterval);

       while(i<size){
            result.push_back(intervals[i++]);
       }

       return result;
    }
};