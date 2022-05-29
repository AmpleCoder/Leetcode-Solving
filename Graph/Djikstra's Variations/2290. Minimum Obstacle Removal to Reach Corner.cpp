/*
bhot pyara sawal 
djikstra's ki feel kaise aayegi?
aisa socho ki (0,0) se (row-1,col-1) tk jaane ke bhot saare path honge apne ko aisa select krna hei jisse apne ko number of
obstacle's in between kam se kam mile to ye djikstra's se hota hei agar obstacle's ko paar krne ki koi cost bhi hoti to ye code cover 
kr lega us cheez ko bhi
*/

class Solution {
    int dirX[4]={-1,0,1,0};
    int dirY[4]={0,-1,0,1};
    
public:
    int minimumObstacles(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();
        int dx,dy;
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minPq;
        dist[0][0]=a[0][0];
        minPq.push({dist[0][0],0,0});
        
        while(!minPq.empty()){
            vector<int> curr = minPq.top();
            int currDist = curr[0];
            int x= curr[1];
            int y=curr[2];
            
            minPq.pop();
            
            if(x==row-1 && y==col-1){
                // return currDist;
                break;
            }
            
            for(int i=0;i<4;i++){
                dx=x+dirX[i];
                dy=y+dirY[i];
                
                if(dx>=0 && dx<row && dy>=0 && dy<col && currDist + a[dx][dy] < dist[dx][dy]){
                    dist[dx][dy] = a[dx][dy] + currDist;
                    minPq.push({dist[dx][dy],dx,dy});
                }
            }
        }
        
        return dist[row-1][col-1];
    }
};