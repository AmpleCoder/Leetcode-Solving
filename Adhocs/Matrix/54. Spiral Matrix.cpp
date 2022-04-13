class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a)
    {
        int top,bottom,left,right,i,j;
        top=left=0;
        bottom=a.size()-1;
        right=a[0].size()-1;
        
        vector<int> ans;
        
        while(top<=bottom && left<=right)
        {
            for(i=left;i<=right;i++)
            {
                ans.push_back(a[top][i]);
            }
            
            top++;
            
            if(top>bottom)  break;
            
            for(i=top;i<=bottom;i++)
            {
                ans.push_back(a[i][right]);
            }
            
            right--;
            
            if(right<left)  break;
            
            for(i=right;i>=left;i--)
            {
                ans.push_back(a[bottom][i]);
            }
            
            bottom--;
            
            if(bottom<top)  break;
            
            for(i=bottom;i>=top;i--)
            {
                ans.push_back(a[i][left]);
            }
            
            left++;
        }
        
        return ans;
    }
};