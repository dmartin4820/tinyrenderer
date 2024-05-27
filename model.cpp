#include <fstream>
#include <sstream>
#include <iostream>
#include "model.h"

Model::Model() {};
Model::Model(string filename) {
    ifstream obj{filename};

    if (!obj){
        cout << "Can't read" << endl;
    }

    string line{};
    while (getline(obj, line)) {
		vector<string> svec{};
		istringstream s{line};
        string c{};
        smatch results;
        regex vertex_regex{R"((v)\s+(-?\d*\.?\d*e?-?\d*\d*)\s+(-?\d*\.?\d*e?-?\d*\d*)\s+(-?\d*\.?\d*e?-?\d*\d*))"};

        auto vertex_match = regex_search(line, results, vertex_regex);
        if (vertex_match && results[1] == "v") {
            Vec3f v{stof(results[2]), stof(results[3]), stof(results[4])};
            vertices.push_back(v);
        }

        smatch fresults;
        regex face_regex{R"((f)\s(\d+)\/(\d+)\/(\d+)\s(\d+)\/(\d+)\/(\d+)\s(\d+)\/(\d+)\/(\d+))"};
        auto face_match = regex_match(line, fresults, face_regex);
        if (face_match && fresults[1] == "f") {
                vector<int> face{
                    stoi(fresults[2])-1, 
                    stoi(fresults[5])-1, 
                    stoi(fresults[8])-1,
                };
                faces.push_back(face);
        }
    }
};
Vec3f Model::vert(int index) {
    return vertices[index];
};

vector<int> Model::face(int index) {
    return faces[index];
};

int Model::nvertices(){
    return vertices.size();
};
int Model::nfaces(){
    return faces.size();
};
