#include <bits/stdc++.h>
using namespace std;
 
/*
 
The algorithm rundown:
Create DAGs from the (disconnected) graphs by merging strongly connected components into single nodes
Imagine a bipartate graph from a DAG where there is an edge from the DAG source node to the DAG sink node,
iff the sink can be reached from the source. Create maximum matchings of these bipartate graphs by utilizing ford-fulkerson algorithm
Let's say mathings are {(source1, sink1), (source2, sink2), ...}. We can connect sink1 to source2, sink2 to source3 ... sinkK to source1 to create a loop.
Multiple disconnected DAGs form multiple of these disconnected loops, swap to connection destinations with other components to create one massive loop
The sources/sinks not part of the matchings can be connected arbiterily, first to each other and when there is only one type left to some 
random node of the other type
 
*/
 
const int maxN = 1e5+4;
 
class UnionFind {
public:
    vector<int> data;
    vector<int> length;
    int count;
    UnionFind(int n) : data(vector<int>(n)), length(vector<int>(n, 1)), count(n) {
        for (int i = 0; i < data.size(); i++)
            data[i] = i;
    }
    int size() const { return data.size(); }
    int Find(int a) const {
        while (a != data[a])
            a = data[a];
        return a;
    }
    bool Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b)
            return false;
        if (length[a] < length[b])
            swap(a, b);
        length[a] += length[b];
        data[b] = a;
        count--;
        return true;
    }
};
 
int nextLowlinkValue = 0;
array<int, maxN> lowlink;
array<int, maxN> ids;
array<bool, maxN> onStack;
void CalculateStronglyConnectedness(int node, array<vector<int>, maxN>& adj, stack<int>& nodeStack)
{
    onStack[node] = true;
    nodeStack.push(node);
    ids[node] = lowlink[node] = nextLowlinkValue;
    nextLowlinkValue++;
 
    for (int neighbor : adj[node])
    {
        if (ids[neighbor] == -1)
            CalculateStronglyConnectedness(neighbor, adj, nodeStack);
        if (onStack[neighbor])
            lowlink[node] = min(lowlink[node], lowlink[neighbor]);
    }
    if (ids[node] == lowlink[node])
    {
        while (!nodeStack.empty())
        {
            int popped = nodeStack.top();
            nodeStack.pop();
            onStack[popped] = false;
            ids[popped] = ids[node];
            if (popped == node)
                break;
        }
    }
}
void CalculateSourcesAndSinks(array<vector<tuple<int, int, int, int>>, maxN>& adj, vector<vector<int>>& sources, 
    vector<vector<int>>& sinks, vector<int>& componentIndexes, unordered_map<int, int>& representatives)
{
    vector<int> freqs(componentIndexes.size(), 0);
    for (auto [id, adjNode] : representatives)
    {
        bool isSink = true;
        for (auto& [n, active, _, __] : adj[adjNode])
            if (active)
            {
                freqs[n]++;
                isSink = false;
            }
        if (isSink)
            sinks[componentIndexes[adjNode]].push_back(adjNode);
    }
    for (auto [id, adjNode] : representatives)
    {
        if (freqs[adjNode] == 0)
            sources[componentIndexes[adjNode]].push_back(adjNode);
    }
}
 
vector<int> CalculateComponentIndexes(const UnionFind& unionFind, int& outComponentCount)
{
    unordered_map<int, int> components;
    vector<int> componentIndex(unionFind.size());
    for (int i = 0; i < unionFind.size(); i++)
    {
        int base = unionFind.Find(i);
        if (components.find(base) == components.end())
            components[base] = components.size();
        componentIndex[i] = components[base];
    }
    outComponentCount = components.size();
    return componentIndex;
}
 
int FordFulkersonDFS(array<vector<tuple<int, int, int, int>>, maxN>& adj, unordered_set<int>& visited, int index, int destination)
{
    if (index == destination)
        return 1;
 
    //for (auto& [neighbor, flow, neighborIdx, _] : adj[index])
    for (int i = ids[index]; i < adj[index].size(); i++)
    {
        auto& [neighbor, flow, neighborIdx, _] = adj[index][i];
        if (visited.find(neighbor) == visited.end() && flow > 0)
        {
            visited.insert(neighbor);
            if (!FordFulkersonDFS(adj, visited, neighbor, destination))
                continue;
            flow -= 1;
            get<1>(adj[neighbor][neighborIdx]) += 1;
            return 1;
        }
        ids[index] = i;
    }
 
    return 0;
}
int ExtractMatchesFromMaxFlowResidue(array<vector<tuple<int, int, int, int>>, maxN>& adj, int node, int destination)
{
    for (auto& [neighbor, flow, neighborIdx, originalFlow] : adj[node])
    {
        if (flow != originalFlow && originalFlow != 0)
        {
            if (neighbor == destination)
                return node;
            flow++;
            return ExtractMatchesFromMaxFlowResidue(adj, neighbor, destination);
        }
    }
    assert(false);
    return -1;
}
 
