class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int,int>> rottenQ;
        for(int r = 0;r<rows;r++) {
            for(int c = 0;c<cols;c++) {
                if(grid[r][c] == 2) {
                    rottenQ.push_back({r,c});
                }
            }
        }
        int t = 0;
        int ind = 0;
        bool added = true;
        while(added) {
            cout << "yo" << endl;
            added = false;
            int size = rottenQ.size();
            for(int i = ind;i<size;i++) {
                auto [r,c] = rottenQ[i];
                cout << r << c << endl;
                if(r+1<rows && grid[r+1][c] == 1) {
                    grid[r+1][c] = 2;
                    rottenQ.push_back({r+1,c});
                    added = true;
                }
                if(c+1<cols && grid[r][c+1]==1) {
                    grid[r][c+1] = 2;
                    rottenQ.push_back({r,c+1});
                    added = true;
                }
                if(r>0 && grid[r-1][c]==1) {
                    grid[r-1][c] = 2;
                    rottenQ.push_back({r-1,c});
                    added = true;
                }
                if(c>0 && grid[r][c-1]==1) {
                    grid[r][c-1] = 2;
                    rottenQ.push_back({r,c-1});
                    added = true;
                }
            }
            if(added) {
                t += 1;
            }
            ind += size - ind;
        }
        for(int r = 0;r<rows;r++) {
            for(int c = 0;c<cols;c++) {
                if(grid[r][c] == 1) {
                    return -1;
                }
            }
        }
        return t;
    }
};
