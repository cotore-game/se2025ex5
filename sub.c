#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int value;
    struct treeNode *left, *right;
};

void printArr(int *bHeapArr, int size);
void printTree(int indent, struct treeNode *ptr);
void swap(int *bHeapArr, int i, int j);
void heapUp(int *bHeapArr, int i);
struct treeNode *transArrTree(int *bHeapArr, int i, int size);

int main(void){
	int data[] = {8, 54, 11, 33, 87, 36, 35, 4, 79, 99}, size = 10;
	int *bHeapArr, i;
	struct treeNode *root; 
	bHeapArr = (int *) malloc(sizeof(int)*size); 
	for(i = 0; i < size; i++){ 
		bHeapArr[i] = data[i];
		heapUp(bHeapArr, i); 
	}
	printArr(bHeapArr, size);
	root = transArrTree(bHeapArr, 0, size);
	printTree(0, root); 
	return 0;
}
void printArr(int *bHeapArr, int size){
	int i;
	for (i = 0; i < size; i++)
		printf("A[%d]=%d%c", i, bHeapArr[i], i == size-1 ? '\n': ','); 
}
void swap(int *bHeapArr, int i, int j){
	int tmp = bHeapArr[i];
	bHeapArr[i] = bHeapArr[j]; 
	bHeapArr[j] = tmp; 
}
void heapUp(int *bHeapArr, int i){
	if(i == 0) return;
	if(bHeapArr[(i-1)/2] > bHeapArr[i]){
		int tmp = bHeapArr[(i-1)/2];
		bHeapArr[(i-1)/2] = bHeapArr[i];
		bHeapArr[i] = tmp;

		heapUp(bHeapArr, (i-1)/2); 
	}
}
void printTree(int indent, struct treeNode *ptr){
	int i;
	if (ptr == NULL) {
		for (i = 0; i < indent; i++) printf(" ");
		printf("NULL\n"); 
	}
	else {
		printTree(indent + 7, ptr->right);
		for (i = 0; i < indent; i++) printf(" ");
		printf("value = %d\n", ptr->value);
		printTree(indent + 7, ptr->left);
	}
}
struct treeNode *transArrTree(int *bHeapArr, int i, int size){
	if (i >= size) return NULL;

    struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
    if (node == NULL) {
        printf("メモリ確保失敗\n");
        exit(1);
    }

    node->value = bHeapArr[i];
    node->left = transArrTree(bHeapArr, 2*i+1, size);
    node->right = transArrTree(bHeapArr, 2*i+2, size);

    return node;
}
