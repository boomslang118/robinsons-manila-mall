/** KLIK MOUSE KANAN*/

//Obed Wibisono (672019119)
//Adhi Satrio Wibowo (672019145)
//Berliana Nala Cantika (672019146)
//Russel Davis Putirulan (672019170)

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
    glPointSize(5.0);
    glLineWidth(3.0f);
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
    
    //lantai parkiran
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(25.0, 0.0, 300.0);
    glVertex3f(450.0, 0.0, 300.0);
    glVertex3f(450.0, 0.0, 0.0);
    glVertex3f(25.0, 0.0, 0.0);
    glEnd();

    //lantai bawah parkiran
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(25.0, -90.0, 300.0);
    glVertex3f(450.0, -90.0, 300.0);
    glVertex3f(450.0, -90.0, 0.0);
    glVertex3f(25.0, -90.0, 0.0);
    glEnd();
    
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(25.0, -90.0, 0.0);
    glVertex3f(25.0, -90.0, 800.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(25.0, 0.0, 0.0);
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

void parkiran(void)
{
    //atap
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(450.0, 0.0, 0.0);
    glVertex3f(450.0, 0.0, -530.0);
    glVertex3f(0.0, 0.0, -530.0);
    glVertex3f(0.0, 0.0, -300.0);
    glVertex3f(0.0, 0.0, -300.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(450.0, 0.0, 0.0);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(240/255.f, 240/255.f, 240/255.f);
    glVertex3f(0.0, -90.0, -301.0);
    glVertex3f(0.0, -90.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -301.0);
    glVertex3f(-100.0, 0.0, -300.0);
    glVertex3f(-100.0, -90.0, -300.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(240/255.f, 240/255.f, 240/255.f);
    glVertex3f(-99.0, -90.0, -530.0);
    glVertex3f(-99.0, -90.0, -300.0);
    glVertex3f(-99.0, 0.0, -300.0);
    glVertex3f(-99.0, 0.0, -530.0);

    //kanan
    glBegin(GL_QUADS);
    glColor3f(240/255.f, 240/255.f, 240/255.f);
    glVertex3f(450.0, 35.0, -530.0);
    glVertex3f(450.0, 35.0, 300.0);
    glVertex3f(450.0, -90.0, 300.0);
    glVertex3f(450.0, -90.0, -530.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(240/255.f, 240/255.f, 240/255.f);
    glVertex3f(450.0, 0.0, -530.0);
    glVertex3f(-100.0, 0.0, -530.0);
    glVertex3f(-100.0, -90.0, -530.0);
    glVertex3f(450.0, -90.0, -530.0);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
    glColor3f(240/255.f, 240/255.f, 240/255.f);
    glVertex3f(450.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, -90.0, 0.0);
    glVertex3f(450.0, -90.0, 0.0);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(450.0, -90.0, -530.0);
    glVertex3f(450.0, -90.0, 0.0);
    glVertex3f(0.0, -90.0, 0.0);
    glVertex3f(0.0, -90.0, -530.0);
    glEnd();

    //atap2
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(0.0, 0.0, -530.0);
    glVertex3f(-100.0, 0.0, -530.0);
    glVertex3f(-100.0, 0.0, -300.0);
    glVertex3f(0.0, 0.0, -300.0);
    glEnd();

    //bawah2
    glBegin(GL_POLYGON);
    glColor3f(209/255.f, 207/255.f, 207/255.f);
    glVertex3f(0.0, -90.0, -530.0);
    glVertex3f(-100.0, -90.0, -530.0);
    glVertex3f(-100.0, -90.0, -300.0);
    glVertex3f(0.0, -90.0, -300.0);
    glEnd();

}

void bangunan2(void)
{
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(0.0, 0.0, -430.0);
    glVertex3f(50.0, 0.0, -530.0);
    glVertex3f(50.0, 30.0, -530.0);
    glVertex3f(0.0, 30.0, -430.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(200.0, 0.0, -430.0);
    glVertex3f(150.0, 0.0, -530.0);
    glVertex3f(150.0, 30.0, -530.0);
    glVertex3f(200.0, 30.0, -430.0);
    glEnd();

    //kiri1
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(25.0, 0.0, -480.0);
    glVertex3f(50.0, 0.0, -530.0);
    glVertex3f(50.0, 60.0, -530.0);
    glVertex3f(25.0, 60.0, -480.0);
    glEnd();

    //kanan1
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(175.0, 30.0, -480.0);
    glVertex3f(150.0, 30.0, -530.0);
    glVertex3f(150.0, 60.0, -530.0);
    glVertex3f(175.0, 60.0, -480.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    glColor3f(240 / 255.f, 252 / 255.f, 164 / 255.f);
    glVertex3f(150.0, 0.0, -530.0);
    glVertex3f(50.0, 0.0, -530.0);
    glVertex3f(50.0, 60.0, -530.0);
    glVertex3f(150.0, 60.0, -530.0);
    glEnd();
}

void gedung_tengah(void)
{
    //depan1
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(-100.0, -90.0, 75.0);
    glVertex3f(-100.0, 120.0, 75.0);
    glVertex3f(-400.0, 120.0, 75.0);
    glEnd();

    //depan2
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-100.0, -90.0, -10.0);
    glVertex3f(-40.0, -90.0, -10.0);
    glVertex3f(-40.0, 80.0, -10.0);
    glVertex3f(-100.0, 80.0, -10.0);
    glEnd();

    //belakang1
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-150.0, -90.0, -400.0);
    glVertex3f(-400.0, -90.0, -400.0);
    glVertex3f(-400.0, 120.0, -400.0);
    glVertex3f(-150.0, 120.0, -400.0);
    glEnd();

    //belakang2
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-40.0, -90.0, -230.0);
    glVertex3f(-100.0, -90.0, -230.0);
    glVertex3f(-100.0, 80.0, -230.0);
    glVertex3f(-40.0, 80.0, -230.0);
    glEnd();

    //kanan2
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-40.0, -90.0, -230.0);
    glVertex3f(-40.0, -90.0, -10.0);
    glVertex3f(-40.0, 80.0, -10.0);
    glVertex3f(-40.0, 80.0, -230.0);
    glEnd();

    //bawah2
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-40.0, -90.0, -230.0);
    glVertex3f(-100.0, -90.0, -230.0);
    glVertex3f(-100.0, -90.0, -10.0);
    glVertex3f(-40.0, -90.0, -10.0);
    glEnd();

    //atas2
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-40.0, 80.0, -230.0);
    glVertex3f(-100.0, 80.0, -230.0);
    glVertex3f(-100.0, 80.0, -10.0);
    glVertex3f(-40.0, 80.0, -10.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-100.0, -90.0, -300.0);
    glVertex3f(-100.0, -90.0, 75.0);
    glVertex3f(-100.0, 120.0, 75.0);
    glVertex3f(-100.0, 120.0, -300.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-100.0, -90.0, -300.0);
    glVertex3f(-150.0, -90.0, -300.0);
    glVertex3f(-150.0, 120.0, -300.0);
    glVertex3f(-100.0, 120.0, -300.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-150.0, -90.0, -400.0);
    glVertex3f(-150.0, -90.0, -300.0);
    glVertex3f(-150.0, 120.0, -300.0);
    glVertex3f(-150.0, 120.0, -400.0);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-400.0, -90.0, -400.0);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(-400.0, 120.0, 75.0);
    glVertex3f(-400.0, 120.0, -400.0);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(-100.0, -90.0, 75.0);
    glVertex3f(-100.0, -90.0, -300.0);
    glVertex3f(-150.0, -90.0, -300.0);
    glVertex3f(-150.0, -90.0, -400.0);
    glVertex3f(-400.0, -90.0, -400.0);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-400.0, 120.0, 75.0);
    glVertex3f(-100.0, 120.0, 75.0);
    glVertex3f(-100.0, 120.0, -300.0);
    glVertex3f(-150.0, 120.0, -300.0);
    glVertex3f(-150.0, 120.0, -400.0);
    glVertex3f(-400.0, 120.0, -400.0);
    glEnd();

}

void tiang(void)
{
    //tiang 1 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-360.0, -90.0, -410.0);
    glVertex3f(-350.0, -90.0, -410.0);
    glVertex3f(-350.0, -20.0, -410.0);
    glVertex3f(-360.0, -20.0, -410.0);
    glEnd();

    //tiang 1 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-350.0, -90.0, -420.0);
    glVertex3f(-360.0, -90.0, -420.0);
    glVertex3f(-360.0, -20.0, -420.0);
    glVertex3f(-350.0, -20.0, -420.0);
    glEnd();

    //tiang 1 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-350.0, -90.0, -420.0);
    glVertex3f(-350.0, -90.0, -410.0);
    glVertex3f(-350.0, -20.0, -410.0);
    glVertex3f(-350.0, -20.0, -420.0);
    glEnd();

    //tiang 1 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-360.0, -90.0, -420.0);
    glVertex3f(-360.0, -90.0, -410.0);
    glVertex3f(-360.0, -20.0, -410.0);
    glVertex3f(-360.0, -20.0, -420.0);
    glEnd();

    //tiang 2 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-290.0, -90.0, -410.0);
    glVertex3f(-280.0, -90.0, -410.0);
    glVertex3f(-280.0, -20.0, -410.0);
    glVertex3f(-290.0, -20.0, -410.0);
    glEnd();

    //tiang 2 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-280.0, -90.0, -420.0);
    glVertex3f(-290.0, -90.0, -420.0);
    glVertex3f(-290.0, -20.0, -420.0);
    glVertex3f(-280.0, -20.0, -420.0);
    glEnd();

    //tiang 2 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-280.0, -90.0, -420.0);
    glVertex3f(-280.0, -90.0, -410.0);
    glVertex3f(-280.0, -20.0, -410.0);
    glVertex3f(-280.0, -20.0, -420.0);
    glEnd();

    //tiang 2 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-290.0, -90.0, -420.0);
    glVertex3f(-290.0, -90.0, -410.0);
    glVertex3f(-290.0, -20.0, -410.0);
    glVertex3f(-290.0, -20.0, -420.0);
    glEnd();

    //tiang 3 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-290.0, -90.0, -510.0);
    glVertex3f(-280.0, -90.0, -510.0);
    glVertex3f(-280.0, -20.0, -510.0);
    glVertex3f(-290.0, -20.0, -510.0);
    glEnd();

    //tiang 3 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-280.0, -90.0, -520.0);
    glVertex3f(-290.0, -90.0, -520.0);
    glVertex3f(-290.0, -20.0, -520.0);
    glVertex3f(-280.0, -20.0, -520.0);
    glEnd();

    //tiang 3 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-280.0, -90.0, -520.0);
    glVertex3f(-280.0, -90.0, -510.0);
    glVertex3f(-280.0, -20.0, -510.0);
    glVertex3f(-280.0, -20.0, -520.0);
    glEnd();

    //tiang 3 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-290.0, -90.0, -520.0);
    glVertex3f(-290.0, -90.0, -510.0);
    glVertex3f(-290.0, -20.0, -510.0);
    glVertex3f(-290.0, -20.0, -520.0);
    glEnd();

    //tiang 4 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-360.0, -90.0, -510.0);
    glVertex3f(-350.0, -90.0, -510.0);
    glVertex3f(-350.0, -20.0, -510.0);
    glVertex3f(-360.0, -20.0, -510.0);
    glEnd();

    //tiang 4 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-350.0, -90.0, -520.0);
    glVertex3f(-360.0, -90.0, -520.0);
    glVertex3f(-360.0, -20.0, -520.0);
    glVertex3f(-350.0, -20.0, -520.0);
    glEnd();

    //tiang 4 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-350.0, -90.0, -520.0);
    glVertex3f(-350.0, -90.0, -510.0);
    glVertex3f(-350.0, -20.0, -510.0);
    glVertex3f(-350.0, -20.0, -520.0);
    glEnd();

    //tiang 4 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-360.0, -90.0, -520.0);
    glVertex3f(-360.0, -90.0, -510.0);
    glVertex3f(-360.0, -20.0, -510.0);
    glVertex3f(-360.0, -20.0, -520.0);
    glEnd();
}

