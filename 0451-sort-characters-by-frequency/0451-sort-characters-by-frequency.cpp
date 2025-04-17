vector<int> freq(256,0);
        

bool compare(char &a, char&b){
    if(freq[a]==freq[b]) return a>b;
    return (freq[a]>freq[b]);
}


class Solution {
public:
    //Keep freq of chars in s
    //vector<int>(256,0)
    //sort vector freq by freq int
    //trave store all freq in string and return
    // vector<int> freq(256,0);
        

    // bool compare(char &a, char&b){
    //     if(freq[a]==freq[b]) return a>b;
    //     return (freq[a]>freq[b])
    // }

    string frequencySort(string s) {
        // vector<int> freq(256,0);
        fill(freq.begin(), freq.end(), 0);

        for(auto ch: s){
            freq[ch]++;
        }
        sort(s.begin(), s.end(),compare);
        return s;
        
    }
};