#include "algo.h"
#include "Nodes.h"
#include "Edges.h"


pedge newEdge(pnode dest, int weight) {
  pedge p = (pedge) malloc (sizeof(edge));
  if(!p)
    return NULL;
  p->endpoint = dest;
  p->weight=weight;
  p->next=NULL;
return p;
}

void addEdge(pedge* curr2,pnode EOP,int weight){
  pedge* temp=curr2;
  while(*temp){
    temp=&(((*temp)->next));
  }*temp=newEdge(EOP,weight);
}
// typedef struct Edge{
//   int src;
//   int dest;
//   double weight;
// }edge;
