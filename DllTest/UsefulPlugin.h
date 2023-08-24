#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "MinHook.h"

#include "bo64_header.h"

typedef char* multi_tok_t;
multi_tok_t init() { return NULL; }

/*
int DumpMemory256(char * P);
int DumpMemory16(char * P);
char *multi_tok(char *input, multi_tok_t *string, const char *delimiter);
char *StrToHex(char *inText, char *array);
void ReplaceEnding(char *inText);
*/


int DumpMemory16(char* P) {
    const char* Tmpstr;
    DEBUG_PRINT("[+] DumpMemory: %p : %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x \n", P, (char)*P, (char)*(P + 1), (char)*(P + 2), (char)*(P + 3), (char)*(P + 4), (char)*(P + 5), (char)*(P + 6), (char)*(P + 7), (char)*(P + 8), (char)*(P + 9), (char)*(P + 10), (char)*(P + 11), (char)*(P + 12), (char)*(P + 13), (char)*(P + 14), (char)*(P + 15));
    return 1;
}

int DumpMemory256(char* P) {

    DumpMemory16((char*)(P)-16);
    DumpMemory16((char*)P);
    DumpMemory16((char*)(P)+16);
    DumpMemory16((char*)(P)+32);
    DumpMemory16((char*)(P)+48);
    DumpMemory16((char*)(P)+64);
    DumpMemory16((char*)(P)+80);
    DumpMemory16((char*)(P)+96);
    DumpMemory16((char*)(P)+112);
    DumpMemory16((char*)(P)+128);
    DumpMemory16((char*)(P)+144);
    DumpMemory16((char*)(P)+160);
    DumpMemory16((char*)(P)+176);
    DumpMemory16((char*)(P)+192);
    DumpMemory16((char*)(P)+208);
    DumpMemory16((char*)(P)+224);
    DumpMemory16((char*)(P)+240);
    DumpMemory16((char*)(P)+256);
    return 1;
}



char* multi_tok(char* input, multi_tok_t* string, const char* delimiter) {
    if (input != NULL)
        *string = input;

    if (*string == NULL)
        return *string;

    char* end = strstr(*string, delimiter);
    if (end == NULL) {
        char* temp = *string;
        *string = NULL;
        return temp;
    }

    char* temp = *string;

    *end = '\0';
    *string = end + strlen(delimiter);
    return temp;
}

char* StrToHex(char* inText, char* array)
{
    int i, j;
    for (i = 0, j = 0; i < strlen(inText); i++, j += 2)
    {
        sprintf((char*)array + j, "%02X", inText[i]);
    }
    array[j] = '\0'; /*adding NULL in the end*/
    return array;
}

void ReplaceEnding(char* inText)
{
    int i, j;
    char Tmpchar;
    for (i = 0; i < strlen(inText); i += 3)
    {
        if ((int)inText[i] == 10)
        {
            //inText[i]='\0';
            inText[i] = 32;
        }
    }
}

void CreateJson(const char* Title, char* TmpContent, char* TmpLargebuf, int bufSize)
{
    memset(TmpLargebuf, '\0', bufSize);


    // strcat(TmpLargebuf,"{");

   //  if (strlen(TmpContent) > 0){
        // strcat(TmpLargebuf,"\"");//SplitLine
        // strcat(TmpLargebuf,Title);//SplitLine
       //  strcat(TmpLargebuf,"\":[");//SplitLine
    strcat(TmpLargebuf, "[");//SplitLine
    strcat(TmpLargebuf, TmpContent);//SplitLine
    strcat(TmpLargebuf, "]");//SplitLine
//}


// strcat(TmpLargebuf,"}");

}