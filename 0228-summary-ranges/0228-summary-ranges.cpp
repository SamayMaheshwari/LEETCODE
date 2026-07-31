class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }

        for (int i = 0; i < nums.size();) {
            int start = nums[i];
            int j = i;
            // Expand the range as long as elements are consecutive
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                j++;
            }

            // Format the range string
            if (nums[j] == start) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[j]));
            }
            
            // Move to the next potential start of a range
            i = j + 1;
        }
        return result;
    }
};