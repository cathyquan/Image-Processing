#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"
using namespace std;

Image Multiply(Image& i1, Image& i2);
Image Subtract(Image& i1, Image& i2);
Image ScreenBlending(Image& i1, Image& i2);
Image Overlay(Image& i1, Image& i2);
Image AddGreen(Image& i1);
Image Scale(Image& i1);
Image SplitRed(Image& i1);
Image SplitGreen(Image& i1);
Image SplitBlue(Image& i1);
Image Combine(Image& i1Red, Image& i2Green, Image& i3Blue);
Image Rotate180(Image& i1);
Image ExtraCredit(Image& i1, Image& i2, Image& i3, Image& i4);
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();
void Task8();
void Task9();
void Task10();
void Task11();

int main() {

    // multiply
    Task1();
    // subtract
    Task2();
    // multiply, screen blending
    Task3();
    // multiply, subtract
    Task4();
    // overlay
    Task5();
    // add 200 to green
    Task6();
    // scale red by 4, blue by 0
    Task7();
    // write each channel to a separate file
    Task8();
    // combine three files into one
    Task9();
    // rotate 180
    Task10();
    // extra credit
    Task11();

}

Image Multiply(Image& i1, Image& i2) {
    Image i3;
    i3.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    vector<Pixel>& p3 = i3.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        float red1 = (float)p1[i].red / (float)255;
        float green1 = (float)p1[i].green / (float)255;
        float blue1 = (float)p1[i].blue / (float)255;

        float red2 = (float)p2[i].red / (float)255;
        float green2 = (float)p2[i].green / (float)255;
        float blue2 = (float)p2[i].blue / (float)255;

        p.red = (int)(255 * red1 * red2 + 0.5f);
        p.green = (int)(255 * green1 * green2 + 0.5f);
        p.blue = (int)(255 * blue1 * blue2 + 0.5f);

        p3.push_back(p);
    }

    return i3;
}

Image Subtract(Image& i2, Image& i1) {
    Image i3;
    i3.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    vector<Pixel>& p3 = i3.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        p.red = 0;
        p.green = 0;
        p.blue = 0;

        int tempRed = (int)(p1[i].red) - (int)(p2[i].red);
        int tempGreen = (int)(p1[i].green) - (int)(p2[i].green);
        int tempBlue = (int)(p1[i].blue) - (int)(p2[i].blue);

        if(tempRed >= 0) {
            p.red = tempRed;
        }
        if(tempGreen >= 0) {
            p.green = tempGreen;
        }
        if(tempBlue >= 0) {
            p.blue = tempBlue;
        }

        p3.push_back(p);
    }
    return i3;
}

Image ScreenBlending(Image& i1, Image& i2) {
    Image i3;
    i3.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    vector<Pixel>& p3 = i3.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        float red1 = (float)p1[i].red / (float)255;
        float green1 = (float)p1[i].green / (float)255;
        float blue1 = (float)p1[i].blue / (float)255;

        float red2 = (float)p2[i].red / (float)255;
        float green2 = (float)p2[i].green / (float)255;
        float blue2 = (float)p2[i].blue / (float)255;

        p.red = 255 * (1.0 - (1.0f - red1) * (1.0f - red2)) + 0.5f;
        p.green = 255 * (1.0 - (1.0f - green1) * (1.0f - green2)) + 0.5f;
        p.blue = 255 * (1.0 - (1.0f - blue1) * (1.0f - blue2)) + 0.5f;

        p3.push_back(p);
    }

    return i3;
}

Image Overlay(Image& i1, Image& i2) {
    Image i3;
    i3.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    vector<Pixel>& p3 = i3.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        float red1 = (float)p1[i].red / (float)255;
        float green1 = (float)p1[i].green / (float)255;
        float blue1 = (float)p1[i].blue / (float)255;

        float red2 = (float)p2[i].red / (float)255;
        float green2 = (float)p2[i].green / (float)255;
        float blue2 = (float)p2[i].blue / (float)255;

        float red3 = 0;
        float green3 = 0;
        float blue3 = 0;

        if(red2 <= 0.5) {
            red3 = 2 * red1 * red2;
        }
        else {
            red3 = 1 - 2 * (1 - red1) * (1 - red2);
        }

        if(green2 <= 0.5) {
            green3 = 2 * green1 * green2;
        }
        else {
            green3 = 1 - 2 * (1 - green1) * (1 - green2);
        }

        if(blue2 <= 0.5) {
            blue3 = 2 * blue1 * blue2;
        }
        else {
            blue3 = 1 - 2 * (1 - blue1) * (1 - blue2);
        }

        p.red = red3 * 255 + 0.5f;
        p.green = green3 * 255 + 0.5f;
        p.blue = blue3 * 255 + 0.5f;

        p3.push_back(p);
    }

    return i3;
}

