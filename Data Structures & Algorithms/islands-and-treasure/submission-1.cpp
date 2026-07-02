class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // using a bfs approach to get O(m+n) time 
        queue<pair<int,int>> islands;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++){
                if(grid[r][c] == 0) {
                    islands.push({r,c});
                }
            }
        }
        vector<pair<int,int>> dirs = {{-1,0}, {0,-1},{1,0},{0,1}};
        while(!islands.empty()) {
            pair<int,int> p = islands.front();
            islands.pop();
            int r = p.first;
            int c = p.second;
            for(pair<int,int> p:dirs) {
                if(r+p.first < 0 || r+p.first >= rows 
                || c+p.second < 0 || c+p.second >= cols) {
                    continue;
                }
                if(grid[r+p.first][c+p.second]!=INF) {
                  continue;
                }
                grid[r+p.first][c+p.second]=grid[r][c] + 1;
                islands.push({r+p.first, c+p.second});
            }
        }
    }
};