vector<pair<int, int>> CalculateSingleComponentConnections(vector<int>& sources, vector<int>& sinks, 
    array<vector<tuple<int, int, int, int>>, maxN>& adj, vector<int>& freelyConnectedSinks, vector<int>& freelyConnectedSources)
{
    vector<pair<int, int>> result;
 
    const int masterSource = adj.size()-1;
    const int masterSink = adj.size()-2;
    ids[masterSource] = 0;
    ids[masterSink] = 0;
    adj[masterSource].clear();
    adj[masterSink].clear();
    for (int source : sources)
    {
        adj[masterSource].push_back({source, 1, adj[source].size(), 1});
        adj[source].push_back({masterSource, 0, adj[masterSource].size()-1, 0});
    }
    for (int sink : sinks)
    {
        adj[sink].push_back({masterSink, 1, adj[masterSink].size(), 1});
        adj[masterSink].push_back({sink, 0, adj[sink].size()-1, 0});
    }
    
    unordered_set<int> visited;
    int count = 0;
    while (FordFulkersonDFS(adj, visited, masterSource, masterSink))
    {
        visited.clear();
        count++;
    }
 
    result = vector<pair<int, int>>(count);
 
    vector<int> rest;
    unordered_set<int> visitedSinks;
    int resultsIndex = 0;
    for (auto [source, flow, neighborIdx, originalFlow] : adj[masterSource])
    {
        if (flow) { freelyConnectedSources.push_back(source); continue; }
        
        result[resultsIndex].second = source;
        int other = ExtractMatchesFromMaxFlowResidue(adj, source, masterSink);
        result[(resultsIndex+1) % count].first = other;
        visitedSinks.insert(other);
        resultsIndex++;
    }
 
    for (int sinkToConnect : sinks)
        if (visitedSinks.find(sinkToConnect) == visitedSinks.end())
            freelyConnectedSinks.push_back(sinkToConnect);
 
    return result;
}
 
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;
 
    array<vector<int>, maxN> adj;
    UnionFind unionFind(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        unionFind.Union(a, b);
    }
 
    int componentCount;
    vector<int> componentIndexes = CalculateComponentIndexes(unionFind, componentCount);
 
    fill(lowlink.begin(), lowlink.end(), -1);
    fill(ids.begin(), ids.end(), -1);
    fill(onStack.begin(), onStack.end(), false);
    stack<int> theStack;
    for (int i = 0; i < n; i++)
    {
        if (ids[i] == -1)
            CalculateStronglyConnectedness(i, adj, theStack);
    }
    
    unordered_map<int, int> representatives;
    for (int i = 0; i < n; i++)
        if (representatives.find(ids[i]) == representatives.end())
            representatives[ids[i]] = i;
    
    // Remember to leave space for the maximum flow source and sink
    array<vector<tuple<int, int, int, int>>, maxN> dag;
    for (int i = 0; i < adj.size(); i++)
        for (int j = 0; j < adj[i].size(); j++)
        {
            int first = representatives[ids[i]];
            int second = representatives[ids[adj[i][j]]];
            if (first != second)
            {
                dag[first].push_back({second, 1, dag[second].size(), 1});
                dag[second].push_back({first, 0, dag[first].size()-1, 0});
            }
        }
    
 
    vector<vector<int>> sources(componentCount, vector<int>());
    vector<vector<int>> sinks(componentCount, vector<int>());
    CalculateSourcesAndSinks(dag, sources, sinks, componentIndexes, representatives);
 
    // Special case if no new edges are needed
    if (componentCount == 1 && sources[0][0] == sinks[0][0])
    {
        cout << "0";
        return 0;
    }
 
    /*
    cout << "DAG:";
    for (int i = 0; i < dag.size(); i++)
    {
        if (componentIndexes[i] != componentIndexes[349])
            continue;
        //if (dag[i].size() > 0)
        //    cout << "\n" << i << ": ";
        for (int j = 0; j < dag[i].size(); j++)
            if (get<1>(dag[i][j]))
                cout << i << ' ' << get<0>(dag[i][j]) << ' ' << 1 << '\n';
    }
 
    cout << "\nSinks and sources:\n";
    for (auto& arr : sinks)
    {
        cout << " c: ";
        for (int sink : arr)
            cout << sink+1 << ' ';
    }
    cout << '\n';
    for (auto& arr : sources)
    {
        cout << " c: ";
        for (int source : arr)
            cout << source+1 << ' ';
    }
    cout << '\n';
    //*/
 
    // We can use ids array again in ford fulkerson to keep track of the next edges to iterate
    fill(ids.begin(), ids.end(), 0);
    vector<vector<pair<int, int>>> componentConnections(componentCount);
    vector<int> connectFreelySinks;
    vector<int> connectFreelySources;
    int totalNewConnectionSize = 0;
    for (int i = 0; i < componentCount; i++)
    {
        componentConnections[i] = CalculateSingleComponentConnections(sources[i], sinks[i], dag, connectFreelySinks, connectFreelySources);
        totalNewConnectionSize += componentConnections[i].size();
        assert(componentConnections[i].size() > 0);
 
        /*
        cout << "Component connections: ";
        for (int j = 0; j < componentConnections[i].size(); j++)
            cout << componentConnections[i][j].first+1 << '-' << componentConnections[i][j].second+1 << ' ';
        cout << '\n';
        //*/
    }
 
    // Now swap two edges on each component to form a long closed loop
    for (int i = 0; i < componentCount-1; i++)
        swap(componentConnections[i][0].second, componentConnections[i+1][0].second);
    
    // Connect free sinks and sources arbiterily. We can push them for example to the first component
    totalNewConnectionSize += max(connectFreelySinks.size(), connectFreelySources.size());
    int idx = 0;
    for (; idx < min(connectFreelySinks.size(), connectFreelySources.size()); idx++)
        componentConnections[0].push_back({connectFreelySinks[idx], connectFreelySources[idx]});
    for (; idx < connectFreelySinks.size(); idx++)
        componentConnections[0].push_back({connectFreelySinks[idx], componentConnections[0][0].second});
    for (; idx < connectFreelySources.size(); idx++)
        componentConnections[0].push_back({componentConnections[0][0].first, connectFreelySources[idx]});
 
 
    cout << totalNewConnectionSize << '\n';
    for (int i = 0; i < componentConnections.size(); i++)
        for (int j = 0; j < componentConnections[i].size(); j++)
            cout << componentConnections[i][j].first+1 << ' ' << componentConnections[i][j].second+1 << '\n';
}