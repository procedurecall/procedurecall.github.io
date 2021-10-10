// iterative implementation
bool CanWin(int n) {
  vector<bool> dp(n + 1); // same as our memo before, but now a vector
  // dp[0] is already false by default
  // iterate through the remaining values bottom-up
  // note that compared to our previous implementation, i takes on the value of
  // our "current" n
  for (int i = 1; i <= n; ++i) {
    // for every possible move:
    for (int sq = 1; sq * sq <= i; ++sq) {
      if (!dp[i - sq * sq]) {
        // found a winning move!
        dp[i] = true;
        break;
      }
    }
  }
  return dp[n];
}
