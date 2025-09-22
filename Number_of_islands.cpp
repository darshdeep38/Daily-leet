class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';  // mark as visited

        int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};  // up, down, left, right

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == '1') {
                    q.push({nx, ny});
                    grid[nx][ny] = '0';  // mark as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++islands;
                }
            }
        }

        return islands;
    }
};
