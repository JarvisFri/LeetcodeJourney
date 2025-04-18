class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]) i++;
            else {
                swap(nums1[i], nums2[j]);
                i++;
                

                while(j+1<n && nums2[j]>nums2[j+1]){
                    swap(nums2[j],nums2[j+1]);
                    j++;
                } 
                j=0;
            }
        }
        // while(i<m) res.push_back(nums1[i]);
        while( j<n) nums1[i++]=nums2[j++];

   
        return;

    }
};