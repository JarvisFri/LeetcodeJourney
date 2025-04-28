class Solution {
public:
//Group identifier : way to identify string of same group
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map< string, int> anagram_map;
    vector<vector<string>> res;
    // vector<int> key(26,0);

    for (string str : strs) {
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());
        // for(char  c: str) key[c-'a']++;
        
        if(anagram_map.find(sorted_str)!=anagram_map.end())
            res[anagram_map[sorted_str]].push_back(str);
        else{
            res.push_back({str});
            anagram_map[sorted_str]=res.size()-1;
        }
        // fill(key.begin(), key.end(),0);
    }

    // for (auto& pair : anagram_map) {
    //     res.push_back(pair.second);
    // }


    return res;
}

};