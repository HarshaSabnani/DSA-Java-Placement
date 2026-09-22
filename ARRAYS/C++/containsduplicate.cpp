#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for (int num : nums) {

            if (st.find(num) != st.end())
                return true;

            st.insert(num);
        }

        return false;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (obj.containsDuplicate(nums))
        cout << "Duplicate Exists";
    else
        cout << "No Duplicate";

    return 0;
}