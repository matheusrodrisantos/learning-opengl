#include <GL/glut.h>
#include <time.h>


GLfloat xf, yf, win;
GLint view_w, view_h;


void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void desenha(void){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	int x,y,z;
	srand(time(NULL)); 
	x=rand()%9;
	y=rand()%9;
	z=rand()%9;
	//printf("%d ", rand() % 100);
	
	//Cubo 1
	glPushMatrix();
	glTranslatef(x, 0.0, 0.0);
	glScalef(3.0, 2.0, 5.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Cubo 2
	glPushMatrix();
	glRotatef(25.0, 0.0, 0.0, 1.0);
	glTranslatef(2.0, y, 0.0);
	glScalef(2.0, 1.0, 4.0);
	glutWireCube(1.0);
	glPopMatrix();

	//Cubo 3
	glPushMatrix();
	glTranslatef(0.0, 0.0, z);
	glScalef(2.0, 1.0, 4.0);
	glutWireCube(1.0);
	glPopMatrix();
	
	//Cubo 4
	glPushMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glScalef(2.0, 1.0, 4.0);
	glutWireCube(1.0);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/ (GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Aula - 29/04/2019 (Matrizes)");
	init();
	glutDisplayFunc(desenha);
	glutReshapeFunc(reshape);
	glutMainLoop();
}






