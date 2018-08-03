#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
*
*
**/

#define TRUE 1
#define FIRSTWORD 0
#define SAMESTR 0
#define HDSIZE 24
#define FLSIZE 26
#define NAMESIZE 30
#define INPUTBUFFERSIZE 50
#define ASCIIANUM 97
#define READSIZE 1000
#define HISTSIZE 100

typedef struct FunctionList FL;
typedef struct HeaderList HL;

FL* flarr[FLSIZE];
HL* hdarr[HDSIZE];


struct FunctionList {

	char *flName;
	char *flPtype;
	char *flHName;
	char *flInfo;

	struct FunctionList *alNext;
	struct FunctionList *hdNext;

	struct HeaderList *hdAddr;

};

struct HeaderList {

	char *hdName;
	char *hdInfo;

	struct FunctionList *flAddr;

};

void link_to_header(FL *funcNode);
void link_at_alphabet(FL *funcNode);
void read_function_data();
void read_header_data();
void print_menu();
void function_search_menu();
void header_search_menu();
void find_function_data(char *findFuncName);
void print_function_data(FL *temp);
void print_header_data(int index);
void quit_program();