void bangunan1(void)
{
    //bawah
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-370.0, -20.0, -530.0);
    glVertex3f(-270.0, -20.0, -530.0);
    glVertex3f(-270.0, -20.0, -400.0);
    glVertex3f(-370.0, -20.0, -400.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-270.0, -20.0, -400.0);
    glVertex3f(-270.0, -20.0, -530.0);
    glVertex3f(-270.0, 80.0, -530.0);
    glVertex3f(-270.0, 80.0, -400.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-370.0, -20.0, -400.0);
    glVertex3f(-370.0, -20.0, -530.0);
    glVertex3f(-370.0, 80.0, -530.0);
    glVertex3f(-370.0, 80.0, -400.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-370.0, 70.0, -530.0);
    glVertex3f(-270.0, 70.0, -530.0);
    glVertex3f(-270.0, 80.0, -400.0);
    glVertex3f(-370.0, 80.0, -400.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-370.1, 0.0, -530.0);
    glVertex3f(-370.1, 0.0, -400.0);
    glVertex3f(-370.1, 20.0, -530.0);
    glVertex3f(-370.1, 20.0, -400.0);
    glVertex3f(-370.1, 40.0, -530.0);
    glVertex3f(-370.1, 40.0, -400.0);
    glVertex3f(-370.1, 60.0, -530.0);
    glVertex3f(-370.1, 60.0, -400.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-370.1, -20.0, -510.0);
    glVertex3f(-370.1, 80.0, -510.0);
    glVertex3f(-370.1, -20.0, -490.0);
    glVertex3f(-370.1, 80.0, -490.0);
    glVertex3f(-370.1, -20.0, -470.0);
    glVertex3f(-370.1, 80.0, -470.0);
    glVertex3f(-370.1, -20.0, -450.0);
    glVertex3f(-370.1, 80.0, -450.0);
    glVertex3f(-370.1, -20.0, -430.0);
    glVertex3f(-370.1, 80.0, -430.0);
    glVertex3f(-370.1, -20.0, -410.0);
    glVertex3f(-370.1, 80.0, -410.0);
    glEnd();
}

void gedung_belakang(void)
{
    //depan1
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-420.0, -90.0, -570.0);
    glVertex3f(500.0, -90.0, -570.0);
    glVertex3f(500.0, -20.0, -570.0);
    glVertex3f(-420.0, -20.0, -570.0);
    glEnd();

    //belakang1
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(500.0, -90.0, -920.0);
    glVertex3f(-420.0, -90.0, -920.0);
    glVertex3f(-420.0, -20.0, -920.0);
    glVertex3f(500.0, -20.0, -920.0);
    glEnd();

    //kanan1
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(500.0, -90.0, -570.0);
    glVertex3f(500.0, -90.0, -920.0);
    glVertex3f(500.0, -20.0, -920.0);
    glVertex3f(500.0, -20.0, -570.0);
    glEnd();


    //kiri1
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-420.0, -90.0, -570.0);
    glVertex3f(-420.0, -90.0, -920.0);
    glVertex3f(-420.0, -20.0, -920.0);
    glVertex3f(-420.0, -20.0, -570.0);
    glEnd();

    //atas1
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-500.0, -20.0, -1000.0);
    glVertex3f(500.0, -20.0, -1000.0);
    glVertex3f(500.0, -20.0, -530.0);
    glVertex3f(-500.0, -20.0, -530.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.0, -90.0, -920.0);
    glVertex3f(500.0, -90.0, -920.0);
    glVertex3f(500.0, -90.0, -570.0);
    glVertex3f(-420.0, -90.0, -570.0);
    glEnd();

    //depan2
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-500.0, -20.0, -530.0);
    glVertex3f(500.0, -20.0, -530.0);
    glVertex3f(500.0, 90.0, -530.0);
    glVertex3f(-500.0, 90.0, -530.0);
    glEnd();

    //kanan2
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(500.0, -20.0, -1000.0);
    glVertex3f(500.0, -20.0, -530.0);
    glVertex3f(500.0, 90.0, -530.0);
    glVertex3f(500.0, 90.0, -1000.0);
    glEnd();

    //kiri2
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(-500.0, -20.0, -1000.0);
    glVertex3f(-500.0, -20.0, -530.0);
    glVertex3f(-500.0, 90.0, -530.0);
    glVertex3f(-500.0, 90.0, -1000.0);
    glEnd();

    //belakang2
    glBegin(GL_QUADS);
    glColor3f(232/255.f, 223/255.f, 176/255.f);
    glVertex3f(500.0, -20.0, -1000.0);
    glVertex3f(-500.0, -20.0, -1000.0);
    glVertex3f(-500.0, 90.0, -1000.0);
    glVertex3f(500.0, 90.0, -1000.0);
    glEnd();

    //pintu 1 bagian luar
    glBegin(GL_QUADS);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-420.1, -90.0, -625.0);
    glVertex3f(-420.1, -90.0, -575.0);
    glVertex3f(-420.1, -30.0, -575.0);
    glVertex3f(-420.1, -30.0, -625.0);
    glEnd();

    //bagian pintu 1 luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -90.0, -625.0);
    glVertex3f(-420.2, -30.0, -625.0);
    glVertex3f(-420.2, -30.0, -625.0);
    glVertex3f(-420.2, -30.0, -575.0);
    glVertex3f(-420.2, -30.0, -575.0);
    glVertex3f(-420.2, -90.0, -575.0);
    glVertex3f(-420.2, -90.0, -575.0);
    glVertex3f(-420.2, -90.0, -625.0);
    glVertex3f(-420.2, -30.0, -600.0);
    glVertex3f(-420.2, -90.0, -600.0);
    glEnd();

    //gagang pintu 1 luar
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -60.0, -601.0);
    glVertex3f(-420.2, -60.0, -599.0);
    glEnd();

    //pintu 1 bagian dalam
    glBegin(GL_QUADS);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-419.9, -90.0, -625.0);
    glVertex3f(-419.9, -90.0, -575.0);
    glVertex3f(-419.9, -30.0, -575.0);
    glVertex3f(-419.9, -30.0, -625.0);
    glEnd();

    //bagian pintu 1 dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.8, -90.0, -625.0);
    glVertex3f(-419.8, -30.0, -625.0);
    glVertex3f(-419.8, -30.0, -625.0);
    glVertex3f(-419.8, -30.0, -575.0);
    glVertex3f(-419.8, -30.0, -575.0);
    glVertex3f(-419.8, -90.0, -575.0);
    glVertex3f(-419.8, -90.0, -575.0);
    glVertex3f(-419.8, -90.0, -625.0);
    glVertex3f(-419.8, -30.0, -600.0);
    glVertex3f(-419.8, -90.0, -600.0);
    glEnd();

    //gagang pintu 1 dalam
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.8, -60.0, -601.0);
    glVertex3f(-419.8, -60.0, -599.0);
    glEnd();

    //pintu 2 bagian luar
    glBegin(GL_QUADS);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-420.1, -90.0, -825.0);
    glVertex3f(-420.1, -90.0, -775.0);
    glVertex3f(-420.1, -30.0, -775.0);
    glVertex3f(-420.1, -30.0, -825.0);
    glEnd();

    //bagian pintu 2 luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -90.0, -825.0);
    glVertex3f(-420.2, -30.0, -825.0);
    glVertex3f(-420.2, -30.0, -825.0);
    glVertex3f(-420.2, -30.0, -775.0);
    glVertex3f(-420.2, -30.0, -775.0);
    glVertex3f(-420.2, -90.0, -775.0);
    glVertex3f(-420.2, -90.0, -775.0);
    glVertex3f(-420.2, -90.0, -825.0);
    glVertex3f(-420.2, -30.0, -800.0);
    glVertex3f(-420.2, -90.0, -800.0);
    glEnd();

    //gagang pintu 2 luar
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -60.0, -801.0);
    glVertex3f(-420.2, -60.0, -799.0);
    glEnd();

    //pintu 2 bagian dalam
    glBegin(GL_QUADS);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glEnd();

    //bagian pintu 2 dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -30.0, -800.0);
    glVertex3f(-419.9, -90.0, -800.0);
    glEnd();

    //gagang pintu 2 dalam
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.8, -60.0, -801.0);
    glVertex3f(-419.8, -60.0, -799.0);
    glEnd();

    //pintu gudang 1 bagian belakang
    glBegin(GL_QUADS);
    glColor3f(171/255.f, 89/255.f, 79/255.f);
    glVertex3f(380.0, -90.0, -920.1);
    glVertex3f(480.0, -90.0, -920.1);
    glVertex3f(480.0, -20.0, -920.1);
    glVertex3f(380.0, -20.0, -920.1);
    glEnd();

    //pintu gudang 2 bagian belakang
    glBegin(GL_QUADS);
    glColor3f(171/255.f, 89/255.f, 79/255.f);
    glVertex3f(240.0, -90.0, -920.1);
    glVertex3f(340.0, -90.0, -920.1);
    glVertex3f(340.0, -20.0, -920.1);
    glVertex3f(240.0, -20.0, -920.1);
    glEnd();

    //pintu gudang 3 bagian belakang
    glBegin(GL_POLYGON);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-100.0, -90.0, -920.1);
    glVertex3f(-150.0, -90.0, -920.1);
    glVertex3f(-150.0, -20.0, -920.1);
    glVertex3f(-100.0, -20.0, -920.1);
    glEnd();

    //pintu gudang 3 bagian belakang
    glBegin(GL_POLYGON);
    glColor3f(224/255.f, 224/255.f, 224/255.f);
    glVertex3f(-150.0, -90.0, -920.1);
    glVertex3f(-200.0, -90.0, -920.1);
    glVertex3f(-200.0, -20.0, -920.1);
    glVertex3f(-150.0, -20.0, -920.1);
    glEnd();
}

