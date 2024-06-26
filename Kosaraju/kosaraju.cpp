#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <fstream>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[], stack<int> &stack)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, stack);
        }
    }
    stack.push(node);
}

void dfs_reverse(int node, vector<int> &visited, vector<int> adjReverse[], vector<int> &component)
{
    visited[node] = 1;
    component.push_back(node);
    for (auto i : adjReverse[node])
    {
        if (!visited[i])
        {
            dfs_reverse(i, visited, adjReverse, component);
        }
    }
}

void kosaraju(int n, vector<int> adj[], vector<vector<int>> &cfcs)
{
    vector<int> visited(n, 0);
    stack<int> stack;     

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, stack);
        }
    }

    vector<int> adjReverse[n]; 
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (auto j : adj[i])
        {
            adjReverse[j].push_back(i);
        }
    }

    while (!stack.empty())
    {
        int node = stack.top();
        stack.pop();
        if (!visited[node])
        {
            vector<int> component;
            dfs_reverse(node, visited, adjReverse, component);
            cfcs.push_back(component);
        }
    }

    return;
}

int main(int argc, char *argv[])
{
    int start_node = 1;
    string input_file = "";
    string output_file = "null";

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            cout << "Help" << endl;
            cout << "-h: mostra help" << endl;
            cout << "-o <arquivo>: redireciona a saída para o arquivo" << endl;
            cout << "-f <arquivo>: lê o grafo do arquivo" << endl;
            return 0;
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            output_file = argv[i + 1];
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            input_file = argv[i + 1];
        }
        else if (strcmp(argv[i], "-i") == 0)
        {
            start_node = atoi(argv[i + 1]);
        }
    }

    if (input_file == "")
    {
        cout << "No input file specified. Use the -f parameter" << endl;
        return 1;
    }

    ifstream fin(input_file);
    if (!fin)
    {
        cerr << "Could not open input file: " << input_file << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        fin >> v1 >> v2;
        v1--;
        v2--;

        adj[v1].push_back(v2);
    }

    vector<vector<int>> cfcs;
    kosaraju(n, adj, cfcs);

    if (output_file != "null")
    {
        ofstream fout(output_file);
        if (!fout)
        {
            cerr << "Could not open output file: " << output_file << endl;
            return 1;
        }
        for (const auto &cfc : cfcs)
        {
            int contador = 0;
            for (int node : cfc)
            {
                if (contador == cfc.size() - 1)
                {
                    fout << node + 1;
                }
                else
                {
                    fout << node + 1 << " ";
                }
                contador++;
            }
            fout << endl;
        }

        fout.close();
    }
    else
    {
        for (const auto &component : cfcs)
        {
            for (int node : component)
            {
                cout << node + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
