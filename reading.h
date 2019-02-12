#ifndef READING_FILE
#define READING_FILE

struct screenInfo{
  int high;
  int width;
  char** screen;
  char*** screens;
  int numberOfChars;
};

typedef struct screenInfo screenInfo;

screenInfo read();
void end(screenInfo pictureInfo);
screenInfo analyze(screenInfo pictureInfo);

#endif
