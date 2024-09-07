#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    int mostSimilarTarget = -987654321;
    for (int i = 0; i <= target; i++) {
        if (dp[i]) {
            mostSimilarTarget = i;
        }
    }

    int ans = sum - 2 * mostSimilarTarget;
    cout << ans;

    return 0;
}