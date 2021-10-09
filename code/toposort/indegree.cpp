const auto CYCLE_DETECTED = vector<int>();

vector<int> topological_sort(int n, vector<pair<int, int>> edges) {
  // convert to adjacency lists, and record in-degrees
  vector<vector<int>> adj(n);
  vector<int> in_degree(n);
  for (auto &p : edges) {
    adj[p.first].push_back(p.second);
    in_degree[p.second]++;
  }

  // initialize our todo queue with all the in_degree=0 nodes
  queue<int> todo;
  for (int i = 0; i < n; ++i) {
    if (in_degree[i] == 0)
      todo.push(i);
  }

  // traverse our graph
  vector<int> ret;
  while (!todo.empty()) {
    int cur = todo.front();
    todo.pop();
    ret.push_back(cur);
    for (auto i : adj[cur]) {
      --in_degree[i];
      if (in_degree[i] == 0)
        todo.push(i);
    }
  }

  // detect cycles
  if (ret.size() < n)
    return CYCLE_DETECTED;

  return ret;
}
