/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5.0);
    glLineWidth(5.0f);
}

void kamar_1(void)
{
//  depan
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(-40.0, -20.0, 55.1);
    glVertex3f(0.0, -20.0, 55.1);
    glVertex3f(0.0, 20.0, 55.1);
    glVertex3f(-40.0, 20.0, 55.1);
    glEnd();

    //  depan dalam
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, -20.0, 55.0);
    glVertex3f(0.0, -20.0, 55.0);
    glVertex3f(0.0, 20.0, 55.0);
    glVertex3f(-40.0, 20.0, 55.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(0.0, 20.0, 0.0);
    glVertex3f(-40.0, 20.0, 0.0);
    glVertex3f(-40.0, -20.0, 0.0);
    glVertex3f(0.0, -20.0, 0.0);
    glEnd();

    //kanan luar
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-0.1, 20.0, 55.0);
    glVertex3f(-0.1, -20.0, 55.0);
    glVertex3f(-0.1, -20.0, 0.0);
    glVertex3f(-0.1, 20.0, 0.0);
    glEnd();

    //kanan dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(0.0, 20.0, 55.0);
    glVertex3f(0.0, -20.0, 55.0);
    glVertex3f(0.0, -20.0, 40.0);
    glVertex3f(0.0, 20.0, 40.0);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, 20.0, 55.0);
    glVertex3f(-40.0, -20.0, 55.0);
    glVertex3f(-40.0, -20.0, 0.0);
    glVertex3f(-40.0, 20.0, 0.0);
    glEnd();

    // jendela 1 luar
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(-10.0, -15.0, 55.3);
    glVertex3f(-16.0, -15.0, 55.3);
    glVertex3f(-16.0, 11.0, 55.3);
    glVertex3f(-10.0, 11.0, 55.3);
    glEnd();

    //bingkai jendela 1 luar
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(-8.0, -17.0, 55.2);
    glVertex3f(-18.0, -17.0, 55.2);
    glVertex3f(-18.0, 13.0, 55.2);
    glVertex3f(-8.0, 13.0, 55.2);
    glEnd();

        // jendela 1 dalam
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(-10.0, -15.0, 54.7);
    glVertex3f(-16.0, -15.0, 54.7);
    glVertex3f(-16.0, 11.0, 54.7);
    glVertex3f(-10.0, 11.0, 54.7);
    glEnd();

    //bingkai jendela 1 dalam
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(-8.0, -17.0, 54.8);
    glVertex3f(-18.0, -17.0, 54.8);
    glVertex3f(-18.0, 13.0, 54.8);
    glVertex3f(-8.0, 13.0, 54.8);
    glEnd();

    // jendela 2 luar
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(-24.0, -15.0, 55.3);
    glVertex3f(-30.0, -15.0, 55.3);
    glVertex3f(-30.0, 11.0, 55.3);
    glVertex3f(-24.0, 11.0, 55.3);
    glEnd();

    //bingkai jendela 2 luar
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(-22.0, -17.0, 55.2);
    glVertex3f(-32.0, -17.0, 55.2);
    glVertex3f(-32.0, 13.0, 55.2);
    glVertex3f(-22.0, 13.0, 55.2);
    glEnd();

    //jendela 2  dalam
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(-24.0, -15.0, 54.7);
    glVertex3f(-30.0, -15.0, 54.7);
    glVertex3f(-30.0, 11.0, 54.7);
    glVertex3f(-24.0, 11.0, 54.7);
    glEnd();

    //bingkai jendela 2 dalam
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(-22.0, -17.0, 54.8);
    glVertex3f(-32.0, -17.0, 54.8);
    glVertex3f(-32.0, 13.0, 54.8);
    glVertex3f(-22.0, 13.0, 54.8);
    glEnd();

    //ventilasi 1
    /*glBegin(GL_QUADS);
    glColor3f(23/255.f, 19/255.f, 9/255.f);
    glVertex3f(-30.0, 15.0, 55.4);
    glVertex3f(-32.0, 15.0, 55.4);
    glVertex3f(-32.0, 17.0, 55.4);
    glVertex3f(-30.0, 17.0, 55.4); */
}

