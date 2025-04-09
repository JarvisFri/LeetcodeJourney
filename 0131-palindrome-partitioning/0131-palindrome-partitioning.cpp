class Solution { 
public:
    // Check if the given string is a palindrome.
    bool palindrome_check(const string &s){
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) 
                return false;
        }
        return true;
    }
    
    // Recursive function with two pointers: start_ptr and end_ptr.
    void f(const string &s, int start_ptr, int end_ptr, vector<string> curr, vector<vector<string>> &res) {
        int n = s.size();
        
        // Base Case: when start_ptr reaches the end, add the current partition.
        if (start_ptr == n) {
            res.push_back(curr);
            return;
        }
        
        // Out-of-bound check for end_ptr.
        if (end_ptr > n) 
            return;
        
        // Decision 1: Do not partition at the current end_ptr, i.e. extend the current substring.
        f(s, start_ptr, end_ptr + 1, curr, res);
        
        // Decision 2: Partition by taking the substring from start_ptr to end_ptr - 1.
        string temp = s.substr(start_ptr, end_ptr - start_ptr);
        if (palindrome_check(temp)) {
            curr.push_back(temp);
            // After partitioning, start new substring from end_ptr.
            f(s, end_ptr, end_ptr + 1, curr, res);
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        f(s, 0, 1, curr, res);
        return res;
    }
};