void jendela(void)
{
    //jendela 1 samping kiri bagian luar
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-420.1, -90.0, -675.0);
    glVertex3f(-420.1, -90.0, -625.0);
    glVertex3f(-420.1, -30.0, -625.0);
    glVertex3f(-420.1, -30.0, -675.0);
    glEnd();

    //bagian jendela 1 samping kiri luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -90.0, -675.0);
    glVertex3f(-420.2, -30.0, -675.0);
    glVertex3f(-420.2, -30.0, -675.0);
    glVertex3f(-420.2, -30.0, -625.0);
    glVertex3f(-420.2, -30.0, -625.0);
    glVertex3f(-420.2, -90.0, -625.0);
    glVertex3f(-420.2, -90.0, -625.0);
    glVertex3f(-420.2, -90.0, -675.0);
    glVertex3f(-420.2, -30.0, -650.0);
    glVertex3f(-420.2, -90.0, -650.0);
    glEnd();

    //jendela depan bagian luar
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-415.0, -90.0, -569.9);
    glVertex3f(-365.0, -90.0, -569.9);
    glVertex3f(-365.0, -30.0, -569.9);
    glVertex3f(-415.0, -30.0, -569.9);
    glEnd();

    //bagian jendela depan luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-415.0, -90.0, -569.9);
    glVertex3f(-415.0, -30.0, -569.9);
    glVertex3f(-415.0, -30.0, -569.9);
    glVertex3f(-365.0, -30.0, -569.9);
    glVertex3f(-365.0, -30.0, -569.9);
    glVertex3f(-365.0, -90.0, -569.9);
    glVertex3f(-365.0, -90.0, -569.9);
    glVertex3f(-415.0, -90.0, -569.9);
    glVertex3f(-390.0, -30.0, -569.9);
    glVertex3f(-390.0, -90.0, -569.9);
    glEnd();

    //jendela 1 samping kiri bagian dalam
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-419.9, -90.0, -675.0);
    glVertex3f(-419.9, -90.0, -625.0);
    glVertex3f(-419.9, -30.0, -625.0);
    glVertex3f(-419.9, -30.0, -675.0);
    glEnd();

    //bagian jendela 1 samping kiri dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.8, -90.0, -675.0);
    glVertex3f(-419.8, -30.0, -675.0);
    glVertex3f(-419.8, -30.0, -675.0);
    glVertex3f(-419.8, -30.0, -625.0);
    glVertex3f(-419.8, -30.0, -625.0);
    glVertex3f(-419.8, -90.0, -625.0);
    glVertex3f(-419.8, -90.0, -625.0);
    glVertex3f(-419.8, -90.0, -675.0);
    glVertex3f(-419.8, -30.0, -650.0);
    glVertex3f(-419.8, -90.0, -650.0);
    glEnd();

    //jendela depan bagian dalam
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-415.0, -90.0, -570.1);
    glVertex3f(-365.0, -90.0, -570.1);
    glVertex3f(-365.0, -30.0, -570.1);
    glVertex3f(-415.0, -30.0, -570.1);
    glEnd();

    //bagian jendela depan dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-415.0, -90.0, -570.2);
    glVertex3f(-415.0, -30.0, -570.2);
    glVertex3f(-415.0, -30.0, -570.2);
    glVertex3f(-365.0, -30.0, -570.2);
    glVertex3f(-365.0, -30.0, -570.2);
    glVertex3f(-365.0, -90.0, -570.2);
    glVertex3f(-365.0, -90.0, -570.2);
    glVertex3f(-415.0, -90.0, -570.2);
    glVertex3f(-390.0, -30.0, -570.2);
    glVertex3f(-390.0, -90.0, -570.2);
    glEnd();

    //jendela 2 samping kiri bagian luar
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-420.1, -90.0, -775.0);
    glVertex3f(-420.1, -90.0, -700.0);
    glVertex3f(-420.1, -30.0, -700.0);
    glVertex3f(-420.1, -30.0, -775.0);
    glEnd();

    //bagian jendela 2 samping kiri luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -90.0, -775.0);
    glVertex3f(-420.2, -30.0, -775.0);
    glVertex3f(-420.2, -30.0, -775.0);
    glVertex3f(-420.2, -30.0, -700.0);
    glVertex3f(-420.2, -30.0, -700.0);
    glVertex3f(-420.2, -90.0, -700.0);
    glVertex3f(-420.2, -90.0, -700.0);
    glVertex3f(-420.2, -90.0, -775.0);
    glVertex3f(-420.2, -30.0, -725.0);
    glVertex3f(-420.2, -90.0, -725.0);
    glVertex3f(-420.2, -30.0, -750.0);
    glVertex3f(-420.2, -90.0, -750.0);
    glEnd();

    //jendela 2 samping kiri bagian dalam
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -90.0, -700.0);
    glVertex3f(-419.9, -30.0, -700.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glEnd();

    //bagian jendela 2 samping kiri dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glVertex3f(-419.9, -30.0, -775.0);
    glVertex3f(-419.9, -30.0, -700.0);
    glVertex3f(-419.9, -30.0, -700.0);
    glVertex3f(-419.9, -90.0, -700.0);
    glVertex3f(-419.9, -90.0, -700.0);
    glVertex3f(-419.9, -90.0, -775.0);
    glVertex3f(-419.9, -30.0, -725.0);
    glVertex3f(-419.9, -90.0, -725.0);
    glVertex3f(-419.9, -30.0, -750.0);
    glVertex3f(-419.9, -90.0, -750.0);
    glEnd();

    //jendela 3 samping kiri bagian luar
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-420.1, -90.0, -900.0);
    glVertex3f(-420.1, -90.0, -825.0);
    glVertex3f(-420.1, -30.0, -825.0);
    glVertex3f(-420.1, -30.0, -900.0);
    glEnd();

    //bagian jendela 3 samping kiri luar
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-420.2, -90.0, -900.0);
    glVertex3f(-420.2, -30.0, -900.0);
    glVertex3f(-420.2, -30.0, -900.0);
    glVertex3f(-420.2, -30.0, -825.0);
    glVertex3f(-420.2, -30.0, -825.0);
    glVertex3f(-420.2, -90.0, -825.0);
    glVertex3f(-420.2, -90.0, -825.0);
    glVertex3f(-420.2, -90.0, -900.0);
    glVertex3f(-420.2, -30.0, -850.0);
    glVertex3f(-420.2, -90.0, -850.0);
    glVertex3f(-420.2, -30.0, -875.0);
    glVertex3f(-420.2, -90.0, -875.0);
    glEnd();

    //jendela 3 samping kiri bagian dalam
    glBegin(GL_QUADS);
    glColor3f(153/255.f, 153/255.f, 153/255.f);
    glVertex3f(-419.9, -90.0, -900.0);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glVertex3f(-419.9, -30.0, -900.0);
    glEnd();

    //bagian jendela 3 samping kiri dalam
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-419.9, -90.0, -900.0);
    glVertex3f(-419.9, -30.0, -900.0);
    glVertex3f(-419.9, -30.0, -900.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glVertex3f(-419.9, -30.0, -825.0);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -90.0, -825.0);
    glVertex3f(-419.9, -90.0, -900.0);
    glVertex3f(-419.9, -30.0, -850.0);
    glVertex3f(-419.9, -90.0, -850.0);
    glVertex3f(-419.9, -30.0, -875.0);
    glVertex3f(-419.9, -90.0, -875.0);
    glEnd();
}

void lantai_luar(void)
{
    //lantai luar depan
    glBegin(GL_QUADS);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-505.0, -90.0, -570.0);
    glVertex3f(500.0, -90.0, -570.0);
    glVertex3f(500.0, -90.0, -515.0);
    glVertex3f(-505.0, -90.0, -515.0);
    glEnd();

    //pinggir lantai luar depan
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-510.0, -90.0, -515.0);
    glVertex3f(-360.0, -90.0, -515.0);
    glVertex3f(-360.0, -90.0, -510.0);
    glVertex3f(-510.0, -90.0, -510.0);
    glEnd();

    //bagain pinggir lantai luar depan
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-360.0, -90.0, -510.0);
    glVertex3f(-510.0, -90.0, -510.0);
    glVertex3f(-510.0, -95.0, -510.0);
    glVertex3f(-360.0, -95.0, -510.0);
    glEnd();

    //lantai luar belakang
    glBegin(GL_QUADS);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-505.0, -90.0, -1005.0);
    glVertex3f(500.0, -90.0, -1005.0);
    glVertex3f(500.0, -90.0, -920.0);
    glVertex3f(-505.0, -90.0, -920.0);
    glEnd();

    //pinggir lantai luar belakang
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-510.0, -90.0, -1010.0);
    glVertex3f(500.0, -90.0, -1010.0);
    glVertex3f(500.0, -90.0, -1005.0);
    glVertex3f(-510.0, -90.0, -1005.0);
    glEnd();

    //bagian pinggir lantai luar belakang
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-510.0, -90.0, -1010.0);
    glVertex3f(500.0, -90.0, -1010.0);
    glVertex3f(500.0, -95.0, -1010.0);
    glVertex3f(-510.0, -95.0, -1010.0);
    glEnd();

    //lantai luar samping kiri
    glBegin(GL_QUADS);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-505.0, -90.0, -1000.0);
    glVertex3f(-420.0, -90.0, -1000.0);
    glVertex3f(-420.0, -90.0, -530.0);
    glVertex3f(-505.0, -90.0, -530.0);
    glEnd();

    // pinggir lantai luar samping kiri
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-505.0, -90.0, -1010.0);
    glVertex3f(-510.0, -90.0, -1010.0);
    glVertex3f(-510.0, -90.0, -510.0);
    glVertex3f(-505.0, -90.0, -510.0);
    glEnd();

    // bagian pinggir lantai luar samping kiri
    glBegin(GL_QUADS);
    glColor3f(250/255.f, 243/255.f, 112/255.f);
    glVertex3f(-510.0, -90.0, -1010.0);
    glVertex3f(-510.0, -90.0, -510.0);
    glVertex3f(-510.0, -95.0, -510.0);
    glVertex3f(-510.0, -95.0, -1010.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-510.0, -95.0, -1010.0);
    glVertex3f(500.0, -95.0, -1010.0);
    glVertex3f(500.0, -95.0, -510.0);
    glVertex3f(-510.0, -95.0, -510.0);
    glEnd();
}