void ruang_tamu(void)
{
    //depan luar
    glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(0.0, 20.0, 40.1);
    glVertex3f(50.0, 20.0, 40.1);
    glVertex3f(50.0, -20.0, 40.1);
    glVertex3f(0.0, -20.0, 40.1);
    glEnd();

    //depan dalam
    glBegin(GL_POLYGON);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(0.0, 20.0, 40.0);
    glVertex3f(50.0, 20.0, 40.0);
    glVertex3f(50.0, -20.0, 40.0);
    glVertex3f(0.0, -20.0, 40.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(50.0, 20.0, 0.0);
    glVertex3f(0.0, 20.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glVertex3f(15.0, 10.0, 0.0);
    glVertex3f(15.0, -20.0, 0.0);
    glVertex3f(50.0, -20.0, 0.0);
    glEnd();

    // jendela 1 luar
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(20.0, -15.0, 40.3);
    glVertex3f(26.0, -15.0, 40.3);
    glVertex3f(26.0, 11.0, 40.3);
    glVertex3f(20.0, 11.0, 40.3);
    glEnd();

    //bingkai jendela 1 luar
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(18.0, -17.0, 40.2);
    glVertex3f(28.0, -17.0, 40.2);
    glVertex3f(28.0, 13.0, 40.2);
    glVertex3f(18.0, 13.0, 40.2);
    glEnd();

    //jendela 1 dalam
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(20.0, -15.0, 39.7);
    glVertex3f(26.0, -15.0, 39.7);
    glVertex3f(26.0, 11.0, 39.7);
    glVertex3f(20.0, 11.0, 39.7);
    glEnd();

    //bingkai jendela 1 dalam
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(18.0, -17.0, 39.8);
    glVertex3f(28.0, -17.0, 39.8);
    glVertex3f(28.0, 13.0, 39.8);
    glVertex3f(18.0, 13.0, 39.8);
    glEnd();

    //jendela 2 luar
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(32.0, -15.0, 40.3);
    glVertex3f(38.0, -15.0, 40.3);
    glVertex3f(38.0, 11.0, 40.3);
    glVertex3f(32.0, 11.0, 40.3);
    glEnd();

    //bingkai jendela 2 luar
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(30.0, -17.0, 40.2);
    glVertex3f(40.0, -17.0, 40.2);
    glVertex3f(40.0, 13.0, 40.2);
    glVertex3f(30.0, 13.0, 40.2);
    glEnd();

    //jendela 2 dalam
    glBegin(GL_QUADS);
    glColor3f(157/255.f, 68/255.f, 75/255.f);
    glVertex3f(32.0, -15.0, 39.7);
    glVertex3f(38.0, -15.0, 39.7);
    glVertex3f(38.0, 11.0, 39.7);
    glVertex3f(32.0, 11.0, 39.7);
    glEnd();

    //bingkai jendela 2 dalam
    glBegin(GL_QUADS);
    glColor3f(165/255.f, 177/255.f, 187/255.f);
    glVertex3f(30.0, -17.0, 39.8);
    glVertex3f(40.0, -17.0, 39.8);
    glVertex3f(40.0, 13.0, 39.8);
    glVertex3f(30.0, 13.0, 39.8);
    glEnd();

    //plafon teras
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 0/255.f, 128/255.f);
    glVertex3f(0.0, 20.0, 40.0);
    glVertex3f(50.0, 20.0, 40.0);
    glVertex3f(50.0, 20.0, 55.0);
    glVertex3f(0.0, 20.0, 55.0);
    glEnd();

        //pintu luar
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(0.0, 14.0, 40.3);
    glVertex3f(15.0, 14.0, 40.3);
    glVertex3f(15.0, -20.0, 40.3);
    glVertex3f(0.0, -20.0, 40.3);
    glEnd();

    //frame pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(0.0, 14.5, 40.2);
    glVertex3f(15.5, 14.5, 40.2);
    glVertex3f(15.5, -20.0, 40.2);
    glVertex3f(0.0, -20.0, 40.2);
    glEnd();

    //gagang pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(10.0, 5.0, 40.4);
    glVertex3f(10.0, 5.0, 40.4);
    glVertex3f(11.0, 6.0, 40.4);
    glVertex3f(11.0, 6.0, 40.4);
    glEnd();

    //pintu dalam
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(0.0, 14.0, 39.7);
    glVertex3f(15.0, 14.0, 39.7);
    glVertex3f(15.0, -20.0, 39.7);
    glVertex3f(0.0, -20.0, 39.7);
    glEnd();

    //frame pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(0.0, 14.5, 39.8);
    glVertex3f(15.5, 14.5, 39.8);
    glVertex3f(15.5, -20.0, 39.8);
    glVertex3f(0.0, -20.0, 39.8);
    glEnd();

    //gagang pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(10.3, 1.0, 39.6);
    glVertex3f(10.3, 1.0, 39.6);
    glVertex3f(10.3, 2.0, 39.6);
    glVertex3f(10.3, 2.0, 39.6);
    glEnd();
}

void ruang_tengah(void)
{
    //belakang luar
    glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(-40.0, 20.0, -80.1);
    glVertex3f(50.0, 20.0, -80.1);
    glVertex3f(50.0, -20.0, -80.1);
    glVertex3f(-40.0, -20.0, -80.1);
    glEnd();

    //belakang dalam
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(50.0, 20.0, -80.0);
    glVertex3f(-40.0, 20.0, -80.0);
    glVertex3f(-40.0, -20.0, -80.0);
    glVertex3f(50.0, -20.0, -80.0);
    glEnd();

    //kanan luar
    glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(50.1, 20.0, -80.0);
    glVertex3f(50.1, -20.0, -80.0);
    glVertex3f(50.1, -20.0, 40.0);
    glVertex3f(50.1, 20.0, 40.0);
    glVertex3f(50.1, 40.0, 0.0);
    glEnd();

    //kanan dalam
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(50.0, 20.0, -80.0);
    glVertex3f(50.0, -20.0, -80.0);
    glVertex3f(50.0, -20.0, 40.0);
    glVertex3f(50.0, 20.0, 40.0);
    glEnd();

    //kiri luar
    glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 102/255.f);
    glVertex3f(-40.1, 20.0, 55.0);
    glVertex3f(-40.1, -20.0, 55.0);
    glVertex3f(-40.1, -20.0, -80.0);
    glVertex3f(-40.1, 20.0, -80.0);
    glVertex3f(-40.1, 40.0, 0.0);
    glEnd();

    //kiri dalam
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, 20.0, 55.0);
    glVertex3f(-40.0, -20.0, 55.0);
    glVertex3f(-40.0, -20.0, -80.0);
    glVertex3f(-40.0, 20.0, -80.0);
    glEnd();

    //lantai dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-40.0, -20.0, -80.0);
    glVertex3f(50.0, -20.0, -80.0);
    glVertex3f(50.0, -20.0, 55.0);
    glVertex3f(-40.0, -20.0, 55.0);
    glEnd();

    //lantai teras
    glBegin(GL_QUADS);
    glColor3f(47/255.f, 79/255.f, 79/255.f);
    glVertex3f(0.0, -19.9, 40.0);
    glVertex3f(50.0, -19.9, 40.0);
    glVertex3f(50.0, -19.9, 55.0);
    glVertex3f(0.0, -19.9, 55.0);
    glEnd();
}

