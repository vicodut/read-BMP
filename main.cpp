#include "pixel.hpp"

using namespace std;


picture::picture(const char* filename){
    FILE* file;
    file = fopen(filename, "rb");

    std::cout << sizeof(fileHeader) << std::endl;

    if(file != NULL) { // file opened
        fread(&fileHeader, sizeof(fileHeader), 1, file); //reading the FILEHEADER
        fread(&infoHeader, sizeof(infoHeader), 1, file); //reading the FILEHEADER

        std::cout << infoHeader.img_Width << std::endl;
        fclose(file);
    }
}

int main()
{
  new picture("lenaColor.bmp");
	return 0;
}

