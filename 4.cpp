class Solution {
public:
    int find(
        vector<int>& nums1, int l1, 
        vector<int>& nums2, int l2,
        int k) {
            int m = nums1.size();
            int n = nums2.size();
            
            int len1 = m - l1;
            int len2 = n - l2;
            if (len1 > len2) {
                return find(nums2, l2, nums1, l1, k);
            }

            if (len1 == 0) {
                return nums2[l2 + k - 1];
            }

            if (k == 1) {
                return min(nums1[l1], nums2[l2]);
            }

            int new_l1 = min(l1 + k/2 - 1, m-1);
            int new_l2 = min(l2 + k/2 - 1, n-1);

            if (nums1[new_l1] < nums2[new_l2]) {
                return find(nums1, new_l1 + 1, nums2, l2, k - (new_l1 - l1 + 1));
            } else {
                return find(nums1, l1, nums2, new_l2 + 1, k - (new_l2 - l2 + 1));
            }
 
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;


        if (m == 0) {
            return (nums2[left - 1] + nums2[right -1]) * 0.5;
        } if (n == 0) {
            return (nums1[left - 1] + nums1[right -1]) * 0.5;
        }

        return 0.5 * (find(nums1, 0, nums2, 0,left) + find(nums1, 0, nums2, 0, right));

    }
};
