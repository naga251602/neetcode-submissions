class Solution {
  public:
    vector<tuple<int, int, int>> getRotten(vector<vector<int>>& mat) {
        vector<tuple<int, int, int>> oranges;
        
        for (int i = 0; i < mat.size(); i ++) {
            for (int j = 0; j < mat[i].size(); j ++) {
                if (mat[i][j] == 2) oranges.push_back({i, j, 0});
            }
        }
        
        return oranges;
    }
    int orangesRotting(vector<vector<int>>& mat) {
        
        int mintime = 0;
        
        vector<tuple<int, int, int>> rotten = getRotten(mat);
        deque<tuple<int, int, int>> q(rotten.begin(), rotten.end());
        vector<pair<int,int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [i, j, t] = q.front();
            q.pop_front();
            
            mintime = t;
            
            for (auto p: directions) {
                int x = p.first + i, y = p.second + j;
                
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[i].size() && mat[x][y] == 1) {
                    mat[x][y] = 2;
                    q.push_back({x, y, t+1});
                }
            }
        }
        
        for (int i = 0; i < mat.size(); i ++) {
            for (int j = 0; j < mat[i].size(); j ++) {
                if (mat[i][j] == 1) return -1;
            }
        }

        return mintime;
    }
};