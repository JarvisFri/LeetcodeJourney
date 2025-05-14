class Solution {
public:
    int bs(vector<int>& smaller, vector<int>& larger) {
    int m = smaller.size(), n = larger.size();
    int total = m + n;
    int leftTotal = (total + 1) / 2; // Elements in left half
    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int j = leftTotal - mid;
        if (mid < m && j > 0 && larger[j - 1] > smaller[mid]) {
            lo = mid + 1;
        } else if (mid > 0 && j < n && smaller[mid - 1] > larger[j]) {
            hi = mid;
        } else {
            return mid; // Valid partition
        }
    }
    return lo;
}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& smaller = (nums1.size() < nums2.size()) ? nums1 : nums2;
    vector<int>& larger = (nums1.size() < nums2.size()) ? nums2 : nums1;
    int m = smaller.size(), n = larger.size();
    if (m == 0) {
        int total = n;
        if (total % 2) return larger[total / 2];
        return (larger[total / 2 - 1] + larger[total / 2]) / 2.0;
    }
    int total = m + n;
    int leftTotal = (total + 1) / 2;
    int medianIdx = bs(smaller, larger);
    int largerMedianIdx = leftTotal - medianIdx;

    // Max of left half
    int max_left = INT_MIN;
    if (medianIdx > 0) max_left = smaller[medianIdx - 1];
    if (largerMedianIdx > 0) max_left = std::max(max_left, larger[largerMedianIdx - 1]);

    if (total % 2) {
        return max_left; // Odd case
    } else {
        // Min of right half
        int min_right = INT_MAX;
        if (medianIdx < m) min_right = smaller[medianIdx];
        if (largerMedianIdx < n) min_right = std::min(min_right, larger[largerMedianIdx]);
        return (static_cast<double>(max_left) + min_right) / 2.0; // Even case
    }
}
};