#include <stdio.h>

typedef struct function{ 
	char fname[20];
	char fheader[20];
	char fprototype[100];
	char fdes[10000];
	struct function *next;
	struct function *prev;
}function;

typedef struct header{
	char hname[20];
	struct function *list;
	struct header *next;
	struct header *prev;
}header;


