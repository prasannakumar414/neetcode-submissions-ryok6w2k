class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i= 0; i<rows;i++) {
            for(int j=0;j<cols;j++) 
            {
                if(grid[i][j] == '1') {
                    count += 1;
                    updateNeighbours(grid, i, j);
                }
            }
        }
        return count;
    }

    void updateNeighbours(vector<vector<char>>& grid, int row, int column) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(grid[row][column] != '1'){
            return;
        }
        grid[row][column] = '2';
        if (row+1 < rows) {
            updateNeighbours(grid, row + 1, column);
        }
        if ( row - 1 >=0) {
            updateNeighbours(grid, row-1, column);
        }
        if (column+1 < cols) {
            updateNeighbours(grid, row, column + 1);
        }
        if ( column - 1 >=0) {
            updateNeighbours(grid, row, column-1);
        }
    }
};
