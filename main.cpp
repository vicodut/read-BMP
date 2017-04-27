#include "pixel.hpp"

using namespace std;


picture::picture(const char* filename, const char* filenameOut){
    int i = 0;
    fileIn = filename;
    fileOut = filenameOut;
//  Ouverture du ficher de lecture
    ifstream file;
    file.open(fileIn, ios::in | ios::binary);

    if(file.is_open()) { // file opened
//      Lecture des Headers
        file.read((char*) (&fileHeader), sizeof(fileHeader));
        file.read((char*) (&infoHeader), sizeof(infoHeader));
  
//      Variale temporaire pour stocker un pixel
        pixel tmp;
        
//      Lecture / Stockage / Ecriture des pixels
        for (i = 0; i < infoHeader.img_Width * infoHeader.img_Height; i++)
        {
            file.read((char*) (&tmp), sizeof(pixel));
            pixelTab.push_back(tmp);
        }

//      Fermeture des fichiers
        file.close();
    }
}

void picture::write(void)
{
    int i = 0;
//  Ouverture du fichier de sortie
    ofstream file;
    file.open(fileOut, ios::out | ios::binary);
    
    if(file.is_open()) 
    {
//      Ecriture des Headers
        file.write((char*) (&fileHeader), sizeof(fileHeader));
        file.write((char*) (&infoHeader), sizeof(infoHeader));
        
        for (i = 0; i < infoHeader.img_Width * infoHeader.img_Height; i++)
        {
            file.write((char *) (&pixelTab[i]), sizeof(pixel));
        }
    }
    std::cout << file.is_open() << std::endl;
    file.close();
}

int main()
{
    picture Lena("lenaColor.bmp", "lenaOut.bmp");
    Lena.write();
    return 0;
}

