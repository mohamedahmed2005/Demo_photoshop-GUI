/* Center Light Filter
#include<iostream>
#include"Image_Class.h"
#include<cmath>
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image("samurai.jpg");
    //This variable that take the value
    float c=1.5;

    int a= image.width>>1;
    int b= image.height>>1;
    float A= image.width * 0.707107;
    float B= image.height * 0.707107;
    A*=A;
    B*=B;
    float z;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            z=c*sqrt(1- square(i-a)/A - square(j-b)/B);
            image(i,j,0)=(image(i,j,0)*z>255)?255:image(i,j,0)*z;
            image(i,j,1)=(image(i,j,1)*z>255)?255:image(i,j,1)*z;
            image(i,j,2)=(image(i,j,2)*z>255)?255:image(i,j,2)*z;
        }
    }
    string nameImage="centerLight_10.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////
/* Egg Filter
#include<iostream>
#include<cmath>
#include "Image_Class.h"
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image("night3.jpg");
    Image image2(image.width,image.height);
    int a=image.width>>1;
    int b=image.height>>1;
    float a2=a*a;
    float b2=b*b;
    float d,d2;
    for(int i=0;i<image.width;++i){
        d=image.height*sqrt(1-(i-a)/a2);
        for(int j=0;j<image.height;++j){
            if(square(j-b)/b2 + square(i-a)/a2 >1){
                image2(i,j,0)=0;
                image2(i,j,1)=0;
                image2(i,j,2)=0;
            }
            else{
                if(d)
                d2=(j+(b* sqrt(1- square(i-a)/a2)-b))/d;
                image2(i,j,0)=image(i,d2*image.height,0);
                image2(i,j,1)=image(i,d2*image.height,1);
                image2(i,j,2)=image(i,d2*image.height,2);
            }
        }
    }
    string nameImage="Ellipse_3.jpg";
    image2.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////
/* Rotate The back groundby angle From To 0 to 45
 * The first Part
#include<iostream>
#include"Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    float ang=10;
    ang = ang*3.141593 /180;
    float slope=tan(ang);
    float slope2= -1/slope;
    int y=image.width*sin(ang);
    int x=(image.height-y)*slope;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            if(j>slope2*(i-image.width)+y || j<slope2*i+image.height-y || j>slope*i+image.height-y || j<slope*(i-image.width)+y){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
            else{
                // implementation for any filter
            }
        }
    }
    string nameImage="Rotate2_4.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
/* The second Part
 * #include<iostream>
#include<cmath>
#include"Image_Class.h"
using namespace std;
int main(){
    Image image("purple_imagewano.jpg");
    float ang=10;
    ang = ang*3.141593 /180;
    float slope=tan(1.570796-ang);
    float slope2 = -1/slope;
    int y=image.width*sin(ang);
    int x=(image.height-y)/slope;
    int d1=image.height-y;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            if(j>slope*i+y || j<slope*(i-image.width+x) || j<slope2*i+y || j>slope2*(i-image.width)+d1){
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
            else{
                // implementation for any filter
            }
        }
    }
    string nameImage = "rotateFilter2.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////
/* Cardiod Filter
#include<iostream>
#include "Image_Class.h"
using namespace std;
int square(int x){return x*x;}
int main(){
    Image image(1000,1000);
    Image image2("gamma_adjusted_image.jpg");
    double d1=image2.width/1000.0;
    double d2=image2.height/1000.0;
    for(float i=1;i<1000;++i){
        for(float j=0;j<1000;++j){
            if(0.7*square(i-500) + square((575-j)- 13.416*sqrt(abs(i-500))) >175000 ){
                //To control the color of background
                image(i,j,0)=255;
                image(i,j,1)=50;
                image(i,j,2)=50;
            }
            else{
                image(i,j,0)=image2(i*d1,j*d2,0);
                image(i,j,1)=image2(i*d1,j*d2,1);
                image(i,j,2)=image2(i*d1,j*d2,2);
            }
        }
    }
    string nameImage="Cardiod3_6.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////
/* Jail Filter
#include<iostream>
#include<cmath>
#include"Image_Class.h"
using namespace std;
int main(){
    Image image("mario.bmp");
    float coef = 45.0/image.width;
    float z;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            z = sin(coef * i);
            if(z<0) {
                image(i, j, 0) = -255 * z;
                image(i, j, 1) = -255 * z;
                image(i, j, 2) = -255 * z;
            }
        }
    }
    string nameImage="Jail_2.jpg";
    image.saveImage(nameImage);
    system(nameImage.c_str());
    return 0;
}*/
//////////////////////////////////////////////////////////////////////////