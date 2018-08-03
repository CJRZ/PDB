#include "stdCLib.h"

void link_to_header(FL *funcNode) {
	FL *temp;
	int i;

	for (i = 0; i < HDSIZE; i++) {
		if (strcmp(funcNode->flHName, hdarr[i]->hdName) == SAMESTR) {
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
	char firApb = funcNode->flName[FIRSTWORD];
	int num;
	FL *temp;

	if (firApb < ASCIIANUM)
		firApb = ASCIIANUM;
	num = (int)firApb - ASCIIANUM;

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
	FILE* data = fopen("./Function_data.txt", "r");
	int i = 0;

	while (fgets(tmp, READSIZE, data)) {

		FL* funcNode = (FL*)malloc(sizeof(FL));
		FL* temp;

		spl = strtok(tmp, "\t");
		funcNode->flName = (char*)malloc(strlen(spl) + 1);
		strcpy(funcNode->flName, spl);

		spl = strtok(NULL, "\t");
		funcNode->flHName = (char*)malloc(strlen(spl) + 1);
		strcpy(funcNode->flHName, spl);

		spl = strtok(NULL, "\t");
		funcNode->flPtype = (char*)malloc(strlen(spl) + 1);
		strcpy(funcNode->flPtype, spl);

		spl = strtok(NULL, "\t");
		funcNode->flInfo = (char*)malloc(strlen(spl) + 1);
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
	data = fopen("./Header_data.txt", "r");

	while (fgets(tmp, READSIZE, data)) {

		hdarr[i] = (HL*)malloc(sizeof(HL));

		spl = strtok(tmp, "\t");
		hdarr[i]->hdName = (char*)malloc(strlen(spl) + 1);
		strcpy(hdarr[i]->hdName, spl);

		spl = strtok(NULL, "\t");
		hdarr[i]->hdInfo = (char*)malloc(strlen(spl) + 1);
		strcpy(hdarr[i]->hdInfo, spl);

		hdarr[i]->flAddr = NULL;
		i++;
	}
	fclose(data);
}

