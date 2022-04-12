/*
follow ups
1)Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and 
then use their updated values to update other cells.

2)In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when 
the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

this is scalability problem which can be thought in many ways one some are provided in discussion section
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int row,col,i,j,newX,newY,k;
        row=a.size();
        col=a[0].size();
        int x[]={-1,0,1,0,-1,-1,1,1};
        int y[]={0,-1,0,1,1,-1,1,-1};
        vector<vector<int>> count(row,vector<int>(col,0));
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                for(k=0;k<8;k++){
                    newX=i+x[k];
                    newY=j+y[k];
                    
                    if((newX>=0&&newX<row) && (newY>=0&&newY<col)){
                        if(a[newX][newY]==1){
                            count[i][j]++;
                        }
                    }
                }
            }
        }
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(count[i][j]<2 && a[i][j]==1){
                    a[i][j]=0;
                }
                
                else if((count[i][j]==2 || count[i][j]==3) &&  a[i][j]==1){
                    a[i][j]=1;
                }
                
                else if(count[i][j]>3 && a[i][j]==1){
                    a[i][j]=0;
                }
                
                else if(count[i][j]==3 && a[i][j]==0){
                    a[i][j]=1;
                }
            }
        }
    }
};

//solution for the first follow up how to think? - we can use bits where first bit represents prev state second tells new state
class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int row,col,i,j,newX,newY,k;
        row=a.size();
        col=a[0].size();
        int x[]={-1,0,1,0,-1,-1,1,1};
        int y[]={0,-1,0,1,1,-1,1,-1};
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                
                int count=0;
                
                for(k=0;k<8;k++){
                    newX=i+x[k];
                    newY=j+y[k];
                    
                    if((newX>=0&&newX<row) && (newY>=0&&newY<col)){
                        if((a[newX][newY]&1)==1){
                            count++;
                        }
                    }
                }
                
                // cout<<count<<" ";
                
                if(count<2){
                    if((a[i][j]&1)==1){
                        a[i][j]=1;
                    }
                }

                else if(count==2 || count==3){
                    if((a[i][j]&1)==1){
                        a[i][j]=3;
                    }

                    else if(count==3){
                        a[i][j]=2;
                    }
                }

                else if(count>3){
                    if((a[i][j]&1)==1){
                        a[i][j]=1;
                    }
                }
            }
            
            // cout<<endl;
        }
        
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                a[i][j]=(a[i][j]>>1);
            }
        }
    }
};