#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += encrypt(i);

        return sum;
    }
    int encrypt(int num)
    {
        int max;
        vector<int> digits;
        int temp;
        int i;

        for (i = 1; (temp = num % 10) != num; num /= 10, ++i)
            digits.push_back(temp);
        digits.push_back(num);

        sort(digits.begin(), digits.end());
        max = digits[digits.size() - 1];

        int enc_num = max;

        for (int j = 1; j < i; ++j)
            enc_num = (enc_num * 10) + max;

        return enc_num;
    }
};