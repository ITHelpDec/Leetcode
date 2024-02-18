// topological sort - O(V + E) time complexity

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        std::vector<int> courses(numCourses, 0);

        // structured bindings would be nicer here with std::pair
        for (const auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            ++courses[prerequisite[0]];
        }

        std::queue<int> q;
        for (int i = 0; i != numCourses; ++i ) {
            if (courses[i] == 0) { q.push(i); }
        }

        while (!q.empty()) {
            int prerequisite = q.front();
            q.pop();

            --numCourses;

            for (const int course : graph[prerequisite]) {
                if (--courses[course] == 0) { q.push(course); }
            }
        }

        return !numCourses;
    }
};
