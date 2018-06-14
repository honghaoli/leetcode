class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        stopsOfBus.resize(routes.size());
        for (int i = 0; i < routes.size(); ++i) {
            for (int s : routes[i]) {
                stopsOfBus[i].insert(s);
                busesAtStop[s].insert(i);
            }
        }
        return bfs(S, T);
    }

private:
    vector<unordered_set<int>> stopsOfBus;
    unordered_map<int, unordered_set<int>> busesAtStop;
    unordered_set<int> visited, visited_bus;

    int bfs(int source, int target) {
        if (source == target) return 0;
        queue<pair<int, int>> q;
        q.push({source, 0});
        while (!q.empty()) {
            int stop = q.front().first;
            int step = q.front().second;
            if (stop == target) return step;
            q.pop();
            visited.insert(stop);
            // find all the buses for this stop
            for (auto it = busesAtStop[stop].begin(); it != busesAtStop[stop].end(); ++it) {
                if (visited_bus.count(*it) != 0) continue;
                visited_bus.insert(*it);
                for (auto iter = stopsOfBus[*it].begin(); iter != stopsOfBus[*it].end(); ++iter) {
                    if (visited.count(*iter) == 0)
                        q.push({*iter, step + 1});
                }
            }
        }
        // not found
        return -1;
    }
};

