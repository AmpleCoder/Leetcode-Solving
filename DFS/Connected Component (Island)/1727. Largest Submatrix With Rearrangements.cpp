/*

*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row,col,maxArea=0;
        row=matrix.size();
        col=matrix[0].size();
        
        vector<vector<int>> consecutiveOnes(row,vector<int>(col,0));
        
        for(int i=0;i<col;i++)
        {
            int ones=0;
            
            for(int j=0;j<row;j++)
            {
                if(matrix[j][i]==1)
                {
                    ones++;
                }
                
                else
                {
                    ones=0;
                }
                
                consecutiveOnes[j][i]=ones;
            }
        }
        
        for(int i=0;i<row;i++)
        {
            sort(consecutiveOnes[i].begin(),consecutiveOnes[i].end());
        }
        
        for(int i=0;i<row;i++)
        {
            int currRowMaxArea=0;
            
            for(int j=0;j<col;j++)
            {
                currRowMaxArea=max(currRowMaxArea,consecutiveOnes[i][j]*(col-j));
            }
            
            maxArea=max(maxArea,currRowMaxArea);
        }
        
        return maxArea;
    }
};