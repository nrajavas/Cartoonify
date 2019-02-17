/***
 assignment1.cpp
 Assignment-1: Cartoonify
 
 Name: Rajavasireddy, Nikhil
 
 Collaborators: Crowther, Blake; Peters, Kevin; Simmons, Michael
 ** Note: although the assignment should be completed individually
 you may speak with classmates on high level algorithmic concepts. Please
 list their names in this section
 
 Project Summary: I took a picture of Stephen Curry of the Golden State Warriors and cartoonified it to the best of my ability. I used Chaikin's algorithm to achieve this.
 ***/


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <iostream>
using namespace std;

class Vertex {
    GLfloat x, y;
public:
    Vertex(GLfloat, GLfloat);
    GLfloat get_y() { return y; };
    GLfloat get_x() { return x; };
};

Vertex::Vertex(GLfloat X, GLfloat Y) {
    x = X;
    y = Y;
}

void setup() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

vector<Vertex> generate_points(vector<Vertex> control_points) {
    vector<Vertex> points;
    
    // TODO:
    // Generate points for a given Chaikin curve iteration
    points.push_back(control_points.front());
    
    for(int i = 0; i <= control_points.size() - 2; i++) {
        float delta_x = control_points[i + 1].get_x() - control_points[i].get_x();
        float delta_y = control_points[i + 1].get_y() - control_points[i].get_y();
        
        points.push_back(Vertex(control_points[i].get_x() + 0.25 * delta_x, control_points[i].get_y() + 0.25 * delta_y));
        points.push_back(Vertex(control_points[i].get_x() + 0.75 * delta_x, control_points[i].get_y() + 0.75 * delta_y));
    }
    
    points.push_back(control_points.back());
    
    return points;
}

