class Solution {
    public:
    
        void dfs(vector<vector<char>>& grid, int r, int c)
        {
            int rows = grid.size();
            int cols = grid[0].size();
    
            // Out of bounds
            if(r < 0 || c < 0 || r >= rows || c >= cols)
                return;
    
            // Water or already visited
            if(grid[r][c] == '0')
                return;
    
            // Mark visited
            grid[r][c] = '0';
    
            // Explore 4 directions
            dfs(grid, r + 1, c);
            dfs(grid, r - 1, c);
            dfs(grid, r, c + 1);
            dfs(grid, r, c - 1);
        }
    
        int numIslands(vector<vector<char>>& grid) {
    
            int rows = grid.size();
            int cols = grid[0].size();
    
            int islands = 0;
    
            for(int r = 0; r < rows; r++)
            {
                for(int c = 0; c < cols; c++)
                {
                    if(grid[r][c] == '1')
                    {
                        islands++;
    
                        dfs(grid, r, c);
                    }
                }
            }
    
            return islands;
        }
    };