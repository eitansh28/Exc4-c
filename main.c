#include<stdio.h>
#include<stdlib.h>
#include "Nodes.h"
#include "Edges.h"
#include "algo.h"



int main(){

  pnode Graph = NULL;
  char choose;
  pnode* head=&Graph;

 while(scanf("%c",&choose)!=EOF){
   if(choose=='A'){
     deleteGraph(head);
     int numOfNodes=0;
     scanf("%d",&numOfNodes);
     *head=newNode(0);
     for(int i=1;i<numOfNodes;i++){
       insertNodeLast(i,head);
     }
     }else if(choose=='n'){
         int key,dest,weight;
         pnode currnode;
         scanf("%d",&key);
         currnode=g(key,*head);
         pnode a;
         while(scanf("%d",&dest)!=0 && scanf("%d",&weight)!=0){
           a=g(dest,*head);
           addEdge(&(currnode->edges),a,weight);
         }
       }else if(choose=='B'){
         int a,dest,weight;
         scanf("%d",&a);
         pnode Nnode=g(a,*head);
         if(Nnode==NULL){
           insertNodeLast(a,head);
          }
         else{
           pnode ite=g(a,*head);
           deleteEdge2(&(ite->edges));
         }
         pnode c;
         pnode t=g(a,*head);
         while(scanf("%d",&dest)!=0 && scanf("%d",&weight)!=0){
           c=g(dest,*head);
           addEdge(&(t->edges),c,weight);
           //printGraph_cmd(*head);
         }
           //printGraph_cmd(*head);
           // addnode(head);
           // printGraph_cmd(*head);
         }else if(choose=='D'){
           int x;
           scanf("%d",&x);
           deletenode(x,head);
           //printGraph_cmd(*head);
         }else if(choose=='S'){
           int x,y;
           scanf("%d",&x);
           scanf("%d",&y);
           int ans=dijikstra(x,y,*head);
           printf("Dijsktra shortest path:");
           printf(" %d\n",ans);
         }else if(choose=='T'){
           tsp(*head);
         }else if(choose=='\n' || choose==EOF){
           deleteGraph(head);
           return 0;
         }
       }return 0;
     }
