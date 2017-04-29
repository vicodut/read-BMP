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

void picture::addBorder(int size, char r, char b, char g)
{
    int i = 0, j = 0;
    for (i = 0; i < infoHeader.img_Width * infoHeader.img_Height; i++)
    {
        if(i < (512 * size) || i > infoHeader.img_Width * infoHeader.img_Height - (512 * size))
        {
            pixelTab[i].blue = b;
            pixelTab[i].red = r;
            pixelTab[i].green = g;
        }
        if (i % 512 == 0 && i <= infoHeader.img_Width * infoHeader.img_Height - (512 * size) && i >= (512 * size))
        {
            for (j = 0; j < size; j++)
            {
                pixelTab[i - j].blue = b;
                pixelTab[i - j].red = r;
                pixelTab[i - j].green = g;
                pixelTab[i + j].blue = b;
                pixelTab[i + j].red = r;
                pixelTab[i + j].green = g;
            }
        }
    }
}

void picture::mozaik(int size)
{
    int i = 0, j = 0, x = 0, y = 0;
    int red;
    int blue;
    int green; 
    for (i = 0; i < infoHeader.img_Height; i += size)
    {
       for(j = 0; j < infoHeader.img_Width; j += size)
        {
          for(y = 0; y < size; y++)
          {
            for(x = 0; x < size; x++)
            {
              int index = (i*infoHeader.img_Height)+(j + x)+(y * infoHeader.img_Width);
              if (index < infoHeader.img_Width * infoHeader.img_Height)
              {
              red += pixelTab[index].red;
              blue += pixelTab[index].blue;
              green += pixelTab[index].green;
              }
            }
          }

//        On recupère la moyenne de la zone de pixel
          red = red / (size * size);
          green = green / (size * size);
          blue = blue / (size * size);

//        On Re-ecrit le tableau avec la moyenne de chaque zone 
          for(y = 0; y < size; y++)
          {
            for(x = 0; x < size; x++)
            {
              int index = (i*infoHeader.img_Width)+(j + x)+(y * infoHeader.img_Width);
              if (index < infoHeader.img_Width * infoHeader.img_Height)
              {
              pixelTab[index].red = red;
              pixelTab[index].blue = blue;
              pixelTab[index].green = green;
              }
            }
          }
//        On re-initialize les valeurs des pixel de zone
          red = 0;
          blue = 0;
          green = 0;
        }
    }
}

int main()
{
    picture Lena("lenaColor.bmp", "lenaOut.bmp");
//    Lena.addBorder(30, 0xff, 90, 90);
    cout << "Mozaik: ";
    int size;
    cin >> size;
    Lena.mozaik(size);
    Lena.write();
    return 0;
}

