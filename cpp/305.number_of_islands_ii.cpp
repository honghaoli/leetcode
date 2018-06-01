// Classical weighted quick union algorithm.
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        M = m;
        N = n;
        parent = vector<int>(m * n, -1);    // parent node.
        sz = vector<int>(m * n, 0);         // tree size of each union part
        num_islands = 0;
        vector<int> result;
        for (auto &p : positions) {
            add_land(p);
            result.push_back(num_islands);
        }
        return result;
    }

private:
    int M, N;
    int num_islands;
    vector<int> parent, sz;
    const vector<int> dx{0, 1, 0, -1};
    const vector<int> dy{-1, 0, 1, 0};

    int inline index(int x, int y) {
        return x * N + y;
    }

    int inline index(pair<int, int> &pos) {
        return index(pos.first, pos.second);
    }

    void add_land(pair<int, int> &pos) {
        int idx = index(pos);
        if (parent[idx] >= 0) return;       // this site is already land, no need to update it

        num_islands++;                      // we first add this land, then decrease the number after connected with neighbors
        parent[idx] = idx;
        sz[idx] = 1;
        for (int k = 0; k < 4; k++) {
            int x = pos.first + dx[k];
            int y = pos.second + dy[k];
            int index2 = index(x, y);
            if (x >= 0 && x < M && y >= 0 && y < N && parent[index2] >= 0)   // if matrix[x][y] valid and it's not water
                connect(index2, idx);
        }
    }

    void connect(int index1, int index2) {
        int r1 = root(index1);
        int r2 = root(index2);
        if (r1 == r2) return;       // they are already connected.
        // smaller tree to be a child of the larger tree
        // the reason why we use size other than height, is because during path compression, height will change while size will not!
        if (sz[r1] > sz[r2]) {
            parent[r2] = r1;
            sz[r1] += sz[r2];
        } else {
            parent[r1] = r2;
            sz[r2] += sz[r1];
        }
        // shorter tree to be a child of the higher tree
        // // following use sz = tree height
        // if (sz[r1] == sz[r2])   
        //     sz[r2]++;
        // that means island decrease by 1
        num_islands--;
    }

    int root(int index) {
        // path compression, use p[i] = p[p[i]] in the same loop
        // https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf (page 29)
        while (parent[index] != index) {
            parent[index] = parent[parent[index]];
            index = parent[index];
        }
        return index;
    }
};