class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int t = 0, f = 0; // Counters for 'T' and 'F' characters
        int ans = 0; // Maximum consecutive answers

        while (end < n) {
            // Update counters based on the current character
            t += (s[end] == 'T');
            f += (s[end] == 'F');

            while (t > k && f > k) {
                // If both counters exceed 'k', move the start pointer and adjust counters
                if (s[start] == 'T')
                    t--;
                else
                    f--;
                start++;
            }

            ans = max(ans, end - start + 1); // Update the maximum consecutive answers
            end++;
        }

        return ans;
    }
};