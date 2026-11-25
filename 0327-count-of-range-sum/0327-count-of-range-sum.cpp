class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return mergeSort(prefix, 0, n + 1, lower, upper);
    }
    
private:
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper) 
                  + mergeSort(prefix, mid, right, lower, upper);
        
        int j = mid, k = mid;
        for (int i = left; i < mid; i++) {
            while (k < right && prefix[k] - prefix[i] < lower) k++;
            while (j < right && prefix[j] - prefix[i] <= upper) j++;
            count += j - k;
        }
        vector<long long> temp(right - left);
        int p = left, q = mid, t = 0;
        while (p < mid && q < right) {
            if (prefix[p] <= prefix[q]) temp[t++] = prefix[p++];
            else temp[t++] = prefix[q++];
        }
        while (p < mid) temp[t++] = prefix[p++];
        while (q < right) temp[t++] = prefix[q++];
        for (int i = 0; i < t; i++) prefix[left + i] = temp[i];
        
        return count;
    }
};