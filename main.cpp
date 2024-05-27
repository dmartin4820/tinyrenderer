#include "tgaimage.h"
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
    Vec3f v0{};
    v0.zeros();

    std::cout << v0 << std::endl;
    //for (int i=0; i<model->nfaces(); i++) {
    //    for (int j=0; j<3; j++) {
    //        Vec3f v0 = model->vert(face[j]);
    //        Vec3f v1 = model->vert(face[(j+1)%3]);
    //        int x0 = (v0.x+1.)*width/2.;
    //        int y0 = (v0.y+1.)*height/2.;
    //        int x1 = (v1.x+1.)*width/2.;
    //        int y1 = (v1.y+1.)*height/2.;
    //        line(x0, y0, x1, y1, image, white);
    //    }
    //} 
	return 0;
}

