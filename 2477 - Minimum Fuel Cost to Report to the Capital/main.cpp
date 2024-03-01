// O(V+E) DFS solution
// create and populate an adjacency list
// perform a dfs through the adjacency list, marking things as visited as we go along
// keep a count of all the adjacent nodes and increment the answer accordingly

class Solution {
public:
    long long minimumFuelCost(const std::vector<std::vector<int>>& roads, int seats) {
        int n = roads.size();
        std::vector<std::vector<int>> adj(n + 1);

        for (const auto &road : roads) {
            int u = road.front();
            int v = road.back();

            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        std::vector<bool> vis(n + 1, false);
        dfs(adj, 0, seats, vis);

        return answer;
    }
private:
    long long answer = 0;

    int dfs(const std::vector<std::vector<int>> &adj, int u, int seats, std::vector<bool> &vis) {
        vis[u] = true;

        int count = 1;

        for (int i : adj[u]) {
            if (vis[i] == false) { count += dfs(adj, i, seats, vis); }
        }

        if (u != 0) { answer += std::ceil(static_cast<double>(count) / seats); }

        return count;

    }
};

// another similar DFS solution below, but faster (passing smaller variables by value this time round, and more const-refs)
// naming is also slightly more declarative
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        std::vector<std::vector<int>> adj(roads.size() + 1);
        
        for (const auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        
        dfs(0, -1, adj, seats);
        
        return fuel;
    }
private:
    long long fuel;

    long long dfs(int node, int parent, const std::vector<std::vector<int>> &adj, int seats) {
        int reps = 1;

        for (int child : adj[node]) {
            if (child != parent) { reps += dfs(child, node, adj, seats); }
        }

        if (node != 0) { fuel += ceil(static_cast<double>(reps) / seats); }

        return reps;
    }
};
