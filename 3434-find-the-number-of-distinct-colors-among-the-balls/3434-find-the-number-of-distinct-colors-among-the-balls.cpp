class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;
        vector<int> result;

        int distinctColors = 0;

        for (auto& q : queries) {
            int ball = q[0], color = q[1];


            if (ballColor.count(ball)) {
                int prevColor = ballColor[ball];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    distinctColors--;
                }
            }


            ballColor[ball] = color;
            if (++colorCount[color] == 1) {
                distinctColors++;
            }

            result.push_back(distinctColors);
        }

        return result;
    }
};
