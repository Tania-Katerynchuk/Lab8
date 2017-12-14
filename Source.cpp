#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
bool EntrancTopGraph(vector<vector<int>> boundSubgraph, int k);
void MatrixAdjacencySupgraph(vector<vector<int>> matrixAdjacency, vector<vector<int>> boundSubgraph, int n);
void OutputMatrixAdjacencySupgraph(vector<vector<int>> boundSubgraph, vector<vector<int>> tempSubgraph, int nSubgraph);

void InputMatrixAdjacency(vector<vector<int>>& matrixAdjacency,int n) {
	cout << "¬ведiть матрицю сумiжностi\n\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			int arc;
			cin >> arc;
			matrixAdjacency[i].push_back(arc);
		}
		matrixAdjacency.push_back(vector<int>());
	}
	
}
void OutputMatrixAdjacency(vector<vector<int>> matrixAdjacency, int n) {
	cout << "ћатриц€ сумiжностi: "<<endl<<"  ";
	for (int i = 1; i <= n; i++) {
		cout <<" "<< i;
	}
	cout << endl<<"   ";
	
	for (int i = 1; i <= n; i++) {
		cout << "__";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " |";
		for (int j = 0; j < n; j++) {
			cout <<matrixAdjacency[i][j]<<" ";
		}
		cout <<"|"<< endl;
	}
	cout << "   ";
	for (int i = 1; i <= n; i++) {
		cout << "__";
	}
	cout << endl;
}

void SearchBoundSubgraph(vector<vector<int>> matrixAdjacency, int n) {
	vector<vector<int>> boundSubgraph;
	int nSupgraph = 0;
	boundSubgraph.push_back(vector<int>());
	boundSubgraph[nSupgraph].push_back(0);
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (matrixAdjacency[i][j] > 0) {
					if (EntrancTopGraph(boundSubgraph, i)) {
						if(!EntrancTopGraph(boundSubgraph, j))
							boundSubgraph[nSupgraph].push_back(j);
					}
					else {
						nSupgraph++;
						boundSubgraph.push_back(vector<int>());
						boundSubgraph[nSupgraph].push_back(j);
					}

				}
			}
		}

		
	}
	MatrixAdjacencySupgraph(matrixAdjacency, boundSubgraph, n);

}

void MatrixAdjacencySupgraph(vector<vector<int>> matrixAdjacency, vector<vector<int>> boundSubgraph,int n) {
	for (int i = 0; i < boundSubgraph.size(); i++) {
		for (int repeat_counter = 0; repeat_counter < boundSubgraph[i].size(); repeat_counter++)
		{
			int temp = boundSubgraph[i][0];
			for (int element_counter = repeat_counter + 1; element_counter < boundSubgraph[i].size(); element_counter++)
			{
				if (boundSubgraph[i][repeat_counter] > boundSubgraph[i][element_counter])
				{
					temp = boundSubgraph[i][repeat_counter];
					boundSubgraph[i][repeat_counter] = boundSubgraph[i][element_counter];
					boundSubgraph[i][element_counter] = temp;
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < boundSubgraph.size(); i++) {
		vector<vector<int>> tempSubgraph;
		for (int j = 0; j < boundSubgraph[i].size(); j++) {
			tempSubgraph.push_back(vector<int>());
			for (int k = 0; k < boundSubgraph[i].size();k++) {
				tempSubgraph[j].push_back(matrixAdjacency[boundSubgraph[i][j]][boundSubgraph[i][k]]);
				
				
				
			}
		}
		OutputMatrixAdjacencySupgraph(boundSubgraph, tempSubgraph, i);
		cout << endl;
	}
}


void OutputMatrixAdjacencySupgraph(vector<vector<int>> boundSubgraph, vector<vector<int>> tempSubgraph, int nSubgraph) {
	cout << "ћатриц€ сумiжностi "<<nSubgraph+1<<" зв'€зного пiдграфа даного графа: \n\n  ";
	for (int i = 0; i < tempSubgraph.size(); i++) {
		cout << " " << boundSubgraph[nSubgraph][i]+1;
	}
	cout << endl << "   ";

	for (int i = 0; i < tempSubgraph.size(); i++) {
		cout << "__";
	}
	cout << endl;
	for (int i = 0; i < tempSubgraph.size(); i++) {
		cout << boundSubgraph[nSubgraph][i] + 1  << " |";
		for (int j = 0; j < tempSubgraph.size(); j++) {
			cout << tempSubgraph[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "   ";
	for (int i = 0; i < tempSubgraph.size(); i++) {
		cout << "__";
	}
	cout << endl;
}


bool EntrancTopGraph(vector<vector<int>> boundSubgraph,int k) {
	for (int i = 0; i < boundSubgraph.size(); i++) {
		for (int j = 0; j < boundSubgraph[i].size(); j++) {

			if (boundSubgraph[i][j] == k) {
				return true;
			}
		}
	}
	return false;
}


int main() {
	setlocale(LC_CTYPE, "ukr");
	int n=6;
	cout << "¬ведiть кiлькiсть вершин графа: "; cin >> n;
	vector<vector <int>> matrixAdjacency(n);
	InputMatrixAdjacency(matrixAdjacency,n);
	
	OutputMatrixAdjacency(matrixAdjacency,n);
	SearchBoundSubgraph(matrixAdjacency, n);


	system("pause");
	return 0;
}
