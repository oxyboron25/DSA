class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        if (n==1){
            return 1;
        }

        int cnt=1;
        // int idx=-1;        
        vector<char> ans;

        for (int i=1; i<n; i++){
            if (chars[i-1] == chars[i]){
                cnt++;
                // idx=i;
            } else {
                string temp = "";
                temp += chars[i-1];
                if (cnt>1) temp += to_string(cnt);

                for (auto it : temp){
                    ans.push_back(it);
                }

                cnt=1;
            }
        }

        string temp = "";
        temp += chars[n-1];
        if (cnt>1) temp += to_string(cnt);

        for (auto it : temp){
            ans.push_back(it);
        }


        chars = ans;
        return chars.size();
        


    }
};