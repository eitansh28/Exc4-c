#include "Edges.h"
#include "algo.h"
#include "Nodes.h"

void deleteEdge(int id, pedge* first);
void deleteEdge2(pedge* first);


pnode g(int key,pnode head){
  pnode temp=head;
  while(temp){
    if(temp->node_num==key){
      return temp;
    }
      temp=temp->next;
    }return NULL;
}
pnode getnode(int key, pnode head){
  pnode temp=head;
  while(temp->node_num!=key){
    temp=temp->next;
  }return temp;
}
pnode newNode(int node_num) {
  pnode p = (pnode) malloc (sizeof(node));
  if(!p)
    return NULL;
  p->node_num = node_num;
  p->edges=NULL;
  p->next=NULL;
return p;
}

void insertNodeLast(int node_num,pnode *head){
  pnode *p = head;
  while(*p){
    p = &((*p)->next);
  }
  *p = newNode(node_num);
}


void addnode(pnode *head){
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
  }
}

void deleteEdge(int id, pedge* first){
  if(!*first)
    return;
  pedge f=*first;
  pedge* prev= first;
  while(f){
    if(f->endpoint->node_num==id){
      *prev=f->next;
      free(f);
      f=*prev;
      return;
  }else{
    prev=&(f->next);
    f=f->next;
  }
}
}

void deleteEdge2(pedge* first){
  if(!*first)
    return;
  pedge f=*first;
  pedge* prev= first;
  while(f){
      *prev=f->next;
      free(f);
      f=*prev;
}
}

void deletenode(int id,pnode* head){
  if(!*head)
    return;
  pnode h = *head;
  pnode d = *head;
  pnode* prev = head;
  while(d){
    deleteEdge(id,(&(d->edges)));
    d=d->next;
  }
  while(h){
    if((h)->node_num==id){
      deleteEdge2(&(h->edges));
      *prev=h->next;
      free(h);
      h=*prev;
      return;
    }else{
      prev=&(h->next);
      h=h->next;
    }
  }
}
