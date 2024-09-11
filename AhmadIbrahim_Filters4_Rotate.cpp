/*
//Rotate Filter from -45 to 45 while the width greater than height
#include <iostream>
#include<cmath>
#include"Image_Class.h"
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image("toy1.jpg");
    float ang=-10;
    bool isLikeSquareAt45= false;
    if(ang>40||ang<-40)
        isLikeSquareAt45=true;

    if(image.width>image.height && ang) {
        if (ang > 0) {
            ang = ang * 3.1415927 / 180;
            float cosA = cos(ang);
            float sinA = sin(ang);
            int y = image.width * sin(ang);
            if(isLikeSquareAt45)
                y*=0.68;
            float slope = tan(ang);
            float slope2 = -1 / slope;
            int xs = (slope * y + image.height - slope * image.width + slope2 * y) / (slope2 - slope);
            int ys = slope * (xs - image.width + y) + image.height;
            Image image2(sqrt(pow(xs - image.width + y, 2) + pow(ys - image.height, 2)), sqrt(pow(y - xs, 2) + ys * ys));
            int af, ag;
            for (int i = 0; i < image2.width; ++i) {
                for (int j = 0; j < image2.height; ++j) {
                    ag = y + i * cosA - j * sinA;
                    ag = image.width - ag;
                    af = sinA * (i - slope * j) + j / cosA;
                    image2(image2.width - i, j, 0) = image(ag, af, 0);
                    image2(image2.width - i, j, 1) = image(ag, af, 1);
                    image2(image2.width - i, j, 2) = image(ag, af, 2);
                }
            }
            string nameImage =
                    "RotateWid5_" + to_string(int((ang * 180 / 3.1415927))) + "__" + to_string(image2.width) + "x" +
                    to_string(image2.height) + ".jpg";
            image2.saveImage(nameImage);
            system(nameImage.c_str());
        }
        else if (ang < 0) {
            ang = -ang * 3.1415927 / 180;
            float cosA = cos(ang);
            float sinA = sin(ang);
            int y = image.width * sin(ang);
            if(isLikeSquareAt45)
                y*=0.68;float slope = tan(ang);
            float slope2 = -1 / slope;
            int xs = (slope * y + image.height - slope * image.width + slope2 * y) / (slope2 - slope);
            int ys = slope * (xs - image.width + y) + image.height;
            Image image2(sqrt(pow(xs - image.width + y, 2) + pow(ys - image.height, 2)), sqrt(pow(y - xs, 2) + ys * ys));
            cout << "image2.width = " << image2.width << "\timage2.height = " << image2.height << '\n';
            int ag, af;
            for (int i = 0; i < image2.width; ++i) {
                for (int j = 0; j < image2.height; ++j) {
                    ag = y + i * cosA - j * sinA;
                    af = sinA * (i - slope * j) + j / cosA;
                    image2(i, j, 0) = image(ag, af, 0);
                    image2(i, j, 1) = image(ag, af, 1);
                    image2(i, j, 2) = image(ag, af, 2);
                }
            }
            string nameImage =
                    "RotateWid5_" + to_string(-int((ang * 180 / 3.1415927))) + "__" + to_string(image2.width) + "x" +
                    to_string(image2.height) + ".jpg";
            image2.saveImage(nameImage);
            system(nameImage.c_str());
        }
    }
    return 0;
}
*/


/*Rotate Filter from -45 to 45 while the width less than height

#include<iostream>
#include"Image_Class.h"
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image("luffy.jpg");
    float ang=-1;
    bool isLikeSquareAt45= false;
    if(ang>40||ang<-40)
        isLikeSquareAt45=true;
    if(ang>0){
        ang = ang*3.141593 /180;
        float slope=tan(ang);
        float slope2 = -1/slope;
        float sinA=sin(ang);
        float cosA=cos(ang);
        int y=image.width*sin(ang);
        if(isLikeSquareAt45)
            y*=0.8;
        int xs= (2*y-image.height-slope*image.width)/(slope2-slope);
        int ys= slope*(xs-image.width)+y;
        Image image2(int(sqrt(square(image.width-xs) + square(y - ys))), int(sqrt(xs*xs + square(image.height-y-ys))));
        int pc,is,js;
        for(int i=0;i<image2.width;++i){
            for(int j=0;j<image2.height;++j){
                pc=j-slope*i;
                is=pc*sinA+i/cosA;
                js=y+pc*cosA;
                image2(i,j,0)=image(is,js,0);
                image2(i,j,1)=image(is,js,1);
                image2(i,j,2)=image(is,js,2);
            }
        }
        string nameImage = "rotateFilter4.jpg";
        image2.saveImage(nameImage);
        system(nameImage.c_str());
    }
    if(ang<0) {
        ang = -ang * 3.141593 / 180;
        float slope = tan(ang);
        float slope2 = -1 / slope;
        float cosAng = cos(ang);
        int y = image.width * sin(ang);
        if(isLikeSquareAt45)
            y*=0.8;
        int xs = (2 * y - image.height - slope * image.width) / (slope2 - slope);
        int ys = slope * (xs - image.width) + y;
        Image image2(int(sqrt(square(image.width - xs) +square(y - ys))), int(sqrt(
                xs * xs + square(image.height - y - ys))));
        int kd, ko, is, js;
        ko = image.height - y;
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                kd = image2.height - j;
                is = cosAng * (i + slope * kd);
                js = ko - (kd - slope * i) * cosAng;
                image2(i, j, 0) = image(is, js, 0);
                image2(i, j, 1) = image(is, js, 1);
                image2(i, j, 2) = image(is, js, 2);
            }
        }
        string nameImage = "Rotate2_7.jpg";
        image2.saveImage(nameImage);
        system(nameImage.c_str());
    }
    return 0;
}*/
