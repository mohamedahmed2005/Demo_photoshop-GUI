/* Rotate Background where the width greater than height from -45 to 45
#include<iostream>
#include"Image_Class.h"
#include<cmath>
using namespace std;
int main(){
    Image image("Water 7.jpg");
    float ang = -5;
    if(image.width>image.height) {
        if (ang < 0) {
            ang = -ang * 3.1415927 / 180;
            int y = image.width * sin(ang);
            float slope = tan(ang);
            float slope2 = -1 / slope;
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    if (j < slope * (-i + image.width - y) || j < slope2 * (-i + image.width - y) ||
                        j > slope * (y - i) + image.height || j > slope2 * (y - i) + image.height) {
                        image(i, j, 0) = 100;
                        image(i, j, 1) = 100;
                        image(i, j, 2) = 100;
                    }
                }
            }
        } else if (ang > 0) {
            ang = ang * 3.1415927 / 180;
            int y = image.width * sin(ang);
            float slope = tan(ang);
            float slope2 = -1 / tan(ang);
            for (int i = 0; i < image.width; ++i) {
                for (int j = 0; j < image.height; ++j) {
                    if (j < slope * (i - y) || j < slope2 * (i - y) ||
                        j > slope * (i - image.width + y) + image.height ||
                        j > slope2 * (i - image.width + y) + image.height) {
                        image(i, j, 0) = 0;
                        image(i, j, 1) = 100;
                        image(i, j, 2) = 255;
                    }
                }
            }
        }
    }
    string nameImage="RotateWid3_2.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////
/* Cardiod Filter the second version
#include<iostream>
#include "Image_Class.h"
#include<cmath>
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image(1000,1000);
    Image image2("luffy.jpg");
    double d1=image2.width/1000.0;
    double d2=image2.height/1000.0;
    float angle=45;
    angle = angle*3.1415927/180;
    float angle2=315;
    angle2 = angle2*3.1415927/180;
    float cosAng = cos(angle);
    float sinAng = sin(angle);
    float cosAng2 = cos(angle2);
    float sinAng2 = sin(angle2);
    float k,k2;
    for(float i=0;i<1000;++i){
        for(float j=0;j<1000;++j){
            if(0.7*square(i-500) + square((575-j)- 13.416*sqrt(abs(i-500))) >175000 ){
                k=0.7*square(cosAng*(i-150)+sinAng*(j-850)) + square((sinAng*(i-150)+cosAng*(850-j))- 4*sqrt(abs(cosAng*(i-150)+sinAng*(j-850))));
                k2=0.7*square(cosAng2*(i-850)+sinAng2*(j-850)) + square((sinAng2*(i-850)+cosAng2*(850-j))- 4*sqrt(abs(cosAng2*(i-850)+sinAng2*(j-850))));
                //Each the if statement has variable k belongs to the first heart with left and versa with k2
                if(k <500) {
                    image(i, j, 0) = 200;
                    image(i, j, 1) = 185;
                    image(i, j, 2) = 255;
                }
                else if(k <1000) {
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 70;
                    image(i, j, 2) = 180;
                }
                else if(k<2000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 100;
                }
                else if(k<3000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 10;
                }
                else if(k<4000){
                    image(i, j, 0) = 255 ;
                    image(i, j, 1) = 105;
                    image(i, j, 2) = 33;
                }
                else if(k<5000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 120;
                    image(i, j, 2) = 50;
                }

                else if(k2 <500) {
                    image(i, j, 0) = 200;
                    image(i, j, 1) = 185;
                    image(i, j, 2) = 255;
                }
                else if(k2 <1000) {
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 70;
                    image(i, j, 2) = 180;
                }
                else if(k2<2000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 100;
                }
                else if(k2<3000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 0;
                    image(i, j, 2) = 10;
                }
                else if(k2<4000){
                    image(i, j, 0) = 255 ;
                    image(i, j, 1) = 105;
                    image(i, j, 2) = 33;
                }
                else if(k2<5000){
                    image(i, j, 0) = 255;
                    image(i, j, 1) = 120;
                    image(i, j, 2) = 50;
                }
                //this color the big background
                else{
                    image(i,j,0)=100;
                    image(i,j,1)=100;
                    image(i,j,2)=100;
                }

            }
            //to fill the image
            else{
                image(i,j,0)=image2(i*d1,j*d2,0);
                image(i,j,1)=image2(i*d1,j*d2,1);
                image(i,j,2)=image2(i*d1,j*d2,2);
            }
        }
    }
    string nameImage="CardiodFilter.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////
/* Vintage Filter
#include<iostream>
#include<cmath>
#include"Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    float coef;
    for(int i=0;i<image.height;++i){
        coef=3*abs(0.3*sin(i));
        for(int j=0;j<image.width;++j){
            image(j,i,0)=(image(j,i,0)*coef>255)?255:image(j,i,0)*coef;
            image(j,i,1)=(image(j,i,0)*coef>255)?255:image(j,i,0)*coef;
            image(j,i,2)=(image(j,i,0)*coef>255)?255:image(j,i,0)*coef;
        }
    }
    string nameImage="vintage.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////
/*SemiCircle Frame Filter
#include<iostream>
#include "Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    //This is width semicircles number and it have to be even number
    int n=10;
    
    n>>=1;
    int  n2=(float)n*image.height/image.width;
    n=image.width/n;
    float arcoef =6.283186/n;
    float coef =  1/arcoef;

    n2=image.height/n2;
    float arcoef2 =6.283186/n2;
    float coef2 =  1/arcoef2;

    int sini,sinj;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            sini = sin(i*arcoef)*coef;
            sinj = sin(j*arcoef2)*coef2;
            if(sini>j || -sini>image.height-j || -sinj>i || sinj>image.width-i){
                image(i,j,0)=225;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
            else if(-sini>j || sini>image.height-j || sinj>i || -sinj>image.width-i){
                image(i,j,0)=0;
                image(i,j,1)=255;
                image(i,j,2)=255;
            }
        }
    }
    string imageName="CirclesFilter2_3.jpg";
    image.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}
*/
