class Solution {
public:
    //keep two new freq arrays
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq1(1001, 0);
        vector<int> freq2(1001, 0);
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) freq1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) freq2[nums2[i]]++;

        int temp;
        for(int i=0; i<1001; i++){
            if(freq1[i] && freq2[i]){
                temp=min(freq1[i],freq2[i]);
                while(temp){
                    ans.push_back(i);
                    temp--;
                }
            }
        }

        return ans;
        
    }
};