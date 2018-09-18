class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {   //find median of each, discard a half and recurse.
        int A_size = nums1.length;
        int B_size = nums2.length;
        int l_num = (A_size + B_size +1)/2;                            
        int r_num = (A_size + B_size +2)/2;                            //make r_num >= 1
        return (find_mid(nums1,nums2,0,0,l_num) + find_mid(nums1,nums2,0,0,r_num))/2.0;
    }
    double find_mid(int[] nums1, int[] nums2,int A_start, int B_start, int K){   
        if(A_start > (nums1.length - 1)) {return nums2[B_start + K -1];}      // if nums1 or nums2 is empty
        if(B_start > (nums2.length - 1)) {return nums1[A_start + K -1];}  
        if(K == 1){return Math.min(nums1[A_start], nums2[B_start]);}          // only one step left
        
        double A_mid = Integer.MAX_VALUE;
        double B_mid = Integer.MAX_VALUE;
        if(A_start + K/2 -1 < nums1.length){
            A_mid = nums1[A_start + K/2 -1];       //get the median of nums1
        }
        if(B_start + K/2 -1< nums2.length){
            B_mid = nums2[B_start + K/2 -1];       //get the median of nums2
        }
        if(A_mid < B_mid){                         // recursion
            return find_mid(nums1,nums2,A_start + K/2, B_start, K-K/2);
        }
        else{
            return find_mid(nums1,nums2,A_start, B_start + K/2, K-K/2);
        }
    }
}
