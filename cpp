/** KLIK MOUSE KANAN*/

#include <windows.h>
#include <gl/glut.h>

void init(void); void ukuran(int, int);
void tampil(void); void hilang(void); void display(void);
void rangka(void);
void keyboard(unsigned char, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("TR - Robbinsons Place Manila");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}

void rangka(void)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
     glVertex3f(250.0, -90.0, 180.0);
    glVertex3f(250.0, -90.0, 180.0);
    glVertex3f(250.0, 90.0, 180.0);
    glVertex3f(250.0, 90.0, 180.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(250.0, -90.0, -180.0);
    glVertex3f(-250.0, -90.0, -180.0);
    glVertex3f(-250.0, 90.0, -180.0);
    glVertex3f(250.0, 90.0, -180.0);
    glEnd();
    
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
     glVertex3f(250.0, -90.0, -180.0);
    glVertex3f(250.0, -90.0, 180.0);
    glVertex3f(250.0, 90.0, 180.0);
    glVertex3f(250.0, 90.0, -180.0);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
     glVertex3f(-250.0, -90.0, -180.0);
    glVertex3f(-250.0, -90.0, 180.0);
    glVertex3f(-250.0, 90.0, 180.0);
    glVertex3f(-250.0, 90.0, -180.0);
    glEnd();
}

