#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return profit;
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "Maximum Profit = " << obj.maxProfit(prices);

    return 0;
}