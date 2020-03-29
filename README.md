# MiniRT
## Ray Tracing project using miniLibX
Three lights with different colors       |  All possible objects
:---------------------------------------:|:-------------------------:
![three_colors](https://user-images.githubusercontent.com/53476597/77856715-5a0fc600-71f9-11ea-85d4-bbc69f4da5b4.png) | ![all_objs](https://user-images.githubusercontent.com/53476597/77856787-cb4f7900-71f9-11ea-8cbf-e33f1cc404f0.png)
### Usage
This project uses miniLibX library (https://github.com/pbondoer/MinilibX), OpenGL and Appkit frameworks.

```
$ make
$ ./miniRT /path/to/file.rt [--save]
```

The ```--save``` flag is used to save image in bmp image.

### Format of *.rt files
Every object represented by capital letter can be declared once in the scene. Each type of element can be separated by one or more line break(s). Each type of information from an element can be separated by one or more
space(s). Each element first’s information is the type identifier (composed by one or two character(s)), followed by all specific information for each object in a strict order such as:
```
R  [x] [y] #resolution 
A  b [R, G, B] #ambient light
c  [x, y, z] [normal] [FOV] #camera
l  [x, y, z] b [R, G, B] #point light

sp [x, y, z] [radius] [R, G, B]  #sphere
sq [x, y, z] [normal] [side] [R, G, B] #square
tr P0[x, y, z] P1[x, y, z] P2[x, y, z] [R, G, B] #triangle
pl [x, y, z] [normal] [R, G, B] #plane
cy [x, y, z] [normal] [radius] [height] [R, B, G]  #cylinder
cu [x, y, z] [normal] [side] [R, G, B] #cube
```
where:
```
b - brightness constant in range [0, 1]
[R, G, B] - vector representing the color in RGB format; each color in the range [0, 255]
[x, y, z] - coordinates of the centre of the object
[normal] - 3d normalized orientation vector; in range [-1,1] for each x,y,z
P*[x, y, z] - coordinates of * point of trinagle\
FOV - horizontal field of view in degrees in range [0,180]
```
### Controls

In the window of image it is possible to move camera and apply filter:
```
D - increase x coordinate of the camera
A - decrease x coordinate of the camera
S - decrease z coordinate of the camera
W - increase z coordinate of the camera
Q - decrease y coordinate of the camera
E - increase y coordinate of the camera
<- - change to the previous camera
-> - change to the next camera
F - apply Sepia filter
```


