#include <map>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

map<int, vector<int>> createGraph()
{
    return map<int, vector<int>>{
        {0, {1, 3, 5}},
        {1, {3, 5}},
        {2, {1, 6}},
        {3, {1, 2, 3, 4}},
        {4, {1, 5, 6}},
        {5, {3}}};
}

map<int, int> dfs_search(const map<int, vector<int>> &graph, int src)
{
    map<int, bool> marked;
    map<int, int> node_from;
    stack<int> stack;

    marked[src] = true;
    stack.push(src);

    while (!stack.empty())
    {
        int current = stack.top();
        stack.pop();
        for (int neighbor : graph.at(current))
        {
            if (marked.find(neighbor) == marked.end())
            {
                marked[neighbor] = true;
                stack.push(neighbor);
                node_from[neighbor] = current;
            }
        }
    }

    return node_from;
}

int main()
{
    auto G = createGraph();
    auto node_from = dfs_search(G, 0);
    for (auto pair:node_from)
        cout <<"Node"<< pair.first << " " << pair.second << endl;
    return 0;
}