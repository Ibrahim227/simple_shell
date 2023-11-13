#include "main.h"

/**
* avoid_segfault - avoid segfault
* @signumber: signal num,ber
* Return: Success
*/
void avoid_segfault(int signumber __attribute__((unused)))
{
	exit(1);
}

