#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FunctionList FL;
typedef struct HeaderList HL;

struct FunctionList{
	
	char *flName; 
	char *flPtype;
	char *flHName;
	char *flInfo;

	struct FL *alNext;
	struct FL *hdNext;

	struct HL *hdAddr;

};

struct HeaderList{

	char *hdName;
	char *hdInfo;
	
	struct FL *flAddr;

};

void read_file(FL*);
