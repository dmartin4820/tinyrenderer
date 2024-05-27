#ifndef __MODEL_H__
#define __MODEL_H__

#include <array>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class Face {
    array<int, 3> vertex_indices;
    array<int, 3> vertex_texture_indices;
    array<int, 3> vertex_normal_indices;

    public:
        Face(){};
        ~Face(){};
        void add_v_index(int dimension){};
        void add_vt_index(int dimension){};
        void add_vn_index(int dimension){};
        int get_v_index(int dimension){};
        int get_vt_index(int dimension){};
        int get_vn_index(int dimension){};

}

class Model {

    private:
        vector<Vec3f> vertices;
        array<int, 3> faces; 
    public:
        Model(string filename){};

        Vec3f vert(vector<int> face){};
        array<int> face(int index){};

        int nfaces(){};
};

#endif //__MODEL_H__
