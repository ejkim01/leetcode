/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/


int threeSumClosest(vector<int> &num, int target) {
    if(num.size()<3) return INT_MAX;
    sort(num.begin(),num.end());
    int minDiff = INT_MAX;
    for(int i=0; i<num.size()-2; i++) {
        int left=i+1, right = num.size()-1;
        while(left<right) {
            int diff = num[i]+num[left]+num[right]-target;
            if(abs(diff)<abs(minDiff)) minDiff = diff;
            if(diff==0) 
                break;
            else if(diff<0)
                left++;
            else
                right--;
        }
    } 
    return target+minDiff;
}
