//
// Created by Cathy Quan on 11/6/21.
//

#ifndef PROJECT2_HEADER_H
#define PROJECT2_HEADER_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Header
{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
public:
    Image();
    Header GetHeaderObject();
    void SetWidth(short w);
    void SetHeight(short h);
    void SetHeaderObject(Header head);
    int GetNumPixels();
    vector<Pixel>& GetPixels();
    void PrintPixel(int i);
    bool ReadFile(string fileName);
    bool WriteFile(string fileName);
    bool TestingResults(Image& test);
private:
    Header headerObject;
    int numPixels;
    vector<Pixel> pixels;
};

#endif //PROJECT2_HEADER_H
