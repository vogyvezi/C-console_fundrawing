#include "drawing.h"
#include <stdlib.h>
#include <stdio.h>



void draw(screenInfo pictureInfo)
{
  for(register int i=0; i<pictureInfo.high;i++)
  {
    for(register int j=0; j<pictureInfo.width;j++)
    {
      printf("%c",pictureInfo.screen[i][j] );
    }
    printf("\n");
  }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void fullDrawing(screenInfo pictureInfo)
{
  printf("\n");
  for (int h = 0; h < pictureInfo.numberOfChars; h++) {
    for (int r = 0; r < pictureInfo.high; r++) {
      for (int c = 0; c < pictureInfo.width; c++) {
        printf("%c",pictureInfo.screens[h][r][c]);
      }
    printf("\n");
    }
  printf("\n\n");
  }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void saving(screenInfo pictureInfo)
{
  printf("\n\n");
  for(register int j=0; j<pictureInfo.width;j++)
  {
    printf("_");
  }
  printf("\n");
  printf("Which number do you want to save? <1-...>: ");
  int number;
  while (scanf("%d",&number )==EOF || number<1 ) {
    printf("\nGive proper number-- ");
  }

  char nameOfFile[50];
  getchar();
  printf("Name of file to saving:---");
  gets(nameOfFile);
  FILE* outFile=fopen(nameOfFile,"a");
  while(outFile==NULL)
  {
    printf("\nError,repeat name of file:\n--");
    gets(nameOfFile);
    outFile=fopen(nameOfFile,"a");
  }

  for (int r = 0; r < pictureInfo.high; r++)
  {
    for (int c = 0; c < pictureInfo.width; c++)
    {
      fprintf(outFile,"%c", pictureInfo.screens[number-1][r][c]);
    }
  fprintf(outFile,"\n");
  }

  fclose(outFile);
}
