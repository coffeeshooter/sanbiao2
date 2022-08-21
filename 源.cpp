#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define HASHSIZE 15
#define NULLKEY -1234
struct HashTable {
	int* elem;
	int count;
};

int numHash = 0;

void InitHashTable(HashTable* H) {
	int i;
	numHash = HASHSIZE;
	H->count = numHash;
	H->elem = (int*)malloc(numHash * sizeof(int));
	for (i = 0; i < numHash; i++)
		H->elem[i] = NULLKEY;
}

int Hash(int key) {
	return key % numHash;
}

void InsertHash(HashTable* H, int key) {
	int addr = Hash(key);
	while (H->elem[addr] != NULLKEY)
		addr = (addr + 1) % numHash;
	H->elem[addr] = key;
}

bool SearchKeyInHash(HashTable H, int key, int* addr) {
	*addr = Hash(key);
	while (H.elem[*addr] != key) {
		*addr = (*addr + 1) % numHash;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
			return false;
	}
	return true;
}

void printHashTable(HashTable H) {
	int i;
	for (i = 0; i < numHash; i++)
		printf("%d ", H.elem[i]);
	printf("\n");
}

int main() {
	int i;
	HashTable* H = (HashTable*)malloc(sizeof(HashTable));
	int a[10] = { 1,13,2,3,4,5,6,7,26,47};
	InitHashTable(H);
	printHashTable(*H);
	for (i = 0; i < 10; i++)
		InsertHash(H, a[i]);
	printHashTable(*H);
	if (SearchKeyInHash(*H, 26, &i))
		printf("找到了！\n");
	else
		printf("关键字不存在！\n");
	return 0;
}