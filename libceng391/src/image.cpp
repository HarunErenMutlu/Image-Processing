// 270201089 Harun Eren MUTLU
#include "ceng391/image.hpp"

#include<fstream>
#include<cstring>
#include<iostream>
#include <sstream>

using namespace std;

namespace ceng391 {

Image::Image(int width, int height, int n_channels, int step)
{
        m_width = width;
        m_height = height;
        if (n_channels == 1 || n_channels == 3 || n_channels == 4){m_n_channels = n_channels;}
        else{ throw::invalid_argument( "N_Channels must be equal to 1,3 or 4" );}
        if (step < m_width*n_channels) step = m_width*n_channels;
        m_step = step;
        m_data = new uchar[m_step * m_height];
}

Image::~Image()
{
        delete [] m_data;
}

void Image::set_rect(int x_tl, int y_tl, int width, int height, uchar value)
{
        if (x_tl < 0) {
                width += x_tl;
                x_tl = 0;
        }

        if (y_tl < 0) {
                height += y_tl;
                y_tl = 0;
        }
        int y_max = min(y_tl + height, m_height);
        int x_max = min(x_tl + width, m_width);
        if(m_n_channels == 1){ 
                size_t length = min(width, m_width - x_tl);
                for (int y = y_tl; y < y_max; ++y) {
                        uchar *row_y = data(y) + x_tl;
                        memset(row_y, value, length);
        }
        }
        else{
                for (int y = y_tl; y < y_max; ++y){
                        uchar *row_y = data(y);
                        for(int x = x_tl; x<x_max; ++x){
                                uchar *pixel = row_y+x*m_n_channels;
                                for(int i =0; i<m_n_channels; i++){
                                        if (i == 3) {memset(pixel+i, (uchar) 255, 1);}
                                        else{memset(pixel+i, value, 1);}
                                }

                        }
                }
        }  
}

void Image::set_rect(int x_tl, int y_tl, int width, int height, uchar R, uchar G, uchar B)
{
        if (x_tl < 0) {
                width += x_tl;
                x_tl = 0;
        }

        if (y_tl < 0) {
                height += y_tl;
                y_tl = 0;
        }
        if (m_n_channels ==1){
                int value = R * 0.3 + G * 0.59 + B * 0.11;
                if (value > 255) {value =  255;}
                if (value<0){value = 0;}
                set_rect(x_tl, y_tl, width, height, value);
        }
        else if(m_n_channels == 4){set_rect(x_tl, y_tl, width, height, R, G, B, 255);}
        else{
                int y_max = min(y_tl + height, m_height);
                int x_max = min(x_tl + width, m_width);
                for (int y = y_tl; y < y_max; ++y) {
                        uchar *row_y = data(y);
                        for(int x = x_tl; x<x_max; ++x){
                                uchar *pixel = row_y+x*3;
                                memset(pixel, R, 1);
                                memset(pixel+1, G, 1);
                                memset(pixel+2, B, 1);
                        }
                }
        }
}

void Image::set_rect(int x_tl, int y_tl, int width, int height, uchar R, uchar G, uchar B, uchar A)
{
        if (x_tl < 0) {
                width += x_tl;
                x_tl = 0;
        }
        if (y_tl < 0) {
                height += y_tl;
                y_tl = 0;
        }
        if (m_n_channels ==1){
                int value = R * 0.3 + G * 0.59 + B * 0.11;
                if (value > 255) {value =  255;}
                if (value<0){value = 0;}
                set_rect(x_tl, y_tl, width, height, value);
        }
        else if(m_n_channels == 3){set_rect(x_tl, y_tl, width, height, R, G, B);}
        else{
                int y_max = min(y_tl + height, m_height);
                int x_max = min(x_tl + width, m_width);
                for (int y = y_tl; y < y_max; ++y) {
                        uchar *row_y = this->data(y);
                        for(int x = x_tl; x<x_max; ++x){
                                uchar *pixel = row_y+x*4;
                                memset(pixel, R, 1);
                                memset(pixel+1, G, 1);
                                memset(pixel+2, B, 1);
                                memset(pixel+3, A, 1);
                        }
                }
        }
}
void Image::write_ppm(const  std::string& filename) const
{
        const string magic_head = "P6";
        ofstream fout;
        string extended_name = filename + ".ppm";
        fout.open(extended_name.c_str(), ios::out | ios::binary);
        fout << magic_head << "\n";
        fout << m_width << " " << m_height << " 255\n";
        for (int y = 0; y < m_height; ++y) {
                const uchar *row_data = this->data(y);
                for (int x =0; x<m_width; ++x){
                        const uchar *pixels = row_data + x*m_n_channels;
                        fout.write(reinterpret_cast<const char*>(pixels),
                            3*sizeof(uchar));
                }
        }
        fout.close();
}

void Image::write_pnm(const  std::string& filename) const
{       if(m_n_channels == 1){
                const string magic_head = "P5";
                ofstream fout;
                string extended_name = filename + ".pgm";
                fout.open(extended_name.c_str(), ios::out | ios::binary);
                fout << magic_head << "\n";
                fout << m_width << " " << m_height << " 255\n";
                for (int y = 0; y < m_height; ++y) {
                        const uchar *row_data = this->data(y);
                        fout.write(reinterpret_cast<const char*>(row_data),
                                m_width*sizeof(uchar));
                }
                fout.close();
        }
        else{
                write_ppm(filename);}
}

void Image::recreate_image_members(int width,int height,int n_channels) 
{
        if(width!= this->m_width || height != this->m_height || n_channels != this->m_n_channels){
                delete [] m_data;
                m_width = width;
                m_height = height;
                m_n_channels = n_channels;
                m_step = width * n_channels;
                m_data = new uchar[m_step * height];
        }
        
}

void Image::read_pnm(const std::string& filename)
{       
        ifstream fp(filename.c_str());
        if(fp.fail()){
                cout << "Couldn't open the file "<< filename <<endl;
                exit(1);
        }
        string magic_num;
        fp >> magic_num;
        if(magic_num != "P5" && magic_num != "P6"){
                fp.close();
                throw::invalid_argument( "The format of Image must be PPM or PGM" );}


        int width,height,max_value;
        stringstream ss;
        ss << fp.rdbuf();
        ss >> width >> height>>max_value;
        if (max_value > 65536 || max_value <0){
                fp.close();
                throw::invalid_argument( "Max Value must be between 0 and 65536" ); // It is created according to this document: http://netpbm.sourceforge.net/doc/ppm.html
        }
        
        if (magic_num == "P5"){
                uchar value;
                recreate_image_members(width, height, 1);
                for(int y = 0; y < height; ++y){
                        uchar * row_data = this->data(y);
                        for (int x = 0; x < width; ++x) {
                                ss >> value;
                                row_data[x] = value;
                        }
                }

        }
        else{
                uchar r,g,b;
                recreate_image_members(width, height, 4);
                for(int y = 0; y < height; ++y){
                        uchar * row_data = this->data(y);
                        for (int x = 0; x < width; ++x) {
                                ss >> r >> g >> b;
                                row_data[x*4] = r;
                                row_data[x*4+1] = g;
                                row_data[x*4+2] = b;
                                row_data[x*4+3] = 255;
                        }
                }
        }
}

void Image::to_rgb(){
        if (m_n_channels == 3) {return;}
        else{
                int new_m_step = m_width*3;
                uchar *new_data;
                new_data = new uchar[new_m_step* m_height]; 
                if(m_n_channels == 4){
                        for (int y = 0; y < m_height; ++y){
                                int row = y*new_m_step;
                                uchar * row_data = this->data(y);
                                for (int x =0; x < m_width; ++x){
                                        int pixel = row+x*3;
                                        uchar *pixels = row_data + x*4;
                                        for (int i=0;i<3;i++){                
                                                new_data[pixel+i] = pixels[i];}
                                
                                }
                        }       
                }
                else{
                        for (int y = 0; y < m_height; ++y){
                                int row = y*new_m_step;
                                uchar * row_data = this->data(y);
                                for (int x =0; x<m_width; ++x){
                                        int pixel = row+x*3;
                                        uchar *pixels = row_data + x;
                                        for (int i = 0; i < 3;i++)
                                        {
                                                new_data[pixel+i] = pixels[0];
                                        }
                                        
                                }
                        }
                }
                recreate_image_members(m_width, m_height, 3);
                m_data = new_data;
        }
}

void Image::to_rgba(){
        if (m_n_channels == 4) {return;}
        else{
                int new_m_step = m_width*4;
                uchar *new_data;
                new_data = new uchar[new_m_step* m_height]; 
                if(m_n_channels == 3){
                        for (int y = 0; y < m_height; ++y){
                                int row = y*new_m_step;
                                uchar * row_data = this->data(y);
                                for (int x =0; x<m_width; ++x){
                                        int pixel = row+x*4;
                                        uchar *pixels = row_data + x*3;
                                        for (int i=0;i<3;i++){                
                                                new_data[pixel+i] = pixels[i];
                                        }
                                        new_data[pixel+3] = 255;
                                
                                }
                                } 
        }
                else{
                        for (int y = 0; y < m_height; ++y){
                                int row = y*new_m_step;
                                uchar * row_data = this->data(y);
                                for (int x =0; x<m_width; ++x){
                                        int pixel = row+x*4;
                                        uchar *pixels = row_data + x;
                                        for (int i = 0; i < 3;i++)
                                        {
                                                new_data[pixel+i] = pixels[0];
                                        }
                                        new_data[pixel+3] = 255;
                                        
                                }
                        }
                }
                recreate_image_members(m_width, m_height, 4);
                m_data = new_data;
        }
        
}

void Image::to_grayscale(){
        if (m_n_channels == 1) {return;}
        else {
                uchar *new_data;
                new_data = new uchar[m_width* m_height]; 
                for (int y = 0; y < m_height; ++y){
                        int row = y*m_width;
                        uchar * row_data = this->data(y);
                        for (int x =0; x<m_width; ++x){
                                int pixel = row+x;
                                uchar *pixels = row_data + x*m_n_channels;              
                                int new_pixel = pixels[0]*0.3 + pixels[1]*0.59 + pixels[2]*0.11;
                                if (new_pixel > 255) {new_pixel =  255;}
                                if (new_pixel<0){new_pixel = 0;}
                                new_data[pixel] = new_pixel;
                        }
                }
                recreate_image_members(m_width, m_height, 1);
                m_data = new_data; 
        }
}

}
