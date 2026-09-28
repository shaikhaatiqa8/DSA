class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;
        int half = (m + n + 1) / 2;

        while (lo <= hi) {
            int i = (lo + hi) / 2;   // elements taken from nums1
            int j = half - i;        // elements taken from nums2

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) hi = i - 1;   // too many from nums1
            else              lo = i + 1;   // too few from nums1
        }
        return 0.0; // unreachable for valid input
    }
};
