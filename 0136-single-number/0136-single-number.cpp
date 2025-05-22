class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto elt : nums){
            res=res^elt;
        }

        return res;
    }
};