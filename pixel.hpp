#include <iostream>
#include <vector>
#include <fstream>

#pragma pack( 1)
using namespace std;

class picture //A Picture is a collection of pixels.
{
public:
  const char *fileIn;
  const char *fileOut;
	struct // Its RGB values default pixels wil be black
	{
    unsigned char magicNumber[2]; //define the format type.
    unsigned int  size; //Size of the image
    int           reserved;
    unsigned int  offset; //Starting point of the pixel matrix
	}fileHeader ;
  struct
  {
    int   info_ize;
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
	struct pixel// Its RGB values default pixels wil be black
	{
		char blue = 0;
		char green = 0;
		char red = 0;
	};
	//      Initialisation du tableau qui viens recuperer les pixels
  vector<pixel> pixelTab;
	picture(const char* filename, const char* filenameOut);
  void addBorder(int size = 0, char r = 0, char b = 0, char g = 0);
  void mozaik(int size);
	void write(void);
};


