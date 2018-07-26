#include "clibsearch.h"

int main(void)
{
	FL* flarr[26];
	HL* hdarr[24];
	FL* funcNode = (FL*)malloc(sizeof(FL));

	char tmp[1000];
	char *spl;
	FILE *csv;
	int count;
	csv=fopen("C_data_txt.txt", "r, ccs=UTF-8");
	while(fgets(tmp, 1000, csv))
	{
		count = 1;
		spl = strtok(tmp, "\t");
		printf("%d\n", strlen(spl));
		funcNode->flName = (char*)malloc(sizeof(strlen(spl)));
		strcpy(funcNode->flName, spl); 
		printf("st : %s\n", funcNode->flName);

		while (spl)
		{
			spl = strtok(NULL, "\t");
			count++;
			if (count == 2)
			{
				funcNode->flHName = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flHName, spl); 
				printf("st : %s\n", funcNode->flHName);
			}
			if (count == 3)
			{
				funcNode->flPtype = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flPtype, spl); 
				printf("st : %s\n", funcNode->flPtype);
			}
			if (count == 4)
			{
				funcNode->flInfo = (char*)malloc(sizeof(strlen(spl)));
				strcpy(funcNode->flInfo, spl); 
				printf("st : %s\n", funcNode->flInfo);
			}
		}
			
	}
	fclose(csv);
	return 0;
}

