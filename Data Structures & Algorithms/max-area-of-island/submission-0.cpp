class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < rows;i++) {
            for(int j = 0;j<cols; j++) {
                maxArea = max(maxArea, updateNeighbours(grid, i, j));
            }
        }
        return maxArea;
    }

    int updateNeighbours(vector<vector<int>>& grid, int row, int col) {
        if(grid[row][col] != 1) {
            return 0;
        }
        grid[row][col] = 2;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 1;
        if(row + 1 < rows) {
            if(grid[row+1][col] == 1) {
                maxArea += updateNeighbours(grid, row+1, col);
            }
        }
        if (row - 1 >= 0) {
            if (grid[row-1][col] == 1) {
                maxArea += updateNeighbours(grid, row - 1, col);
            }
        }
        if (col + 1 < cols) {
            if(grid[row][col+1] == 1) {
                maxArea += updateNeighbours(grid, row, col+1);
            }
        }
        if (col - 1 >= 0) {
            if(grid[row][col-1] == 1) {
                maxArea += updateNeighbours(grid, row, col-1);
            }
        }
        return maxArea;
    }
};
