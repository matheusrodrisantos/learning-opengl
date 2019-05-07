#include <GL/glut.h>

static int year = 0, day = 0;
static int yearMercurio = 0, dayMercurio = 0;
static int yearVenus = 0, dayVenus = 0;
static int yearMarte = 0, dayMarte = 0;
static int yearTerra = 0, dayTerra = 0;
static int yearJupiter = 0, dayJupiter = 0;
static int yearSaturno = 0, daySaturno = 0;
static int yearUrano = 0, dayUrano = 0;
static int yearNetuno = 0, dayNetuno = 0;




void init(void) {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
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
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
		//sol 
		glColor3f(1.0,0.75,0.0);
		glutSolidSphere(0.32, 200, 16);

	glPopMatrix();
	glPushMatrix();		
		//mercurio 
		glColor3f(0.55,0.27,0.07);
		glRotatef((GLfloat) yearMercurio, 0.0, 1.0, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef((GLfloat) dayMercurio, 0.0, 1.0, 0.0);
		glutSolidSphere(0.05, 100, 8);
		
	glPopMatrix();
	glPushMatrix();
		//venus 
		glColor3f(0.8,0.5,0.2);
		glRotatef((GLfloat) yearVenus, 0.0, 1.0, 0.0);
		glTranslatef(0.9, 0.0, 0.0);
		glRotatef((GLfloat) dayVenus, 0.0, 1.0, 0.0);
		glutSolidSphere(0.1, 100, 8);
	glPopMatrix();
	
	glPushMatrix();
		//terra
		glColor3f(0.0,0.9,2.9);
		glRotatef((GLfloat) yearTerra, 0.0, 1.0, 0.0);
		glTranslatef(1.4, 0.0, 0.0);
		glRotatef((GLfloat) dayTerra, 0.0, 1.0, 0.0);
		glutSolidSphere(0.09, 100, 8);
		
		//LUA
		glColor3f(1.0,0.9,0.9);
		glRotatef((GLfloat) yearTerra, 0.0, 1.0, 0.0);
		glTranslatef(0.2, 0.0, 0.0);
		glRotatef((GLfloat) dayTerra, 0.0, 1.0, 0.0);
		glutSolidSphere(0.05, 10, 8);
	glPopMatrix();
	
	glPushMatrix();
		//marte
		glColor3f(0.55,0.0,0.0);
		glRotatef((GLfloat) yearMarte, 0.0, 1.0, 0.0);
		glTranslatef(1.9, 0.0, 0.0);
		glRotatef((GLfloat) dayMarte, 0.0, 1.0, 0.0);
		glutSolidSphere(0.1, 100, 8);
	glPopMatrix();
	
	glPushMatrix();
		//Jupiter
		glColor3f(0.59,0.29,0.0);
		glRotatef((GLfloat) yearJupiter, 0.0, 1.0, 0.0);
		glTranslatef(2.4, 0.0, 0.0);
		glRotatef((GLfloat) dayJupiter, 0.0, 1.0, 0.0);
		glutSolidSphere(0.21, 100, 8);
	glPopMatrix();
	
	glPushMatrix();
		//Saturno
		glColor3f(0.59,0.5,0.0);
		glRotatef((GLfloat) yearSaturno, 0.0, 1.0, 0.0);
		glTranslatef(2.9, 0.0, 0.0);
		glRotatef((GLfloat) daySaturno, 0.0, 1.0, 0.0);
		glutSolidSphere(0.13, 100, 8);
	glPopMatrix();
	
	glPushMatrix();
		//urano 
		glColor3f(0.39,0.58,0.93);
		glRotatef((GLfloat) yearUrano, 0.0, 1.0, 0.0);
		glTranslatef(3.4, 0.0, 0.0);
		glRotatef((GLfloat) dayUrano, 0.0, 1.0, 0.0);
		glutSolidSphere(0.10, 100, 8);
	glPopMatrix();
	
	glPushMatrix();
		//netuno 
		glColor3f(0.0,0.0,0.8);
		glRotatef((GLfloat) yearNetuno, 0.0, 1.0, 0.0);
		glTranslatef(3.9, 0.0, 0.0);
		glRotatef((GLfloat) dayNetuno, 0.0, 1.0, 0.0);
		glutSolidSphere(0.09, 100, 8);
	glPopMatrix();
	
	glutSwapBuffers();
}
void animacao(int x){
	dayMercurio = (dayMercurio + 20) % 360;
	glutPostRedisplay(); 

	yearMercurio = (yearMercurio + 10) % 360; 
	glutPostRedisplay(); 
	
	dayVenus = (dayVenus + 30) % 360;
	glutPostRedisplay(); 

	yearVenus = (yearMercurio + 11) % 360; 
	glutPostRedisplay(); 

	dayMarte = (dayMarte + 20) % 360;
	glutPostRedisplay(); 

	yearMarte = (yearMarte + 12) % 360; 
	glutPostRedisplay(); 
	
	dayTerra = (dayTerra + 20) % 360;
	glutPostRedisplay(); 

	yearTerra = (yearTerra + 13) % 360; 
	glutPostRedisplay(); 

	dayJupiter = (dayJupiter + 60) % 360;
	glutPostRedisplay(); 

	yearJupiter = (yearJupiter + 14) % 360; 
	glutPostRedisplay(); 
	
	dayUrano = (dayUrano + 20) % 360;
	glutPostRedisplay(); 

	yearUrano = (yearUrano + 15) % 360; 
	glutPostRedisplay(); 

	dayNetuno = (dayNetuno + 20) % 360;
	glutPostRedisplay(); 

	yearNetuno = (yearNetuno + 16) % 360; 
	glutPostRedisplay(); 
	
	daySaturno = (daySaturno + 17) % 360;
	glutPostRedisplay(); 

	yearSaturno = (yearSaturno + 18) % 360; 
	glutPostRedisplay(); 
	
	
	glutPostRedisplay();
	glutTimerFunc(100, animacao, 0);
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
	glutTimerFunc(0,animacao,0);
	glutMainLoop();
}
