class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //Esmart solution
        //Take 3 pointers, i=m-1, j=n-1, k=m+n-1;
        //Now while i && j >=0
        //Check for last elt of each elt and populate it at k

        int i=m-1, j=n-1, k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
        //If i>0 its already sorted and in nums1 
        //if j>0
        while(j>=0) nums1[k--]=nums2[j--];
    }
};