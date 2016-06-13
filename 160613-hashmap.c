#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE -1
typedef int STATUS;

typedef struct _NODE{
	int data;
	struct _NODE* next;
} NODE;

typedef struct _HASH_TABLE{
	NODE* value[10];
} HASH_TABLE;

HASH_TABLE* create_hash_table(){
	HASH_TABLE* pHashTbl = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
	memset(pHashTbl, 0, sizeof(HASH_TABLE));
	return pHashTbl;
}

NODE* find_data_in_hash(HASH_TABLE* pHashTbl, int data){
	NODE* pNode;
	if(NULL == pHashTbl){
		return NULL;
	}
	if(NULL == (pNode = pHashTbl->value[data%10])){
		return NULL;
	}
	while(pNode){
		if(data == pNode->data){
			return pNode;
		}
		pNode = pNode->next;
	}
	return NULL;
}

STATUS insert_data_into_hash(HASH_TABLE* pHashTbl, int data){
	NODE* pNode;
	if(NULL == pHashTbl){
		return FALSE;
	}

	if(NULL == pHashTbl->value[data%10]){
		pNode = (NODE*)malloc(sizeof(NODE));
		memset(pNode, 0, sizeof(NODE));
		pNode->data = data;
		pHashTbl->value[data%10] = pNode;
		return TRUE;
	}

	if(NULL != find_data_in_hash(pHashTbl, data)){
		return FALSE;
	}

	pNode = pHashTbl->value[data%10];
	while(NULL != pNode->next){
		pNode = pNode->next;
	}

	pNode->next = (NODE*)malloc(sizeof(NODE));
	memset(pNode->next, 0, sizeof(NODE));
	pNode->next->data = data;
	return TRUE;
}

STATUS delete_data_from_hash(HASH_TABLE* pHashTbl, int data){
	NODE* pHead;
	NODE* pNode;
	if(NULL == pHashTbl || NULL == pHashTbl->value[data%10]){
		return FALSE;
	}
	if(NULL == (pNode = find_data_in_hash(pHashTbl, data))){
		return FALSE;
	}
	if(pNode == pHashTbl->value[data % 10]){
		pHashTbl->value[data%10] = pNode->next;
		free(pNode);
		return TRUE;
	}
	// pNode is not the first node in value[data%10] list :
	pHead = pHashTbl->value[data%10];
	while(pNode != pHead->next){
		pHead = pHead->next;
	}
	pHead->next = pNode->next;
}

int main(){
	HASH_TABLE* hashtable = create_hash_table();
	insert_data_into_hash(hashtable, 1);
	insert_data_into_hash(hashtable, 16);
	insert_data_into_hash(hashtable, 21);
	insert_data_into_hash(hashtable, 11);
	insert_data_into_hash(hashtable, 12);
	insert_data_into_hash(hashtable, 4);

	if(hashtable->value[3]){
		printf("hashtable 3 : %d \n",hashtable->value[3]->data);
	} else{
		printf("hashtable 1 : %d \n",hashtable->value[1]->data);
	}

	return 0;
}