Image AddGreen(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        p.green = 255;
        int tempGreen = (int)(p1[i].green) + 200;

        if(tempGreen < 255) {
            p.green = tempGreen;
        }

        p.red = p1[i].red;
        p.blue = p1[i].blue;

        p2.push_back(p);
    }

    return i2;
}

Image Scale(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        float red1 = (float)p1[i].red / (float)255;
        p.red = 255;
        if((int)(red1 * 4 * 255 + 0.5f) < 255) {
            p.red = (int)(red1 * 4 * 255 + 0.5f);
        }
        p.green = p1[i].green;
        p.blue = 0;

        p2.push_back(p);
    }

    return i2;
}

Image SplitRed(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        p.red = p1[i].red;
        p.green = p1[i].red;
        p.blue = p1[i].red;

        p2.push_back(p);
    }

    return i2;
}

Image SplitGreen(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        p.red = p1[i].green;
        p.green = p1[i].green;
        p.blue = p1[i].green;

        p2.push_back(p);
    }

    return i2;
}

Image SplitBlue(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = 0; i < i1.GetNumPixels(); i++) {
        p.red = p1[i].blue;
        p.green = p1[i].blue;
        p.blue = p1[i].blue;

        p2.push_back(p);
    }

    return i2;
}

Image Combine(Image& i1Red, Image& i2Green, Image& i3Blue) {
    Image i4;
    i4.SetHeaderObject(i1Red.GetHeaderObject());

    vector<Pixel>& p1 = i1Red.GetPixels();
    vector<Pixel>& p2 = i2Green.GetPixels();
    vector<Pixel>& p3 = i3Blue.GetPixels();
    vector<Pixel>& p4 = i4.GetPixels();
    Pixel p;

    for(int i = 0; i < i1Red.GetNumPixels(); i++) {
        p.red = p1[i].red;
        p.green = p2[i].green;
        p.blue = p3[i].blue;

        p4.push_back(p);
    }
    return i4;
}

Image Rotate180(Image& i1) {
    Image i2;
    i2.SetHeaderObject(i1.GetHeaderObject());

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    Pixel p;

    for(int i = i1.GetNumPixels() - 1; i >= 0 ; i--) {
        p.red = p1[i].red;
        p.green = p1[i].green;
        p.blue = p1[i].blue;

        p2.push_back(p);
    }
    return i2;
}

Image ExtraCredit(Image& i1, Image& i2, Image& i3, Image& i4) {
    Image i5;
    i5.SetHeaderObject(i1.GetHeaderObject());
    i5.SetWidth(i1.GetHeaderObject().width + i2.GetHeaderObject().width);
    i5.SetHeight(i1.GetHeaderObject().height + i3.GetHeaderObject().height);

    vector<Pixel>& p1 = i1.GetPixels();
    vector<Pixel>& p2 = i2.GetPixels();
    vector<Pixel>& p3 = i3.GetPixels();
    vector<Pixel>& p4 = i4.GetPixels();
    vector<Pixel>& p5 = i5.GetPixels();
    Pixel p;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;

    for(int i = 0; i < i5.GetNumPixels(); i++) {
        if(i >= i5.GetNumPixels() / 2) {
            if((i / i1.GetHeaderObject().width) % 2 == 0) {
                p.red = p1[count1].red;
                p.green = p1[count1].green;
                p.blue = p1[count1].blue;
                p5.push_back(p);
                count1++;
            }
            else {
                p.red = p2[count2].red;
                p.green = p2[count2].green;
                p.blue = p2[count2].blue;
                p5.push_back(p);
                count2++;
            }
        }
        else {
            if((i / i1.GetHeaderObject().width) % 2 == 0) {
                p.red = p4[count4].red;
                p.green = p4[count4].green;
                p.blue = p4[count4].blue;
                p5.push_back(p);
                count4++;
            }
            else {
                p.red = p3[count3].red;
                p.green = p3[count3].green;
                p.blue = p3[count3].blue;
                p5.push_back(p);
                count3++;
            }
        }
    }
    return i5;
}

