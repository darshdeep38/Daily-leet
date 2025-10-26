class Solution {
public:
    int uniquePaths(int m, int n) {
        // The total number of moves = (m - 1) downs + (n - 1) rights
        // We need to choose (m - 1) moves out of total (m + n - 2)
        // So the answer = C(m + n - 2, m - 1)
        
        long long ans = 1;
        int total = m + n - 2;
        int r = min(m - 1, n - 1); // to reduce computation

        for (int i = 1; i <= r; i++) {
            ans = ans * (total - r + i) / i;
        }
        return (int)ans;
    }
}
