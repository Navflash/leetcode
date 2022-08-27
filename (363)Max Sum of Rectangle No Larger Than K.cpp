class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        // n^3 * log(2e5)
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + A[i-1][j-1];
            
        int ans = INT_MIN;
        set<int> st;
        for(int i=1; i<=n; i++) {
            for(int j=i; j<=n; j++) {
                // fix these two row endpoints
                // do subarray sum equals k
                
                st = {0};
                for(int l=1; l<=m; l++) {
                    int cur = dp[j][l] - dp[i-1][l];
                    // we want to find the closest to k
                    int target = cur - k;
                    auto it = st.lower_bound(target);
                    
                    if(it != st.end())
                        ans = max(ans, cur - *it);
                    st.insert(cur);
                }
            }
        }
        return ans;
    }
};