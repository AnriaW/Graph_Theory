#include <bits/stdc++.h>

#define MAX_N 20001
#define ll long long int
using namespace std;

int n, m;
struct Node {
    vector<int> adj;
    vector<int> rev_adj;
};

Node g[MAX_N];

stack<int> S;
bool visited[MAX_N];
int component[MAX_N];
vector<int> components[MAX_N];
int numComponents;

void dfs_1(int x) {
    visited[x] = true;
    for (int i = 0; i < g[x].adj.size(); i++) {
        if (!visited[g[x].adj[i]]) dfs_1(g[x].adj[i]);
    }
    S.push(x);
}

void dfs_2(int x) {
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i = 0; i < g[x].rev_adj.size(); i++) {
        if (!visited[g[x].rev_adj[i]]) dfs_2(g[x].rev_adj[i]);
    }
}

void Kosaraju() {
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs_1(i);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    while (!S.empty()) {
        int v = S.top();
        S.pop();
        if (!visited[v]) {
            dfs_2(v);
            numComponents++;
        }
    }
}

int main(int argc, char *argv[]) {
    string inputFile;
    string outputFile;
    bool printHelp = false;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h") {
            printHelp = true;
        } else if (arg == "-o") {
            if (i + 1 < argc) {
                outputFile = argv[++i];
            } else {
                cerr << "Error: Missing argument for -o" << endl;
                return 1;
            }
        } else if (arg == "-f") {
            if (i + 1 < argc) {
                inputFile = argv[++i];
            } else {
                cerr << "Error: Missing argument for -f" << endl;
                return 1;
            }
        } else {
            cerr << "Error: Unknown option '" << arg << "'" << endl;
            return 1;
        }
    }

    if (printHelp) {
        cout << "Usage: " << argv[0] << " -f <input_file> [-o <output_file>] [-h]" << endl;
        cout << "-f <input_file>: Specify the input graph file." << endl;
        cout << "-o <output_file>: Redirect output to the specified file." << endl;
        cout << "-h: Print this help message." << endl;
        return 0;
    }

    if (!outputFile.empty()) {
        freopen(outputFile.c_str(), "w", stdout);
    }

    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Error: Unable to open input file '" << inputFile << "'" << endl;
        return 1;
    }

    fin >> n >> m;
    int a, b;
    while (m--) {
        fin >> a >> b;
        g[a].adj.push_back(b);
        g[b].rev_adj.push_back(a);
    }
    fin.close();

    Kosaraju();

    for (int i = 0; i < numComponents; ++i) {
        for (int j = 0; j < components[i].size(); ++j) {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
    cout << flush;

    return 0;
}
