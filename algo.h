#include<stdio.h>
#include<stdlib.h>


typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void deletenode(int id,pnode* head);
void addnode(pnode *head);
void insertNodeLast(int node_num,pnode *head);
pnode newNode(int node_num);
pnode getnode(int key, pnode head);
pnode g(int key,pnode head);
pedge newEdge(pnode dest, int weight);
void addEdge(pedge* curr,pnode EOP,int weight);
void makeGraph(pnode *head);
void printGraph_cmd(pnode head);
void deleteGraph(pnode* head);
int dijikstra(int x, int y ,pnode head);
void shortPath(int x, int y, pnode head);
void tsp(pnode head);
