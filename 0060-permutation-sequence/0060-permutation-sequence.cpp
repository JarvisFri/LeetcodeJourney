class Solution {
public:
    // Returns the ith available element from the numset, and marks it as used.
    int search(vector<int>& numset, int i) {
        // Remove debug output
        // cout << i << " ";
        for (int j = 1; j < 10; j++) {
            if (numset[j] == 1) {
                i--;
                if (i == 0) {
                    numset[j] = 0;
                    return j;
                }
            }
        }
        return 0;
    }
    
    void f(vector<int>& numset, int n, int k, vector<int>& fact, string &ans) {
        // Base case: if no digits are left, return.
        if (n == 0)
            return;
        
        int order = k / fact[n - 1];
        int a = search(numset, order + 1);
        ans += '0' + a;
        k = k % fact[n - 1];
        f(numset, n - 1, k, fact, ans);
    }
    
    string getPermutation(int n, int k) {
        // Adjust k for 0-indexing
        k--; 
        
        // numset marks available digits from 1 to 9 (index 0 is ignored)
        vector<int> numset(10, 1);
        // Precompute factorials from 0! to 9!
        vector<int> fact;
        int currF = 1;
        for (int i = 0; i < 10; i++){
            if (i == 0)
                fact.push_back(currF);
            else {
                currF *= i;
                fact.push_back(currF);
            }
        }
        
        string ans = "";
        f(numset, n, k, fact, ans);
        return ans;
    }
};
