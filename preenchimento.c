#include<stdio.h>
#include<GL/glut.h>


GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x7f,  0xfe,  0x0, 
 0x0,  0xc4, 0x23, 0x0,
 0x0,  0x83,  0x21,  0x80, 
 0x0,  0x7,  0xe0,  0x80, 
 0x0,  0x7,  0xf0,  0x80, 
 0x0,  0x8f,  0xf9,  0x80, 
 0x0,  0xff,  0xff,  0x0, 
 0x0,  0x4f,  0xf1,  0x0, 
 0x0,  0x6f,  0xf1,  0x0, 
 0x0,  0x2f,  0xf3,  0x0, 
 0x0,  0x27,  0xe2,  0x0, 
 0x0,  0x30,  0x66,  0x0, 
 0x0,  0x1b,  0x1c,  0x0, 
 0x0,  0xb,  0x88,  0x0, 
 0x0,  0xb,  0x98,  0x0, 
 0x0,  0x8,  0x18,  0x0, 
 0x0,  0xa,  0x90,  0x0, 
 0x0,  0x8,  0x10,  0x0, 
 0x0,  0xc,  0x30,  0x0, 
 0x0,  0x6,  0x60,  0x0, 
 0x0,  0x3,  0xc0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0
};

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glOrtho(0,256,0,256,-1,1);
	
}
void desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_BACK,GL_LINE);// CRIA O POLIGN NO MODO LINHA 
	
	//CUBO SEM PREENCHIMENTO
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(30,226);	
		glVertex2i(113,226);	
		glVertex2i(113,143);	
		glVertex2i(30,143);	
	glEnd();
	
	//CUBO COM PREENCHIMENTO
	glPolygonMode(GL_BACK,GL_FILL);// FILL FAZ O PREENCHIMENTO
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(143,226);
		glVertex2i(226,226);
		glVertex2i(225,143);
		glVertex2i(143,143);
	glEnd();
	
	
	// CUBO COM GRADIENTE 
	glBegin(GL_POLYGON);
		glVertex2i(30,113);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(113,113);
		glColor3f(1.0,1.0,0.0);
		glVertex2i(113,30);
		glColor3f(0.0,0.0,1.0);
		glVertex2i(30,30);
	glEnd();
	
	
	// CUBO PADRÃO DE PREENCHIMENTO 
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(tux);
	glBegin(GL_POLYGON);
		glVertex2i(143,113);
		glVertex2i(226,113);
		glVertex2i(226,30);
		glVertex2i(143,30);
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);
	
	glFlush();
	glutSwapBuffers();
}


void main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(256,256);
	glutCreateWindow("Preenchimento");
	init();
	
	glutDisplayFunc(desenha);
	glutMainLoop();
	
}
