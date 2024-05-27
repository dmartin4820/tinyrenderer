#include <fstream>
#include <iostream>
#include "model.h"

Model::Model(string filename) {
        
};

Vec3f Model::vert(int index) {
    return this->vertices[index];
}

array<int> face(int index) {
    //if (index > 3 || index < 0) {
    //    throw exception;
    //}
    return this->faces[index];
};

int nfaces(){
    return this->faces.size();
};
