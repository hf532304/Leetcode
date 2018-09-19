class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {       //compare from end to start, which save time of moving elements
        int k = m + n - 1;         //k represents the size of nums1
        int m1 = m - 1;
        int n1 = n - 1;
        while(n1 >= 0 && m1 >= 0){
            if(nums1[m1] > nums2[n1]) nums1[k--] = nums1[m1--];
            else    nums1[k--] = nums2[n1--];
        }
        while(n1 >= 0){
            nums1[k--] = nums2[n1--];
        }
    }
}