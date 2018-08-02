#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
* FISRTWORD : 함수이름의 첫글자, 알파벳 순서대로 넣기 위해 비교
*
*
**/

#define FIRSTWORD 0
#define FLSIZE 26
#define HDSIZE 24
#define READSIZE 1000

typedef struct FunctionList FL;
typedef struct HeaderList HL;

FL* flarr[FLSIZE];
HL* hdarr[HDSIZE];


struct FunctionList {

	char flName[1000];
	char flPtype[1000];
	char flHName[1000];
	char flInfo[3000];

	struct FunctionList *alNext;
	struct FunctionList *hdNext;

	struct HeaderList *hdAddr;

};

struct HeaderList {

	char hdName[1000];
	char hdInfo[1000];

	struct FunctionList *flAddr;

};

void link_to_header(FL *funcNode);
void link_at_alphabet(FL *funcNode);
void read_function_data();
void read_header_data();
void print_menu();
void print_search_menu();
void print_header_menu();
void print_function_data(char *findFuncName);
void print_header_data(int headerNum);

void link_to_header(FL *funcNode) {
	FL *temp;
	int i;

	for (i = 0; i < HDSIZE; i++) {
		if (strcmp(funcNode->flHName, hdarr[i]->hdName) == 0) {
			break;
		}
	}
	if (hdarr[i]->flAddr == NULL) {
		hdarr[i]->flAddr = funcNode;
		return;
	}
	temp = hdarr[i]->flAddr;
	while (temp->hdNext != NULL) {
		temp = temp->hdNext;
	}
	temp->hdNext = funcNode;
}

void link_at_alphabet(FL *funcNode) {
	char firApb = funcNode->flName[0];
	int num;
	FL *temp;

	if (firApb<97)
		firApb = 97;
	num = (int)firApb - 97;

	if (flarr[num] == NULL) {
		flarr[num] = funcNode;
		return;
	}

	temp = flarr[num];
	while (temp->alNext != NULL) {
		temp = temp->alNext;
	}

	temp->alNext = funcNode;
}

void read_function_data() {
	char tmp[READSIZE];
	char* spl;
	FILE* data = fopen("Function_data.txt", "r");
	int i = 0;

	while (fgets(tmp, READSIZE, data)) {

		FL* funcNode = (FL*)malloc(sizeof(FL));
		FL* temp;

		spl = strtok(tmp, "\t");
		strcpy(funcNode->flName, spl);

		spl = strtok(NULL, "\t");
		strcpy(funcNode->flHName, spl);

		spl = strtok(NULL, "\t");
		strcpy(funcNode->flPtype, spl);

		spl = strtok(NULL, "\t");
		strcpy(funcNode->flInfo, spl);
		
		funcNode->alNext = NULL;
		funcNode->hdNext = NULL;
		funcNode->hdAddr = NULL;

		link_to_header(funcNode);
		link_at_alphabet(funcNode);
	}
	fclose(data);
}

void read_header_data() {
	char tmp[READSIZE];
	char* spl;
	FILE *data;
	int i = 0;
	data = fopen("Header_data.txt", "r");

	while (fgets(tmp, READSIZE, data)) {

		hdarr[i] = (HL*)malloc(sizeof(HL));

		spl = strtok(tmp, "\t");
		strcpy(hdarr[i]->hdName, spl);

		spl = strtok(NULL, "\t");
		strcpy(hdarr[i]->hdInfo, spl);

		hdarr[i]->flAddr = NULL;
		i++;
	}
	fclose(data);
}

void print_menu() {
	int menuNum;

	puts("*********************");
	puts(" 1. Search ");
	puts(" 2. Print ");
	puts("*********************");

	scanf("%d", &menuNum);

	switch (menuNum)
	{
	case 1:
		print_search_menu();
		break;
	case 2:
		print_header_menu();
		break;
	case 3:
		exit(1);
	}
}

void print_search_menu() {

	char findFuncName[20];

	printf(" 함수명을 입력하세요 : ");
	scanf("%s", findFuncName);

	print_function_data(findFuncName);

}

void print_header_menu() {
	int i, headerNum;
	puts("*****************************");

	for (i = 0; i <HDSIZE; i++)
	{
		printf("%d. %s ", i + 1, hdarr[i]->hdName);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}

	puts("*****************************");

	printf(" 보고 싶은 헤더의 번호를 입력하세요 : ");
	scanf("%d", &headerNum);

	print_header_data(headerNum - 1);
}

void print_function_data(char *findFuncName) {
	int funcIndex;
	FL *temp;

	funcIndex = findFuncName[0] - 97;
	temp = flarr[funcIndex];
	while (strcmp(temp->flName, findFuncName) != 0)
	{
		printf("%s\n", temp->flName);
		if (temp->alNext == NULL)
		{
			puts(" 없는 함수입니다.\n");
			return;
		}
		temp = temp->alNext;
	}

	printf("이름 : %s,  원형 : %s, 헤더 : %s\n 설명: %s\n", temp->flName, temp->flPtype, temp->flHName, temp->flInfo);
}

void print_header_data(int headerNum) {


}
#pragma once
