#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define WORD_LENGTH 20
#define MEAN_LENGTH 200

typedef struct {
	char word[WORD_LENGTH];
	char mean[MEAN_LENGTH];
}element;

typedef struct treeNode {
	element key;
	struct treeNode *left;
	struct treeNode *right;
}treeNode;

treeNode* insertKey(treeNode *p, element key) {
	treeNode *NNode;
	int compare;

	if (p == NULL) {
		NNode = (treeNode*)malloc(sizeof(treeNode));
		NNode->key = key;
		NNode->left = NULL;
		NNode->right = NULL;
		return NNode;
	}
	compare = strcmp(key.word, p->key.word);
	if (compare < 0) p->left = insertKey(p->left, key);
	else if (compare > 0) p->right = insertKey(p->right, key);
	else printf("There are same word\n");

	return p;
}

void insert(treeNode **root, element key) {
	*root = insertKey(*root, key);
}

void delNode(treeNode *root, element key) {
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (strcmp(p->key.word, key.word) != 0)) {
		parent = p;
		if (strcmp(key.word, p->key.word) < 0)p = p->left;
		else p = p->right;
	}

	if (p == NULL) {
		printf("\n������ �ܾ �����ϴ�!");
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p)parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL)child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p)parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	else {
		succ_parent = p;
		succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent->left == succ) succ_parent->left = succ->right;
		else succ_parent->right = succ->right;
		p->key = succ->key;
		p = succ;
	}
	free(p);
}

treeNode* searchBST(treeNode *root, element key) {
	treeNode *p;
	int compare;
	p = root;

	while (p != NULL) {
		compare = strcmp(key.word, p->key.word);
		if (compare < 0)p = p->left;
		else if (compare > 0)p = p->right;
		else {
			printf("\nã�� �ܾ� : %s", p->key.word);
			return p;
		}
	}
	return p;
}

void displayInorder(treeNode *root) {
	if (root) {
		displayInorder(root->left);
		printf("\n%s : %s", root->key.word, root->key.mean);
		displayInorder(root->right);
	}
}

void menu() {
	printf("\n--------------------------------");
	printf("\n\t1. ���");
	printf("\n\t2. �Է�");
	printf("\n\t3. ����");
	printf("\n\t4. �˻�");
	printf("\n\t5. ����");
	printf("\n--------------------------------");
}

void main() {
	char sel;
	element e;
	treeNode *root = NULL, *temp = NULL;

	do {
		menu();
		sel = getchar(); getchar();

		switch (sel - '0') {
		case 1:
			printf("\t[�������]");
			displayInorder(root); printf("\n\t[���� ��]");
			break;
		case 2:
			printf("\n[�ܾ��Է�] �ܾ �Է��Ͻÿ� : "); gets(e.word);
			printf("\n[�ܾ��Է�] �ܾ��� ���� �Է��Ͻÿ� ; "); gets(e.mean);
			insert(&root, e);
			break;
		case 3:
			printf("\n[�ܾ����]������ �ܾ� : "); gets(e.word);
			delNode(root, e);
			break;
		case 4:
			printf("\n[�ܾ�˻�]�˻��� �ܾ� : "); gets(e.word);
			temp = searchBST(root, e);
			if (temp != NULL) printf("\n�ܾ� �� : %s", temp->key.mean);
			else printf("\n���� �ܾ�");
			break;
		}
	} while ((sel - '0') != 5);

	getchar();
}
