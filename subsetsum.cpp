#include <iostream>
#include <vector>

bool hasSubsetSum(const std::vector<int>& arr, int targetSum) {
    int n = arr.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= targetSum; j++) {
            // phần tử thứ i nhỏ hơn j
            if (arr[i - 1] <= j) {
                // thì tổng để tạo ra nó sẽ bằng thằng trước nó hoặc 
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int targetSum = 12;

    if (hasSubsetSum(arr, targetSum)) {
        std::cout << "There exists a combination with the sum " << targetSum << "." << std::endl;
    } else {
        std::cout << "No combination with the sum " << targetSum << " exists." << std::endl;
    }

    return 0;
}
