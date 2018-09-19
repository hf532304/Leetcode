class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { //sorted array so use binary search and insert
        int left = 0;
        int right = m-1;                        //two pointer in nums1
        int index_2 = 0;
        nums1.erase(nums1.begin() + m, nums1.end());
        while(index_2 < n){
            left = 0;
            right = nums1.size()-1;
            while(left <= right){
                int mid = (left + right)/2;
                if(nums1[mid] == nums2[index_2]){
                    left = mid;
                    break;
                }
                else if(nums1[mid] < nums2[index_2]){
                    left = mid + 1;
                }
                else if(nums1[mid] > nums2[index_2]){
                    right = mid - 1;
                }
            }
            nums1.insert(nums1.begin() + left, nums2[index_2]);
            index_2++;
        }
    }
};