# This is a follow along repo for the tinyrenderer tutorial. See below link for more details

# Check [the wiki](https://github.com/ssloy/tinyrenderer/wiki) for the detailed lessons.

## compilation
```sh
git clone https://github.com/ssloy/tinyrenderer.git &&
cd tinyrenderer &&
mkdir build &&
cd build &&
cmake .. &&
cmake --build . -j &&
./tinyrenderer ../obj/diablo3_pose/diablo3_pose.obj ../obj/floor.obj
```
The rendered image is saved to `framebuffer.tga`.
