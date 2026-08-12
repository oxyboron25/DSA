class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> mp;
        
        int n = s.size();
        int ans = 0;

        // for minSize only
        for (int i=0; i+minSize <= n; i++){
            string sub = s.substr(i, minSize);
            unordered_set<char> st(sub.begin(), sub.end());

            int val = st.size(); // uniq chars
            
            if (val <= maxLetters){
                mp[sub]++;      // sub's occurence++
                ans = max(ans, mp[sub]);
            }
        }

        return ans;
        
    }
};