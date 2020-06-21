struct point {
  int x, y;
};

struct line {
  point a, b;

  pair<int, int> slope_ratio() {
    auto ret = make_pair(a.x - b.x, a.y - b.y);
    int gcd = __gcd(ret.first, ret.second);
    ret.first /= gcd;
    ret.second /= gcd;
    return ret;
  }
};

int intersection_count(vector<line> lines) {
  int count = 0;
  for (size_t i = 0; i < lines.size(); ++i)
    for (size_t j = i + 1; j < lines.size(); ++j)
      if (lines[i].slope_ratio() != lines[j].slope_ratio()) {
        ++count;
      }
  return count;
}
