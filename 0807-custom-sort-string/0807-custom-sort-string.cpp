// vector<int> orderIdx(26, INT_MAX);
// bool compare(char & a, char & b){
// return orderIdx[a-'a']<orderIdx[b-'a'];
// }


class Solution {
public:
    string customSortString(string order, string s) {
        
        
        // for(int i=0; i<order.size(); i++){
        //     orderIdx[order[i]-'a']=i;
        // }
        sort(s.begin(), s.end(), [order](char & a, char & b){
            return order.find(a)<order.find(b);
        });
        return s;
    }
};