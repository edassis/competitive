/* Universidade de Brasília
 * Departamento de Ciência da Computação
 * CIC0169 - Programação Competitiva 
 * Prof. Dr. Vinicius R. P. Borges
 * 
 * Simulado da Prova III: Solucao do problema Vertice Dominante
 * 
 * Compilar: g++ solucao_dfs_dominator.cpp -std=c++11 -o dominante
 * Executar: ./dominante
 */

#include<bits/stdc++.h>

using namespace std;

int V, tc, count = 1;
vector<vector<int>> graph(505);
vector<bool> visitados(505,false);
bool first;

void dfs(int u) {

	visitado[u] = true;
        
	for (int v : graph[u]) {
            if (!visited[v])
                dfs(v);
	}
}

int main() {
        int a,b,q,m;
        
	scanf("%d %d %d", &V,&m,&q);
        
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;
            
            graph[a].push_back(b);
        }
   
        dfs(0);

        for(int i = 0; i < q; i++)
        {
            scanf("%d %d",&a,&b);
            a--;
            b--;
            for (int k = 0; k < V; k++)
                curVisited.reset(k);
            
            dfs(0, a);
            
            if (initVisited.test(b) && (a == b || !curVisited.test(b)))
                printf("sim\n");
            else
		printf("nao\n");
	}

	return 0;
}