void Task1() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part1.tga");

    Image image1;
    image1.ReadFile("input//layer1.tga");

    Image image2;
    image2.ReadFile("input//pattern1.tga");
    Image image3 = Multiply(image1, image2);
    image3.WriteFile("output//part1.tga");
    image3.TestingResults(test);
}
void Task2() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part2.tga");

    Image image1;
    image1.ReadFile("input//layer2.tga");
    Image image2;
    image2.ReadFile("input//car.tga");
    Image image3 = Subtract(image1, image2);
    image3.WriteFile("output//part2.tga");
    image3.TestingResults(test);
}
void Task3() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part3.tga");

    Image image1;
    image1.ReadFile("input//layer1.tga");
    Image image2;
    image2.ReadFile("input//pattern2.tga");
    Image loadedImage;
    Image temp = Multiply(image1, image2);
    loadedImage.ReadFile("input//text.tga");
    Image image3 = ScreenBlending(loadedImage, temp);
    image3.WriteFile("output//part3.tga");
    image3.TestingResults(test);
}
void Task4() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part4.tga");

    Image image1;
    image1.ReadFile("input//layer2.tga");
    Image image2;
    image2.ReadFile("input//circles.tga");
    Image loadedImage;
    Image temp = Multiply(image1, image2);
    loadedImage.ReadFile("input//pattern2.tga");
    Image image3 = Subtract(loadedImage, temp);
    image3.WriteFile("output//part4.tga");
    image3.TestingResults(test);
}
void Task5() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part5.tga");

    Image image1;
    image1.ReadFile("input//layer1.tga");
    Image image2;
    image2.ReadFile("input//pattern1.tga");
    Image image3 = Overlay(image1, image2);
    image3.WriteFile("output//part5.tga");
    image3.TestingResults(test);
}
void Task6() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part6.tga");

    Image image1;
    image1.ReadFile("input//car.tga");
    Image image2 = AddGreen(image1);
    image2.WriteFile("output//part6.tga");
    image2.TestingResults(test);
}
void Task7() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part7.tga");

    Image image1;
    image1.ReadFile("input//car.tga");
    Image image2 = Scale(image1);
    image2.WriteFile("output//part7.tga");
    image2.TestingResults(test);
}
void Task8() {
    Image testRed;
    testRed.ReadFile("examples//EXAMPLE_part8_r.tga");
    Image testGreen;
    testGreen.ReadFile("examples//EXAMPLE_part8_g.tga");
    Image testBlue;
    testBlue.ReadFile("examples//EXAMPLE_part8_b.tga");

    Image image1;
    image1.ReadFile("input//car.tga");
    Image imageRed = SplitRed(image1);
    Image imageGreen = SplitGreen(image1);
    Image imageBlue = SplitBlue(image1);
    imageRed.WriteFile("output//part8_r.tga");
    imageGreen.WriteFile("output//part8_g.tga");
    imageBlue.WriteFile("output//part8_b.tga");
    imageRed.TestingResults(testRed);
    imageGreen.TestingResults(testGreen);
    imageBlue.TestingResults(testBlue);
}
void Task9() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part9.tga");

    Image image1;
    image1.ReadFile("input//layer_red.tga");
    Image image2;
    image2.ReadFile("input//layer_green.tga");
    Image image3;
    image3.ReadFile("input//layer_blue.tga");
    Image image4 = Combine(image1, image2, image3);
    image4.WriteFile("output//part9.tga");
    image4.TestingResults(test);
}
void Task10() {
    Image test;
    test.ReadFile("examples//EXAMPLE_part10.tga");

    Image image1;
    image1.ReadFile("input//text2.tga");
    Image image2 = Rotate180(image1);
    image2.WriteFile("output//part10.tga");
    image2.TestingResults(test);
}
void Task11() {
    Image test;
    test.ReadFile("examples//EXAMPLE_extracredit.tga");

    Image image1;
    image1.ReadFile("input//car.tga");
    Image image2;
    image2.ReadFile("input//circles.tga");
    Image image3;
    image3.ReadFile("input//pattern1.tga");
    Image image4;
    image4.ReadFile("input//text.tga");
    Image image5 = ExtraCredit(image1, image2, image3, image4);
    image5.WriteFile("output//extracredit.tga");
    image5.TestingResults(test);
}