void bangunanlt1(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(450.0, -90.0, 300.0);
    glVertex3f(25.0, -90.0, 300.0);
    glVertex3f(25.0, 0.0, 300.0);
    glVertex3f(450.0, 0.0, 300.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(450.0, -90.0, 300.0);
    glVertex3f(470.0, -90.0, 820.0);
    glVertex3f(470.0, 0.0, 820.0);
    glVertex3f(450.0, 0.0, 300.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(25.0, -90.0, 300.0);
    glVertex3f(25.0, -90.0, 800.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(25.0, 0.0, 300.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(470.0, -90.0, 820.0);
    glVertex3f(25.0, -90.0, 800.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(470.0, 0.0, 820.0);
    glEnd();
    //lantai
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(470.0, -90.0, 820.0);
    glVertex3f(25.0, -90.0, 800.0);
    glVertex3f(25.0, -90.0, 300.0);
    glVertex3f(450.0, -90.0, 300.0);
    glEnd();
}

void bangunanlt2(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(245 / 255.f, 245 / 255.f, 245 / 255.f);
    glVertex3f(450.0, 0.0, 300.0);
    glVertex3f(75.0, 0.0, 300.0);
    glVertex3f(75.0, 80.0, 300.0);
    glVertex3f(450.0, 80.0, 300.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(245 / 255.f, 245 / 255.f, 245 / 255.f);
    glVertex3f(450.0, 0.0, 300.0);
    glVertex3f(450.0, 0.0, 800.0);
    glVertex3f(450.0, 80.0, 800.0);
    glVertex3f(450.0, 80.0, 300.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(245 / 255.f, 245 / 255.f, 245 / 255.f);
    glVertex3f(75.0, 0.0, 300.0);
    glVertex3f(75.0, 0.0, 800.0);
    glVertex3f(75.0, 80.0, 800.0);
    glVertex3f(75.0, 80.0, 300.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(245 / 255.f, 245 / 255.f, 245 / 255.f);
    glVertex3f(450.0, 0.0, 800.0);
    glVertex3f(75.0, 0.0, 800.0);
    glVertex3f(75.0, 80.0, 800.0);
    glVertex3f(450.0, 80.0, 800.0);
    glEnd();
    //lantai
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(450.0, 0.0, 300.0);
    glVertex3f(450.0, 0.0, 800.0);
    glVertex3f(75.0, 0.0, 800.0);
    glVertex3f(75.0, 0.0, 300.0);
    glEnd();

    //lantai luar kanan
    glBegin(GL_POLYGON);
    glColor3f(196 / 255.f, 194 / 255.f, 192 / 255.f);
    glVertex3f(470.0, 0.0, 820.0);
    glVertex3f(450.0, 0.0, 800.0);
    glVertex3f(450.0, 0.0, 300.0);
    glEnd();

    //lantai luar belakang
    glBegin(GL_POLYGON);
    glColor3f(196 / 255.f, 194 / 255.f, 192 / 255.f);
    glVertex3f(470.0, 0.0, 820.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(450.0, 0.0, 800.0);
    glEnd();

    //lantai luar kiri
    glBegin(GL_POLYGON);
    glColor3f(196 / 255.f, 194 / 255.f, 192 / 255.f);
    glVertex3f(75.0, 0.0, 800.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(25.0, 0.0, 550.0);
    glVertex3f(75.0, 0.0, 550.0);
    glEnd();
}

void ataplt2(void)
{
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(247 / 255.f, 247 / 255.f, 218 / 255.f);
    glVertex3f(450.0, 80.0, 300.0);
    glVertex3f(450.0, 80.0, 800.0);
    glVertex3f(275.0, 90.0, 800.0);
    glVertex3f(275.0, 90.0, 300.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(247 / 255.f, 247 / 255.f, 218 / 255.f);
    glVertex3f(75.0, 80.0, 300.0);
    glVertex3f(75.0, 80.0, 800.0);
    glVertex3f(275.0, 90.0, 800.0);
    glVertex3f(275.0, 90.0, 300.0);
    glEnd();
    //depan
    glBegin(GL_TRIANGLES);
    glColor3f(247 / 255.f, 247 / 255.f, 218 / 255.f);
    glVertex3f(450.0, 80.0, 300.0);
    glVertex3f(75.0, 80.0, 300.0);
    glVertex3f(275.0, 90.0, 300.0);
    glEnd();
    //belakang
    glBegin(GL_TRIANGLES);
    glColor3f(247 / 255.f, 247 / 255.f, 225.f);
    glVertex3f(450.0, 80.0, 800.0);
    glVertex3f(75.0, 80.0, 800.0);
    glVertex3f(275.0, 90.0, 800.0);
    glEnd();
}
void lorong(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(325.0, 20.0, 50.0);
    glVertex3f(240.0, 20.0, 50.0);
    glVertex3f(240.0, 70.0, 50.0);
    glVertex3f(325.0, 70.0, 50.0);
    glEnd();
    //depan miring kanan
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(350.0, 20.0, 100.0);
    glVertex3f(325.0, 20.0, 50.0);
    glVertex3f(325.0, 70.0, 50.0);
    glVertex3f(350.0, 70.0, 100.0);
    glEnd();
    //depan miring kiri
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(200.0, 20.0, 100.0);
    glVertex3f(240.0, 20.0, 50.0);
    glVertex3f(240.0, 70.0, 50.0);
    glVertex3f(200.0, 70.0, 100.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(350.0, 20.0, 100.0);
    glVertex3f(350.0, 20.0, 299.9);
    glVertex3f(350.0, 70.0, 299.9);
    glVertex3f(350.0, 70.0, 100.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(200.0, 20.0, 100.0);
    glVertex3f(200.0, 20.0, 299.9);
    glVertex3f(200.0, 70.0, 299.9);
    glVertex3f(200.0, 70.0, 100.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 240 / 255.f, 240 / 255.f);
    glVertex3f(350.0, 20.0, 299.9);
    glVertex3f(200.0, 20.0, 299.9);
    glVertex3f(200.0, 70.0, 299.9);
    glVertex3f(350.0, 70.0, 299.9);
    glEnd();
}

void lorongatap(void)
{
    //atap deoab
    glBegin(GL_TRIANGLES);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(325.0, 70.0, 50.0);
    glVertex3f(275.0, 90.0, 100.0);
    glVertex3f(225.0, 70.0, 50.0);
    glEnd();
    //atap deoab kiri
    glBegin(GL_TRIANGLES);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(200.0, 70.0, 100.0);
    glVertex3f(275.0, 90.0, 100.0);
    glVertex3f(225.0, 70.0, 50.0);
    glEnd();
    //atap deoab kanan
    glBegin(GL_TRIANGLES);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(325.0, 70.0, 50.0);
    glVertex3f(275.0, 90.0, 100.0);
    glVertex3f(350.0, 70.0, 100.0);
    glEnd();
    //atap kiri
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(200.0, 70.0, 100.0);
    glVertex3f(200.0, 70.0, 299.9);
    glVertex3f(275.0, 90.0, 299.9);
    glVertex3f(275.0, 90.0, 100.0);
    glEnd();
    //atap kanan
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(350.0, 70.0, 100.0);
    glVertex3f(350.0, 70.0, 299.9);
    glVertex3f(275.0, 90.0, 299.9);
    glVertex3f(275.0, 90.0, 100.0);
    glEnd();
    //atap belakang
    glBegin(GL_TRIANGLES);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(350.0, 70.0, 299.9);
    glVertex3f(200.0, 70.0, 299.9);
    glVertex3f(275.0, 90.0, 299.9);
    glEnd();
}

void bangunankiri(void)
{
    //depan kanan
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(30.9, 0.0, 50.0);
    glVertex3f(30.9, 0.0, 150.0);
    glVertex3f(30.9, 80.0, 150.0);
    glVertex3f(30.9, 80.0, 50.0);
    glEnd();
    //depan depan
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(30.9, 0.0, 50.0);
    glVertex3f(-50.9, 0.0, 50.0);
    glVertex3f(-50.9, 80.0, 50.0);
    glVertex3f(30.9, 80.0, 50.0);
    glEnd();
    //depan miring
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(25.9, 0.0, 200.0);
    glVertex3f(0.9, 0.0, 150.0);
    glVertex3f(0.9, 80.0, 150.0);
    glVertex3f(25.9, 80.0, 200.0);
    glEnd();
    //depan belakang
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(0.9, 0.0, 150.0);
    glVertex3f(-50.9, 0.0, 150.0);
    glVertex3f(-50.9, 80.0, 150.0);
    glVertex3f(0.9, 80.0, 150.0);
    glEnd();
    //depan kiri
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(-50.9, 0.0, 50.0);
    glVertex3f(-50.9, 0.0, 150.0);
    glVertex3f(-50.9, 80.0, 150.0);
    glVertex3f(-50.9, 80.0, 50.0);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(74.9, 0.0, 150.0);
    glVertex3f(30.9, 0.0, 150.0);
    glVertex3f(30.9, 80.0, 150.0);
    glVertex3f(74.9, 80.0, 150.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(74.9, 0.0, 150.0);
    glVertex3f(74.9, 0.0, 550.0);
    glVertex3f(74.9, 80.0, 550.0);
    glVertex3f(74.9, 80.0, 150.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(25.9, 0.0, 200.0);
    glVertex3f(25.9, 0.0, 450.0);
    glVertex3f(25.9, 80.0, 450.0);
    glVertex3f(25.9, 80.0, 200.0);
    glEnd();
    //belakang kiri
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(0.9, 0.0, 450.0);
    glVertex3f(0.9, 0.0, 550.0);
    glVertex3f(0.9, 80.0, 550.0);
    glVertex3f(0.9, 80.0, 450.0);
    glEnd();
    //belakang depan
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(74.9, 0.0, 550.0);
    glVertex3f(0.9, 0.0, 550.0);
    glVertex3f(0.9, 80.0, 550.0);
    glVertex3f(74.9, 80.0, 550.0);
    glEnd();
    //belakang belakang
    glBegin(GL_POLYGON);
    glColor3f(180 / 255.f, 175 / 255.f, 171 / 255.f);
    glVertex3f(25.9, 0.0, 450.0);
    glVertex3f(0.9, 0.0, 450.0);
    glVertex3f(0.9, 80.0, 450.0);
    glVertex3f(25.9, 80.0, 450.0);
    glEnd();

    //lantai bagian bawah
    glBegin(GL_POLYGON);
    glColor3f(224 / 255.f, 224 / 255.f, 224 / 255.f);
    glVertex3f(-50.9, 0.0, 50.0);
    glVertex3f(-50.9, 0.0, 150.0);
    glVertex3f(0.9, 0.0, 150.0);
    glVertex3f(25.9, 0.0, 200.0);
    glVertex3f(30.9, 0.0, 150.0);
    glVertex3f(30.9, 0.0, 50.0);
    glEnd();

    //lantai bagian bawah
    glBegin(GL_POLYGON);
    glVertex3f(25.9, 0.0, 450.0);
    glVertex3f(0.9, 0.0, 450.0);
    glVertex3f(0.9, 0.0, 550.0);
    glVertex3f(75.9, 0.0, 550.0);
    glVertex3f(74.9, 0.0, 150.0);
    glVertex3f(25.9, 0.0, 150.0);
    glEnd();

    //lantai bagian atas
    glBegin(GL_POLYGON);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-50.9, 80.0, 50.0);
    glVertex3f(-50.9, 80.0, 150.0);
    glVertex3f(0.9, 80.0, 150.0);
    glVertex3f(25.9, 80.0, 200.0);
    glVertex3f(30.9, 80.0, 150.0);
    glVertex3f(30.9, 80.0, 50.0);
    glEnd();

    //lantai bagian atas
    glBegin(GL_POLYGON);
    glVertex3f(25.9, 80.0, 450.0);
    glVertex3f(0.9, 80.0, 450.0);
    glVertex3f(0.9, 80.0, 550.0);
    glVertex3f(75.9, 80.0, 550.0);
    glVertex3f(74.9, 80.0, 150.0);
    glVertex3f(25.9, 80.0, 150.0);
    glEnd();
}

void lantaibaru(void)
{
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(450.0, -90.0, -450.0);
    glVertex3f(450.0, -90.0, 300.0);
    glVertex3f(450.0, 20.0, 300.0);
    glVertex3f(450.0, 20.0, -450.0);
    glEnd();
}

void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    rangka();
    lantaibaru();
    bangunanlt1();
    bangunanlt2();
    lorong();
    bangunankiri();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rangka();
    lantaibaru();
    bangunanlt1();
    bangunanlt2();
    ataplt2();
    lorong();
    lorongatap();
    bangunankiri();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void display(void)
{
    if (is_depth)
        tampil();
    else
        hilang();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case'w':
    case'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case'd':
    case'D':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case's':
    case'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case'a':
    case'A':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case'7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case'9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case'2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case'8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case'6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case'4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case'1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case'3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case'5':
        if (is_depth)
        {
            is_depth = 0;
            tampil();
        }
        else
        {
            is_depth = 1;
            hilang();
        }
        break;
    }
    display();
}

void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void putar()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    putar();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, lebar / tinggi, 5.0, 1000.0);
    glTranslatef(0.0, -5.0, -300.0);
    glMatrixMode(GL_MODELVIEW);
}

