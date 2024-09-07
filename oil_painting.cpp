#include<iostream>
#include"Image_Class.h"
#include <vector>
using namespace std;

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
void oil_painting(Image& image) {
    int width = image.width;
    int height = image.height ;
    if (width > 1000 || height > 1000){
        resize2_image(1000,1000,image);
    }
    double intensity_level = 5; // Intensity levels used for effect
    int radius = 2; // Radius of 2 for 5x5 neighborhood
    int intensity_size = 256; // Maximum intensity value (0-256)

    for (int i = radius; i < image.width - radius; ++i) {
        for (int j = radius; j < image.height - radius; ++j) {

            vector<int> cur_intensity_count(intensity_size, 0);
            vector<int> average_R(intensity_size, 0);
            vector<int> average_G(intensity_size, 0);
            vector<int> average_B(intensity_size, 0);

            for (int k = i - radius; k <= i + radius; ++k) {
                for (int l = j - radius; l <= j + radius; ++l) {
                    // Calculate intensity for the current pixel
                    int R = image(k, l, 0);
                    int G = image(k, l, 1);
                    int B = image(k, l, 2);
                    int cur_intensity = (int)((double)((R + G + B) / 3) * intensity_level) / 255;

                    // Safeguard for intensity bounds
                    cur_intensity = max(0, min(255, cur_intensity));

                    // Update intensity count and sum of RGB values
                    cur_intensity_count[cur_intensity]++;
                    average_R[cur_intensity] += R;
                    average_G[cur_intensity] += G;
                    average_B[cur_intensity] += B;
                }
            }

            // Find the intensity with the maximum count
            int mx_intensity_count = 0, mx_intensity_index = 0;
            for (int M = 0; M < intensity_size; ++M) {
                if (cur_intensity_count[M] > mx_intensity_count) {
                    mx_intensity_count = cur_intensity_count[M];
                    mx_intensity_index = M;
                }
            }

            // Assign the average RGB values to the output image
            if (mx_intensity_count > 0) {
                image(i, j, 0) = average_R[mx_intensity_index] / mx_intensity_count;
                image(i, j, 1) = average_G[mx_intensity_index] / mx_intensity_count;
                image(i, j, 2) = average_B[mx_intensity_index] / mx_intensity_count;
            }
        }
    }
    resize2_image(width,height,image);
}