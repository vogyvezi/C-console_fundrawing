#include "reading.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



screenInfo read()
{
  char nameOfFile[50];
  screenInfo infoReturn={1,0,0,0,0};    //high width
  FILE* inFile;
  int width=0;  //counter
///////////////////////////////////////////////////////////////////////////////
  printf("Name of file to drawing:\n---");
  gets(nameOfFile);
  inFile=fopen(nameOfFile,"r");
  while(inFile==NULL)
  {
    printf("\nError,repeat name of file:\n--");
    gets(nameOfFile);
    inFile=fopen(nameOfFile,"r");
  }
///////////////////////////////////////////////////////////////////////////////
  char ch = getc(inFile);
  while ( (ch != EOF)) {
    width++;
    if(ch == '\n')
    {
        infoReturn.high++;
        width--;        //nie chcemy liczyć \n
        if(infoReturn.width < width)
        {
          infoReturn.width= width;
        }
        width=0;
    }
        ch = getc(inFile);
    }
///////////////////////////////////////////////////////////////////////////////
infoReturn.screen=(char**)malloc(infoReturn.high*sizeof(char*));
for(register int i=0; i<infoReturn.high; i++) // i<infoReturn.high-1
{
  infoReturn.screen[i]=(char*)malloc(infoReturn.width*sizeof(char));
}

for(register int i=0; i<infoReturn.high;i++)
{
  for(register int j=0; j<infoReturn.width;j++)
  {
    *(*(infoReturn.screen+i)+j)=' ';
  }
}
//////////////////////////////////////////////////////////////////////////////
fseek(inFile,0,0);
ch = getc(inFile);
int w=0,h=0;

while ( (ch != EOF)) {
    if(ch == '\n')
    {
        h++;
        w=0;
        ch = getc(inFile);
    }
    else
    {
      *(*(infoReturn.screen+h)+w)=ch;
      w++;
      ch = getc(inFile);
    }
}
/////////////////////////////////////////////////////////////////////////////
  fclose(inFile);
  return infoReturn;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void end(screenInfo pictureInfo)
{
  for(register int i=0; i<pictureInfo.high; i++)  //for(register int i=0; i<pictureInfo.high-1; i++)
  {
    free((pictureInfo.screen+i));
  }
  free(pictureInfo.screen);



  for(int h=0; h<pictureInfo.numberOfChars; h++)
  {
    for(int r=0; r<pictureInfo.high; r++)
    {
      free(pictureInfo.screens[h][r]);
    }
  }

  for(int h=0; h<pictureInfo.numberOfChars; h++)
  {
    free(pictureInfo.screens[h]);
  }
  free(pictureInfo.screens);

  printf("OK!\n");
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

screenInfo analyze(screenInfo pictureInfo)
{
  char  ch;
  char table[85];
  int counter=0;

  for(int i=0; i<pictureInfo.high;i++)
  {
    for(int j=0; j<pictureInfo.width;j++)
    {
      ch=pictureInfo.screen[i][j];
      for(int k=0; k<=pictureInfo.numberOfChars; k++)
      {
        if(ch != table[k] && ch != ' ')
          {
            counter++;
          }
      }
      if(counter>pictureInfo.numberOfChars)
      {
        table[pictureInfo.numberOfChars]=ch;
        pictureInfo.numberOfChars++;
      }
      counter=0;
    }
  }
///////////////////////////////////////////////////////////////////////////////
  pictureInfo.screens=(char***)malloc(pictureInfo.numberOfChars*sizeof(char**));

  for(int h=0; h<pictureInfo.numberOfChars; h++)
  {
    pictureInfo.screens[h]=(char**)malloc(sizeof(char*)*pictureInfo.high);
    for(int r=0; r<pictureInfo.high; r++){
      pictureInfo.screens[h][r]=(char*)malloc(sizeof(char)*pictureInfo.width);
    }
  }
///////////////////////////////////////////////////////////////////////////////
  for (int h = 0; h < pictureInfo.numberOfChars; h++) {
    for (int r = 0; r < pictureInfo.high; r++) {
      for (int c = 0; c < pictureInfo.width; c++) {
        pictureInfo.screens[h][r][c]=' ';
      }}}
///////////////////////////////////////////////////////////////////////////////

    for (int h = 0; h < pictureInfo.numberOfChars; h++)
    {
      for (int r = 0; r < pictureInfo.high; r++)
      {
        for (int c = 0; c < pictureInfo.width; c++)
        {
            if(pictureInfo.screen[r][c]==table[h])
            {
              pictureInfo.screens[h][r][c]=pictureInfo.screen[r][c];
            }
          }}}
///////////////////////////////////////////////////////////////////////////////

  return pictureInfo;
}
