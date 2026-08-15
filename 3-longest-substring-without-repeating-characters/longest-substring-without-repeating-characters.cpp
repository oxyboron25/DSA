class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        if (n==0){
            return 0;
        }

        int l=-1, r=0;

        unordered_map<char,int> mp;
        int max_len = INT_MIN;

        while(r<n){
            mp[s[r]]++;

            while (mp[s[r]] > 1){
                l++;
                mp[s[l]]--;
            }

            max_len = max(max_len, r-l);

            r++;
        }

        return max_len;
        

    }
};