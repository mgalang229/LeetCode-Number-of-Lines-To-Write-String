class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 0, width = 0, rem = 0;
        for (int i = 0; i < s.size(); i++) {
            if (rem > 0) {
                width += rem;
                rem = 0;
            }
            int letter_w = widths[s[i]-'a'];
            if (width + letter_w > 100) {
                lines++;
                rem = letter_w;
                width = 0;
            } else {
                width += letter_w;
            }
        }
        if (rem > 0) {
            width += rem;
        }
        lines++;
        return {lines, width};
    }
};