void garis_tembok(void)
{
    //garis horizontal tembok depan
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.0, 0.0, -530.0);
    glVertex3f(500.0, 0.0, -530.0);
    glVertex3f(-500.0, 20.0, -530.0);
    glVertex3f(500.0, 20.0, -530.0);
    glVertex3f(-500.0, 40.0, -530.0);
    glVertex3f(500.0, 40.0, -530.0);
    glVertex3f(-500.0, 60.0, -530.0);
    glVertex3f(500.0, 60.0, -530.0);
    glVertex3f(-500.0, 80.0, -530.0);
    glVertex3f(500.0, 80.0, -530.0);
    glEnd();

    //garis vertikal tembok depan
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.0, -20.0, -530.0);
    glVertex3f(-500.0, 90.0, -530.0);
    glVertex3f(-480.0, -20.0, -530.0);
    glVertex3f(-480.0, 90.0, -530.0);
    glVertex3f(-460.0, -20.0, -530.0);
    glVertex3f(-460.0, 90.0, -530.0);
    glVertex3f(-440.0, -20.0, -530.0);
    glVertex3f(-440.0, 90.0, -530.0);
    glVertex3f(-420.0, -20.0, -530.0);
    glVertex3f(-420.0, 90.0, -530.0);
    glVertex3f(-400.0, -20.0, -530.0);
    glVertex3f(-400.0, 90.0, -530.0);

    glVertex3f(-380.0, -20.0, -530.0);
    glVertex3f(-380.0, 90.0, -530.0);
    glVertex3f(-360.0, -20.0, -530.0);
    glVertex3f(-360.0, 90.0, -530.0);
    glVertex3f(-340.0, -20.0, -530.0);
    glVertex3f(-340.0, 90.0, -530.0);
    glVertex3f(-320.0, -20.0, -530.0);
    glVertex3f(-320.0, 90.0, -530.0);
    glVertex3f(-300.0, -20.0, -530.0);
    glVertex3f(-300.0, 90.0, -530.0);

    glVertex3f(-280.0, -20.0, -530.0);
    glVertex3f(-280.0, 90.0, -530.0);
    glVertex3f(-260.0, -20.0, -530.0);
    glVertex3f(-260.0, 90.0, -530.0);
    glVertex3f(-240.0, -20.0, -530.0);
    glVertex3f(-240.0, 90.0, -530.0);
    glVertex3f(-220.0, -20.0, -530.0);
    glVertex3f(-220.0, 90.0, -530.0);
    glVertex3f(-200.0, -20.0, -530.0);
    glVertex3f(-200.0, 90.0, -530.0);

    glVertex3f(-180.0, -20.0, -530.0);
    glVertex3f(-180.0, 90.0, -530.0);
    glVertex3f(-160.0, -20.0, -530.0);
    glVertex3f(-160.0, 90.0, -530.0);
    glVertex3f(-140.0, -20.0, -530.0);
    glVertex3f(-140.0, 90.0, -530.0);
    glVertex3f(-120.0, -20.0, -530.0);
    glVertex3f(-120.0, 90.0, -530.0);
    glVertex3f(-100.0, -20.0, -530.0);
    glVertex3f(-100.0, 90.0, -530.0);

    glVertex3f(-80.0, -20.0, -530.0);
    glVertex3f(-80.0, 90.0, -530.0);
    glVertex3f(-60.0, -20.0, -530.0);
    glVertex3f(-60.0, 90.0, -530.0);
    glVertex3f(-40.0, -20.0, -530.0);
    glVertex3f(-40.0, 90.0, -530.0);
    glVertex3f(-20.0, -20.0, -530.0);
    glVertex3f(-20.0, 90.0, -530.0);
    glVertex3f(0.0, -20.0, -530.0);
    glVertex3f(0.0, 90.0, -530.0);

    glVertex3f(20.0, -20.0, -530.0);
    glVertex3f(20.0, 90.0, -530.0);
    glVertex3f(40.0, -20.0, -530.0);
    glVertex3f(40.0, 90.0, -530.0);
    glVertex3f(60.0, -20.0, -530.0);
    glVertex3f(60.0, 90.0, -530.0);
    glVertex3f(80.0, -20.0, -530.0);
    glVertex3f(80.0, 90.0, -530.0);
    glVertex3f(100.0, -20.0, -530.0);
    glVertex3f(100.0, 90.0, -530.0);

    glVertex3f(120.0, -20.0, -530.0);
    glVertex3f(120.0, 90.0, -530.0);
    glVertex3f(140.0, -20.0, -530.0);
    glVertex3f(140.0, 90.0, -530.0);
    glVertex3f(160.0, -20.0, -530.0);
    glVertex3f(160.0, 90.0, -530.0);
    glVertex3f(180.0, -20.0, -530.0);
    glVertex3f(180.0, 90.0, -530.0);
    glVertex3f(200.0, -20.0, -530.0);
    glVertex3f(200.0, 90.0, -530.0);

    glVertex3f(220.0, -20.0, -530.0);
    glVertex3f(220.0, 90.0, -530.0);
    glVertex3f(240.0, -20.0, -530.0);
    glVertex3f(240.0, 90.0, -530.0);
    glVertex3f(260.0, -20.0, -530.0);
    glVertex3f(260.0, 90.0, -530.0);
    glVertex3f(280.0, -20.0, -530.0);
    glVertex3f(280.0, 90.0, -530.0);
    glVertex3f(300.0, -20.0, -530.0);
    glVertex3f(300.0, 90.0, -530.0);

    glVertex3f(320.0, -20.0, -530.0);
    glVertex3f(320.0, 90.0, -530.0);
    glVertex3f(340.0, -20.0, -530.0);
    glVertex3f(340.0, 90.0, -530.0);
    glVertex3f(360.0, -20.0, -530.0);
    glVertex3f(360.0, 90.0, -530.0);
    glVertex3f(380.0, -20.0, -530.0);
    glVertex3f(380.0, 90.0, -530.0);
    glVertex3f(400.0, -20.0, -530.0);
    glVertex3f(400.0, 90.0, -530.0);

    glVertex3f(420.0, -20.0, -530.0);
    glVertex3f(420.0, 90.0, -530.0);
    glVertex3f(440.0, -20.0, -530.0);
    glVertex3f(440.0, 90.0, -530.0);
    glVertex3f(460.0, -20.0, -530.0);
    glVertex3f(460.0, 90.0, -530.0);
    glVertex3f(480.0, -20.0, -530.0);
    glVertex3f(480.0, 90.0, -530.0);
    glVertex3f(500.0, -20.0, -530.0);
    glVertex3f(500.0, 90.0, -530.0);
    glEnd();

    //garis tembok samping
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.1, 0.0, -530.0);
    glVertex3f(-500.1, 0.0, -1000.0);
    glVertex3f(-500.1, 20.0, -530.0);
    glVertex3f(-500.1, 20.0, -1000.0);
    glVertex3f(-500.1, 40.0, -530.0);
    glVertex3f(-500.1, 40.0, -1000.0);
    glVertex3f(-500.1, 60.0, -530.0);
    glVertex3f(-500.1, 60.0, -1000.0);
    glVertex3f(-500.1, 80.0, -530.0);
    glVertex3f(-500.1, 80.0, -1000.0);
    glEnd();

    // bagian garis tembook samping
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.1, -20.0, -1000.0);
    glVertex3f(-500.1, 90.0, -1000.0);
    glVertex3f(-500.1, -20.0, -980.0);
    glVertex3f(-500.1, 90.0, -980.0);
    glVertex3f(-500.1, -20.0, -960.0);
    glVertex3f(-500.1, 90.0, -960.0);
    glVertex3f(-500.1, -20.0, -940.0);
    glVertex3f(-500.1, 90.0, -940.0);
    glVertex3f(-500.1, -20.0, -920.0);
    glVertex3f(-500.1, 90.0, -920.0);

    glVertex3f(-500.1, -20.0, -900.0);
    glVertex3f(-500.1, 90.0, -900.0);
    glVertex3f(-500.1, -20.0, -880.0);
    glVertex3f(-500.1, 90.0, -880.0);
    glVertex3f(-500.1, -20.0, -860.0);
    glVertex3f(-500.1, 90.0, -860.0);
    glVertex3f(-500.1, -20.0, -840.0);
    glVertex3f(-500.1, 90.0, -840.0);
    glVertex3f(-500.1, -20.0, -820.0);
    glVertex3f(-500.1, 90.0, -820.0);

    glVertex3f(-500.1, -20.0, -800.0);
    glVertex3f(-500.1, 90.0, -800.0);
    glVertex3f(-500.1, -20.0, -780.0);
    glVertex3f(-500.1, 90.0, -780.0);
    glVertex3f(-500.1, -20.0, -760.0);
    glVertex3f(-500.1, 90.0, -760.0);
    glVertex3f(-500.1, -20.0, -740.0);
    glVertex3f(-500.1, 90.0, -740.0);
    glVertex3f(-500.1, -20.0, -720.0);
    glVertex3f(-500.1, 90.0, -720.0);

    glVertex3f(-500.1, -20.0, -700.0);
    glVertex3f(-500.1, 90.0, -700.0);
    glVertex3f(-500.1, -20.0, -680.0);
    glVertex3f(-500.1, 90.0, -680.0);
    glVertex3f(-500.1, -20.0, -660.0);
    glVertex3f(-500.1, 90.0, -660.0);
    glVertex3f(-500.1, -20.0, -640.0);
    glVertex3f(-500.1, 90.0, -640.0);
    glVertex3f(-500.1, -20.0, -620.0);
    glVertex3f(-500.1, 90.0, -620.0);

    glVertex3f(-500.1, -20.0, -600.0);
    glVertex3f(-500.1, 90.0, -600.0);
    glVertex3f(-500.1, -20.0, -580.0);
    glVertex3f(-500.1, 90.0, -580.0);
    glVertex3f(-500.1, -20.0, -560.0);
    glVertex3f(-500.1, 90.0, -560.0);
    glVertex3f(-500.1, -20.0, -540.0);
    glVertex3f(-500.1, 90.0, -540.0);
    glEnd();

    //garis tembok belakang
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.0, 0.0, -1000.0);
    glVertex3f(500.0, 0.0, -1000.0);
    glVertex3f(-500.0, 20.0, -1000.0);
    glVertex3f(500.0, 20.0, -1000.0);
    glVertex3f(-500.0, 40.0, -1000.0);
    glVertex3f(500.0, 40.0, -1000.0);
    glVertex3f(-500.0, 60.0, -1000.0);
    glVertex3f(500.0, 60.0, -1000.0);
    glVertex3f(-500.0, 80.0, -1000.0);
    glVertex3f(500.0, 80.0, -1000.0);
    glEnd();

    //garis tembok depan
    glBegin(GL_LINES);
    glColor3f(201/255.f, 201/255.f, 201/255.f);
    glVertex3f(-500.0, -20.0, -1000.0);
    glVertex3f(-500.0, 90.0, -1000.0);
    glVertex3f(-480.0, -20.0, -1000.0);
    glVertex3f(-480.0, 90.0, -1000.0);
    glVertex3f(-460.0, -20.0, -1000.0);
    glVertex3f(-460.0, 90.0, -1000.0);
    glVertex3f(-440.0, -20.0, -1000.0);
    glVertex3f(-440.0, 90.0, -1000.0);
    glVertex3f(-420.0, -20.0, -1000.0);
    glVertex3f(-420.0, 90.0, -1000.0);
    glVertex3f(-400.0, -20.0, -1000.0);
    glVertex3f(-400.0, 90.0, -1000.0);

    glVertex3f(-380.0, -20.0, -1000.0);
    glVertex3f(-380.0, 90.0, -1000.0);
    glVertex3f(-360.0, -20.0, -1000.0);
    glVertex3f(-360.0, 90.0, -1000.0);
    glVertex3f(-340.0, -20.0, -1000.0);
    glVertex3f(-340.0, 90.0, -1000.0);
    glVertex3f(-320.0, -20.0, -1000.0);
    glVertex3f(-320.0, 90.0, -1000.0);
    glVertex3f(-300.0, -20.0, -1000.0);
    glVertex3f(-300.0, 90.0, -1000.0);

    glVertex3f(-280.0, -20.0, -1000.0);
    glVertex3f(-280.0, 90.0, -1000.0);
    glVertex3f(-260.0, -20.0, -1000.0);
    glVertex3f(-260.0, 90.0, -1000.0);
    glVertex3f(-240.0, -20.0, -1000.0);
    glVertex3f(-240.0, 90.0, -1000.0);
    glVertex3f(-220.0, -20.0, -1000.0);
    glVertex3f(-220.0, 90.0, -1000.0);
    glVertex3f(-200.0, -20.0, -1000.0);
    glVertex3f(-200.0, 90.0, -1000.0);

    glVertex3f(-180.0, -20.0, -1000.0);
    glVertex3f(-180.0, 90.0, -1000.0);
    glVertex3f(-160.0, -20.0, -1000.0);
    glVertex3f(-160.0, 90.0, -1000.0);
    glVertex3f(-140.0, -20.0, -1000.0);
    glVertex3f(-140.0, 90.0, -1000.0);
    glVertex3f(-120.0, -20.0, -1000.0);
    glVertex3f(-120.0, 90.0, -1000.0);
    glVertex3f(-100.0, -20.0, -1000.0);
    glVertex3f(-100.0, 90.0, -1000.0);

    glVertex3f(-80.0, -20.0, -1000.0);
    glVertex3f(-80.0, 90.0, -1000.0);
    glVertex3f(-60.0, -20.0, -1000.0);
    glVertex3f(-60.0, 90.0, -1000.0);
    glVertex3f(-40.0, -20.0, -1000.0);
    glVertex3f(-40.0, 90.0, -1000.0);
    glVertex3f(-20.0, -20.0, -1000.0);
    glVertex3f(-20.0, 90.0, -1000.0);
    glVertex3f(0.0, -20.0, -1000.0);
    glVertex3f(0.0, 90.0, -1000.0);

    glVertex3f(20.0, -20.0, -1000.0);
    glVertex3f(20.0, 90.0, -1000.0);
    glVertex3f(40.0, -20.0, -1000.0);
    glVertex3f(40.0, 90.0, -1000.0);
    glVertex3f(60.0, -20.0, -1000.0);
    glVertex3f(60.0, 90.0, -1000.0);
    glVertex3f(80.0, -20.0, -1000.0);
    glVertex3f(80.0, 90.0, -1000.0);
    glVertex3f(100.0, -20.0, -1000.0);
    glVertex3f(100.0, 90.0, -1000.0);

    glVertex3f(120.0, -20.0, -1000.0);
    glVertex3f(120.0, 90.0, -1000.0);
    glVertex3f(140.0, -20.0, -1000.0);
    glVertex3f(140.0, 90.0, -1000.0);
    glVertex3f(160.0, -20.0, -1000.0);
    glVertex3f(160.0, 90.0, -1000.0);
    glVertex3f(180.0, -20.0, -1000.0);
    glVertex3f(180.0, 90.0, -1000.0);
    glVertex3f(200.0, -20.0, -1000.0);
    glVertex3f(200.0, 90.0, -1000.0);

    glVertex3f(220.0, -20.0, -1000.0);
    glVertex3f(220.0, 90.0, -1000.0);
    glVertex3f(240.0, -20.0, -1000.0);
    glVertex3f(240.0, 90.0, -1000.0);
    glVertex3f(260.0, -20.0, -1000.0);
    glVertex3f(260.0, 90.0, -1000.0);
    glVertex3f(280.0, -20.0, -1000.0);
    glVertex3f(280.0, 90.0, -1000.0);
    glVertex3f(300.0, -20.0, -1000.0);
    glVertex3f(300.0, 90.0, -1000.0);

    glVertex3f(320.0, -20.0, -1000.0);
    glVertex3f(320.0, 90.0, -1000.0);
    glVertex3f(340.0, -20.0, -1000.0);
    glVertex3f(340.0, 90.0, -1000.0);
    glVertex3f(360.0, -20.0, -1000.0);
    glVertex3f(360.0, 90.0, -1000.0);
    glVertex3f(380.0, -20.0, -1000.0);
    glVertex3f(380.0, 90.0, -1000.0);
    glVertex3f(400.0, -20.0, -1000.0);
    glVertex3f(400.0, 90.0, -1000.0);

    glVertex3f(420.0, -20.0, -1000.0);
    glVertex3f(420.0, 90.0, -1000.0);
    glVertex3f(440.0, -20.0, -1000.0);
    glVertex3f(440.0, 90.0, -1000.0);
    glVertex3f(460.0, -20.0, -1000.0);
    glVertex3f(460.0, 90.0, -1000.0);
    glVertex3f(480.0, -20.0, -1000.0);
    glVertex3f(480.0, 90.0, -1000.0);
    glVertex3f(500.0, -20.0, -1000.0);
    glVertex3f(500.0, 90.0, -1000.0);
    glEnd();
}

