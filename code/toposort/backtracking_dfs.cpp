const int BLUE = 0, GREEN = 1, RED = 2;

// returns TRUE if a cycle is detected
// (and, if so, sets ret to an empty vector)
bool backtracking_dfs(vector<vector<int>> &adj, vector<int> &ret,
                      vector<int> &color, int v) {
  // if we have already visited here, act appropriately

  // if the color is green, a CYCLE has been detected
  if (color[v] == GREEN) {
    ret = vector<int>();
    return true;
  }
  // if the color is red, do nothing (already visited and recursed on)
  if (color[v] == RED) {
    return false;
  }
  // otherwise, add the current node to the stack of greens
  color[v] = GREEN;
  // then visit its neighbours
  for (int u : adj[v]) {
    // if any neighbour searches find a cycle, return true again
    if (backtracking_dfs(adj, ret, color, u))
      return true;
  }
  // done visiting all neighbours and their traversals too
  // remove from stack
  color[v] = RED;
  // add to return list
  ret.push_back(v);

  // no cycle detected
  return false;
}

// this becomes a helper function
vector<int> topological_sort(int n, vector<pair<int, int>> edges) {
  vector<int> ret;

  // convert edge list to adjacency lists
  vector<vector<int>> adj(n);
  for (auto &p : edges) {
    // construct the graph with the edges in reverse since the return vector
    // will be reversed if we do so
    adj[p.second].push_back(p.first);
  }

  vector<int> color(n, BLUE);

  // simulate a "super node", i.e. do the DFS from all starting positions
  for (int i = 0; i < n; ++i) {
    // if a cycle is detected, terminate early here too
    if (backtracking_dfs(adj, ret, color, i))
      return ret;
  }
  return ret;
}
