#include "algo.h"
// #include "Nodes.h"
// #include "Edges.h"
void deleteEdge2(pedge* first);


void deleteGraph(pnode* head){
  if(!*head)
    return;
  pnode h = *head;
  pnode d = *head;
  pnode* prev = head;
  while(h){
    deleteEdge2(&(h->edges));
    h=h->next;
  }while(d){
    *prev=d->next;
    free(d);
    d=*prev;
  }
}
// void makeGraph(pnode *head){
//   int numOfNodes=0;
//   scanf("%d",&numOfNodes);
//   *head=newNode(0);
//   for(int i=1;i<numOfNodes;i++){
//     insertNodeLast(i,head);
//   }char n;
//   int key,dest,weight;
//   pnode currnode;
//   scanf("%c",&n);
//   while(scanf("%c",&n)!='\n'){
//     if(n=='n'){
//       scanf("%d",&key);
//       currnode=g(key,*head);
//       pnode a;
//       while(scanf("%d",&dest)!=0 && scanf("%d",&weight)!=0){
//         a=g(dest,*head);
//         addEdge(&(currnode->edges),a,weight);
//       }
//     }else if(n=='B'){
//         //printGraph_cmd(*head);
//         addnode(head);
//         //printGraph_cmd(*head);
//       }else if(n=='D'){
//         int x;
//         scanf("%d",&x);
//         deletenode(x,head);
//         //printGraph_cmd(*head);
//       }else if(n=='S'){
//         int x,y;
//         //printf(" vvv ");
//         scanf("%d",&x);
//         //printf("%d",x);
//         scanf("%d",&y);
//         //printf("%d",y);
//         int ans=dijikstra(x,y,*head);
//         printf("Dijsktra shortest path:");
//         printf("%d",ans);
//         //printf(" ggg ");
//       }else if(n=='T'){
//         tsp(*head);
//       }//else if(n==EOF){
//         //return;
//       //}
//       else if(n=='A'){
//         //printf("ffff");
//         makeGraph(head);
//         //printGraph_cmd(*head);
//       }else{
//         return;
//       }
//     }
//
//
// }





void printGraph_cmd(pnode head){
  node p = *head;
  while(p.next){
    printf("node num: %d ",p.node_num);
    printf(" edges: ");
    while(p.edges){
      printf("dest: %d ",p.edges->endpoint->node_num);
      printf("w: %d ",p.edges->weight);
      p.edges=p.edges->next;
    }p=*p.next;
    printf("\n");
  }
    printf("node num: %d ",p.node_num);
    printf(" edges: ");
    while(p.edges){
      printf("dest: %d ",p.edges->endpoint->node_num);
      printf("w: %d ",p.edges->weight);
      p.edges=p.edges->next;
  }printf("\n");
  printf("\n");
}


int dijikstra(int x, int y ,pnode head){

    node p =*head;
    int wheight [100];
    int visited [100];
    int gothereby [100];
    int numofnodes=0;
    int wc=0;
    int vc=0;
    int gotherebycounter=0;
    while(p.next){
        wheight[wc]=2147483647;
        visited[vc]=0;
        gothereby[gotherebycounter]=-1;
        gotherebycounter++;
        vc++;
        wc++;
        p=*p.next;
        numofnodes++;
    }
    wheight[wc]=2147483647;
    visited[vc]=0;
    gothereby[gotherebycounter]=-1;
    gotherebycounter++;
    vc++;
    wc++;
    numofnodes++;
    wheight[x]=0;
    p=*head;
    int numofruns=0;
    while (numofruns<numofnodes){
        double minimumofshortweight=2147483647;
        int shortesttorootunvisted=-1;
        node temp =*head;
        int whilecounter=0;
        while (temp.next){
            if (!visited[whilecounter]&&wheight[whilecounter]<minimumofshortweight){
                minimumofshortweight=wheight[whilecounter];
                shortesttorootunvisted=whilecounter;
            }

            whilecounter++;
            temp = *temp.next;
        }


        temp=*head;
        int togettoshortestunvisted =0;
        while (togettoshortestunvisted<shortesttorootunvisted){
            temp=*temp.next;
            togettoshortestunvisted++;
        }
        edge currentedges=*temp.edges;
        while (currentedges.next){
            edge neighoredge=currentedges;
            int edgedest=neighoredge.endpoint->node_num;
            double newpossibleweight=minimumofshortweight+neighoredge.weight;
            if (visited[edgedest]) {
                currentedges=*currentedges.next;
                continue;
            }
            if (wheight[edgedest] <= newpossibleweight) {
                currentedges=*currentedges.next;
                continue;
            }
            gothereby[edgedest]=shortesttorootunvisted;
            wheight[edgedest]=newpossibleweight;
            currentedges=*currentedges.next;
        }
        int tchecker=1;
        while (tchecker){
            edge neighoredge=currentedges;
            int edgedest=neighoredge.endpoint->node_num;
            double newpossibleweight=minimumofshortweight+neighoredge.weight;
            if (visited[edgedest]) {
                tchecker=0;
                continue;
            }
            if (wheight[edgedest] <= newpossibleweight) {
                tchecker=0;
                continue;
            }
            gothereby[edgedest]=shortesttorootunvisted;
            wheight[edgedest]=newpossibleweight;
            tchecker=0;
        }

        visited[shortesttorootunvisted]=1;
        numofruns++;
        if(numofnodes==numofruns){
            break;
        }

        p=*p.next;
    }
    int bugfixer=gothereby[0]-gothereby[0];

    return wheight[y]+bugfixer;
}
void shortpath(int x, int y, pnode head){
    node p=*head;
    int wheight[100];
    int visited [100];
    int gothereby [100];
    int lastnodeid=0;
    int numofnodes=0;
    int wc=0;
    int vc=0;
    int gotherebycounter=0;
    while (p.next){
        wheight[wc]=2147483647;
        visited[vc]=0;
        gothereby[gotherebycounter]=-1;
        wc++;
        numofnodes++;
        vc++;
        gotherebycounter++;
        p=*p.next;
    }
    wheight[wc]=2147483647;
    visited[vc]=0;
    gothereby[gotherebycounter]=-1;
    numofnodes++;
    lastnodeid=p.node_num;
    p=*head;
    while (lastnodeid<p.node_num){
        int minimumofshortestweight=2147483647;
        int shortesttorootunvisited=-1;
        for(int i =0; i<numofnodes;i++){
            if(!visited[i]&&wheight[i]<minimumofshortestweight){
                minimumofshortestweight=wheight[i];
                shortesttorootunvisited=i;
            }
        }
        node temp =*head;
        while (temp.node_num<shortesttorootunvisited){
            temp=*temp.next;
        }
        edge currentedges=*temp.edges;
        while (currentedges.next){
            edge neighboredge=currentedges;
            int destedge=neighboredge.endpoint->node_num;
            int newpossibleweight=minimumofshortestweight+neighboredge.weight;
            if(visited[destedge]){
                currentedges=*currentedges.next;
                continue;
            }
            if(wheight[destedge]<=newpossibleweight){
                currentedges=*currentedges.next;
                continue;
            }
            gothereby[destedge]=shortesttorootunvisited;
            wheight[destedge]=newpossibleweight;
            currentedges=*currentedges.next;
        }
        for (int i = 0; i < 1; i++) {
            edge neighboredge=currentedges;
            int destedge=neighboredge.endpoint->node_num;
            int newpossibleweight=minimumofshortestweight+neighboredge.weight;
            if(visited[destedge]){
                continue;
            }
            if(wheight[destedge]<=newpossibleweight){
                continue;
            }
            gothereby[destedge]=shortesttorootunvisited;
            wheight[destedge]=newpossibleweight;
        }
        visited[shortesttorootunvisited]=1;
        p=*p.next;
    }
    if(wheight[y]>=100000){
        printf("\nwheight is :");
        printf("%d",-1);
    }
    else {
        printf("\nwheight is :");
        printf("%d", wheight[y]);
    }
    return;


}

