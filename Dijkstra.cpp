/** \file Dijkstra.cpp
*	\brief Dijkstra's algorithm implementation
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

/** \fn void Dijkstra(int** GR, int V)
*	\brief Dijkstra's algorithm immediate implementation
*	\param **GR - adjacency matrix of the graph
*	\param V - number of vertexes
*	<br>*distance - array of distances from the 1st vertes to others
*	<br>*visited - array of visited vertexes
*/
void Dijkstra(int** GR, int V) {
	int* distance=new int[V], count, index, i, u, m=1;
	bool* visited=new bool[V];
	for (i=0; i<V; i++) {
		distance[i]=INT_MAX;
		visited[i]=false;
	}
	distance[0]=0;
	for (count=0; count<V-1; count++) {
		int min=INT_MAX;
		for (i=0; i<V; i++)
			if (!visited[i] && distance[i]<=min) {
				min=distance[i];
				index=i;
			}
		u=index;
		visited[u]=true;
		for (i=0; i<V; i++)
			if (!visited[i] && GR[u][i] && (distance[u]!=INT_MAX) &&
				(distance[u]+GR[u][i]<distance[i]))
				distance[i]=distance[u]+GR[u][i];
	}
	printf("Distances from the first vertex:\n");
	for (i=0; i<V; i++)
		if (distance[i]!=INT_MAX)
			printf("%d ",distance[i]);
		else printf("(no path) ");
}
void main()
{
	int N,**GR;
	printf("Input number of vertexes: "); scanf("%d",&N);
	GR=new int*[N];
	for (int i=0; i<N; i++)
		GR[i] = new int[N];
	printf("Input distances between vertexes; if it is not exist, input 0\n");
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++) {
			printf("From %d to %d=",i+1,j+1);
			scanf("%d",&GR[i][j]);
	}
	Dijkstra(GR,N);
	delete[] GR;
		
	getch();
}