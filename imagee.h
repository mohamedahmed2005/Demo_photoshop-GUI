#ifndef IMAGEE_H_INCLUDED
#define IMAGEE_H_INCLUDED
#include "Image_Class.h"
using namespace std;
void purple(Image& primary,string& name);
void black_white(Image& primary, string &name);
void invert_image(Image& primary, string &name);
void flip(Image& primary, string &name);
void crop(Image& primary, string &name);
void rotate_image(Image& primary, string &name);
void grayscale_image(Image& primary, string &name);
void merge_image(Image& primary,string &name);
void lighten_darken_image(Image &primary, string&name);
void adding_frame(Image& primary, string& name);
void Infra_Red(Image& primary, string& name);
void resizing(Image& primary, string &name);
void detect_edge(Image& primary, string& name);
void blurImage(Image& primary,string& name);
void sunny_filter(Image& primary,string& name);
void filter_choices(string filter_choice, Image& primary, string &name);
void filters_menu(Image & primary, string &name);
void asking_for_saving(Image& primary, string &name);
void save_image(Image& primary,string& name);
void load_image(Image& primary, string& name);
string valid_choice(string filter_choice);
string image_name_validate(string name,string& Image_name);
string choice_load_save(string choice);
string choice_load_save_2(string choice);
bool is_number(string x);
#endif
