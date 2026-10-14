class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        string result = "";
        int nines = sum / 9;
        int remainder = sum % 9;
        result += string(nines, '9');
        if (remainder > 0) {
            result += to_string(remainder);
        }
        result += string(num - result.size(), '0');
        return result;
    }
};