void kamar_mandi(void)
{
    //depan
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, -20.0, -45.0);
    glVertex3f(-10.0, -20.0, -45.0);
    glVertex3f(-10.0, 20.0, -45.0);
    glVertex3f(-40.0, 20.0, -45.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-10.0, -20.0, -45.0);
    glVertex3f(-10.0, -20.0, -80.0);
    glVertex3f(-10.0, 20.0, -80.0);
    glVertex3f(-10.0, 20.0, -45.0);
    glEnd();

    //pintu luar
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(-9.8, 14.0, -45.0);
    glVertex3f(-9.8, 14.0, -60.0);
    glVertex3f(-9.8, -20.0, -60.0);
    glVertex3f(-9.8, -20.0, -45.0);
    glEnd();

    //frame pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-9.9, 15.0, -45.0);
    glVertex3f(-9.9, 15.0, -60.5);
    glVertex3f(-9.9, -20.0, -60.5);
    glVertex3f(-9.9, -20.0, -45.0);
    glEnd();

    //gagang pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-9.7, -1.0, -55.0);
    glVertex3f(-9.7, -1.0, -56.0);
    glVertex3f(-9.7, -2.0, -56.0);
    glVertex3f(-9.7, -2.0, -55.0);
    glEnd();

        //pintu dalam
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(-10.2, 14.0, -45.0);
    glVertex3f(-10.2, 14.0, -60.0);
    glVertex3f(-10.2, -20.0, -60.0);
    glVertex3f(-10.2, -20.0, -45.0);
    glEnd();

    //frame pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-10.1, 15.0, -45.0);
    glVertex3f(-10.1, 15.0, -60.5);
    glVertex3f(-10.1, -20.0, -60.5);
    glVertex3f(-10.1, -20.0, -45.0);
    glEnd();

    //gagang pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-10.3, -1.0, -55.0);
    glVertex3f(-10.3, -1.0, -56.0);
    glVertex3f(-10.3, -2.0, -56.0);
    glVertex3f(-10.3, -2.0, -55.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, 20.0, -45.0);
    glVertex3f(-40.0, -20.0, -45.0);
    glVertex3f(-40.0, -20.0, -80.0);
    glVertex3f(-40.0, 20.0, -80.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(-40.0, -20.0, -80.0);
    glVertex3f(-10.0, -20.0, -80.0);
    glVertex3f(-10.0, 20.0, -80.0);
    glVertex3f(-40.0, 20.0, -80.0);
    glEnd();
}

