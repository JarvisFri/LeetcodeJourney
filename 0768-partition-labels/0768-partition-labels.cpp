class Solution {
public:
    //i stores the first ocurrance to that char in string
    //j stores last occurance of same char in string
    //if i==j partition

    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26,-1);
        for( int k=0; k<s.size(); k++){
            lastIdx[s[k]-'a']=k;
        }
        vector<int> partition;
        int i=0, j=0,prev=0;
        while(i<s.size()){
            if(j<lastIdx[s[i]-'a'])
            j=lastIdx[s[i]-'a'];
            if(i==j) {
                partition.push_back(i+1-prev);
                prev= i+1;
                }
            i++;
        }
        return partition;
    }
};