void draw_curve(vector<Vertex> control_points, int n_iter) {
    
    // TODO:
    // Draw a Chaikin curve based on the given control points
    vector<Vertex> gen_points = control_points;
    for (int i = 0; i <= n_iter - 1; i++) {
        gen_points = generate_points(gen_points);
    }
    glBegin(GL_LINES);
    for (int j = 0; j <= gen_points.size() - 2; j++) {
        glVertex2f(gen_points[j].get_x(), gen_points[j].get_y());
        glVertex2f(gen_points[j + 1].get_x(), gen_points[j + 1].get_y());
    }
    glEnd();
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Set our color to black (R, G, B)
    glColor3f(0.0f, 0.0f, 0.0f);
    
    // TODO:
    // Draw cartoon
    vector<Vertex> hairline_bottom = {Vertex(-0.082f, 0.322f), Vertex(-0.063f, 0.363f), Vertex(-0.041f, 0.398f), Vertex(-0.014f, 0.404f), Vertex(0.013f, 0.401f), Vertex(0.068f, 0.409f), Vertex(0.073f, 0.322f), Vertex(0.081f, 0.281f)};
    draw_curve(hairline_bottom, 10);
    vector<Vertex> hairline_top = {Vertex(-0.082f, 0.322f), Vertex(-0.079f, 0.371f), Vertex(-0.066f, 0.409f), Vertex(-0.048f, 0.453f), Vertex(-0.02f, 0.473f), Vertex(0.009f, 0.476f), Vertex(0.037f, 0.47f), Vertex(0.055f, 0.441f), Vertex(0.068f, 0.409f), Vertex(0.077f, 0.371f), Vertex(0.078f, 0.281f)};
    draw_curve(hairline_top, 10);
    vector<Vertex> jaw = {Vertex(-0.063f, 0.214f), Vertex(-0.06f, 0.176f), Vertex(-0.046f, 0.141f), Vertex(-0.027f, 0.109f), Vertex(-0.005f, 0.083f), Vertex(0.022f, 0.074f), Vertex(0.044f, 0.109f), Vertex(0.057f, 0.158f), Vertex(0.065f, 0.199f), Vertex(0.067f, 0.237f)};
    draw_curve(jaw, 10);
    vector<Vertex> right_ear = {Vertex(-0.063f, 0.214f), Vertex(-0.079f, 0.231f), Vertex(-0.084f, 0.258f), Vertex(-0.086f, 0.29f), Vertex(-0.0709f, 0.301f), Vertex(-0.082f, 0.322f)};
    draw_curve(right_ear, 10);
    vector<Vertex> left_ear = {Vertex(0.067f, 0.237f), Vertex(0.081f, 0.281f)};
    draw_curve(left_ear, 10);
    vector<Vertex> nose = {Vertex(0.014f, 0.275f), Vertex(0.009f, 0.243f), Vertex(0.003f, 0.214f), Vertex(0.021f, 0.199f), Vertex(0.036f, 0.223f), Vertex(0.029f, 0.255f), Vertex(0.029f, 0.278f)};
    draw_curve(nose, 10);
    vector<Vertex> right_brow = {Vertex(-0.035f, 0.293f), Vertex(-0.02f, 0.307f), Vertex(-0.005f, 0.298f), Vertex(0.009f, 0.293f)};
    draw_curve(right_brow, 10);
    vector<Vertex> left_brow = {Vertex(0.036f, 0.29f), Vertex(0.06f, 0.284f)};
    draw_curve(left_brow, 10);
    vector<Vertex> right_eye_top = {Vertex(-0.03f, 0.275f), Vertex(-0.015f, 0.287f), Vertex(0.0f, 0.281f)};
    draw_curve(right_eye_top, 10);
    vector<Vertex> right_eye_bottom = {Vertex(-0.03f, 0.275f), Vertex(-0.025f, 0.255f), Vertex(-0.01f, 0.255f), Vertex(0.0f, 0.281f)};
    draw_curve(right_eye_bottom, 10);
    vector<Vertex> left_eye_top = {Vertex(0.031f, 0.281f), Vertex(0.045f, 0.278f), Vertex(0.057f, 0.26f)};
    draw_curve(left_eye_top, 10);
    vector<Vertex> left_eye_bottom = {Vertex(0.031f, 0.281f), Vertex(0.037f, 0.258f), Vertex(0.057f, 0.26f)};
    draw_curve(left_eye_bottom, 10);
    vector<Vertex> up_lip_top = {Vertex(-0.01f, 0.17f), Vertex(0.006f, 0.179f), Vertex(0.029f, 0.179f), Vertex(0.037f, 0.161f)};
    draw_curve(up_lip_top, 10);
    vector<Vertex> up_lip_bottom = {Vertex(-0.01f, 0.17f), Vertex(0.008f, 0.164f), Vertex(0.021f, 0.164f), Vertex(0.037f, 0.161f)};
    draw_curve(up_lip_bottom, 10);
    vector<Vertex> low_lip_bottom = {Vertex(-0.01f, 0.17f), Vertex(0.001f, 0.144f), Vertex(0.026f, 0.138f), Vertex(0.037f, 0.161f)};
    draw_curve(low_lip_bottom, 10);
    vector<Vertex> low_lip_top = {Vertex(-0.01f, 0.17f), Vertex(0.004f, 0.161f), Vertex(0.021f, 0.158f), Vertex(0.037f, 0.161f)};
    draw_curve(low_lip_top, 10);
    vector<Vertex> torso_out_right = {Vertex(-0.068f, 0.22f), Vertex(-0.064f, 0.147f), Vertex(-0.069f, 0.1f), Vertex(-0.094f, 0.08f), Vertex(-0.151f, 0.036f), Vertex(-0.197f, -0.028f), Vertex(-0.219f, -0.121f), Vertex(-0.22f, -0.247f), Vertex(-0.205f, -0.381f), Vertex(-0.199f, -0.468f)};
    draw_curve(torso_out_right, 10);
    vector<Vertex> torso_out_left = {Vertex(0.037f, 0.1f), Vertex(0.031f, 0.045f), Vertex(0.063f, 0.004f), Vertex(0.101f, -0.028f), Vertex(0.134f, -0.089f), Vertex(0.14f, -0.194f), Vertex(0.129f, -0.261f), Vertex(0.118f, -0.314f), Vertex(0.119f, -0.404f), Vertex(0.114f, -0.486f)};
    draw_curve(torso_out_left, 10);
    vector<Vertex> jersey = {Vertex(0.08f, -0.486f), Vertex(0.085f, -0.372f), Vertex(0.106f, -0.279f), Vertex(0.081f, -0.019f), Vertex(0.037f, 0.045f), Vertex(0.047f, -0.037f), Vertex(0.011f, -0.092f), Vertex(-0.015f, -0.046f), Vertex(-0.056f, 0.004f), Vertex(-0.094f, 0.077f), Vertex(-0.145f, 0.048f), Vertex(-0.105f, -0.04f), Vertex(-0.112f, -0.224f), Vertex(-0.112f, -0.489f)};
    draw_curve(jersey, 10);
    vector<Vertex> beard = {Vertex(-0.068f, 0.22f), Vertex(-0.051f, 0.217f), Vertex(-0.035f, 0.185f), Vertex(-0.028f, 0.132f), Vertex(-0.02f, 0.161f), Vertex(-0.012f, 0.193f), Vertex(0.011f, 0.199f), Vertex(0.031f, 0.193f), Vertex(0.037f, 0.176f), Vertex(0.039f, 0.144f), Vertex(0.062f, 0.179f)};
    draw_curve(beard, 10);
    vector<Vertex> right_pupil = {Vertex(-0.015f, 0.287f), Vertex(-0.01f, 0.287f), Vertex(-0.025f, 0.255f), Vertex(-0.01f, 0.255f), Vertex(-0.015f, 0.287f)};
    draw_curve(right_pupil, 10);
    vector<Vertex> left_pupil = {Vertex(0.045f, 0.278f), Vertex(0.05f, 0.274f), Vertex(0.037f, 0.258f), Vertex(0.042f, 0.258f), Vertex(0.045f, 0.278f)};
    draw_curve(left_pupil, 10);

    
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1000, 550); // Set your own window size
    glutCreateWindow("Assignment 1");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