int indexOf(int pointId, pnode node[]) {
    int i;
    for (i=0;i<100;i++) {
        if (node[i]->node_num == pointId)
            return i;
    }
    return -1;
}

int shortPath(int x, int y, const pnode head){

    int size=0;
    pnode p;
    int i, j;
    pnode points [100];
    int weight [100];
    int visited [100];
    int gotHereBy [100];
    int gotHereByCounter=0;
    int srcIndex, destIndex;

    /*Init values*/
    i = 0;
    p = head;
    while (p) {
        weight[i] = 2147483647;
        visited[i] = 0;
        gotHereBy[i] = -1;
        points[i] = p;

        if (p->node_num == x)
            srcIndex = i;
        if (p->node_num == y)
            destIndex = i;

        size++;
        i++;
        p = p->next;
    }

    weight[srcIndex] = 0;

    for (i=0; i<size; i++) {

        int minimumOfShortWeight = 2147483647;
        int shortestToRootUnvisted=-1;
        p = head;
        j=0;
        while (p) {
            if ( (!visited[j]) && weight[j]<minimumOfShortWeight ){
                minimumOfShortWeight=weight[j];
                shortestToRootUnvisted=j;
            }
            j++;
            p = p->next;
        }

        pnode shortestToRootPoint = head;
        for (j=0; j<shortestToRootUnvisted; j++) {
            shortestToRootPoint = shortestToRootPoint->next;
        }

        pedge currentEdges = shortestToRootPoint->edges;
        while (currentEdges) {
            pedge neighorEdge = currentEdges;
            int edgeDestId=neighorEdge->endpoint->node_num;
            int edgeDestIndex = indexOf(edgeDestId, points);
            int newPossiblewWight = minimumOfShortWeight + (neighorEdge->weight);
            if (visited[edgeDestIndex]) {
                currentEdges=currentEdges->next;
                continue;
            }
            if (weight[edgeDestIndex] <= newPossiblewWight) {
                currentEdges=currentEdges->next;
                continue;
            }
            gotHereBy[edgeDestIndex]=shortestToRootUnvisted;
            weight[edgeDestIndex]=newPossiblewWight;
            currentEdges=currentEdges->next;
        }

        visited[shortestToRootUnvisted]=1;


    }

    return weight[destIndex];
}
void copyarray (int arrtobec[],int arr [],int size){
    for (int i = 0; i <size ; ++i) {
        arr[i]=arrtobec[i];
    }
    return;
}







int minTSP=24141;

void printarray(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sumPer(int* arr,int len,pnode head){
    int sum=0;
    //printf(" %d \n",minTSP);
    for(int i=0;i<len;i++){
        if(shortPath(arr[i],arr[i+1],head)<0){
          return;
         }
        //printf(" %d \n",shortPath(arr[i],arr[i+1],head));
        sum+=shortPath(arr[i],arr[i+1],head);
    }if(sum<minTSP&&sum>=0){
        minTSP=sum;
        //printf(" %d \n",minTSP);
    }
}
//permutation function
void permutation(int *arr, int start, int end,pnode head)
{
    if(start==end)
    {
        sumPer(arr, end,head);

        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end,head);
        swap((arr+i), (arr+start));
    }
}



void tsp(pnode head){
    //printf("\nweenternow\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        //printf("%d",arr[i]);
    }permutation(arr,0,size-1,head);
    if(minTSP==0){
      minTSP=-1;
    }
    printf("TSP shortest path: %d \n",minTSP);
    minTSP=24141;

}
