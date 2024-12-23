class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited, finished;
    bool check(int index) {
        if (visited[index] == true) return finished[index];
        visited[index] = true;
        bool ans = true;
        for (int i = 0; i < adj[index].size(); i++) {
            if (check(adj[index][i]) == false) {
                ans = false;
                break;
            }
        }

        finished[index] = ans;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        visited.resize(numCourses);
        finished.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[a].push_back(b);
        }
        for (int i = 0; i < numCourses; i++) {
            if (check(i) == false) return false;
        }        
        return true;
    }
};
