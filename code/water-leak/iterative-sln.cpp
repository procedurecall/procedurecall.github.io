double total_resting_in(double amount_poured, int row, int glass_no) {
  vector<vector<double>> dp(row + 1);
  dp[0].push_back(amount_poured);

  auto lookup = [&](int i, int j) -> double {
    if (j < 0 || j > i)
      return 0;
    return dp[i][j];
  };

  for (int i = 1; i <= row; ++i) {
    dp[i].resize(i+1);
    for (int j = 0; j <= i; ++j) {
      double amount_from_up_left = max(lookup(i - 1, j - 1) - 1, double(0)) / 2;
      double amount_from_up_right = max(lookup(i - 1, j) - 1, double(0)) / 2;
      dp[i][j] = amount_from_up_left + amount_from_up_right;
    }
  }

  return min(dp[row][glass_no], double(1));
}
