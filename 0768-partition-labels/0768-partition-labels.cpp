class Solution {
public:
    //i stores the first ocurrance to that char in string
    //j stores last occurance of same char in string
    //if i==j partition

    vector<int> partitionLabels(string s) {
        vector<vector<int>> freq(26);
        for( int k=0; k<s.size(); k++){
            freq[s[k]-'a'].push_back(k);
        }
        vector<int> partition;
        int i=0, j=0,prev=0;
        while(i<s.size()){
            if(j<freq[s[i]-'a'].back())
            j=freq[s[i]-'a'].back();
            if(i==j) {
                partition.push_back(i+1-prev);
                prev= i+1;
                }
            i++;
        }
        return partition;
    }
};