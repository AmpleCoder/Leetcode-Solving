/*
    approach:
        pretty simple and yet awesome observation is that if we've given two end diagonal points then we can fetch 
        the remain end point point of other diagonal

    follow up:
        1) max area rectangle
        2) number of rectangle 
        3) min/max area rectangle if axis is rotated by theta degree
        4) min/max area for other shapes
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int, int>> pointSet;
        int minArea = INT_MAX, size = points.size(), currArea;

        for(auto &currPoint: points){
            int x, y;
            x = currPoint[0];
            y = currPoint[1];
            pair<int, int> currPointPair;
            currPointPair.first = x;
            currPointPair.second = y;
            pointSet.insert(currPointPair);
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                int x1, x2, y1, y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];

                if(x1 == x2 || y1 == y2){
                    continue;
                }

                pair<int, int> endPoint1;
                pair<int, int> endPoint2;
                endPoint1.first = x1;
                endPoint1.second = y2;

                endPoint2.first = x2;
                endPoint2.second = y1;

                if(pointSet.find(endPoint1) != pointSet.end() && pointSet.find(endPoint2) != pointSet.end()){
                    currArea = abs(x1 - x2) * abs(y1 - y2);
                    minArea = min(minArea, currArea);
                }
            }
        }

        return (minArea == INT_MAX ? 0 : minArea);
    }
};