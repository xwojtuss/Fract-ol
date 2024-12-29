# FRACT-OL

Fract-ol is a 42 project focusing around fractals, self-similar shapes that are a great segue for learning complex numbers. Ever wanted to zoom into the fractals yourself? Well, now you have a chance to do so, with three different sets!

Right now you can choose between: Mandelbrot, Julia and Burningship.

![Mandelbrot](https://github.com/xwojtuss/Fract-ol/blob/main/preview/Mandelbrot.png)
![Julia](https://github.com/xwojtuss/Fract-ol/blob/main/preview/Julia.png)
![Burningship](https://github.com/xwojtuss/Fract-ol/blob/main/preview/Burningship.png)

This project uses minilibx, which is an X11 library designed for 42 students. The library is automatically cloned from github, configured and compiled.

## Getting Started

These instructions will help you get a copy of the project up and running.

### Dependencies

- gcc
- cc
- make
- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)

### Installing

1. Clone the repository:
```
git clone https://github.com/xwojtuss/Fract-ol.git
```

2. Navigate to the project directory:
```
cd Fract-ol
```

3. Run the make command to build the project:
```
make
```

## Running the project

To run the project just run the fractol program with a second argument, the argument can be: Mandelbrot, Julia or Burningship
```
./fractol [type of fractal]
```
For the Julia fractal you can click on the screen to pass different complex numbers into the equation!
Enjoy the views!

## Authors

* **Wojtek Kornatowski** - [xwojtuss](https://github.com/xwojtuss)
