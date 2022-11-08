// 270201089 Harun Eren MUTLU
#include <cstdlib>
#include <iostream>

#include "ceng391/image.hpp"

using namespace std;
using ceng391::Image;
typedef unsigned char uchar;

void exercise_1();
void exercise_2();
void exercise_3();
int main(int /*argc*/, char** /*argv*/)
{       
        exercise_1();
        exercise_2();
        exercise_3();

        return EXIT_SUCCESS;
}

void exercise_1(){
        cout << "Starting Exercise 1"<< endl;
        Image img(300, 300,4);
        cout << "Created image of size (" << img.w()
             << "x" << img.h() << ")"<< " and "<<img.n_channels()<< " channels!" << endl;
        img.set(0);
        img.set_rect(170, 170, 50, 50, 182);
        img.set_rect(130, 130, 50, 50, 200, 18, 200);
        img.set_rect(90, 90, 50, 50, 238, 148, 0, 255);
        img.write_pnm("/tmp/test_img");
        string type = (img.n_channels()==1) ? "pgm" : "ppm";
        cout << "Saved to tmp as test_img."<< type <<endl;  
        cout << " "<<endl;
}

void exercise_2(){
        cout <<"Starting Exercise 2 "<<endl;
        Image img(300,250,4);
        img.read_pnm("/tmp/test_img.ppm"); // if you will try an grayscale you should replace ppm to pgm
        cout << "Loaded image of size (" << img.w()
             << "x" << img.h() << ")"<< " and "<<img.n_channels()<< " channels!" << endl;
        img.write_pnm("/tmp/loaded_img");
        string type = (img.n_channels()==1) ? "pgm" : "ppm";
        cout << "Saved to tmp as loaded_img."<< type <<endl;
        cout <<" "<<endl;
}

void exercise_3(){
        cout <<"Starting Exercise 3 "<<endl;
        cout << "Creating the same image with Exercise 1..."<<endl;
        Image img(300,300,4);
        img.set(0);
        img.set_rect(170, 170, 50, 50, 182);
        img.set_rect(130, 130, 50, 50, 200, 18, 200);
        img.set_rect(90, 90, 50, 50, 238, 148, 0, 255);
        cout << "Image is created."<<endl;
        cout<<" "<<endl;

        cout << "Converting to RGB... "<< endl;
        img.to_rgb();
        cout << "Converted to RGB "<< endl;
        img.write_pnm("/tmp/rgb_img");
        cout << "Saved to tmp as rgb_img.ppm"<<endl;
        cout <<" "<<endl;

        cout << "Converting to RGBA... "<< endl;
        img.to_rgba();
        cout << "Converted to RGBA "<< endl;
        img.write_pnm("/tmp/rgba_img");
        cout << "Saved to tmp as rgba_img.ppm"<<endl;
        cout <<" "<<endl;
        
        cout << "Converting to Grayscale... "<< endl;
        img.to_grayscale();
        cout << "Converted to grayscale "<< endl;
        img.write_pnm("/tmp/grayscale_img");
        cout << "Saved to tmp as grayscale_img.pgm"<<endl;
        cout <<" "<<endl;

        cout << "Converting to RGB again... "<< endl;
        img.to_rgb();
        cout << "Converted to RGB "<< endl;
        img.write_pnm("/tmp/rgb_from_grayscale_img");
        cout << "Saved to tmp as rgb_from_grayscale_img.ppm"<<endl;
}

/// Local Variables:
/// mode: c++
/// compile-command: "make -C ../build image-test"
/// End:
