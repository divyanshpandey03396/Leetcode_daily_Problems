class Solution {
public:
     int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int ROWS = triangle.size();
        for(int r = 1; r < ROWS; r++) {
            int n = triangle[r].size();
            for(int i = 0; i < n; i++) {
                if(i == 0) {
                    triangle[r][i] += triangle[r-1][i];
                } else if (i == n - 1) {
                    triangle[r][i] += triangle[r-1][i-1];
                } else {
                    int mn = min(triangle[r-1][i], triangle[r-1][i-1]);
                    triangle[r][i] += mn;
                }
            }
        }
        
        for(int x : triangle[ROWS-1]) {
            ans = min(ans, x);
        }
        
        return ans;
    }
};