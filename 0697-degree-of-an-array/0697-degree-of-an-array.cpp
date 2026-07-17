class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> map;
        map.reserve(nums.size());
        vector<int> first(50000, 0);
        vector<int> last(50000, 0);
        int maxm = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            maxm = max(maxm, map[nums[i]]);
            if (first[nums[i]] == 0) {
                first[nums[i]] = i + 1;
            }
            last[nums[i]] = i + 1;
        }
        int ans = INT_MAX;
        for (auto& [num, freq] : map) {
            if (freq == maxm) {
                ans = min(ans, last[num] - first[num]);
            }
        }
        return ans + 1;
    }
};