class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>::iterator itr,ptr;
        itr=nums.begin();
        ptr=nums.end();
        k=k%nums.size();
        
        reverse(itr,ptr);
        reverse(itr,itr+k);
        reverse(itr+k,ptr);
    }
};