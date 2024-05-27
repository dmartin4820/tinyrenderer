#include "tgaimage.h"
#include <cstring>
#include <regex>
#include "model.h"
#include <opencv2/opencv.hpp>

using namespace cv;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
    bool steep = false;
    if (std::abs(x0-x1)<std::abs(y0-y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0>x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1-x0;
    int dy = y1-y0;
    int derror2 = std::abs(dy)*2;
    int error2 = 0;
    int y = y0;
    for (int x=x0; x<=x1; x++) {
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
        error2 += derror2;
        if (error2 > dx) {
            y += (y1>y0?1:-1);
            error2 -= dx*2;
        }
    }
}

int main(int argc, char** argv) {
    string input_path = argv[1];

    string::size_type start = input_path.rfind("/");
    string::size_type end = input_path.rfind(".");
    int len = end - start - 1;
    string filename = input_path.substr(start + 1 , len) + ".tga";

    cout << filename << endl;
    
    const char* filename_out = filename.c_str();

      
    Model *model = new Model(input_path);

    int height = 800;
    int width = 800;
    TGAImage image(height, width,TGAImage::RGB);

    cout << model->nfaces() << endl;
    cout << model->nvertices() << endl;

    for (int i=0; i < model->nfaces(); i++) {

        vector<int> face = model->face(i);
        for (int j=0; j<3; j++) {
            Vec3f v0 = model->vert(face[j]);
            Vec3f v1 = model->vert(face[(j+1)%3]);
            int x0 = (v0[0]+1.)*width/2.;
            int y0 = (v0[1]+1.)*height/2.;
            int x1 = (v1[0]+1.)*width/2.;
            int y1 = (v1[1]+1.)*height/2.;
            line(x0, y0, x1, y1, image, white);
        }
    } 
    image.flip_vertically();
    try {
        image.write_tga_file(filename_out);
    } catch(...) {
        cout << "using default filename out" << endl;
        image.write_tga_file("mytinyrenderer.tga");
    }
	return 0;
}

