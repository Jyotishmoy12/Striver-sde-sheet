#include <bits/stdc++.h>

void tpoSort(int node, vector<bool> &visited,
               unordered_map<int,list<int> > &adj, stack<int> &s)
{
   visited[node] = true;

   for(auto neighbour : adj[node])
   {
       if(!visited[neighbour])
       {
           tpoSort(neighbour, visited, adj, s);
       }
   }

   // Put the node into stack while comming back from the recursion
   s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

   // Step 1 : Create an adjacency list
   unordered_map<int, list<int> > adj;

   for(int i = 0; i<edges.size(); i++)
   {
       int u = edges[i][0];
       int v  = edges[i][1];

       // Because of directed graph
       adj[u].push_back(v);
   }

   // Visited List, ans Vector and Stack
   vector<bool> visited(v);
   stack<int>s;
   vector<int> ans;

   // Call DFS Topological order for all the vertices

   // Nodes are starting from 0 as per question
   for(int i = 0; i<v; i++)
   {
       if(!visited[i])
       {
           tpoSort(i, visited, adj, s);
       }
   }

   // Now take the answer form stack

   while(!s.empty())
   {
       int topNode = s.top();
       ans.push_back(topNode);
       s.pop();
   }

   return ans;
}
