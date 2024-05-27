#ifndef __MODEL_H__
#define __MODEL_H__
#include <string>
#include <typeinfo>
#include <array>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Model {

    private:
        vector<Vec3f> vertices;
        vector<vector<int>> faces; 
    public:
        Model();
        Model(string filename);

        Vec3f vert(int index);
        vector<int> face(int index);

        int nfaces();
};

#endif //__MODEL_H__
