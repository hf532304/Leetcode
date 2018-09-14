class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m < n)
            return findMedianSortedArrays(nums2,nums1); //make sure m > n
        int lo = 0;
        int hi = 2 * n;
        while(lo <= hi){                 //lo == hi
            int mid2 = (lo + hi)/2;
            int mid1 = m + n - mid2;                       //the relationship between median1 and median2
            double L1 = (mid1 == 0)? INT_MIN : nums1[(mid1-1)/2];        //get the left edge of Median
            double L2 = (mid2 == 0)? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1 == 2*m)? INT_MAX : nums1[mid1/2];          //get the right edge of Median
            double R2 = (mid2 ==2*n)? INT_MAX :nums2[mid2/2];         
            if(L1 > R2){                                              //to make sure L1 < R2 && L2 < R1
                lo = mid2+1;
            }
            else if(L2 > R1){
                hi = mid2-1;
            }
            else 
                return (max(L1,L2) + min(R1,R2))/2.0;               //get the Median
        }
    }
};
