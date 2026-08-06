class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        for (int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }
        
        vector<int> res(2*n);
        stack<int> st;

        for (int i=2*n-1; i>=0; i--){
            while (!st.empty() && nums[i] >= st.top()){    // >=
                st.pop();
            }

            if (st.empty()){
                res[i] = -1;
            } else {
                res[i] = st.top();
            }

            st.push(nums[i]); // forgot to push
        }

        vector<int> ans;

        for (int i=0; i<n; i++){
            ans.push_back(res[i]);
        }

        return ans;



    }
};