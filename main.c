#include "reading.h"
#include "drawing.h"
#include <stdlib.h>
#include "stdio.h"

int main()
{

  screenInfo pictureInfo;
  pictureInfo=read();
  draw(pictureInfo);
  pictureInfo=analyze(pictureInfo);
  fullDrawing(pictureInfo);
  saving(pictureInfo);
  end(pictureInfo);

return 0;
}
