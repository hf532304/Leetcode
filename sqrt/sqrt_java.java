class Solution {
    public int mySqrt(int x) {
        int left = 1; 
        int right = Integer.MAX_VALUE - 1;
        if(x == 0) return 0;
        while(left <= right){
            int mid = (left + right)/2;
            if(x / mid == mid)
                return mid;
            else if(x / mid < mid)
                right = mid - 1;
            else if(x / mid > mid){
                if(x/(mid+1) < (mid+1))
                    return mid;
                else 
                    left = mid + 1;
            }
        }
        return right;
    }
}