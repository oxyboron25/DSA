class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> nums_set(nums.begin(), nums.end());

        int total = nums[0];

        for (int i=0; i<n-1; i++){
            if (nums[i+1] - nums[i] == 1){
                total += nums[i+1];
            } else {
                break;
            }
        }

        while(nums_set.count(total)){
            total += 1;
        }

        return total;

    }
};