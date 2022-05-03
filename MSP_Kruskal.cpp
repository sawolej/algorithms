#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxM = 100;
int roots[maxM];
long m, d, c1, c2, p, tree, minG = 0,pepesN, temp, maxG=0;
vector < vector<int>> L(100);
vector < vector<int>> S(435);
vector < vector<int>> vectTemp(100);
vector<int> tab;
vector<int> pepes;
vector<int> bef;
bool visited[maxM];

void kruskal();
int find_root(int x);
void add_root(int x, int y);
void visit_node(int x);
void DFS(int start, int stop);
int main()
{
	long start, stop, pep;
	for (int i = 0; i < maxM; i++)
	{
		roots[i] = i;
	}
	cin >> m >> d;
	for (int i = 1; i <= m; i++) L[i].push_back(i);
	for (int i = 0; i < d; i++) {
		cin >> c1 >> c2 >> p;
		if (p > maxG) maxG = p;
		tab.push_back(p-1);
		tab.push_back(c1);
		tab.push_back(c2);
		S.push_back(tab);
		tab.clear();		
	}

	sort(S.begin(), S.end());

	tree = 0;
	kruskal();

	for (int i = 0; i < tree; i++) {
		if (!L.empty()) {
			tab = L.back();
			L.pop_back();
			vectTemp[tab[1]].push_back(tab[2]);
			vectTemp[tab[2]].push_back(tab[1]);
			vectTemp[tab[1]].push_back(tab[0]);
			vectTemp[tab[2]].push_back(tab[0]);
		}
	}


	cin >> start >> stop;
	while (start != 0 && stop != 0) {
		pepes.clear();
		if (maxG <= 1) {
			cin >> pep;
			cout << 0 << "\n";
			cin >> start >> stop;
		}else{
		cin >> pep;
		for (int i = 0; i < maxM; i++) visited[i] = 0;
		pepesN = 0;
		DFS(start, stop);

		minG = pepes.back();
		pepes.pop_back();
		int sizePepes = pepes.size();
		for(int i =0; i<sizePepes; i++){
			
			if (minG > pepes.back()) minG = pepes.back();
			pepes.pop_back();
		}

		cout << ceil((float)pep / (float)minG)<<"\n";
		cin >> start >> stop;
	}
	}

	return 0;
}

void DFS(int start, int stop) {

	
	int iter = 0;
	visited[start] = 1;
	tab = vectTemp[start];

	if (start == stop) {
		
	}else {

		while (visited[tab[iter]] == 1 && iter < tab.size()-2) iter += 2;

		if (iter < tab.size() && visited[tab[iter]]==0) {
			bef.push_back(start);
			pepes.push_back(tab[iter + 1]);			
			DFS(tab[iter], stop);
		}else {
			pepes.pop_back();	
			temp = bef.back();
			bef.pop_back();
			DFS(temp, stop);
		}
	}


}

void kruskal() {
	int w1, w2;
		for (int i = 0; i < d; i++) {
			
			tab = S.back();
			S.pop_back();
			w1 = find_root(tab[1]);
			w2 = find_root(tab[2]);
			if (w1 != w2) {
				L.push_back(tab);
				tree++;
			}
			add_root(w1, w2);
			
		}
}
int find_root(int x) {
	if (x == roots[x]) return x;
	else return find_root(roots[x]);
}

void add_root(int x, int y) {
	roots[x] = roots[y];
}