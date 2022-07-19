/*
compute prefix sum after that fix rows and compute the prefix sum of that seg and use map to store those prefix sum's 
with this it'll become easy
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size(),numOfSubSumTarget=0;
        vector<vector<int>> prefixSum(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                prefixSum[i][j]=matrix[i][j];
                if(i>0)
                {
                    prefixSum[i][j]+=prefixSum[i-1][j];
                }
                
                if(j>0)
                {
                    prefixSum[i][j]+=prefixSum[i][j-1];
                }
                
                if(i>0 && j>0)
                {
                    prefixSum[i][j]-=prefixSum[i-1][j-1];
                }
            }
        }
        
        for(int row1=0;row1<row;row1++)
        {
            for(int row2=row1;row2<row;row2++)
            {
                unordered_map<int,int> prefixSumMap;
                
                for(int currCol=0;currCol<col;currCol++)
                {
                    int currSum=prefixSum[row2][currCol];
                    
                    if(row1>0)
                    {
                        currSum-=prefixSum[row1-1][currCol];
                    }
                    
                    if(currSum==target)
                    {
                        numOfSubSumTarget++;
                    }
                    
                    if(prefixSumMap.find(currSum-target)!=prefixSumMap.end())
                    {
                        numOfSubSumTarget+=prefixSumMap[currSum-target];
                    }
                    
                    prefixSumMap[currSum]++;
                }
            }
        }
        
        return numOfSubSumTarget;
    }
};