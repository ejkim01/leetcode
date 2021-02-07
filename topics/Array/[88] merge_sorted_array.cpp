/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

void merge(int A[], int m, int B[], int n) {
    int pa = m-1, pb = n-1, pc = m+n-1;
    while(pa>=0 && pb>=0) {
        if(A[pa]>B[pb]) 
            A[pc--] = A[pa--];
        else
            A[pc--] = B[pb--];
    }
    while(pa>=0) A[pc--] = A[pa--];
    while(pb>=0) A[pc--] = B[pb--];
}