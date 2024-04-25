/*
    approach:
        simple dsu with initally pointing everyones pointer to -1 
*/

class Solution {
public:
    class UnionFind{
        vector<int> parent;
        int noOfComp;

    public:
        UnionFind(int size){
            parent.resize(size, -1);
            noOfComp = 0;
        }

        void add(int a){
            parent[a] = a;
            noOfComp++;
        }

        int find(int curr){
            if(parent[curr] == -1){
                return -1;
            }

            return (curr == parent[curr] ? curr : parent[curr] = find(parent[curr]));
        }

        void connect(int a, int b){
            if(parent[find(a)] != parent[find(b)]){
                parent[find(a)] = parent[find(b)];
                noOfComp--;   
            }
        }

        int getNoOfComp(){
            return noOfComp;
        }
    };

    vector<int> numIslands2(int row, int col, vector<vector<int>>& positions) {
        int size = positions.size(), currIslands = 0;
        vector<int> result;
        UnionFind uf(row * col);
        int dir[5] = {-1, 0, 1, 0, -1};

        for(auto &currPosition: positions){
            int x = currPosition[0];
            int y = currPosition[1];
            int currIdx = x * col + y;
            
            if(uf.find(currIdx) != -1){
                result.push_back(uf.getNoOfComp());
                continue;
            }

            uf.add(currIdx);

            //traverse adjacents 
            for(int i = 0; i < 4; i++){
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                int newIdx = newX * col + newY;

                if(newX < 0 || newX >= row || newY < 0 || newY >= col || uf.find(newIdx) == -1){
                    continue;
                }

                if(uf.find(newIdx) != uf.find(currIdx)){
                    uf.connect(currIdx, newIdx);
                }
            }

            result.push_back(uf.getNoOfComp());
        }

        return result;
    }
};