void kamar_2(void)
{
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(15.0, 20.0, -40.0);
    glVertex3f(50.0, 20.0, -40.0);
    glVertex3f(50.0, -20.0, -40.0);
    glVertex3f(15.0, -20.0, -40.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0/255.f, 191/255.f, 255/255.f);
    glVertex3f(15.0, 20.0, 0.0);
    glVertex3f(15.0, 20.0, -40.0);
    glVertex3f(15.0, -20.0, -40.0);
    glVertex3f(15.0, -20.0, 0.0);
    glEnd();

    //pintu luar
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(14.8, 14.0, 0.0);
    glVertex3f(14.8, 14.0, -15.0);
    glVertex3f(14.8, -20.0, -15.0);
    glVertex3f(14.8, -20.0, 0.0);
    glEnd();

    //frame pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(14.9, 15.0, 0.0);
    glVertex3f(14.9, 15.0, -15.5);
    glVertex3f(14.9, -20.0, -15.5);
    glVertex3f(14.9, -20.0, 0.0);
    glEnd();

    //gagang pintu luar
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(14.7, -1.0, -11.0);
    glVertex3f(14.7, -1.0, -12.0);
    glVertex3f(14.7, -2.0, -12.0);
    glVertex3f(14.7, -2.0, -11.0);
    glEnd();

    //pintu dalam
    glBegin(GL_QUADS);
    glColor3f(128/255.f, 128/255.f, 128/255.f);
    glVertex3f(15.2, 14.0, 0.0);
    glVertex3f(15.2, 14.0, -15.0);
    glVertex3f(15.2, -20.0, -15.0);
    glVertex3f(15.2, -20.0, 0.0);
    glEnd();

    //frame pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(15.1, 15.0, 0.0);
    glVertex3f(15.1, 15.0, -15.5);
    glVertex3f(15.1, -20.0, -15.5);
    glVertex3f(15.1, -20.0, 0.0);
    glEnd();

    //gagang pintu dalam
    glBegin(GL_QUADS);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(15.3, -1.0, -11.0);
    glVertex3f(15.3, -1.0, -12.0);
    glVertex3f(15.3, -2.0, -12.0);
    glVertex3f(15.3, -2.0, -11.0);
    glEnd();
}

void atap(void)
{
    //plafon
    glBegin(GL_POLYGON);
    glColor3f(255/255.f, 255/255.f, 255/255.f);
    glVertex3f(-40.0, 20.1, -80.0);
    glVertex3f(50.0, 20.1, -80.0);
    glVertex3f(50.0, 20.1, 40.0);
    glVertex3f(0.0, 20.1, 40.0);
    glVertex3f(0.0, 20.1, 55.0);
    glVertex3f(-40.0, 20.1, 55.0);
    glEnd();

    //atap 1
    glBegin(GL_POLYGON);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(-40.0, 20.2, 55.0);
    glVertex3f(-40.0, 40.0, 0.0);
    glVertex3f(-40.0, 20.2, -80.0);
    glVertex3f(0.0, 20.2, -80);
    glVertex3f(0.0, 40.0, 0.0);
    glVertex3f(0.0, 20.2, 55.0);
    glEnd();

    //atap 2
    glBegin(GL_POLYGON);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(0.0, 20.2, 40.0);
    glVertex3f(0.0, 40.0, 0.0);
    glVertex3f(0.0, 20.2, -80.0);
    glVertex3f(50.0, 20.2, -80);
    glVertex3f(50.0, 40.0, 0.0);
    glVertex3f(50.0, 20.2, 40.0);
    glEnd();

    //penutup
    glBegin(GL_TRIANGLES);
    glColor3f(160/255.f, 82/255.f, 45/255.f);
    glVertex3f(0.0, 20.2, 40.0);
    glVertex3f(0.0, 40.0, 0.0);
    glVertex3f(0.0, 20.2, 55.0);
    glEnd();
}


void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    //gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    kamar_1();
    ruang_tamu();
    ruang_tengah();
    kamar_mandi();
    kamar_2();
    atap();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 3.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(3.0, 0.0, 0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0, 0.0, 0.0);
            break;
        case '7':
            glTranslatef(0.0, 3.0, 0.0);
            break;
        case '9':
            glTranslatef(0.0, -3.0, 0.0);
            break;
        case '2':
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case '8':
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case '6':
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case '4':
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        case '1':
            glRotatef(2.0, 0.0, 0.0, 1.0);
            break;
        case '3':
            glRotatef(-2.0, 0.0, 0.0, 1.0);
            break;
        case '5':
            if(is_depth)
            {
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            mouseDown = true;
            xdiff = x - yrot;
            ydiff = -y + xrot;
        }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if(mouseDown)
        {
            yrot = x - xdiff;
            xrot = y + ydiff;

            glutPostRedisplay();
        }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Obed Wibisono- 672019119");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

