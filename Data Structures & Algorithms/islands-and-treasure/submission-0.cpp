class Solution {
public:
    int INF = 2147483647;
    int TOP = 0;
    int BOTTOM = 1;
    int LEFT = 2;
    int RIGHT = 3;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0;r<rows;r++) {
            for(int c = 0;c<cols;c++) {
                if (grid[r][c] == 0) {
                    traverseChest(-1, r, c, grid);
                }
            }
        }
    }

    void traverseChest(int noDir,int row, int col, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(noDir != TOP) {
            int currentValue = grid[row][col];
            if(col - 1 >= 0) {
                if(grid[row][col-1] > currentValue + 1) {
                    grid[row][col-1] = currentValue + 1;
                    traverseChest(BOTTOM, row, col-1, grid);
                }
            }
        }
        if(noDir != BOTTOM) {
            int currentValue = grid[row][col];
            if(col + 1 < cols) {
                if(grid[row][col+1] > currentValue + 1) {
                    grid[row][col+1] = currentValue + 1;
                    traverseChest(TOP, row, col+1, grid);
                }
            }
        }
        if(noDir != LEFT) {
            int currentValue = grid[row][col];
            if(row - 1 >= 0) {
                if(grid[row-1][col] > currentValue + 1) {
                    grid[row-1][col] = currentValue + 1;
                    traverseChest(RIGHT, row-1, col, grid);
                }
            }
        }
        if(noDir != RIGHT) {
            int currentValue = grid[row][col];
            if(row+1 < rows) {
                if(grid[row+1][col] > currentValue + 1) {
                    grid[row+1][col] = currentValue + 1;
                    traverseChest(LEFT, row+1, col, grid);
                }
            }
        }
    } 
};
