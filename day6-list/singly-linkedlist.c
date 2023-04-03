#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *pNext;
}Node;

typedef struct SingleList{
    Node *pHead;
    Node *pTail;
    int size;
}SingleList;

void initialize(SingleList *list){
    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;
}
Node *createNode(int data){
    Node *node = malloc(sizeof(Node));
    if(node != NULL){
        node->data = data;
        node->pNext = NULL;
    }else{
        printf("create node failed");
    }
    return node;
}
void printList(SingleList *list){
    Node *pTmp = list->pHead;
    if(pTmp == NULL){
        printf("List is empty!");
        return;
    }
    while(pTmp != NULL){
        printf("%d ", pTmp->data);
        pTmp = pTmp->pNext;
    }
}
void insertFirst(SingleList *list, int data){
    Node *node = createNode(data);
    if(list->pHead == NULL){
        list->pHead = list->pTail = node;
    }else{
        node->pNext = list->pHead;
        list->pHead = node;
    }
    list->size += 1;
}
void insertLast(SingleList *list, int data){
    Node *node = createNode(data);
    if(list->pHead == NULL){
        list->pHead = list->pTail = node;
    }else{
        list->pTail->pNext = node;
        list->pTail = node;
    }
    list->size += 1;
}
void insertMid(SingleList *list, int pos, int data){
    if(pos < 0 || pos >= list->size){
        printf("Invalid position");
    }else if(pos == 0){
        insertFirst(list, data);
    }else if(pos == list->size - 1){
        insertLast(list, data);
    }else{
            Node *node = createNode(data);
            Node *pIns = list->pHead;
            Node *pPre = NULL;
            int i = 0;
            while(pIns != NULL){
                if(i == pos) break;
                pPre = pIns;
                pIns = pIns->pNext;
                i++;
            }
            pPre->pNext = node;
            node->pNext = pIns;
    }
    list->size += 1;
}
void removeNode(SingleList *list, int data){
    Node *pDel = list->pHead;
    if(pDel == NULL){
        printf("List is empty!");
    }else{
        Node *pPre = NULL;
        while(pDel != NULL){
            if(pDel->data == data) break;
            pPre = pDel;
            pDel = pDel->pNext;
        }
        if(pDel == NULL){
            printf("Couldn't find node!\n");
        }else{
            if(pDel == list->pHead){
                list->pHead = pDel->pNext;
                pDel->pNext = NULL;
                free(pDel);
            }else if(pDel == list->pTail){
                list->pTail = pPre;
                list->pTail->pNext = NULL;
                free(pDel);
            }else{
                pPre->pNext = pDel->pNext;
                pDel->pNext = NULL;
                free(pDel);
            }
        }
    }
}
Node *searchNode(SingleList *list,int data){
    Node *pTmp = list->pHead;
    if(pTmp == NULL){
        printf("List is empty!\n");
        return NULL;
    }
        while(pTmp != NULL){
            if(pTmp->data == data)
                return pTmp;
            pTmp = pTmp->pNext;
        }
        return NULL;
}
int main(){
    SingleList *list;
    initialize(list);
    insertFirst(list,5);
    insertFirst(list,2);
    insertMid(list,1,112);
    insertLast(list,3);
    insertFirst(list,8);
    insertMid(list,3,22);
    printList(list);
    printf("\nRemove data 3\n");
    removeNode(list,3);
    printList(list);
    printf("\nRemove data 8\n");
    removeNode(list,8);
    printList(list);
    printf("\nSearch data 22\n");
    Node *node = searchNode(list,33);
    if(node!=NULL){
        printf("Node %d found\n",node->data);
    } else{
        printf("Node not found\n");
    }
    return 0;
}