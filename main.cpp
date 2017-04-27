#include "pixel.hpp"

using namespace std;


picture::picture(const char* filename, const char* filenameOut){
    int i = 0;
    
//  Ouverture du ficher de lecture
    ifstream file;
    file.open(filename, ios::out | ios::binary);
    
//  Ouverture du fichier de sortie
    ofstream fileOut;
    fileOut.open(filenameOut, ios::in | ios::binary);

    if(file.is_open() && fileOut.is_open()) { // file opened
//      Lecture des Headers
        file.read((char*) (&fileHeader), sizeof(fileHeader));
        file.read((char*) (&infoHeader), sizeof(infoHeader));

//      Initialisation du tableau qui viens recuperer les pixels
        vector<pixel> tab;
//      Variale temporaire pour stocker un pixel
        pixel tmp;
        
//      Ecriture des Headers
        fileOut.write((char*) (&fileHeader), sizeof(fileHeader));
        fileOut.write((char*) (&infoHeader), sizeof(infoHeader));
        
//      Lecture / Stockage / Ecriture des pixels
        for (i = 0; i < infoHeader.img_Width * infoHeader.img_Height; i++)
        {
            file.read((char*) (&tmp), sizeof(pixel));
            tab.push_back(tmp);
            fileOut.write((char *) (&tmp), sizeof(pixel));
        }

//      Fermeture des fichiers
        file.close();
        fileOut.close();
    }
}

int main()
{
    new picture("lenaColor.bmp", "lenaOut.bmp");
    return 0;
}

