#include "stdCLib.h"

int main(void)
{

	read_header_data();
	read_function_data();	

	while (TRUE)
		print_menu();

	return 0;
}

