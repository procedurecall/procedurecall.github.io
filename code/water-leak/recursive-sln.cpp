double f(double amount_poured, int i, int j,
         unordered_map<int, unordered_map<int, double>> &memo) {
  // amount flowed into glass at row i, position j

  if (memo.count(i) > 0 && memo[i].count(j) > 0)
    return memo[i][j];

  if (i == 0 && j == 0)
    return amount_poured;

  if (j < 0 || j > i)
    return 0;

  double amount_from_up_left =
      max(f(amount_poured, i - 1, j - 1, memo) - 1, double(0)) / 2;
  double amount_from_up_right =
      max(f(amount_poured, i - 1, j, memo) - 1, double(0)) / 2;

  memo[i][j] = amount_from_up_left + amount_from_up_right;

  return memo[i][j];
}

double total_resting_in(double amount_pored, int i, int j) {
  unordered_map<int, unordered_map<int, double>> memo;
  return min(f(amount_poured, i, j, memo), double(1));
}
