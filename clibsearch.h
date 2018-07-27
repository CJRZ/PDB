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
#define READSIZE 700

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
	struct HL *hdNext;

};

void read_file(FL*);
