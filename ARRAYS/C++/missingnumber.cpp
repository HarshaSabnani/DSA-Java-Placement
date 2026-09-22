#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int total = n * (n + 1) / 2;

        int sum = 0;

        for (int num : nums)
            sum += num;

        return total - sum;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n (array size): ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " distinct numbers from 0 to " << n << ": ";

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Missing Number = " << obj.missingNumber(nums);

    return 0;
}