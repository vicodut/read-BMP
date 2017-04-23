#include <iostream>
#pragma pack( 1)
using namespace std;

class picture //A Picture is a collection of pixels.
{
public:
	struct // Its RGB values default pixels wil be black
	{
    unsigned char magicNumber[2]; //define the format type.
    unsigned int  size; //Size of the image
    int           reserved;
    unsigned int  offset; //Starting point of the pixel matrix
	}fileHeader ;
  struct
  {
    int   info_Size;
    int   img_Width;
    int   img_Height;
    short biPlanes;//Number of color planes
    short bpp;
    int   compression;
    int   img_Size;
    int   xppm;//X pixels per meter
    int   yppm;//Y pixels per meter
    int   color_Depth;
    int   biClrImportant;//Number of important colors
  } infoHeader;
	struct // Its RGB values default pixels wil be black
	{
		int red = 0;
		int green = 0;
		int blue = 0;
	}rgb;
	picture(const char* filename);
	~picture();
};


