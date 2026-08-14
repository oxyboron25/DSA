class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start=-1;
        int cur=0;
        unordered_map<char,int> mp;
        int max_len = INT_MIN;
        int n = s.size();

        while(cur<n){

            mp[s[cur]]++;

            // make the substring valid
            while (mp[s[cur]] > 2){
                start++;
                mp[s[start]]--;
            }

            max_len = max(max_len, cur-start);
            cur++;      // NOTE: missed this lol
        }

        return max_len;
    }
};