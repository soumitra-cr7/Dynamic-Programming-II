#include <bits/stdc++.h>
using namespace std;

int totalWays(vector<int>& coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amount];
}

int main()
{
    int n;
    cin >> n;

    int amount;
    cin >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    
    int result = totalWays(coins, amount);

    cout << result << endl;
    return 0;
}