void tiang_gedung_belakang(void)
{
    //tiang 1 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-380.0, -90.0, -530.0);
    glVertex3f(-390.0, -90.0, -530.0);
    glVertex3f(-390.0, -20.0, -530.0);
    glVertex3f(-380.0, -20.0, -530.0);
    glEnd();

    //tiang 1 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-390.0, -90.0, -540.0);
    glVertex3f(-380.0, -90.0, -540.0);
    glVertex3f(-380.0, -20.0, -540.0);
    glVertex3f(-390.0, -20.0, -540.0);
    glEnd();

    //tiang 1 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-380.0, -90.0, -540.0);
    glVertex3f(-380.0, -90.0, -530.0);
    glVertex3f(-380.0, -20.0, -530.0);
    glVertex3f(-380.0, -20.0, -540.0);
    glEnd();

    //tiang 1 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-390.0, -90.0, -540.0);
    glVertex3f(-390.0, -90.0, -530.0);
    glVertex3f(-390.0, -20.0, -530.0);
    glVertex3f(-390.0, -20.0, -540.0);
    glEnd();

    //tiang 2 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -530.0);
    glVertex3f(-490.0, -90.0, -530.0);
    glVertex3f(-490.0, -20.0, -530.0);
    glVertex3f(-500.0, -20.0, -530.0);
    glEnd();

    //tiang 2 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -540.0);
    glVertex3f(-500.0, -90.0, -540.0);
    glVertex3f(-500.0, -20.0, -540.0);
    glVertex3f(-490.0, -20.0, -540.0);
    glEnd();

    //tiang 2 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -540.0);
    glVertex3f(-490.0, -90.0, -530.0);
    glVertex3f(-490.0, -20.0, -530.0);
    glVertex3f(-490.0, -20.0, -540.0);
    glEnd();

    //tiang 2 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -540.0);
    glVertex3f(-500.0, -90.0, -530.0);
    glVertex3f(-500.0, -20.0, -530.0);
    glVertex3f(-500.0, -20.0, -540.0);
    glEnd();

    //tiang 3 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -600.0);
    glVertex3f(-490.0, -90.0, -600.0);
    glVertex3f(-490.0, -20.0, -600.0);
    glVertex3f(-500.0, -20.0, -600.0);
    glEnd();

    //tiang 3 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -610.0);
    glVertex3f(-500.0, -90.0, -610.0);
    glVertex3f(-500.0, -20.0, -610.0);
    glVertex3f(-490.0, -20.0, -610.0);
    glEnd();

    //tiang 3 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -610.0);
    glVertex3f(-490.0, -90.0, -600.0);
    glVertex3f(-490.0, -20.0, -600.0);
    glVertex3f(-490.0, -20.0, -610.0);
    glEnd();

    //tiang 3 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -610.0);
    glVertex3f(-500.0, -90.0, -600.0);
    glVertex3f(-500.0, -20.0, -600.0);
    glVertex3f(-500.0, -20.0, -610.0);
    glEnd();

    //tiang 4 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -680.0);
    glVertex3f(-490.0, -90.0, -680.0);
    glVertex3f(-490.0, -20.0, -680.0);
    glVertex3f(-500.0, -20.0, -680.0);
    glEnd();

    //tiang 4 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -690.0);
    glVertex3f(-500.0, -90.0, -690.0);
    glVertex3f(-500.0, -20.0, -690.0);
    glVertex3f(-490.0, -20.0, -690.0);
    glEnd();

    //tiang 4 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -690.0);
    glVertex3f(-490.0, -90.0, -680.0);
    glVertex3f(-490.0, -20.0, -680.0);
    glVertex3f(-490.0, -20.0, -690.0);
    glEnd();

    //tiang 4 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -690.0);
    glVertex3f(-500.0, -90.0, -680.0);
    glVertex3f(-500.0, -20.0, -680.0);
    glVertex3f(-500.0, -20.0, -690.0);
    glEnd();

    //tiang 5 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -760.0);
    glVertex3f(-490.0, -90.0, -760.0);
    glVertex3f(-490.0, -20.0, -760.0);
    glVertex3f(-500.0, -20.0, -760.0);
    glEnd();

    //tiang 5 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -770.0);
    glVertex3f(-500.0, -90.0, -770.0);
    glVertex3f(-500.0, -20.0, -770.0);
    glVertex3f(-490.0, -20.0, -770.0);
    glEnd();

    //tiang 5 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -770.0);
    glVertex3f(-490.0, -90.0, -760.0);
    glVertex3f(-490.0, -20.0, -760.0);
    glVertex3f(-490.0, -20.0, -770.0);
    glEnd();

    //tiang 5 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -770.0);
    glVertex3f(-500.0, -90.0, -760.0);
    glVertex3f(-500.0, -20.0, -760.0);
    glVertex3f(-500.0, -20.0, -770.0);
    glEnd();

    //tiang 6 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -840.0);
    glVertex3f(-490.0, -90.0, -840.0);
    glVertex3f(-490.0, -20.0, -840.0);
    glVertex3f(-500.0, -20.0, -840.0);
    glEnd();

    //tiang 6 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -850.0);
    glVertex3f(-500.0, -90.0, -850.0);
    glVertex3f(-500.0, -20.0, -850.0);
    glVertex3f(-490.0, -20.0, -850.0);
    glEnd();

    //tiang 6 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -850.0);
    glVertex3f(-490.0, -90.0, -840.0);
    glVertex3f(-490.0, -20.0, -840.0);
    glVertex3f(-490.0, -20.0, -850.0);
    glEnd();

    //tiang 6 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -850.0);
    glVertex3f(-500.0, -90.0, -840.0);
    glVertex3f(-500.0, -20.0, -840.0);
    glVertex3f(-500.0, -20.0, -850.0);
    glEnd();

    //tiang 7 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -920.0);
    glVertex3f(-490.0, -90.0, -920.0);
    glVertex3f(-490.0, -20.0, -920.0);
    glVertex3f(-500.0, -20.0, -920.0);
    glEnd();

    //tiang 7 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -930.0);
    glVertex3f(-500.0, -90.0, -930.0);
    glVertex3f(-500.0, -20.0, -930.0);
    glVertex3f(-490.0, -20.0, -930.0);
    glEnd();

    //tiang 7 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -930.0);
    glVertex3f(-490.0, -90.0, -920.0);
    glVertex3f(-490.0, -20.0, -920.0);
    glVertex3f(-490.0, -20.0, -930.0);
    glEnd();

    //tiang 7 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -930.0);
    glVertex3f(-500.0, -90.0, -920.0);
    glVertex3f(-500.0, -20.0, -920.0);
    glVertex3f(-500.0, -20.0, -930.0);
    glEnd();

    //tiang 8 depan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -990.0);
    glVertex3f(-490.0, -90.0, -990.0);
    glVertex3f(-490.0, -20.0, -990.0);
    glVertex3f(-500.0, -20.0, -990.0);
    glEnd();

    //tiang 8 belakang
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -1000.0);
    glVertex3f(-500.0, -90.0, -1000.0);
    glVertex3f(-500.0, -20.0, -1000.0);
    glVertex3f(-490.0, -20.0, -1000.0);
    glEnd();

    //tiang 8 kanan
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-490.0, -90.0, -1000.0);
    glVertex3f(-490.0, -90.0, -990.0);
    glVertex3f(-490.0, -20.0, -990.0);
    glVertex3f(-490.0, -20.0, -1000.0);
    glEnd();

    //tiang 8 kiri
    glBegin(GL_QUADS);
    glColor3f(242/255.f, 242/255.f, 230/255.f);
    glVertex3f(-500.0, -90.0, -1000.0);
    glVertex3f(-500.0, -90.0, -990.0);
    glVertex3f(-500.0, -20.0, -990.0);
    glVertex3f(-500.0, -20.0, -1000.0);
    glEnd();
}

