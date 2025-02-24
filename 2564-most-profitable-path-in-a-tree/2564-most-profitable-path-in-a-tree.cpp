#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        parent[0] = 0;
        
        while (!q.empty()) { 
            int node = q.front(); q.pop();
            for (int neighbor : graph[node]) {
                if (neighbor != parent[node]) {
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }
        
        vector<int> bobPath(n, -1);
        int b = bob, step = 0;
        while (b != 0) {
            bobPath[b] = step++;
            b = parent[b];
        }
        bobPath[0] = step;
        
        int maxProfit = INT_MIN;
        function<void(int, int, int)> dfs = [&](int node, int depth, int profit) {
            if (bobPath[node] != -1) {
                if (depth < bobPath[node])
                    profit += amount[node];
                else if (depth == bobPath[node])
                    profit += amount[node] / 2;
            } else {
                profit += amount[node];
            }
            
            bool isLeaf = true;
            for (int neighbor : graph[node]) {
                if (neighbor != parent[node]) {
                    isLeaf = false;
                    dfs(neighbor, depth + 1, profit);
                }
            }
            
            if (isLeaf) maxProfit = max(maxProfit, profit);
        };
        
        dfs(0, 0, 0);
        return maxProfit;
    }
};