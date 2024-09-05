/*
 * the file contains the filter :
 * 1-adjustBrightness
 * 2-rotate_image
 * 3-add_frame_to_image
 * 4-cropImage
 * 5-simpleThresholding
 * 6-invert_image
 * 7-resize_image
 * 8-blurring
 * 9-grayScale
 * 10-EdgeDetection
 * 11-merge_image
 * 12-flipping_image
 * 13-infrared
 * 14-enhancing sunlight
 * 15-purple
 *
 * Team members :
 *  team member1 : mostafa mahmoud fathi , ID:20231244 , who made :rotate_image, add_frame_to_image,
 *  invert_image, infrared, blurring, enhancing sunlight, purple, and the menu
 *  team member2 : menna abd el-gawad Fathi, ID:20230423, who made cropImage, simpleThresholding
 *  flipping filter, and cropImage
 *  team member3 : dina bahaa abdo  , ID:20230135, who made adjustBrightness, EdgeDetection,
 *  merge_image and gray scale
*/
#include <limits>
#include <regex>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "Image_Class.h"
#include <cctype> // for isdigit
using namespace std;
void saveImage(string filename) {
    Image image(filename);
    cout << "enter the new image name" << endl;
    getline(cin ,filename);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // Save the image
    image.saveImage(filename);
    cout << "Image saved as " << filename << endl;
}
bool fileExists( string& filename) {
    ifstream file(filename);
    return file.good(); // Returns true if the file exists and can be opened
}
void invert_image(Image& image,bool& test) {
    test = false;
    string filename;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k);
            }
        }
    }

    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }


}
void rotate_image(Image& image, string& filename ,bool& test) {
    test = false;
    int degree_choice;
    cout << "Enter the degree: ";
    cin >> degree_choice;
    while (degree_choice != 90 && degree_choice != 180 && degree_choice != 270 && degree_choice != 360 && degree_choice != 0) {
        cout << "Invalid choice. Please enter a valid degree : ";
        cin >> degree_choice;
    }

    if (degree_choice == 270) {
        int rotated_width = image.height;
        int rotated_height = image.width;

        Image rotated_image(rotated_width, rotated_height);

        for (int i = 0; i < rotated_image.width; ++i) {
            for (int j = 0; j < rotated_image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int original_x = image.width - 1 - j;
                    int original_y = i;
                    rotated_image.setPixel(i, j, k, image.getPixel(original_x, original_y, k));
                }
            }
        }
        int temp =image.width;
        image.width =image.height;
        image.height = temp ;
        for (int i = 0; i <rotated_image.width ; ++i) {
            for (int j = 0; j <rotated_image.height ; ++j) {
                for (int k = 0; k < 3 ; ++k) {
                    image(i,j,k) = rotated_image(i,j,k);
                }
            }
        }

        string load_choice ;
        cout << "do you want to save the image ?" <<endl;
        cout << "enter your choice (Y/N) : " <<endl;
        cin.ignore();
        getline(cin ,load_choice);
        while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
            cout << "invalid choice, Please enter your choice again : " << endl;
            getline(cin ,load_choice);

        }
        while (load_choice == "Y" || load_choice == "y"){

            cout << "Please enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";

            getline(cin ,filename);
            image.saveImage(filename);
            system(filename.c_str());


            break;
        }




    }
    else if (degree_choice == 90) {
        int rotated_width = image.height;
        int rotated_height = image.width;

        Image rotated_image(rotated_width, rotated_height);

        for (int i = 0; i < rotated_image.width; ++i) {
            for (int j = 0; j < rotated_image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int original_x = j;
                    int original_y = image.height - 1 - i;
                    rotated_image.setPixel(i, j, k, image.getPixel(original_x, original_y, k));
                }
            }
        }
        int temp =image.width;
        image.width =image.height;
        image.height = temp ;
        for (int i = 0; i <rotated_image.width ; ++i) {
            for (int j = 0; j <rotated_image.height ; ++j) {
                for (int k = 0; k < 3 ; ++k) {
                    image(i,j,k) = rotated_image(i,j,k);
                }
            }
        }

        string load_choice ;
        cout << "do you want to save the image ?" <<endl;
        cout << "enter your choice (Y/N) : " <<endl;
        cin.ignore();
        getline(cin ,load_choice);
        while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
            cout << "invalid choice, Please enter your choice again : " << endl;
            getline(cin ,load_choice);

        }
        while (load_choice == "Y" || load_choice == "y"){

            cout << "Please enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";

            getline(cin ,filename);
            image.saveImage(filename);
            system(filename.c_str());
            break;
        }
    }
    else if (degree_choice == 180) {
        Image rotated_image(image.width, image.height);

        for (int i = 0; i < rotated_image.width; ++i) {
            for (int j = 0; j < rotated_image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int original_x = rotated_image.width - 1 - i;
                    int original_y = rotated_image.height - 1 - j;
                    rotated_image.setPixel(i, j, k, image.getPixel(original_x, original_y, k));
                }
            }
        }
        for (int i = 0; i <rotated_image.width ; ++i) {
            for (int j = 0; j <rotated_image.height ; ++j) {
                for (int k = 0; k < 3 ; ++k) {
                    image(i,j,k) = rotated_image(i,j,k);
                }
            }
        }


        string load_choice ;
        cout << "do you want to save the image ?" <<endl;
        cout << "enter your choice (Y/N) : " <<endl;
        cin.ignore();
        getline(cin ,load_choice);
        while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
            cout << "invalid choice, Please enter your choice again : " << endl;
            getline(cin ,load_choice);

        }
        while (load_choice == "Y" || load_choice == "y"){

            cout << "Please enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";

            getline(cin ,filename);
            image.saveImage(filename);
            system(filename.c_str());
            break;
        }
    }
    else if (degree_choice == 0 || degree_choice == 360) {
        string load_choice ;
        cout << "do you want to save the image ?" <<endl;
        cout << "enter your choice (Y/N) : " <<endl;
        cin.ignore();
        getline(cin ,load_choice);
        while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
            cout << "invalid choice, Please enter your choice again : " << endl;
            getline(cin ,load_choice);

        }
        while (load_choice == "Y" || load_choice == "y") {

            cout << "Please enter image name to store new image\n";
            cout << "and specify extension .jpg, .bmp, .png, .tga: ";

            getline(cin ,filename);
            image.saveImage(filename);
            system(filename.c_str());
            break;
        }
    }

}
void add_frame_simple(Image& image, int* frame_color) {
    // Add a simple frame to the image
    int frame_size = min(image.width, image.height) / 20; // Adjust the frame size as needed
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < frame_size || i >= image.width - frame_size || j < frame_size || j >= image.height - frame_size) {
                // Set the pixel color to the frame color for pixels within the frame border
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, 0, frame_color[0]);
                    image.setPixel(i, j, 1, frame_color[1]);
                    image.setPixel(i, j, 2, frame_color[2]);
                }
            }
        }
    }
}
void add_frame_arboretum(Image& image, int* frame_color) {
    // Add the outer simple frame
    add_frame_simple(image, frame_color);

    // Add space between the outer and inner frames

    int frame_size = min(image.width, image.height) / 20; // Adjust the frame size as needed
    int space = frame_size/3;
    int inner_frame_size = frame_size - space;

    // Add the inner simple frame
    for (int i = space; i < image.width - space; ++i) {
        for (int j = space; j < image.height - space; ++j) {
            if (i < inner_frame_size || i >= image.width - inner_frame_size || j < inner_frame_size || j >= image.height - inner_frame_size) {
                // Set the pixel color to the frame color for pixels within the inner frame border
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, 0, 255); // Red channel
                    image.setPixel(i, j, 1, 255); // Green channel
                    image.setPixel(i, j, 2, 255); // Blue channel
                }
            }
        }
    }
}
void add_frame_to_image(Image& image,bool& test) {
    test = false;
    string filename;
    string frame_type;
    cout << "Please choose the type of frame (simple/arboretum): ";
    cin >> frame_type;
    while(frame_type != "simple" && frame_type != "arboretum"){
        cout << "please enter a valid choice :" << endl;
        cin >> frame_type;
    }
    frame_goto:
      int frame_color[3]; // Array to store RGB values of frame color
      int* ptr_frame_color = frame_color; // Pointer to frame color array

    cout << "Please enter the color of the frame (RGB values separated by spaces, e.g., '255 0 0' for red): ";
    for (int i = 0; i < 3; ++i) {
        cin >> *(ptr_frame_color + i); // Read RGB values via pointer

    }


    if (frame_type == "simple") {
        add_frame_simple(image, ptr_frame_color);
    }
    else if (frame_type == "arboretum") {
        add_frame_arboretum(image, ptr_frame_color);
    }
    else {
        cout << "Invalid frame type. Please choose 'simple' or 'arboretum'." << endl;
        return;
    }

    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    cin.ignore();
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void cropImage(Image& image,bool& test) {
    test = false;
    string filename;
    int x, y, W, H;
    cout << "X coordinate of top-left corner: ";
    cin >> x;
    cout << "Y coordinate of top-left corner: ";
    cin >> y;
    cout << "Width of the cropped region: ";
    cin >> W;
    cout << "Height of the cropped region: ";
    cin >> H;
    regex exp("\\d+");
    while (! regex_match(to_string(x),exp) || ! regex_match(to_string(y),exp)
           || ! regex_match(to_string(W),exp)|| ! regex_match(to_string(H),exp)){
        cout << "Invalid input. Y and x coordinate of top-left corner, Width and height must be numeric integers." << endl;
        cout << "X coordinate of top-left corner: ";
        cin >> x;
        cout << "Y coordinate of top-left corner: ";
        cin >> y;
        cout << "Width of the cropped region: ";
        cin >> W;
        cout << "Height of the cropped region: ";
        cin >> H;
    }

    Image modimage(W, H);

    // Ensure the cropping region is within the bounds of the original image
    int maxX = min(x + W, image.width);
    int maxY = min(y + H, image.height);

    for (int i = x; i < maxX; i++) {
        for (int j = y; j < maxY; j++) {
            for (int k = 0; k < 3; k++) {
                // Copy pixel from original image to cropped image
                modimage.setPixel(i - x, j - y, k, image.getPixel(i, j, k));
            }
        }
    }
    image.height =modimage.height;
    image.width =modimage.width;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k <3 ; ++k) {
                image(i,j,k) = modimage(i,j,k);
            }
        }
    }

    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    cin.ignore();
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void grayScale(Image& image,bool& test){
    string filename ;
    test = false;
    // Calculate average pixel value for each pixel and set all channels to the average value
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image.getPixel(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, avg);
            }
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void grayScale2(Image& image,bool& test){
    string filename ;
    test = false;
    // Calculate average pixel value for each pixel and set all channels to the average value
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image.getPixel(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, avg);
            }
        }
    }

}
void infrared(Image& image,bool& test){
    string filename ;
    test = false;
    // Calculate average pixel value for each pixel and set all channels to the average value
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int temp = image(i,j,1) ;
            image(i,j,0) = 255;
            image(i,j,1) = 255-  image(i,j,2);
            image(i,j,2) = 255 - temp;
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void enhance_sunlight(Image& image,bool& test){
    string filename ;
    test = false;
    // Calculate average pixel value for each pixel and set all channels to the average value
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int x = 0.4 * image(i,j,2);
            image(i,j,2) =image(i,j,2)- x ;
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void purple(Image& image,bool& test){
    string filename ;
    test = false;
    // Calculate average pixel value for each pixel and set all channels to the average value
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int x = 0.4 * image(i,j,1);
            image(i,j,1) =image(i,j,1)- x ;
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void Flipping(Image& image,bool& test) {
    cout << "Which Flip do you want to apply to the Image?" << endl;
    cout << "1. Horizontally\n2. Vertically" << endl;
    cout << "Please Enter Your Choice: ";
    test = false;
    Image newImage = Image(image.width,image.height);
    string filename;
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "Invalid choice, Please Enter Your Choice again : ";
        cin >> choice;
    }
    if (choice == 1) {
        for (int x = image.width - 1; x >= 0; x--) {
            for (int y = 0; y < image.height; y++) {
                for (int k = 0; k < 3; k++) {
                    newImage( image.width - 1 - x, y, k) = image(x, y, k);
                }
            }
        }


        for (int x = 0; x < image.width; x++) {
            for (int y = 0; y < image.height; y++) {
                for (int k = 0; k < 3; k++) {
                    image(x, y, k) = newImage(x, y, k);
                }
            }
        }
    } else if (choice == 2) {
        for (int x = 0; x < image.width; x++) {
            for (int y = image.height - 1; y >= 0; y--) {
                for (int k = 0; k < 3; k++) {
                    newImage(x,  image.height - 1 - y, k) = image(x, y, k);
                }
            }
        }


        for (int x = 0; x < image.width; x++) {
            for (int y = 0; y < image.height; y++) {
                for (int k = 0; k < 3; k++) {
                    image(x, y, k) = newImage(x, y, k);
                }
            }
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    cin.ignore();
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void simpleThresholding(Image& image,bool& test ){
    test = false;
    string filename;
    grayScale2(image,test);

    int threshold = 128;

    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            int grayValue = image.getPixel(j, i, 0); // Assuming getPixel() returns the grayscale value
            if (grayValue < threshold) {
                // Set pixel to black
                image.setPixel(j, i, 0, 0);
                image.setPixel(j, i, 1, 0);
                image.setPixel(j, i, 2, 0);
            }
            else {
                // Set pixel to white
                image.setPixel(j, i, 0, 255);
                image.setPixel(j, i, 1, 255);
                image.setPixel(j, i, 2, 255);
            }
        }
    }

    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void adjustBrightness(Image& image,bool& test) {
    test = false;
    cout << "Enter the brightness percentage (0.5 for decreasing the brightness and 1.5 for increasing the brightness): ";
    double brightnessPercentage;
    cin >> brightnessPercentage;
    while(brightnessPercentage != 0.5 && brightnessPercentage != 1.5){
        cout << " Invalid input. Please, enter the brightness percentage again" << endl;
        cin >> brightnessPercentage;
    }

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Adjust the brightness of each pixel by multiplying by the brightness percentage
                double adjustedPixelValue = image.getPixel(i, j, k) * brightnessPercentage;

                // Ensure that pixel values are within the valid range (0 to 255)
                adjustedPixelValue = max(0.0, min(255.0, adjustedPixelValue));

                // Set the adjusted pixel value
                image.setPixel(i, j, k, adjustedPixelValue);
            }
        }
    }

    string filename;
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    cin.ignore();
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void resize_image(Image& image,Image& resized , bool& test){
    test = false;
    int new_width;
    int new_height;
    string filename;
    cout << "enter the new width then the new height :" << endl;
    cin >> new_width >> new_height;
    regex exp("\\d+");
    while (! regex_match(to_string(new_width),exp) || ! regex_match(to_string(new_height),exp) ){
        cout << "Invalid input. Width and height must be numeric integers." << endl;
        cin >> new_width >> new_height;
    }
    double x = double (image.width)/new_width ;
    double y = double (image.height)/new_height ;
    resized = Image(new_width,new_height);
    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height ; ++j) {
            for (int k = 0; k < 3; ++k) {
                resized(i,j,k) = image(ceil(i*x), ceil(j*y),k);
            }
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    cin.ignore();
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        resized.saveImage(filename);
        system(filename.c_str());
        break;
    }
    test = true;

}
void resize2_image(int new_width ,int new_height,Image& image) {
    double x = double(image.width) / new_width;
    double y = double(image.height) / new_height;
    Image resized(new_width, new_height);
    for (int i = 0; i < new_width; ++i) {
        for (int j = 0; j < new_height; ++j) {
            for (int k = 0; k < 3; ++k) {
                resized(i, j, k) = image(ceil(i * x), ceil(j * y), k);
            }
        }
    }
    image.width = new_width;
    image.height = new_height;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = resized(i, j, k);
            }
        }
    }
}
void blurring(Image& image,bool& test) {
    test = false;
    Image image2;
    Image blurred_image(image.width, image.height);
    vector<vector<int>> matrix;
    vector<int> sequence = {1, 4, 7, 4, 1, 4, 16, 26, 16, 4, 7, 26, 41, 26, 7, 4, 16, 26, 16, 4, 1, 4, 7, 4, 1};

    // Fill the matrix
    for (int i = 0; i < 5; ++i) {
        vector<int> row;
        for (int j = 0; j < 5; ++j) {
            row.push_back(sequence[i * 5 + j]);
        }
        matrix.push_back(row);
    }
    int w = image.width;
    int h = image.height;
    if (image.width >1000 && image.height > 1000){
        resize2_image(700,700,image);
    }

    // Apply Gaussian blur filter
    for (int n = 0; n < 20; ++n) {
        for (int i = 2; i < image.width - 2; ++i) {
            for (int j = 2; j < image.height - 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Compute weighted sum of surrounding pixels
                    int sum = 0;
                    for (int x = -2; x <= 2; ++x) {
                        for (int y = -2; y <= 2; ++y) {
                            sum += image.getPixel(i + x, j + y, k) * matrix[x + 2][y + 2];
                        }
                    }
                    int avg = sum/273;
                    blurred_image.setPixel(i, j, k, avg);
                }
            }
        }

        // Copy blurred image back to the original image
        image.width = image.width - 2;
        image.height = image.height - 2;
        for (int i = 0; i < image.width ; ++i) {
            for (int j = 0; j < image.height ; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image.setPixel(i, j, k, blurred_image.getPixel(i+2, j+2, k));
                }
            }
        }
    }
    resize2_image(w,h,image);

    string filename;
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }

}
void EdgeDetection(Image& image, bool& test) {
    test = false;
    string filename;
    Image image2(image.width,image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image.getPixel(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, avg);
            }
        }
    }

    int threshold = 120;

    for (int i = 0; i < image.height; ++i) {
        for (int j = 0; j < image.width; ++j) {
            int grayValue = image.getPixel(j, i, 0); // Assuming getPixel() returns the grayscale value
            if (grayValue < threshold) {
                // Set pixel to black
                image.setPixel(j, i, 0, 0);
                image.setPixel(j, i, 1, 0);
                image.setPixel(j, i, 2, 0);
            }
            else {
                // Set pixel to white
                image.setPixel(j, i, 0, 255);
                image.setPixel(j, i, 1, 255);
                image.setPixel(j, i, 2, 255);
            }
        }
    }
    for (int i = 1; i < image.width-1; ++i) {
        for (int j = 1; j < image.height-1; ++j ) {
            if ((image(i, j, 0)!=image(i+1, j, 0)||
                 image(i, j, 0)!=image(i-1, j, 0) ||
                 image(i, j, 0)!=image(i, j+1, 0) ||
                 image(i, j, 0)!=image(i, j-1, 0))
                && (image(i,j,0) == 0)) {
                image2(i, j, 0) = 0;
                image2(i, j, 1) = 0;
                image2(i, j, 2) = 0;
            }
            else {
                image2(i, j, 0) = 255;
                image2(i, j, 1) = 255;
                image2(i, j, 2) = 255;
            }
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i,j,k) = image2(i,j,k);
            }
        }
    }

    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
