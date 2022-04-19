#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void init();
void setupArr(int* row, int* col, int* sortOrder);
char** allocArr(int row, int col);
void sortArr(char** fstr, int row, int col, int sortOrder);
void printArr(char** fstr, int row);

int main(void)
{
    char** str;
    int row, col;
    char redo;
    int sortOrder;
    
    init();
REDO:
    setupArr(&row, &col, &sortOrder);
    str = allocArr(row, col);
    sortArr(str, row,col,sortOrder);
    printArr(str, row);
    

    
    for (int i = 0; i < row; i++)
    {
        free(str[i]);
    }
    free(str);
    
    rewind(stdin);
    printf("● Do you want to do it again? (Y or N) -> ");
    scanf("%c", &redo);
    printf("\n");

    if (redo == 'Y' || redo == 'y')
        goto REDO;


    return 0;
}

void init()
{
    char computerAscii[13][40] =
    {
        { "   ._________________."},
        {"   |.---------------.|"},
        {"   ||               ||"},
        {"   ||   -._ .-.     ||"},
        {"   ||   -._| | |    ||\tDevBaeJelly"},
        {"   ||   -._|"" | ""|    ||"},
        {"   ||   -._|.-.|    ||"},
        {"   ||_______________||"},
        {"   /.-.-.-.-.-.-.-.-.\\"},
        {"  /.-.-.-.-.-.-.-.-.-.\\"},
        {" /.-.-.-.-.-.-.-.-.-.-.\\"},
        {"/______/__________\\___o_\\"},
        {"＼_______________________\\"},
    };
    char welcomePrint[26] = "  WELCOME TO SORTGRAM V1";

    for (int i = 0; i < sizeof(computerAscii)/sizeof(computerAscii[0]); i++)
        printf("%s\n", computerAscii[i]);
    for (int i = 0; i < sizeof(welcomePrint) / sizeof(char); i++)
    {
        printf("%c", welcomePrint[i]);
        Sleep(100);
    }
    printf("\n\n");
    
    
}

void setupArr(int* row, int* col, int* sortOrder)
{
    
    printf("*** ROW -> ");
    scanf("%d",row);
    printf("*** COL -> ");
    scanf("%d", col);
AGAIN:
    printf("*** Enter sorting method\n\t(  1 : Ascending sort\n\t(  0 : Just print\n\t( -1 : Descending sort\n ->  ");
    scanf("%d", sortOrder);
    printf("\n");
    if (*sortOrder > 1 || *sortOrder < -1) { printf("\n※WRONG※\n\n"); goto AGAIN; }
    

}

char** allocArr(int row, int col)
{
    char** fstr;
    fstr = malloc(sizeof(char*) * row);

    for (int i = 0; i < row; i++)
        fstr[i] = malloc(sizeof(char) * col);

    for (int i = 0; i < row; i++)
    {
        printf("WORD[%d] : ", i + 1);
        scanf("%s", fstr[i]);
    }
    printf("\n");
    return fstr;
}

void sortArr(char** fstr, int row, int col, int sortOrder)
{
    char* temp=malloc(sizeof(char)*col);
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < row - 1 - i; j++)
        {
            if (sortOrder < 0)
            {
                if (strcmp(fstr[j], fstr[j + 1]) < 0)
                {
                    strcpy(temp, fstr[j]);
                    strcpy(fstr[j], fstr[j + 1]);
                    strcpy(fstr[j + 1], temp);
                }
            }
            if (sortOrder > 0)
            {
                if (strcmp(fstr[j], fstr[j + 1]) > 0)
                {
                    strcpy(temp, fstr[j]);
                    strcpy(fstr[j], fstr[j + 1]);
                    strcpy(fstr[j + 1], temp);
                }
            }  
        }
    }
}

void printArr(char** fstr, int row)
{
    for (int i = 0; i < row; i++)
    {
        if(i==row-1)
            printf("[  %s  ]\n", fstr[i]);
        else
            printf("[  %s  ] -> ", fstr[i]);
        
    }
    printf("\n");
}
