#include<stdio.h>
int vertex;
int graph[100][100];
int n=0; // id edges
int x=0; // id results

struct Edge{
	int src,dest,w;
}edges[100], results[100];

void sort(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(edges[j].w > edges[j+1].w){
				Edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}


void kruskal(){
	int f1, f2, belongs[100];
	for(int i=0;i<n;i++){
		belongs[i] = i;
	}
	
	for(int i=0;i<n;i++){
		f1 = belongs[edges[i].src];
		f2 = belongs[edges[i].dest];
		
		if(f1 != f2){
			results[x++] = edges[i];
			//union
			for(int j=0;j<n;j++){
				if(belongs[j] == f2) belongs[j] = f1;
			}
		}
		
	}
	
}

void printResults(){
	for(int i=0;i<x;i++){
		printf("%c -> %c = %d\n", 65+results[i].src, 65+results[i].dest, results[i].w);
	}
}

int main(){
	printf("Input vertex: ");
	scanf("%d", &vertex);
	getchar();
	
	for(int i=0;i<vertex;i++){
		for(int j=0;j<vertex;j++){
			scanf("%d", &graph[i][j]);
			getchar();
		}
	}
	
	for(int i=0;i<vertex;i++){
		for(int j=0;j<i;j++){
			if(graph[i][j] != 0){
				edges[n].src = i;
				edges[n].dest = j;
				edges[n++].w = graph[i][j];				
			}
		}
	}
	
	sort();	
	kruskal();
	printf("\nResults:\n");
	printResults();
//	for(int i=0;i<n;i++){
//		printf("%d -> %d = %d\n", edges[i].src, edges[i].dest, edges[i].w);
//	}
	//printf("Cost: %d\n",x);
	return 0;
}
