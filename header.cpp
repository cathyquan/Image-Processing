//
// Created by Cathy Quan on 11/6/21.
//

#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

//Image::Header::Header() {
//    idLength = 0;
//    colorMapType = 0;
//    dataTypeCode = 0;
//    colorMapOrigin = 0;
//    colorMapLength = 0;
//    colorMapDepth = 0;
//    xOrigin = 0;
//    yOrigin = 0;
//    width = 0;
//    height = 0;
//    bitsPerPixel = 0;
//    imageDescriptor = 0;
//}

//Image::Pixel::Pixel() {
//    red = 0;
//    blue = 0;
//    green = 0;
//}

Image::Image() {
    headerObject.idLength = 0;
    headerObject.colorMapType = 0;
    headerObject.dataTypeCode = 0;
    headerObject.colorMapOrigin = 0;
    headerObject.colorMapLength = 0;
    headerObject.colorMapDepth = 0;
    headerObject.xOrigin = 0;
    headerObject.yOrigin = 0;
    headerObject.width = 0;
    headerObject.height = 0;
    headerObject.bitsPerPixel = 0;
    headerObject.imageDescriptor = 0;
    numPixels = 0;
}

int Image::GetNumPixels() {
    int totalPixels = headerObject.width * headerObject.height;
    return totalPixels;
}

Header Image::GetHeaderObject() {
    return headerObject;
}

void Image::SetHeaderObject(Header head) {
    headerObject.idLength = head.idLength;
    headerObject.colorMapType = head.colorMapType;
    headerObject.dataTypeCode = head.dataTypeCode;
    headerObject.colorMapOrigin = head.colorMapOrigin;
    headerObject.colorMapLength = head.colorMapLength;
    headerObject.colorMapDepth = head.colorMapDepth;
    headerObject.xOrigin = head.xOrigin;
    headerObject.yOrigin = head.yOrigin;
    headerObject.width = head.width;
    headerObject.height = head.height;
    headerObject.bitsPerPixel = head.bitsPerPixel;
    headerObject.imageDescriptor = head.imageDescriptor;
}

void Image::SetWidth(short w) {
    headerObject.width = w;
}

void Image::SetHeight(short h) {
    headerObject.height = h;
}

vector<Pixel>& Image::GetPixels() {
    return pixels;
}

void Image::PrintPixel(int i) {
    if(!pixels.size())
    {
        cout << "there is no pixel in the picture!" << endl;
        return;
    }
    cout << "red: " << (int) pixels[i].red << ", green: " << (int) pixels[i].green << ", blue: " << (int) pixels[i].blue << endl;
}

bool Image::ReadFile(string fileName) {
    ifstream file(fileName, ios_base::binary);
    if(!file.is_open())
    {
        cout << "error opening file!" << endl;
        return false;
    }
    file.read((char*)&headerObject.idLength, 1);
    file.read((char*)&headerObject.colorMapType, 1);
    file.read((char*)&headerObject.dataTypeCode, 1);
    file.read((char*)&headerObject.colorMapOrigin, 2);
    file.read((char*)&headerObject.colorMapLength, 2);
    file.read((char*)&headerObject.colorMapDepth, 1);
    file.read((char*)&headerObject.xOrigin, 2);
    file.read((char*)&headerObject.yOrigin, 2);
    file.read((char*)&headerObject.width, 2);
    file.read((char*)&headerObject.height, 2);
    file.read((char*)&headerObject.bitsPerPixel, 1);
    file.read((char*)&headerObject.imageDescriptor, 1);
    Pixel P;
    for(int i = 0; i < GetNumPixels(); i++) {
        file.read((char*)&P.blue, sizeof(P.blue));
        file.read((char*)&P.green, sizeof(P.green));
        file.read((char*)&P.red, sizeof(P.red));
        pixels.push_back(P);
    }
    return true;
}

bool Image::WriteFile(string fileName) {
    ofstream file(fileName, ios_base::binary);
    if(!file.is_open())
    {
        cout << "error opening file!" << endl;
        return false;
    }
    file.write((char*)&headerObject.idLength, 1);
    file.write((char*)&headerObject.colorMapType, 1);
    file.write((char*)&headerObject.dataTypeCode, 1);
    file.write((char*)&headerObject.colorMapOrigin, 2);
    file.write((char*)&headerObject.colorMapLength, 2);
    file.write((char*)&headerObject.colorMapDepth, 1);
    file.write((char*)&headerObject.xOrigin, 2);
    file.write((char*)&headerObject.yOrigin, 2);
    file.write((char*)&headerObject.width, 2);
    file.write((char*)&headerObject.height, 2);
    file.write((char*)&headerObject.bitsPerPixel, 1);
    file.write((char*)&headerObject.imageDescriptor, 1);
    Pixel P;
    vector<Pixel> v = GetPixels();
    for(int i = 0; i < GetNumPixels(); i++) {
        P.red = pixels[i].red;
        P.green = pixels[i].green;
        P.blue = pixels[i].blue;
        file.write((char*)&P.blue, sizeof(P.blue));
        file.write((char*)&P.green, sizeof(P.green));
        file.write((char*)&P.red, sizeof(P.red));
    }
    file.close();
    return true;
}

bool Image::TestingResults(Image& test) {

    if(this->GetNumPixels() != test.GetNumPixels()) {
        cout << "numPixels not equal" << endl;
        cout << "this pixels: " << this->GetNumPixels() << endl;
        cout << "test pixels: " << test.GetNumPixels() << endl;
        return false;
    }
    if(this->pixels.size() != test.pixels.size()) {
        cout << "pixels.size is not equal" << endl;
        return false;
    }

    for(int i = 0; i < test.GetNumPixels(); i++) {
        if(this->pixels[i].red == test.pixels[i].red
            && this->pixels[i].green == test.pixels[i].green
            && this->pixels[i].blue == test.pixels[i].blue)
                continue;
        else {
            if (this->pixels[i].red != test.pixels[i].red) {
                cout << "expected R value for pixel " << i << ": " << (int) test.pixels[i].red << endl;
                cout << "actual R value for pixel " << i << ": " << (int) this->pixels[i].red << endl;
            }
            if (this->pixels[i].green != test.pixels[i].green) {
                cout << "expected G value for pixel " << i << ": " << (int) test.pixels[i].green << endl;
                cout << "actual G value for pixel " << i << ": " << (int) this->pixels[i].green << endl;
            }
            if (this->pixels[i].blue != test.pixels[i].blue) {
                cout << "expected B value for pixel " << i << ": " << (int) test.pixels[i].blue << endl;
                cout << "actual B value for pixel " << i << ": " << (int) this->pixels[i].blue << endl;
            }
            cout << "test failed!" << endl;
            return false;
        }
    }
    cout << "test successful!" << endl;
    return true;
}

//Image::Header::Header(char a, char b, char c, short d, short e, char f, short g, short h, short i, short j, char k, char l) {
//    idLength = a;
//    colorMapType = b;
//    dataTypeCode = c;
//    colorMapOrigin = d;
//    colorMapLength = e;
//    colorMapDepth = f;
//    xOrigin = g;
//    yOrigin = h;
//    width = i;
//    height = j;
//    bitsPerPixel = k;
//    imageDescriptor = l;
//}