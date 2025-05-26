class Solution {
public:
    vector<vector<int>> palMemo;
    vector<int> dp;

    bool isPalindrome(string &s, int i, int j){
        if(palMemo[i][j] != -1) return palMemo[i][j];
        int l = i, r = j;
        while(l < r){
            if(s[l] != s[r]) return palMemo[i][j] = 0;
            l++;
            r--;
        }
        return palMemo[i][j] = 1;
    }

    int dfs(string &s, int i){
        int n = s.size();
        if(i == n) return -1; // No cut needed after the last character
        if(dp[i] != -1) return dp[i];

        int minCuts = n;
        for(int j = i; j < n; ++j){
            if(isPalindrome(s, i, j)){
                minCuts = min(minCuts, 1 + dfs(s, j + 1));
            }
        }
        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.size();
        palMemo.assign(n, vector<int>(n, -1));
        dp.assign(n, -1);
        return dfs(s, 0);
    }
};