void merge_image(Image& image, bool& test){
    test = false;
    Image resized ;
    string filename, filename2;
    cout << "enter the image you want to merge with the main image : " << endl;
    getline(cin ,filename2);
    Image image2 = Image(filename2);
    if (image.width > image2.width && image.height > image2.height){
        resize2_image(image2.width ,image2.height,image);
    }
    if (image2.width > image.width && image2.height > image.height){
        resize2_image(image.width ,image.height,image2);
    }
    double x = double (image2.width)/image.width ;
    double y = double (image2.height)/image.height ;
    resized = Image(image.width,image.height);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height ; ++j) {
            for (int k = 0; k < 3; ++k) {
                resized(i,j,k) = image2(ceil(i*x), ceil(j*y),k);
            }
        }
    }
    for (int i = 0; i < image.width;i++) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j % 2 == 1){
                    image (i,j,k) = resized(i,j,k);
                }
            }
        }
    }
    string load_choice ;
    cout << "do you want to save the image ?" <<endl;
    cout << "enter your choice (Y/N) : " <<endl;
    getline(cin ,load_choice);
    while(load_choice != "Y" && load_choice != "y" && load_choice != "N" && load_choice != "n" ){
        cout << "invalid choice, Please enter your choice again : " << endl;
        getline(cin ,load_choice);

    }
    while (load_choice == "Y" || load_choice == "y"){

        cout << "Please enter image name to store new image\n";
        cout << "and specify extension .jpg, .bmp, .png, .tga: ";

        getline(cin ,filename);
        image.saveImage(filename);
        system(filename.c_str());
        break;
    }
}
int main() {


    string filename;
    Image resized ;
    bool test = false ;
    while (true)
    {
        cout <<setw(50) << setfill('*') << " <welcome to the image filters program> " << setw(10) << setfill('*') << "" << endl;
        cout << "please enter the file name you want to load or enter 0 to exit the program : " << endl;
        load_new_image :
        getline(cin ,filename);
        if (filename =="0"){
            cout << "Exiting program." << endl;
            break;
        }
        while (!fileExists(filename))
        {
            cout << "the file does not exist \nplease enter the filename again" << endl;
            getline(cin ,filename);
        }
        cout << "image loaded" << endl;

        bool exitmenu = false;
        bool result = false;
        Image image = Image(filename);
        Image image2 ;
        result_is_the_current_image :
        if (result == true){
            if (test == true){
                image = resized;
            }
            cout << "the current image is the result of the previous filter that was applied" << endl;

        }
        while (!exitmenu) {

            cout << "\nMenu:" << endl;
            cout << "1. load a new image          10. gray scale filter" << endl;
            cout << "2. adjustBrightness          11. detect edges filter" << endl;
            cout << "3. Rotate filter             12. merge two images filter" << endl;
            cout << "4. Add frame filter          13. flipping filter" << endl;
            cout << "5. Crop filter               14. infrared filter" << endl;
            cout << "6. Black and White filter    15. enhancing sunlight filter" << endl;
            cout << "7. Invert filter             16. increasing purple filter" << endl;
            cout << "8. blurring filter           17. Save the image" << endl;
            cout << "9. resize the filter         18. Exit the menu" << endl;
            string choice;
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool check_choice = false;
            for (int i = 0; i <choice.length() ; ++i) {
                if (isdigit(choice[i])){
                    check_choice = true;
                }
                else{
                    check_choice = false;
                }
            }

            if (!choice.empty()  && choice.length() < 3 && check_choice == true) {
                int option = stoi(choice);
                switch (option) {
                    case 1:
                        cout << "please enter the new image name you want to load" << endl;
                        goto load_new_image;
                    case 2:
                        adjustBrightness(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 3:
                        rotate_image(image,filename,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 4:
                        add_frame_to_image(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 5:
                        cropImage(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 6:
                        simpleThresholding(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 7:
                        invert_image(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 8:
                        blurring(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 9:
                        resize_image(image, resized, test);
                        result = true;
                        goto result_is_the_current_image;
                    case 10:
                        grayScale(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 11:
                        EdgeDetection(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 12:
                        merge_image(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 13:
                        Flipping(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 14:
                        infrared(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 15:
                        enhance_sunlight(image,test);
                        result = true;
                        goto result_is_the_current_image;
                    case 16:
                        purple(image, test);
                        result = true;
                        goto result_is_the_current_image;
                    case 17:
                        saveImage(filename);
                        break;
                    case 18:
                        cout << "Exiting menu." << endl;
                        exitmenu = true;
                        break;
                    default:
                        cout << "Invalid choice. Please enter any key to show the menu again." << endl;
                        cin >> choice;
                }
            }
            else
            {
                cout << "Invalid choice. Please enter a valid numeric choice." << endl;
            }

        }
    }
    return 0;
}
