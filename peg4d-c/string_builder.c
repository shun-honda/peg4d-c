//
//  string_builder.c
//  peg4d-c
//

#include <stdio.h>
#include <stdlib.h>
#include "string_builder.h"

void SB_create(StringBuilder *sb)
{
	sb->len = 0;
	sb->extent = 16;
	sb->str = (char *)malloc(sb->extent);
	sb->str[0] = '\0';
}

void SB_delete(StringBuilder *sb)
{
	free(sb->str);
}

void SB_append(StringBuilder *sb, const char *str)
{
	int newLen;
	int newExtent;
    
	newLen = sb->len + strlen(str);
	newExtent = sb->extent;
	while (newExtent <= newLen) {
		newExtent <<= 1;
	}
	if (sb->extent < newExtent) {
		sb->extent = newExtent;
		sb->str = (char *)realloc(sb->str, sb->extent);
		//fprintf(stderr, "newExtent=[%d]\n", newExtent);
	}
	strcpy(sb->str + sb->len, str);
	sb->len = newLen;
}