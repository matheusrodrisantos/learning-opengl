
#include <GL/glut.h>

static int year = 0, day = 0;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
		case 'd':
			day = (day + 10) % 360; glutPostRedisplay(); break;
		case 'D':
			day = (day - 10) % 360; glutPostRedisplay(); break;
		case 'y':
			year = (year + 5) % 360; glutPostRedisplay(); break;
		case 'Y':
			year = (year - 5) % 360; glutPostRedisplay(); break;
		case 27: 
			exit(0); break;
		default: break;
	}
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
		//sol 
		glutSolidSphere(1.0, 10, 16);
		
		
		//planeta 1
		glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);
		
		//lua 2
		glColor3f(0.0,1.0,0.0);
		glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(0.6, 0.0, 0.0);
		
		
		glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.1, 10, 8);

	glPopMatrix();
	glutSwapBuffers();
}
void animacao(int x){
	
}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
