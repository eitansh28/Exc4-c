#include<stdio.h>
#include<stdlib.h>
#include "Nodes.h"
#include "Edges.h"
#include "algo.h"



int main(){
  //int x,y;
  pnode Graph = NULL;
  // Graph =  (pnode) calloc (sizeof(node),1);
  // if(!Graph){
  //   return 0;
  // }


    char choose;
    pnode* head=&Graph;

 while(scanf("%c",&choose)!='v'){
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
           //printf("-is-");
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
         }else if(choose=='\n'){
           deleteGraph(head);
           return 0;
         }
       }
     }



//   while(scanf("%c",&choose) != 0){
//
//
//     switch (choose){
//
//       case 'A':
//         makeGraph(&Graph);
//         //printGraph_cmd(Graph);
//         break;
//
//       case 'B':
//         //printf("nvnvnv");
//         addnode(&Graph);
//         //printGraph_cmd(Graph);
//         break;
//
//       case 'D':
//         scanf(" %d",&x);
//         deletenode(x,&Graph);
//         //printGraph_cmd(Graph);
//         break;
//
//       case 'S':
//         scanf(" %d %d",&x, &y);
//         shortPath(x,y,Graph);
//         break;
//
//       case 'T':
//         //scanf(" %d %d",&x, &y);
//         tsp(Graph);
//         break;
//       }
//   }return 0;
// }
