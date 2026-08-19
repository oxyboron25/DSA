class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, vector<int>> seats;

        for (auto &it : reservedSeats) {
            seats[it[0]].push_back(it[1]);
        }

        long long ans = 2LL * n;

        for (auto &[row, reserved] : seats) {

            bool left = true;    // 2 3 4 5
            bool middle = true;  // 4 5 6 7
            bool right = true;   // 6 7 8 9

            for (int seat : reserved) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            // This row initially contributed 2
            if (left && right) {
                // Still 2 families
            }
            else if (left || right || middle) {
                ans--; // only 1 family
            }
            else {
                ans -= 2; // 0 families
            }
        }

        return ans;
    }
};