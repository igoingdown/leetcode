#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


void DFS(vector<int>& visited, vector<vector<int> >& matrix, int node, int nodeNum);
void DFS_visit(vector<int>& visited, vector<vector<int> >& m, int nodeNum);

int main(void) {
	ifstream infile;
	infile.open("graph.txt");
	int nodeNum;
	infile >> nodeNum;
	int i, j;
	vector<int> visited(nodeNum, 0);
	vector<vector<int> > m(nodeNum, vector<int>(nodeNum, 0));
	while (infile >> i >> j) {
		cout << i << " "<< j << endl;
		m[i - 1][j - 1] = 1;
	}
	DFS_visit(visited, m, nodeNum);
	return 0;
}


void DFS_visit(vector<int>& visited, vector<vector<int> >& m, int nodeNum) {
	for (int i = 0; i < nodeNum; i++) {
		if (!visited[i]) {
			printf("%d\n", i + 1);
			visited[i] = 1;
			DFS(visited, m, i, nodeNum);
		}
	}
}


void DFS(vector<int>& visited, vector<vector<int> >& matrix, int node, int nodeNum){
	for (int i = 0; i < nodeNum; i++) {
		if (!visited[i] && matrix[node][i]) {
			printf("%d\n", i + 1);
			visited[i] = 1;
			DFS(visited, matrix, i, nodeNum);
		}
	}
}


