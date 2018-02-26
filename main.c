#include <stdio.h>
#include "string.h"

void load()
{
    FILE *fptr;
    FILE *fptr2;
    FILE *fptr3;
    
    fptr2 = fopen("stopwords.txt", "r");//read wordlist
    if (fptr2 == NULL)
    {
        printf("\nFile read failed!\n");
        return 0;
    }
    
    fptr = fopen("assignment.txt", "r");//read input
    if (fptr == NULL)
    {
        printf("\nFile read failed!\n");
        return 0;
    }
    
    fptr3 = fopen("output.txt", "wb");//write output
    if (fptr3 == NULL)
    {
        printf("\nFile write failed!\n");
        return 0;
    }
    
    char word[35][10];
    char word2[174][10];
    char word3 = word;
    
    for (int i=0; i<35; i++)
    {
    fscanf(fptr, "%s", &word[i]);
    }
    
    for (int j=0; j<174; j++)
    {
        fscanf(fptr2, "%s\n", word2[j]);
    };
    
    for (int k=0; k<35; k++)
    {
        for (int g=0; g<174; g++)
        {
            int ret = strcmp(word[k], word2[g]);
            if (ret == 0)
            {
                strcpy(word[k], "");
            }
        }
    }
    
    for (int l=0; l<35; l++)
    {
        fprintf(fptr3, "%s", word[l]);
        int run = strcmp(word[l], "");
        if (run != 0)
        {
            fprintf(fptr3, " ");
        }
    }
}
int main()
{
	load();
    return 0;
}
