/* Ball Filter
#include<iostream>
#include"Image_Class.h"
using namespace std;
int main(){
    Image image("mario.bmp");
    Image image2((image.width > image.height)?image.height:image.width,
                 (image.width > image.height)?image.height:image.width);

    // assign the half radius
    int r = 0.5 * image2.width;

    for (int i = 0; i < image2.width; ++i) {
        for (int j = 0; j < image2.height; ++j) {
            double ball = (sqrt((r * r  - (i - r)*(i - r)  - (j - r)*(j - r) )) / r);
            image2(i, j, 0) = image(i, j, 0) * ball;
            image2(i, j, 1) = image(i, j, 1) * ball;
            image2(i, j, 2) = image(i, j, 2) * ball;
        }
    }
    string imageName="BallFilter.jpg";
    image2.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fancy borders
// #include <iostream>
//#include "Image_Class.h"
//using namespace std;
//int square(int x){return x*x;}
//int main(){
//    Image image("luffy.jpg");
//    for(int i=0;i<image.width;++i){
//        for(int j=0;j<image.height;++j){
//
//            //draw the white square bounded the maximum is 60
//            if(((i>image.width-60 && i<image.width-53 || j>53 && j<60) && i>image.width-60 && j<60) ||
//               ((i>image.width-48 && i<image.width-45 || j>45 && j<48) && i>image.width-48 && j<48) ||(i>image.width-35 && j<35) ||
//               ((i<60 && i>53 || j<image.height-53 && j>image.height-60) && i<60 && j>image.height-60) ||
//               ((i<48 && i>45 || j<image.height-45 && j>image.height-48) && i<48 && j>image.height-48) ||(i<35 && j>image.height-35)||
//               ((i<60 && i>53 || j>53 && j<60) && i<60 && j<60) || ((i<48 && i>45 || j>45 && j<48) && i<48 && j<48) ||(i<35 && j<35)||
//               ((i>image.width-60 && i<image.width-53 || j<image.height-53 && j>image.height-60) && i>image.width-60 && j>image.height-60) ||
//               ((i>image.width-48 && i<image.width-45 || j<image.height-45 && j>image.height-48) && i>image.width-48 && j>image.height-48) ||
//               (i>image.width-35 && j>image.height-35)){
//                image(i,j,0)=225;
//                image(i,j,1)=225;
//                image(i,j,2)=225;
//            }
//            //draw the colored lines
//            if(i<20 || j<20 || i>image.width-20 || j>image.height-20){
//                // Here make color of boards
//                image(i,j,0)=0;
//                image(i,j,1)=0;
//                image(i,j,2)=225;
//            }
//            //draw the white straight lines
//            if((i>10 &&i<13       ) || (i>16 && i<20) || (j>10 && j<13) || (j>16 && j<20) || (i<image.width-10 && i>image.width-13) || (i<image.width-16 && i>image.width-20) || (j<image.height-10 && j>image.height-13) || (j<image.height-16 && j>image.height-20) ){
//                image(i,j,0)=225;
//                image(i,j,1)=225;
//                image(i,j,2)=225;
//            }
//            //This part draws the eight circles each line draws one circle
//            if((square(j-30)+square(i-image.width+60+10)<150 && square(j-30)+square(i-image.width+60+10)>100) ||
//               5 (square(i-30)+square(j-image.height+70)<150 && square(i-30)+square(j-image.height+70)>100)||
//               (square(i-70)+square(j-30)>100 && square(i-70)+square(j-30)<150) ||
//               (square(j-70)+square(i-30)>100 && square(j-70)+square(i-30)<150) ||
//               (square(j-70)+square(i-image.width+30)>100 && square(j-70)+square(i-image.width+30)<150) ||
//               6(square(i-70)+square(j-image.height+30)>100 && square(i-70)+square(j-image.height+30)<150) ||
//               (square(i-image.width+30)+square(j-image.height+70)>100 && square(i-image.width+30)+square(j-image.height+70)<150) ||
//               8(square(j-image.height+30)+square(i-image.width+70)>100 && (square(j-image.height+30)+square(i-image.width+70)<150))
//                    ){
//                image(i,j,0)=225;
//                image(i,j,1)=225;
//                image(i,j,2)=225;
//            }
//        }
//    }
//    string imageName="FancyFilter.jpg";
//    image.saveImage(imageName);
//    system(imageName.c_str());
//    return 0;
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Circles borders
 * #include<iostream>
#include "Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    float coef = ((image.width > image.height)?image.height:image.width)/80.0;
    float arcoef = 1/coef;
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            if(abs(sin(i*arcoef))*coef>j || abs(sin(j*arcoef))*coef>i || abs(sin(i*arcoef))*coef>image.height-j || abs(sin(j*arcoef))*coef>image.width-i ){
                image(i,j,0)=225;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
    string imageName="CirclesFilter.jpg";
    image.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////
/* Pixelate Filter
 * #include<iostream>
#include"Image_Class.h"
using namespace std;
int main(){
    // the following variable take number from 1 to 1000 percentage from total pixels of image
    int SlideValue=10;
    //that means if we set it 1000 it will get the pixels that it is average of all pixels
    // try more than value to understand
    Image image("luffy.jpg");
    int value = 0;
    value += SlideValue;
    int b = (value/1000.0)*((image.width < image.height)? image.height: image.width);
    for(int i=0;i<image.width;i+=b){
        for(int j=0;j<image.height;j+=b){
            int R=0,G=0,B=0,k = 0, l = 0;
            for(;(k<b)&&(i+k<image.width);++k){
                for(;(l<b) && (l+j<image.height);++l) {
                    R += image(i + k, j + l, 0);
                    G += image(i + k, j + l, 1);
                    B += image(i + k, j + l, 2);
                }
            }
            R/=  l ;
            G/=  l ;
            B/=  l ;
            for(int k=i;((k<i+b))&&(k<image.width);++k){
                for(int l=j;((l<j+b))&&(l<image.height);++l){
                    image(k,l,0)=R;
                    image(k,l,1)=G;
                    image(k,l,2)=B;
                }
            }
        }
    }
    string imageName="PixelsFilter.jpg";
    image.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
/* Drop of Water Filter
 * #include<iostream>
#include "Image_Class.h"
int square(int x){return x*x;}
using namespace std;
int main(){
    Image image("luffy.jpg");
    float coef = 100.0/((image.width<image.height)?image.width:image.height);
    for(int i=0;i<image.width;++i){
        for(int j=0;j<image.height;++j){
            float c = coef * (sqrt(square(i-image.width/2)+ square(j-image.height/2)));
            float z = .8 *( sin(c)/c + 0.24);
            image(i,j,0) = (image(i,j,0)*z*3 >255)? 255:image(i,j,0)*z*3;
            image(i,j,1) = (image(i,j,0)*z*3 >255)? 255:image(i,j,1)*z*3;
            image(i,j,2) = (image(i,j,0)*z*3 >255)? 255:image(i,j,2)*z*3;
        }
    }
    string imageName="PixelsFilter.jpg";
    image.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////
/* The first part from filter Skew
 * Skew to right
 * #include<iostream>
#include "Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    //the angle for skewing
    float ang=35;
    ang=((ang)/180)*3.1416;
    float slop=tan(ang);
    Image image2(image.width + image.height * cos(ang),image.height * sin(ang));
    //To print whole the height
    float n = (float)image.height / image2.height;
//skewed by one loop
    for(int i=0;i<image2.width;++i){
        for(int j=0;j<image2.height;++j){
// we used adea of flip vertical that the library design depend on it. we made an equation for two straight lines -ve slop and fill the determinant part.
            if((j>image2.height-slop*i) && ((j<image2.height -slop*(i - image.width)))){
                image2(i,j,0) = image(i-(image2.height-j)/slop,j*n,0);
                image2(i,j,1) = image(i-(image2.height-j)/slop,j*n,1);
                image2(i,j,2) = image(i-(image2.height-j)/slop,j*n,2);
            }
        }
    }
    string imageName="skewFilter_1.jpg";
    image2.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}*/

/* Skew Part two
 * #include<iostream>
#include "Image_Class.h"
using namespace std;
int main(){
    Image image("luffy.jpg");
    //The angle of Skew
    float ang =34;
    ang = (ang/180) * 3.1416;
    float slop = tan(ang);
    Image image2(image.width + image.height * cos(ang),image.height * sin(ang));
    float n = (float)image.height/image2.height;
    for(int i=0;i<image2.width;++i){
        for(int j=0;j<image2.height;++j){
            if((j<i*slop) && (j>slop*(i-image.width))){
                image2(i,j,0)=image((i-j/slop),j*n,0);
                image2(i,j,1)=image((i-j/slop),j*n,1);
                image2(i,j,2)=image((i-j/slop),j*n,2);
            }
        }
    }
    string imageName="skewFilter_2.jpg";
    image2.saveImage(imageName);
    system(imageName.c_str());
    return 0;
}*/
////////////////////////////////////////////////////////////////////