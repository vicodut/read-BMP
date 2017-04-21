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
#include "pixel.hpp"
#pragma pack(push, 1)

using namespace std;


int pixel::get_Grey(const pixel p){
	int grey = (p.rgb.red + p.rgb.green + p.rgb.blue) / 3;
	return grey;
}
picture::picture(const char* filename){
    FILE* file;
    file = fopen(filename, "rb");

    std::cout << sizeof(fileHeader) << std::endl;

    if(file != NULL) { // file opened
        file_header(h);
        size_t x = fread(&h, sizeof(fileHeader), 1, file); //reading the FILEHEADER

        std::cout << x;
        fread(&this->infoHeader, sizeof(infoHeader), 1, file);

        fclose(file);
    }
}

int main()
{
	return 0;
}

