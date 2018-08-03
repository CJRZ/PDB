#include "stdCLib.h"

void print_menu() {
	
	char selMenu;

	system("clear");
	system("clear");
	puts("************************************************");
	printf("\n \t1. 헤더 검색  \t 2. 함수 검색\n");
	printf("\n \t!. 종료 \n\n");
	puts("************************************************");

	while (TRUE)
	{
		printf(" 해당 메뉴를 입력하세요 : ");
		scanf("%c", &selMenu);

		if (selMenu >= '1' && selMenu <= '4')
			break;
		else if (selMenu == '!')
			break;
		else
			puts(" 잘못된 입력입니다. \n");
		while (getchar() != '\n');
	}

	switch (selMenu)
	{
		case '1':
			header_search_menu();
			break;
		case '2':
			function_search_menu();
			break;
		case '!':
			quit_program();
		default :
			break;
	}
}

void function_search_menu() {

	char findFuncName[INPUTBUFFERSIZE];
	int i;

	system("clear");
	system("clear");
	while (TRUE)
	{

		printf("\n ! : 종료 , / : 이전화면 \n");
		printf("\n 검색할 함수의 이름을 입력하세요 : ");
		scanf("%s", findFuncName);
		
		for (i = 0; i < strlen(findFuncName); i++)
		{
			if (findFuncName[i] >= 'A' && findFuncName[i] <= 'Z')
				findFuncName[i] += 32;
		}

		if (findFuncName[0] >= '0' && findFuncName[0] <= '9')
		{
			printf(" 숫자로 시작할 수 없습니다.");
			continue;
		}
	
		if (strcmp(findFuncName, "/") == SAMESTR)
		{
			while (getchar() != '\n');
			return;
		}
		else if (strcmp(findFuncName, "!") == SAMESTR)
			quit_program();
		else
			find_function_data(findFuncName);
	}
}

void header_search_menu() {
	int i;
	char headerNum[3];
	char tmp[3];
	char cmpList[26][3];
	for (i = 0; i<26; i++)
	{
		if (i == 0) 
			strcpy(cmpList[i], "/");
		else if (i > 0 && i < 25)
		{
			sprintf(tmp, "%d", i);
			printf("%s\n", tmp);
			strcpy(cmpList[i], tmp);
		}
		else if (i == 25)
			strcpy(cmpList[i], "!");
	}

	system("clear");
	system("clear");
	while (TRUE)
	{
		while ( getchar() != '\n');
		puts("***********************************************************\n");
	
		for (i = 0; i <HDSIZE; i++)
		{
			printf("[%2d]%10s\t",i+1,  hdarr[i]->hdName);
			if ((i + 1) % 4 == 0)
				printf("\n");
		}

		puts("\n***********************************************************");

		printf("\n ! : 종료 , / : 이전화면 \n");
		printf("\n 검색할 헤더의 번호를 입력하세요 : ");
		scanf("%s", headerNum);
		
		for(i = 0;i < 26; i++){
			if(strcmp(cmpList[i], headerNum) == SAMESTR)
				break;
		}
		if (i == 0)
		{
			while (getchar() != '\n');
			return;
		}
		else if (i == 25)
			quit_program();
		else if (i >= 26)
		{
			printf(" \n [1 ~ 24] 의 숫자를 입력해주세요. \n");
			continue;
		}
		else
			print_header_data(i - 1);
	}
}

void find_function_data(char *findFuncName) {
	int funcIndex;
	FL *temp;
	int i, index;
	char *histName[HISTSIZE];

	if (findFuncName[FIRSTWORD] == '_')
		funcIndex = 0;
	else if (findFuncName[FIRSTWORD] >= 'a' && findFuncName[FIRSTWORD] <= 'z')
		funcIndex = findFuncName[FIRSTWORD] - ASCIIANUM;
	else
	{
		printf(" \n\n 찾는 함수가 없습니다.\n");
		return;
	}
	temp = flarr[funcIndex];
	index = 0;

	if (temp == NULL)
	{
		printf(" \n\n찾는 함수가 없습니다. \n");
		return;
	}

	while (strcmp(temp->flName, findFuncName) != SAMESTR)
	{
		histName[index] = (char*)malloc(strlen(temp->flName));
		strcpy(histName[index], temp->flName);
		if (temp->alNext == NULL)
		{
			puts("\n\n 찾는 함수가 없습니다.\n");
			puts("************************************************\n");
			puts("\n 해당 알파벳으로 시작하는 명령어\n");
			for (i = 0; i <= index; i++)
			{
				if (strlen(histName[i]) < 7)
					printf(" %s\t\t\t", histName[i]);
				else if (strlen(histName[i]) < 14)
					printf(" %s\t\t", histName[i]);
				else
					printf(" %s\t", histName[i]);
				free(histName[i]);
				if ((i + 1) % 2 == 0)
					printf("\n");
			}
			printf("\n\n");
			puts("************************************************\n");
			return;
		}
		index++;
		temp = temp->alNext;
	}
	print_function_data(temp);
}

void print_function_data(FL *temp)
{
	int i, enterNum = 1;
	puts("************************************************");
	printf("\n 이름 : \t%s\n", temp->flName);
	printf(" 헤더 : \t%s\n", temp->flHName);
	printf(" 원형 : \t%s\n", temp->flPtype);
	printf(" 설명 : \t");
	for (i = 0; i < strlen(temp->flInfo); i++)
	{
		printf("%c", temp->flInfo[i]);
		if (temp->flInfo[i] == ' ' && (i / 80 == enterNum))
		{
			printf("\n\t\t");
			enterNum++;
		}
	}
	puts("\n************************************************");
	printf("\n\n");
}


void print_header_data(int index)
{
	int i, enterNum = 1;
	char findFuncName[INPUTBUFFERSIZE];
	FL *temp;
	system("clear");
	system("clear");
	while(TRUE)
	{
		
		puts("************************************************\n");
		printf(" 헤더 : \t%s\n", hdarr[index]->hdName);
		printf(" 설명 : \t");
		for (i = 0; i < strlen(hdarr[index]->hdInfo); i++)
		{
			printf("%c", hdarr[index]->hdInfo[i]);
			if (hdarr[index]->hdInfo[i] == ' ' && (i / 80 == enterNum))
			{
				printf("\n\t\t");
				enterNum++;
			}
		}

		printf(" 헤더파일에 포함된 함수 목록 \t\n ");
		temp = hdarr[index]->flAddr;
		while (temp != NULL)
		{
			printf("%s /  ", temp->flName);
			temp = temp->hdNext;
		}
		printf("\n\n");
		puts("************************************************");
		while(TRUE)
		{
			printf("\n ! : 종료, / : 이전화면\n");
			printf(" 검색할 함수의 이름을 입력하세요 : ");
			scanf("%s", findFuncName);
	
			if (strcmp("!", findFuncName) == SAMESTR)
				quit_program();
			else if (strcmp("/", findFuncName) == SAMESTR)
			{
				system("clear");
				system("clear");
				return;
			}
			else 
				find_function_data(findFuncName);
		}
	}
}

void quit_program()
{
	int i;
	system("clear");
	system("clear");
	printf("\n\n bye bye ! \n\n");
	for (i = 0; i < HDSIZE; i++)
		free(hdarr[i]);
	for (i = 0; i < FLSIZE; i++)
		free(flarr[i]);
	exit(1);
}

