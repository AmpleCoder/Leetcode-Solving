/*
simple hei similar to spiral matrix 
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top,bottom,left,right,i,j,current=1;
        top=left=0;
        bottom=n-1;
        right=n-1;
        
        vector<vector<int>> ans(n,vector<int>(n));
        
        while(top<=bottom && left<=right)
        {
            for(i=left;i<=right;i++)
            {
                ans[top][i]=current++;
            }
            
            top++;
            
            if(top>bottom)  break;
            
            for(i=top;i<=bottom;i++)
            {
                ans[i][right]=current++;
            }
            
            right--;
            
            if(right<left)  break;
            
            for(i=right;i>=left;i--)
            {
                ans[bottom][i]=current++;
            }
            
            bottom--;
            
            if(bottom<top)  break;
            
            for(i=bottom;i>=top;i--)
            {
                ans[i][left]=current++;
            }
            
            left++;
        }
        
        return ans;
    }
};