
/*
________________________________________________________________________________________________________________________________________
||____________________________________________________________________________________________________________________________________||
||                                                                                                                                    ||
||																																	  ||
||							Budapesti Műszaki és Gazdaságtudományi Egyetem, 2016-2017, Spring Semester                                ||
||										                                                                                              ||
||										BASICS OF PROGRAMMING 2 : FINAL PROJECT														  ||
||																																	  ||
||																																	  ||
||										BITMAP IMAGE TREATMENT USING C++         													  ||
||																																      ||
||																																	  ||
||																										LAPORTE NATHAN CLAUDE         ||
||																										Nept CODE : IBIS2E	          ||
||																										Ver. 1.02A April 2017         ||
||                                                                                                                                    ||
||																																	  ||
||																																	  ||
||____________________________________________________________________________________________________________________________________||
________________________________________________________________________________________________________________________________________
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#pragma pack(push, 1)

class pixel // each pixel is an object defined by :
{
private:
	struct // Its RGB values default pixels wil be black
	{
		int red = 0;
		int green = 0;
		int blue = 0;
	}rgb;
public:
	pixel(); //Constructor
	~pixel(); //Destructor
	int get_Grey(const pixel p); //Calculating the grey value for Color -> Grey scale transform

};

class file_header
{
private:
	struct{
	unsigned char magicNumber[2]; //define the format type.
	unsigned int size; //Size of the image
	unsigned short int id_one; //First id
	unsigned short int id_two; //second id
	unsigned int offset; //Starting point of the pixel matrix
};
public:
	file_header();
	~file_header();
};

class info_header
{
private:
	struct{
	unsigned int   info_Size;
    int            img_Width;
    int            img_Height;
    unsigned short biPlanes;//Number of color planes
    unsigned short bpp;
    unsigned int   compression;
    unsigned int   img_Size;
    int            xppm;//X pixels per meter
    int            yppm;//Y pixels per meter
    unsigned int   color_Depth;
    unsigned int   biClrImportant;//Number of important colors
	};
public:
	info_header();
	~info_header();
};


class picture //A Picture is a collection of pixels.
{
private:
	file_header fileHeader;
	info_header infoHeader;
	pixel matrix[0][0];
public:
	picture(const char* filename);
	~picture();
};


