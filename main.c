#include "clibsearch.h"

int main(void)
{
	FL* flarr[FLSIZE];
	HL* hdarr[HDSIZE];
	FL* funcNode = (FL*)malloc(sizeof(FL));
	HL* headNode = (HL*)malloc(sizeof(HL));

	char tmp[READSIZE];
	char *spl;
	FILE *fdata, *hdata;
	int count;
	fdata=fopen("C_data_txt.txt", "r");
	hdata=fopen("Header_data.txt", "r");
	while(fgets(tmp, READSIZE, hdata))
	{
		spl = strtok(tmp, "\t");
		headNode->hdName = (char*)malloc(sizeof(strlen(spl)));
		strcpy(headNode->hdName, spl); 
		printf("st : %s\n", headNode->hdName);

		spl = strtok(NULL, "\t");
		headNode->hdInfo = (char*)malloc(sizeof(strlen(spl)));
		strcpy(headNode->hdInfo, spl); 
		printf("st : %s\n", headNode->hdInfo);
			
	}
	while(fgets(tmp, READSIZE, fdata))
	{
		count = 1;
		spl = strtok(tmp, "\t");
		funcNode->flName = (char*)malloc(sizeof(strlen(spl)));
		strcpy(funcNode->flName, spl); 
		//printf("st : %s\n", funcNode->flName);

		while (spl)
		{
			spl = strtok(NULL, "\t");
			count++;
			if (count == 2)
			{
				funcNode->flHName = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flHName, spl); 
				//printf("st : %s\n", funcNode->flHName);
			}
			if (count == 3)
			{
				funcNode->flPtype = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flPtype, spl); 
				//printf("st : %s\n", funcNode->flPtype);
			}
			if (count == 4)
			{
				funcNode->flInfo = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flInfo, spl); 
				//printf("st : %s\n", funcNode->flInfo);
			}
		}
			
	}
	fclose(hdata);
	fclose(fdata);
	return 0;
}

