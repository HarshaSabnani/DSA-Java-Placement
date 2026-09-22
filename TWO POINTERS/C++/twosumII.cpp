#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {

        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left + 1, right + 1};   // 1-based indexing
        }

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {-1, -1};
}

int main() {

    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> ans = twoSum(numbers, target);

    cout << "Indices (1-based): " << ans[0] << " " << ans[1] << endl;

    return 0;
}