/*
Fenwick Tree

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/


class NumArray {
    vector<int> fen;
    vector<int> arr;
    int len;
public:
    NumArray(vector<int>& nums) {
        len = nums.size();
        if (len==0) return;
        
        fen.resize(len+1);
        arr.resize(len);
        arr = nums;
        
        fen[1] = arr[0];
        for (int i=1; i<len; i++)
            fen[i+1] = fen[i] + arr[i];
        
        for (int i=len; i>0; i--) {
            int parent = i - (i & -i);
            if (parent >= 0) fen[i] -= fen[parent];
        }
    }
    
    int sum(int i) {
        int res = 0;
        while (i>0) {
            res += fen[i];
            i = i - (i & -i);
        }
        return res;
    }
    
    void increment(int i, int val) {
        i++;
        while (i<=len) {
            fen[i] += val;
            i = i + (i & -i);
        }
    }
    
    void update(int i, int val) {
        int extra = val - arr[i];
        arr[i] = val;
        increment(i, extra);
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};
