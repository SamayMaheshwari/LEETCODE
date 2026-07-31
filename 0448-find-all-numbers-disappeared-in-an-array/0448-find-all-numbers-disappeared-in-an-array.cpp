class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> ans;
        
        // Step 1: Place the numbers where they are supposed to be 
        while(i < n){
            int correctIndex = nums[i] - 1;
            
            // Swap if the number is not at its correct index
            if(nums[i] != nums[correctIndex]){
                swap(nums[i], nums[correctIndex]);
            }
            else {
                i++;
            }
        }
        
        // Step 2: Check if the numbers are in their correct positions
        // If not, then that index represents a missing number
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i + 1){
                // For a range 1 to N, index i should hold the value i + 1.
                // Since index i is occupied by some other value,
                // i + 1 is the number that is missing from the array.
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};