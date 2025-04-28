class Solution {
public:

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagram_map;
    vector<vector<string>> res;

    for (string str : strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        anagram_map[sorted_str].push_back(str);
    }

    for (auto& pair : anagram_map) {
        res.push_back(pair.second);
    }

    

    return res;
}

};