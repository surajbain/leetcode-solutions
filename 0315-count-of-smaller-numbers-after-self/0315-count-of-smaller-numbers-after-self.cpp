class Solution {
    vector<int> tree;
    int n;
    
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        n = sorted.size();
        
        unordered_map<int, int> rank;
        for (int i = 0; i < n; i++) rank[sorted[i]] = i + 1; 
        
        tree.assign(n + 1, 0);
        vector<int> res(len);
        for (int i = len - 1; i >= 0; i--) {
            int r = rank[nums[i]];
            res[i] = query(r - 1);
            update(r, 1);
        }
        
        return res;
    }
};