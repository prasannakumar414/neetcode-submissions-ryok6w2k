class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> result;
        int rows = heights.size();
        int cols = heights[0].size();
        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(isPA(heights, r,c)) {
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
    bool isPA(vector<vector<int>>& heights, int r, int c) {
        int rows = heights.size();
        int cols = heights[0].size();
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited;
        for(int ro=0;ro<rows;ro++) {
            vector<bool> visit;
            for(int co =0;co<cols;co++) {
                visit.push_back(false);
            }
            visited.push_back(visit);
        }
        Q.push({r,c});
        bool isP = false;
        bool isA = false;
        visited[r][c] = true;
        while(!Q.empty()) {
            auto [currR, currC] = Q.front();
            int currH = heights[currR][currC];
            Q.pop();
            // UP
            if (currR - 1 < 0) {
                isP = true;
            } else if (heights[currR - 1][currC] <= currH && !visited[currR-1][currC]) {
                visited[currR-1][currC] = true;
                Q.push({currR - 1, currC});
            }

            // DOWN
            if (currR + 1 >= rows) {
                isA = true;
            } else if (heights[currR + 1][currC] <= currH && !visited[currR+1][currC]) {
                visited[currR+1][currC] = true;
                Q.push({currR + 1, currC});
            }

            // LEFT
            if (currC - 1 < 0) {
                isP = true;
            } else if (heights[currR][currC - 1] <= currH && !visited[currR][currC-1]) {
                visited[currR][currC-1] = true;
                Q.push({currR, currC - 1});
            }

            // RIGHT
            if (currC + 1 >= cols) {
                isA = true;
            } else if (heights[currR][currC + 1] <= currH && !visited[currR][currC+1]) {
                visited[currR][currC+1] = true;
                Q.push({currR, currC + 1});
            }

            if(isA && isP) {
                return true;
            }
        }
        return false;
    }
};