void objekhilang(void)
{
    //atap gedung belakang
    glBegin(GL_QUADS);
    glColor3f(196/255.f, 194/255.f, 192/255.f);
    glVertex3f(-500.0, 90.0, -1000.0);
    glVertex3f(500.0, 90.0, -1000.0);
    glVertex3f(500.0, 90.0, -530.0);
    glVertex3f(-500.0, 90.0, -530.0);
    glEnd();
    
     //atap2 bangunan 2 
    glBegin(GL_POLYGON);
    glColor3f(245/255.f, 245/255.f, 245/255.f);
    glVertex3f(25.0, 60.0, -480.0);
    glVertex3f(50.0, 60.0, -530.0);
    glVertex3f(150.0, 60.0, -530.0);
    glVertex3f(175.0, 60.0, -480.0);
    glEnd();

    //atap1 bangunan 2
    glBegin(GL_POLYGON);
    glColor3f(245/255.f, 245/255.f, 245/255.f);
    glVertex3f(0.0, 30.0, -430.0);
    glVertex3f(50.0, 30.0, -530.0);
    glVertex3f(150.0, 30.0, -530.0);
    glVertex3f(200.0, 30.0, -430.0);
    glEnd();
    
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(92 / 255.f, 100 / 255.f, 104 / 255.f);
    glVertex3f(470.0, -90.0, 820.0);
    glVertex3f(25.0, -90.0, 800.0);
    glVertex3f(25.0, 0.0, 800.0);
    glVertex3f(470.0, 0.0, 820.0);
    glEnd();
    }
 
 void ornament(void)
 {
    //lemari
    //depan lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-40.0, -20.0, 18.0);
    glVertex3f(-32.0, -20.0, 18.0);
    glVertex3f(-32.0, 4.0, 18.0);
    glVertex3f(-40.0, 4.0, 18.0);
    glEnd();

    //belakang lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-32.0, -20.0, 4.0);
    glVertex3f(-40.0, -20.0, 4.0);
    glVertex3f(-40.0, 4.0, 4.0);
    glVertex3f(-32.0, 4.0, 4.0);
    glEnd();

    //kanan lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-32.0, 4.0, 4.0);
    glVertex3f(-32.0, -20.0, 4.0);
    glVertex3f(-32.0, -20.0, 18.0);
    glVertex3f(-32.0, 4.0, 18.0);
    glEnd();

    //kiri lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-39.8, 4.0, 4.0);
    glVertex3f(-39.8, -20.0, 4.0);
    glVertex3f(-39.8, -20.0, 18.0);
    glVertex3f(-39.8, 4.0, 18.0);
    glEnd();

    //atas lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-40.0, 4.0, 4.0);
    glVertex3f(-40.0, 4.0, 4.0);
    glVertex3f(-40.0, 4.0, 18.0);
    glVertex3f(-40.0, 4.0, 18.0);
    glEnd();

    //bawah lemari
    glBegin(GL_QUADS);
    glColor3f(126/255.f, 171/255.f, 79/255.f);
    glVertex3f(-40.0, -19.0, 4.0);
    glVertex3f(-32.0, -19.0, 4.0);
    glVertex3f(-32.0, -19.0, 18.0);
    glVertex3f(-40.0, -19.0, 18.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-31.8, 4.0, 11.0);
    glVertex3f(-31.8, -20.0, 11.0);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-31.8, -8.0, 12.0);
    glVertex3f(-31.8, -8.0, 10.0);
    glEnd();
    
    //Kasur
    //depan kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-39.0, -20.0, 54.0);
    glVertex3f(-1.0, -20.0, 54.0);
    glVertex3f(-1.0, -16.0, 54.0);
    glVertex3f(-39.0, -16.0, 54.0);
    glEnd();

    //belakang kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-39.0, -20.0, 34.0);
    glVertex3f(-1.0, -20.0, 34.0);
    glVertex3f(-1.0, -16.0, 34.0);
    glVertex3f(-39.0, -16.0, 34.0);
    glEnd();

    //kanan kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-1.0, -16.0, 34.0);
    glVertex3f(-1.0, -20.0, 34.0);
    glVertex3f(-1.0, -20.0, 54.0);
    glVertex3f(-1.0, -16.0, 54.0);
    glEnd();

    //kiri kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-39.0, -16.0, 34.0);
    glVertex3f(-39.0, -20.0, 34.0);
    glVertex3f(-39.0, -20.0, 54.0);
    glVertex3f(-39.0, -16.0, 54.0);
    glEnd();

    //atas kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-39.0, -16.0, 34.0);
    glVertex3f(-1.0, -16.0, 34.0);
    glVertex3f(-1.0, -16.0, 54.0);
    glVertex3f(-39.0, -16.0, 54.0);
    glEnd();

    //bawah kasur
    glBegin(GL_QUADS);
    glColor3f(35/255.f, 166/255.f, 142/255.f);
    glVertex3f(-39.0, -19.0, 34.0);
    glVertex3f(-1.0, -19.0, 34.0);
    glVertex3f(-1.0, -19.0, 54.0);
    glVertex3f(-39.0, -19.0, 54.0);
    glEnd();
    
    //kursi
    //kaki kursi 1 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -90.0, 780.0);
    glVertex3f(27.0, -90.0, 780.0);
    glVertex3f(27.0, -65.0, 780.0);
    glVertex3f(26.0, -65.0, 780.0);
    glEnd();

    //kaki kursi 1 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(27.0, -90.0, 779.0);
    glVertex3f(26.0, -90.0, 779.0);
    glVertex3f(26.0, -65.0, 779.0);
    glVertex3f(27.0, -65.0, 779.0);
    glEnd();

    //kaki kursi 1 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(27.0, -90.0, 780.0);
    glVertex3f(27.0, -65.0, 780.0);
    glVertex3f(27.0, -65.0, 779.0);
    glVertex3f(27.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 1 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -90.0, 780.0);
    glVertex3f(26.0, -65.0, 780.0);
    glVertex3f(26.0, -65.0, 779.0);
    glVertex3f(26.0, -90.0, 779.0);
    glEnd();

   //kaki kursi 2 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -90.0, 780.0);
    glVertex3f(33.0, -90.0, 780.0);
    glVertex3f(33.0, -73.0, 780.0);
    glVertex3f(34.0, -73.0, 780.0);
    glEnd();

    //kaki kursi 2 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(33.0, -90.0, 779.0);
    glVertex3f(34.0, -90.0, 779.0);
    glVertex3f(34.0, -73.0, 779.0);
    glVertex3f(33.0, -73.0, 779.0);
    glEnd();

    //kaki kursi 2 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -90.0, 780.0);
    glVertex3f(34.0, -73.0, 780.0);
    glVertex3f(34.0, -73.0, 779.0);
    glVertex3f(34.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 2 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(33.0, -90.0, 780.0);
    glVertex3f(33.0, -73.0, 780.0);
    glVertex3f(33.0, -73.0, 779.0);
    glVertex3f(33.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 3 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -90.0, 755.0);
    glVertex3f(27.0, -90.0, 755.0);
    glVertex3f(27.0, -65.0, 755.0);
    glVertex3f(26.0, -65.0, 755.0);
    glEnd();

    //kaki kursi 3 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(27.0, -90.0, 754.0);
    glVertex3f(26.0, -90.0, 754.0);
    glVertex3f(26.0, -65.0, 754.0);
    glVertex3f(27.0, -65.0, 754.0);
    glEnd();

    //kaki kursi 3 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(27.0, -90.0, 755.0);
    glVertex3f(27.0, -65.0, 755.0);
    glVertex3f(27.0, -65.0, 754.0);
    glVertex3f(27.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 3 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -90.0, 755.0);
    glVertex3f(26.0, -65.0, 755.0);
    glVertex3f(26.0, -65.0, 754.0);
    glVertex3f(26.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 4 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -90.0, 755.0);
    glVertex3f(33.0, -90.0, 755.0);
    glVertex3f(33.0, -73.0, 755.0);
    glVertex3f(34.0, -73.0, 755.0);
    glEnd();

    //kaki kursi 4 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(33.0, -90.0, 754.0);
    glVertex3f(34.0, -90.0, 754.0);
    glVertex3f(34.0, -73.0, 754.0);
    glVertex3f(33.0, -73.0, 754.0);
    glEnd();

    //kaki kursi 4 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -90.0, 755.0);
    glVertex3f(34.0, -73.0, 755.0);
    glVertex3f(34.0, -73.0, 754.0);
    glVertex3f(34.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 4 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(33.0, -90.0, 755.0);
    glVertex3f(33.0, -73.0, 755.0);
    glVertex3f(33.0, -73.0, 754.0);
    glVertex3f(33.0, -90.0, 754.0);
    glEnd();

    //bagian dudukan kursi
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -78.0, 754.0);
    glVertex3f(34.0, -78.0, 754.0);
    glVertex3f(34.0, -78.0, 780.0);
    glVertex3f(26.0, -78.0, 780.0);
    glEnd();

    //sandaran kursi kiri bagian depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -74.0, 780.0);
    glVertex3f(26.0, -65.0, 780.0);
    glVertex3f(26.0, -65.0, 755.0);
    glVertex3f(26.0, -74.0, 755.0);
    glEnd();

    //sandaran kursi kiri bagian belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(27.0, -74.0, 780.0);
    glVertex3f(27.0, -65.0, 780.0);
    glVertex3f(27.0, -65.0, 755.0);
    glVertex3f(27.0, -74.0, 755.0);
    glEnd();

    //bagian sandaran kursi atas
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -65.0, 755.0);
    glVertex3f(27.0, -65.0, 755.0);
    glVertex3f(27.0, -65.0, 780.0);
    glVertex3f(26.0, -65.0, 780.0);
    glEnd();

    //pinggir kursi kiri bagian depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -73.0, 780.0);
    glVertex3f(34.0, -73.0, 780.0);
    glVertex3f(34.0, -75.0, 779.0);
    glVertex3f(26.0, -75.0, 779.0);
    glEnd();

    //pingir kursi kiri bagian belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -73.0, 780.0);
    glVertex3f(26.0, -73.0, 780.0);
    glVertex3f(26.0, -75.0, 779.0);
    glVertex3f(34.0, -75.0, 779.0);
    glEnd();

    //pingir kursi kiri bagian atas
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -73.0, 780.0);
    glVertex3f(26.0, -73.0, 780.0);
    glVertex3f(26.0, -73.0, 779.0);
    glVertex3f(34.0, -73.0, 779.0);
    glEnd();

    //pinggir kursi kiri bagian depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(26.0, -73.0, 755.0);
    glVertex3f(34.0, -73.0, 755.0);
    glVertex3f(34.0, -75.0, 754.0);
    glVertex3f(26.0, -75.0, 754.0);
    glEnd();

    //pingir kursi kiri bagian belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -73.0, 755.0);
    glVertex3f(26.0, -73.0, 755.0);
    glVertex3f(26.0, -75.0, 754.0);
    glVertex3f(34.0, -75.0, 754.0);
    glEnd();

    //pingir kursi kiri bagian atas
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(34.0, -73.0, 755.0);
    glVertex3f(26.0, -73.0, 755.0);
    glVertex3f(26.0, -73.0, 754.0);
    glVertex3f(34.0, -73.0, 754.0);
    glEnd();
    
    //meja
     //kaki kursi 1 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(40.0, -90.0, 780.0);
    glVertex3f(41.0, -90.0, 780.0);
    glVertex3f(41.0, -78.0, 780.0);
    glVertex3f(40.0, -78.0, 780.0);
    glEnd();

    //kaki kursi 1 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(41.0, -90.0, 779.0);
    glVertex3f(40.0, -90.0, 779.0);
    glVertex3f(40.0, -78.0, 779.0);
    glVertex3f(41.0, -78.0, 779.0);
    glEnd();

    //kaki kursi 1 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(41.0, -90.0, 780.0);
    glVertex3f(41.0, -78.0, 780.0);
    glVertex3f(41.0, -78.0, 779.0);
    glVertex3f(41.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 1 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(40.0, -90.0, 780.0);
    glVertex3f(40.0, -78.0, 780.0);
    glVertex3f(40.0, -78.0, 779.0);
    glVertex3f(40.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 2 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(50.0, -90.0, 780.0);
    glVertex3f(51.0, -90.0, 780.0);
    glVertex3f(51.0, -78.0, 780.0);
    glVertex3f(50.0, -78.0, 780.0);
    glEnd();

    //kaki kursi 2 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(51.0, -90.0, 779.0);
    glVertex3f(50.0, -90.0, 779.0);
    glVertex3f(50.0, -78.0, 779.0);
    glVertex3f(51.0, -78.0, 779.0);
    glEnd();

    //kaki kursi 2 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(51.0, -90.0, 780.0);
    glVertex3f(51.0, -78.0, 780.0);
    glVertex3f(51.0, -78.0, 779.0);
    glVertex3f(51.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 2 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(50.0, -90.0, 780.0);
    glVertex3f(50.0, -78.0, 780.0);
    glVertex3f(50.0, -78.0, 779.0);
    glVertex3f(50.0, -90.0, 779.0);
    glEnd();

    //kaki kursi 3 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(40.0, -90.0, 755.0);
    glVertex3f(41.0, -90.0, 755.0);
    glVertex3f(41.0, -78.0, 755.0);
    glVertex3f(40.0, -78.0, 755.0);
    glEnd();

    //kaki kursi 3 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(41.0, -90.0, 754.0);
    glVertex3f(40.0, -90.0, 754.0);
    glVertex3f(40.0, -78.0, 754.0);
    glVertex3f(41.0, -78.0, 754.0);
    glEnd();

    //kaki kursi 3 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(41.0, -90.0, 755.0);
    glVertex3f(41.0, -78.0, 755.0);
    glVertex3f(41.0, -78.0, 754.0);
    glVertex3f(41.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 3 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(40.0, -90.0, 755.0);
    glVertex3f(40.0, -78.0, 755.0);
    glVertex3f(40.0, -78.0, 754.0);
    glVertex3f(40.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 4 depan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(50.0, -90.0, 755.0);
    glVertex3f(51.0, -90.0, 755.0);
    glVertex3f(51.0, -78.0, 755.0);
    glVertex3f(50.0, -78.0, 755.0);
    glEnd();

    //kaki kursi 4 belakang
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(51.0, -90.0, 754.0);
    glVertex3f(50.0, -90.0, 754.0);
    glVertex3f(50.0, -78.0, 754.0);
    glVertex3f(51.0, -78.0, 754.0);
    glEnd();

    //kaki kursi 4 kanan
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(51.0, -90.0, 755.0);
    glVertex3f(51.0, -78.0, 755.0);
    glVertex3f(51.0, -78.0, 754.0);
    glVertex3f(51.0, -90.0, 754.0);
    glEnd();

    //kaki kursi 4 kiri
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(50.0, -90.0, 755.0);
    glVertex3f(50.0, -78.0, 755.0);
    glVertex3f(50.0, -78.0, 754.0);
    glVertex3f(50.0, -90.0, 754.0);
    glEnd();

    //bagian atas meja
    glBegin(GL_QUADS);
    glColor3f(168/255.f, 127/255.f, 61/255.f);
    glVertex3f(40.0, -78.0, 754.0);
    glVertex3f(51.0, -78.0, 754.0);
    glVertex3f(51.0, -78.0, 780.0);
    glVertex3f(40.0, -78.0, 780.0);
    glEnd();

}
 
void bangunan_lt1(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(25.8, -90.0, 75.0);
    glVertex3f(25.8, -45.0, 75.0);
    glVertex3f(-400.0, -45.0, 75.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(-400.0, -90.0, 400.0);
    glVertex3f(-400.0, -45.0, 400.0);
    glVertex3f(-400.0, -45.0, 75.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(25.8, -90.0, 75.0);
    glVertex3f(25.8, -90.0, 700.0);
    glVertex3f(25.8, -45.0, 700.0);
    glVertex3f(25.8, -45.0, 75.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, -90.0, 400.0);
    glVertex3f(25.8, -90.0, 700.0);
    glVertex3f(25.8, -45.0, 700.0);
    glVertex3f(-400.0, -45.0, 400.0);
    glEnd();
    //alas DASAR
    glBegin(GL_POLYGON);
    glColor3f(118/255.f, 104/255.f, 104/255.f);
    glVertex3f(-400.0, -90.0, 820.0);
    glVertex3f(-400.0, -90.0, 75.0);
    glVertex3f(25.8, -90.0, 75.0);
    glVertex3f(25.8, -90.0, 820.0);
    glEnd();
}

void bangunan_lt2(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(-400.0, -45.0, 75.0);
    glVertex3f(25.9, -45.0, 75.0);
    glVertex3f(25.9, 0.0, 75.0);
    glVertex3f(-400.0, 0.0, 75.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(-400.0, -45.0, 75.0);
    glVertex3f(-400.0, -45.0, 475.0);
    glVertex3f(-400.0, 0.0, 475.0);
    glVertex3f(-400.0, 0.0, 75.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(25.9, -45.0, 75.0);
    glVertex3f(25.9, -45.0, 700.0);
    glVertex3f(25.9, 0.0, 700.0);
    glVertex3f(25.9, 0.0, 75.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(-400.0, -45.0, 400.0);
    glVertex3f(25.9, -45.0, 700.0);
    glVertex3f(25.9, 0.0, 700.0);
    glVertex3f(-400.0, 0.0, 400.0);
    glEnd();
    //potong
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(-400.0, -45.0, 475.0);
    glVertex3f(25.9, -45.0, 600.0);
    glVertex3f(25.9, 0.0, 600.0);
    glVertex3f(-400.0, 0.0, 475.0);
    glEnd();
    //lantai
    glBegin(GL_POLYGON);
    glColor3f(196/255.f, 205/255.f, 208/255.f);
    glVertex3f(-400.0, -45.0, 75.0);
    glVertex3f(-400.0, -45.0, 400.0);
    glVertex3f(25.0, -45.0, 700.0);
    glVertex3f(25.0, -45.0, 75.0);
    glEnd();
    //lantai potong
    glBegin(GL_POLYGON);
    glColor3f(161/255.f, 157/255.f, 145/255.f);
    glVertex3f(-400.0, -44.9, 75.0);
    glVertex3f(-400.0, -44.9, 475.0);
    glVertex3f(25.9, -44.9, 600.0);
    glVertex3f(25.9, -44.9, 75.0);
    glEnd();
    //atap potong
    glBegin(GL_POLYGON);
    glColor3f(161/255.f, 157/255.f, 145/255.f);
    glVertex3f(-400.0, 0.0, 75.0);
    glVertex3f(-400.0, 0.0, 475.0);
    glVertex3f(25.9, 0.0, 600.0);
    glVertex3f(25.9, 0.0, 75.0);
    glEnd();
}

void bangunanlt3(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, 0.0, 75.0);
    glVertex3f(25.8, 0.0, 75.0);
    glVertex3f(25.8, 45.0, 75.0);
    glVertex3f(-400.0, 45.0, 75.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, 0.0, 75.0);
    glVertex3f(-400.0, 0.0, 400.0);
    glVertex3f(-400.0, 45.0, 400.0);
    glVertex3f(-400.0, 45.0, 75.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(25.8, 0.0, 75.0);
    glVertex3f(25.8, 0.0, 700.0);
    glVertex3f(25.8, 45.0, 700.0);
    glVertex3f(25.8, 45.0, 75.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(139/255.f, 156/255.f, 157/255.f);
    glVertex3f(-400.0, 0.0, 400.0);
    glVertex3f(25.8, 0.0, 700.0);
    glVertex3f(25.8, 45.0, 700.0);
    glVertex3f(-400.0, 45.0, 400.0);
    glEnd();
    //atap
    glBegin(GL_POLYGON);
    glColor3f(116/255.f, 124/255.f, 127/255.f);
    glVertex3f(-400.0, 45.0, 75.0);
    glVertex3f(-400.0, 45.0, 400.0);
    glVertex3f(25.8, 45.0, 700.0);
    glVertex3f(25.8, 45.0, 75.0);
    glEnd();
    //tower kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-375.0, -90.0, 500.0);
    glVertex3f(-375.0, -90.0, 525.0);
    glVertex3f(-375.0, 0.0, 525.0);
    glVertex3f(-375.0, 0.0, 500.0);
    glEnd();
    //tower kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-350.0, -90.0, 500.0);
    glVertex3f(-350.0, -90.0, 525.0);
    glVertex3f(-350.0, 0.0, 525.0);
    glVertex3f(-350.0, 0.0, 500.0);
    glEnd();
    //tower depan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-375.0, -90.0, 525.0);
    glVertex3f(-350.0, -90.0, 525.0);
    glVertex3f(-350.0, 0.0, 525.0);
    glVertex3f(-375.0, 0.0, 525.0);
    glEnd();
    //tower belakang
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-375.0, -90.0, 500.0);
    glVertex3f(-350.0, -90.0, 500.0);
    glVertex3f(-350.0, 0.0, 500.0);
    glVertex3f(-375.0, 0.0, 500.0);
    glEnd();
    //jembatan alas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325.0, 0.1, 400.0);
    glVertex3f(-325.0, 0.1, 550.0);
    glVertex3f(-400.0, 0.1, 550.0);
    glVertex3f(-400.0, 0.1, 400.0);
    glEnd();
    //jembatan atas
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325.0, 25.0, 400.0);
    glVertex3f(-325.0, 25.0, 550.0);
    glVertex3f(-400.0, 25.0, 550.0);
    glVertex3f(-400.0, 25.0, 400.0);
    glEnd();
    //jembatan kiri
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-400.0, 0.1, 400.1);
    glVertex3f(-400.0, 0.1, 550.1);
    glVertex3f(-400.0, 25.0, 550.1);
    glVertex3f(-400.0, 25.0, 400.1);
    glEnd();
    //jembatan kanan
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-325.0, 0.1, 400.1);
    glVertex3f(-325.0, 0.1, 550.1);
    glVertex3f(-325.0, 25.0, 550.1);
    glVertex3f(-325.0, 25.0, 400.1);
    glEnd();
    //jembatan depan
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-325.0, 0.1, 550.1);
    glVertex3f(-325.0, 0.1, 550.1);
    glVertex3f(-400.0, 25.0, 550.1);
    glVertex3f(-400.0, 25.0, 550.1);
    glEnd();
}

void bangunanlt4(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(186/255.f, 203/255.f, 220/255.f);
    glVertex3f(-200.0, 45.0, 542.5);
    glVertex3f(25.8, 45.0, 542.5);
    glVertex3f(25.8, 65.0, 542.5);
    glVertex3f(-200.0, 65.0, 542.5);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(186/255.f, 203/255.f, 220/255.f);
    glVertex3f(25.8, 45.0, 542.5);
    glVertex3f(25.8, 45.0, 700.0);
    glVertex3f(25.8, 65.0, 700.0);
    glVertex3f(25.8, 65.0, 542.5);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(186/255.f, 203/255.f, 220/255.f);
    glVertex3f(-200.0, 45.0, 542.5);
    glVertex3f(25.8, 45.0, 700.0);
    glVertex3f(25.8, 65.0, 700.0);
    glVertex3f(-200.0, 65.0, 542.5);
    glEnd();
    //atap
    glBegin(GL_POLYGON);
    glColor3f(116/255.f, 124/255.f, 127/255.f);
    glVertex3f(-200.0, 65.0, 542.5);
    glVertex3f(-200.0, 65.0, 542.5);
    glVertex3f(25.8, 65.0, 700.0);
    glVertex3f(25.8, 65.0, 542.5);
    glEnd();
    //ac depan
    glBegin(GL_POLYGON);
    glColor3f(175/255.f, 184/255.f, 190/255.f);
    glVertex3f(-150.0, 65.0, 542.5);
    glVertex3f(-25.0, 65.0, 542.5);
    glVertex3f(-25.0, 90.0, 542.5);
    glVertex3f(-150.0, 90.0, 542.5);
    glEnd();
    //ac kanan
    glBegin(GL_POLYGON);
    glColor3f(175/255.f, 184/255.f, 190/255.f);
    glVertex3f(-25.0, 65.0, 542.5);
    glVertex3f(-25.0, 65.0, 650.0);
    glVertex3f(-25.0, 90.0, 650.0);
    glVertex3f(-25.0, 90.0, 542.5);
    glEnd();
    //ac belakang
    glBegin(GL_POLYGON);
    glColor3f(175/255.f, 184/255.f, 190/255.f);
    glVertex3f(-150.0, 65.0, 542.5);
    glVertex3f(-25.0, 65.0, 650.0);
    glVertex3f(-25.0, 90.0, 650.0);
    glVertex3f(-150.0, 90.0, 542.5);
    glEnd();
    //ac atap
    glBegin(GL_TRIANGLES);
    glColor3f(175/255.f, 184/255.f, 190/255.f);
    glVertex3f(-150.0, 90.0, 542.5);
    glVertex3f(-25.0, 90.0, 542.5);
    glVertex3f(-25.0, 90.0, 650.0);
    glEnd();
}

void lingkaran (void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-350.0, 45.0, 200.0);
    glVertex3f(-250.0, 45.0, 200.0);
    glVertex3f(-250.0, 75.0, 200.0);
    glVertex3f(-350.0, 75.0, 200.0);
    glEnd();
    //depan miring kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-200.0, 45.0, 250.0);
    glVertex3f(-250.0, 45.0, 200.0);
    glVertex3f(-250.0, 75.0, 200.0);
    glVertex3f(-200.0, 75.0, 250.0);
    glEnd();
    //depan miring kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-350.0, 45.0, 200.0);
    glVertex3f(-400.0, 45.0, 250.0);
    glVertex3f(-400.0, 75.0, 250.0);
    glVertex3f(-350.0, 75.0, 200.0);
    glEnd();
    //belakang miring kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-200.0, 45.0, 350.0);
    glVertex3f(-250.0, 45.0, 400.0);
    glVertex3f(-250.0, 75.0, 400.0);
    glVertex3f(-200.0, 75.0, 350.0);
    glEnd();
    //belakang miring kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-350.0, 45.0, 400.0);
    glVertex3f(-400.0, 45.0, 350.0);
    glVertex3f(-400.0, 75.0, 350.0);
    glVertex3f(-350.0, 75.0, 400.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-200.0, 45.0, 250.0);
    glVertex3f(-200.0, 45.0, 350.0);
    glVertex3f(-200.0, 75.0, 350.0);
    glVertex3f(-200.0, 75.0, 250.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-399.9, 45.0, 250.0);
    glVertex3f(-399.9, 45.0, 350.0);
    glVertex3f(-399.9, 75.0, 350.0);
    glVertex3f(-399.9, 75.0, 250.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-350.0, 45.0, 400.0);
    glVertex3f(-250.0, 45.0, 400.0);
    glVertex3f(-250.0, 75.0, 400.0);
    glVertex3f(-350.0, 75.0, 400.0);
    glEnd();
    //atap
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-350.0, 75.0, 200.0);
    glVertex3f(-250.0, 75.0, 200.0);
    glVertex3f(-200.0, 75.0, 250.0);
    glVertex3f(-200.0, 75.0, 350.0);
    glVertex3f(-250.0, 75.0, 400.0);
    glVertex3f(-350.0, 75.0, 400.0);
    glVertex3f(-400.0, 75.0, 350.0);
    glVertex3f(-400.0, 75.0, 250.0);
    glVertex3f(-350.0, 75.0, 200.0);
    glEnd();

}

void oval(void)
{
    //depan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-140.0, 45.0, 200.0);
    glVertex3f(-40.0, 45.0, 200.0);
    glVertex3f(-40.0, 75.0, 200.0);
    glVertex3f(-140.0, 75.0, 200.0);
    glEnd();
    //depan miring kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(0.0, 45.0, 250.0);
    glVertex3f(-40.0, 45.0, 200.0);
    glVertex3f(-40.0, 75.0, 200.0);
    glVertex3f(0.0, 75.0, 250.0);
    glEnd();
    //depan miring kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-140.0, 45.0, 200.0);
    glVertex3f(-180.0, 45.0, 250.0);
    glVertex3f(-180.0, 75.0, 250.0);
    glVertex3f(-140.0, 75.0, 200.0);
    glEnd();
    //belakang miring kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(0.0, 45.0, 450.0);
    glVertex3f(-40.0, 45.0, 500.0);
    glVertex3f(-40.0, 75.0, 500.0);
    glVertex3f(0.0, 75.0, 450.0);
    glEnd();
    //belakang miring kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-140.0, 45.0, 500.0);
    glVertex3f(-180.0, 45.0, 450.0);
    glVertex3f(-180.0, 75.0, 450.0);
    glVertex3f(-140.0, 75.0, 500.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(0.0, 45.0, 250.0);
    glVertex3f(0.0, 45.0, 450.0);
    glVertex3f(0.0, 75.0, 450.0);
    glVertex3f(0.0, 75.0, 250.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-180.0, 45.0, 250.0);
    glVertex3f(-180.0, 45.0, 450.0);
    glVertex3f(-180.0, 75.0, 450.0);
    glVertex3f(-180.0, 75.0, 250.0);
    glEnd();
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-140.0, 45.0, 500.0);
    glVertex3f(-40.0, 45.0, 500.0);
    glVertex3f(-40.0, 75.0, 500.0);
    glVertex3f(-140.0, 75.0, 500.0);
    glEnd();
    //atap
    glBegin(GL_POLYGON);
    glColor3f(168/255.f, 184/255.f, 196/255.f);
    glVertex3f(-140.0, 75.0, 200.0);
    glVertex3f(-40.0, 75.0, 200.0);
    glVertex3f(0.0, 75.0, 250.0);
    glVertex3f(0.0, 75.0, 450.0);
    glVertex3f(-40.0, 75.0, 500.0);
    glVertex3f(-140.0, 75.0, 500.0);
    glVertex3f(-180.0, 75.0, 450.0);
    glVertex3f(-180.0, 75.0, 250.0);
    glEnd();
}

void taman (void)
{
    //belakang
    glBegin(GL_POLYGON);
    glColor3f(164/255.f, 162/255.f, 58/255.f);
    glVertex3f(-350.0, -90.0, 780.0);
    glVertex3f(-150.0, -90.0, 780.0);
    glVertex3f(-150.0, -80.0, 780.0);
    glVertex3f(-350.0, -80.0, 780.0);
    glEnd();
    //depan
    glBegin(GL_POLYGON);
    glColor3f(164/255.f, 162/255.f, 58/255.f);
    glVertex3f(-300.0, -90.0, 710.0);
    glVertex3f(-200.0, -90.0, 710.0);
    glVertex3f(-200.0, -80.0, 710.0);
    glVertex3f(-300.0, -80.0, 710.0);
    glEnd();
    //kiri
    glBegin(GL_POLYGON);
    glColor3f(164/255.f, 162/255.f, 58/255.f);
    glVertex3f(-300.0, -90.0, 710.0);
    glVertex3f(-350.0, -90.0, 780.0);
    glVertex3f(-350.0, -80.0, 780.0);
    glVertex3f(-300.0, -80.0, 710.0);
    glEnd();
    //kanan
    glBegin(GL_POLYGON);
    glColor3f(164/255.f, 162/255.f, 58/255.f);
    glVertex3f(-150.0, -90.0, 780.0);
    glVertex3f(-200.0, -90.0, 710.0);
    glVertex3f(-200.0, -80.0, 710.0);
    glVertex3f(-150.0, -80.0, 780.0);
    glEnd();
    //alas
    glBegin(GL_POLYGON);
    glColor3f(111/255.f, 97/255.f, 96/255.f);
    glVertex3f(-350.0, -80.0, 780.0);
    glVertex3f(-300.0, -80.0, 710.0);
    glVertex3f(-200.0, -80.0, 710.0);
    glVertex3f(-150.0, -80.0, 780.0);
    glEnd();
    //atas belakang
    glBegin(GL_POLYGON);
    glColor3f(156/255.f, 163/255.f, 155/255.f);
    glVertex3f(-325.0, -80.0, 780.0);
    glVertex3f(-175.0, -80.0, 780.0);
    glVertex3f(-175.0, -70.0, 780.0);
    glVertex3f(-325.0, -70.0, 780.0);
    glEnd();
    //atas depan
    glBegin(GL_POLYGON);
    glColor3f(156/255.f, 163/255.f, 155/255.f);
    glVertex3f(-275.0, -80.0, 710.0);
    glVertex3f(-225.0, -80.0, 710.0);
    glVertex3f(-225.0, -70.0, 710.0);
    glVertex3f(-275.0, -70.0, 710.0);
    glEnd();
    //atas kiri
    glBegin(GL_POLYGON);
    glColor3f(156/255.f, 163/255.f, 155/255.f);
    glVertex3f(-275.0, -80.0, 710.0);
    glVertex3f(-325.0, -80.0, 780.0);
    glVertex3f(-325.0, -70.0, 780.0);
    glVertex3f(-275.0, -70.0, 710.0);
    glEnd();
    //atas kanan
    glBegin(GL_POLYGON);
    glColor3f(156/255.f, 163/255.f, 155/255.f);
    glVertex3f(-175.0, -80.0, 780.0);
    glVertex3f(-225.0, -80.0, 710.0);
    glVertex3f(-225.0, -70.0, 710.0);
    glVertex3f(-175.0, -70.0, 780.0);
    glEnd();
    //alas atas
    glBegin(GL_POLYGON);
    glColor3f(34/255.f,139/255.f,34/255.f);
    glVertex3f(-325.0, -70.0, 780.0);
    glVertex3f(-275.0, -70.0, 710.0);
    glVertex3f(-225.0, -70.0, 710.0);
    glVertex3f(-175.0, -70.0, 780.0);
    glEnd();
}

void hilang(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    
    bangunanlt1();
    bangunanlt2();
    parkiran();
    bangunan2();
    lorong();
    bangunankiri();
    gedung_tengah();
    tiang();
    bangunan1();
    gedung_belakang();
    jendela();
    lantai_luar();
    garis_tembok();
    tiang_gedung_belakang();
    ornament();
    taman();
    bangunan_lt1();
    bangunan_lt2();
    bangunanlt3();
    bangunanlt4();
    lingkaran();
    oval();
    
    glPopMatrix();
    glutSwapBuffers();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    
    objekhilang();
    bangunan_lt1();
    bangunan_lt2();
    ataplt2();
    parkiran();
    bangunan2();
    lorong();
    lorongatap();
    bangunankiri();
    gedung_tengah();
    tiang();
    bangunan1();
    gedung_belakang();
    jendela();
    lantai_luar();
    garis_tembok();
    tiang_gedung_belakang();
    ornament();
    taman();
    bangunan_lt1();
    bangunan_lt2();
    bangunanlt3();
    bangunanlt4();
    lingkaran();
    oval();
    
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

void mouseMotion(int x, int y)
{
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
    gluPerspective(100.0, lebar / tinggi, 5.0, 4000.0);
    glTranslatef(0.0, -5.0, -300.0);
    glMatrixMode(GL_MODELVIEW);
}

