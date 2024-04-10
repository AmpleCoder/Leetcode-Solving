/*
    approach:
        same as maximal rectangle with thoda sa change  
*/

class Solution {
public:
    int maximumSquareAreaInGivenHistogram(vector<int> &height){
        int size = height.size(), currArea, maxArea = 0, currWidth, currHeight;
        stack<int> pse, nse;
        vector<int> psIdx(size, -1);
        vector<int> nsIdx(size, size);

        pse.push(0);

        for(int i = 1; i < size; i++){
            while(!pse.empty() && height[i] <= height[pse.top()]){
                pse.pop();
            }

            if(!pse.empty()){
                psIdx[i] = pse.top();
            }

            pse.push(i);
        }

        nse.push(size - 1);

        for(int i = size - 2; i >= 0; i--){
            while(!nse.empty() && height[i] <= height[nse.top()]){
                nse.pop();
            }

            if(!nse.empty()){
                nsIdx[i] = nse.top();
            }

            nse.push(i);
        }

        for(int i = 0; i < size; i++){
            currWidth = nsIdx[i] - psIdx[i] - 1;
            currHeight = height[i];

            if(currWidth >= currHeight){
                currArea = currHeight * currHeight;
                maxArea = max(maxArea, currArea);
            }
        }

        return maxArea;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int row, col, maxSquareArea = 0, currSquareArea;
        row = matrix.size();
        col = matrix[0].size();
        vector<int> height(col, 0);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    height[j] = (i == 0 ? 1 : height[j] + 1);
                }

                else{
                    height[j] = 0;
                }
            }

            currSquareArea = maximumSquareAreaInGivenHistogram(height);
            maxSquareArea = max(maxSquareArea, currSquareArea);
        }

        return maxSquareArea;
    }
};