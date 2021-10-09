// top-down dynamic programming approach: add a memo to the brute force
bool CanWin(int n, unordered_map<int, bool> &memo) { // pass memo by reference
  if (memo.count(n) > 0)
    return memo[n];
  // base case: if nothing left, immediate loss (no possible move)
  if (n == 0) {
    memo[n] = false;
    return false;
  }
  // otherwise, iterate through the next moves
  // for every possible square number (the square number is sq*sq)
  for (int sq = 1; sq * sq <= n; ++sq) {
    // do we win by taking sq*sq from n
    // we win when the other player loses
    if (!CanWin(n - sq * sq, memo)) {
      memo[n] = true;
      return true;
    }
  }
  // if we never found a winning move, they're all losing moves
  memo[n] = false;
  return false;
}

bool CanWin(int n) {
  unordered_map<int, bool> memo;
  return CanWin(n, memo);
}
