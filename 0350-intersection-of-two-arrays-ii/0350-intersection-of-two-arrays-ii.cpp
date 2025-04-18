class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        
        vector<int>ans;

        int n1=nums1.size(), n2=nums2.size(), prev;

        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                while(i<n1 && j<n2 && nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
                }
            }
            else if(nums1[i]<nums2[j]){
                prev=nums1[i];
                while(i<n1 && (nums1[i]==prev)) i++;
            }else{
                prev=nums2[j];
                while(j<n2 && (nums2[j]==prev)) j++;
            }
        }
        return ans;
    }
};