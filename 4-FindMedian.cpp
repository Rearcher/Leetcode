class Solution {
public://基本思想是归并排序
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int cp[m+n];
        int length = m+n;
        int goal, i, j;
        int k = 0;
        double ans = 0;
        bool pos_i = true, pos_j = true;
        
        if(m==0) {
            if(n==0) return 0;
            else {
                if(n%2) return 1.0*nums2[n/2];
                else return 1.0*(nums2[n/2]+nums2[n/2-1])/2;
            }
        }
        else if(n==0) {
            if(m%2) return 1.0*nums1[m/2];
            else return 1.0*(nums1[m/2]+nums1[m/2-1])/2;
        }
        
        
        if(nums1[0] <= nums1[m-1]) {
            pos_i = true;
            i = 0;
        }
        else {
            pos_i = false;
            i = m-1;
        }
    
        if(nums2[0] <= nums2[n-1]) {
            pos_i = true;
            j = 0;
        }
        else {
            pos_j = false;
            j = n-1;
        }

        goal = length/2;
        
        if(pos_i && pos_j) {
            while(k <= goal) {
                if(i >= m) cp[k++] = nums2[j++];
                else if(j >= n) cp[k++] = nums1[i++];
                else {
                    if(nums1[i] <= nums2[j]) cp[k++] = nums1[i++];
                    else cp[k++] = nums2[j++];
                }
            }
            if((m+n)%2) ans = 1.0*cp[goal];
            else ans = 1.0*(cp[goal-1]+cp[goal])/2;
            return ans;
        }

        if(pos_i && !pos_j) {
            while(k <= goal) {
                if(i >= m) cp[k++] = nums2[j--];
                else if(j < 0) cp[k++] = nums1[i++];
                else {
                    if(nums1[i] <= nums2[j]) cp[k++] = nums1[i++];
                    else cp[k++] = nums2[j--];
                }
            }
            if((m+n)%2) ans = 1.0*cp[goal];
            else ans = 1.0*(cp[goal-1]+cp[goal])/2;
            return ans;
        }
        
        if(!pos_i && pos_j) {
            while(k <= goal) {
                if(i < 0) cp[k++] = nums2[j++];
                else if(j >= n) cp[k++] = nums1[i--];
                else {
                    if(nums1[i] <= nums2[j]) cp[k++] = nums1[i--];
                    else cp[k++] = nums2[j++];
                }
            }
            if((m+n)%2) ans = 1.0*cp[goal];
            else ans = 1.0*(cp[goal-1]+cp[goal])/2;
            return ans;
        }

        if(!pos_i && !pos_j) {
            while(k <= goal) {
                if(i < 0) cp[k++] = nums2[j--];
                else if(j < 0) cp[k++] = nums1[i--];
                else {
                    if(nums1[i] <= nums2[j]) cp[k++] = nums1[i--];
                    else cp[k++] = nums2[j--];
                }
            }
            if((m+n)%2) ans = 1.0*cp[goal];
            else ans = 1.0*(cp[goal-1]+cp[goal])/2;
            return ans;
        }
        return ans;


    }
};