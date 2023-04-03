printf("\nSearch data 22\n");
    Node *node = searchNode(list,22);
    if(node!=NULL){
        printf("Node %d found\n",node->data);
    }else{
        printf("Node %d not found\n",node->data);
    }