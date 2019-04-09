#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>

void Desenha(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f,1.0f,1.0f);
	glutWireCube(2);
	glFlush();
}


void Inicializa(){
	glClearColor(0.0,0.0,0.0,0.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-1.5,1.5);
	
	
}

int main(int argc, char **argv){
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(450,450);
	glutCreateWindow("Projecoes");
	glutDisplayFunc(Desenha);
	
	
	Inicializa();
	glutMainLoop();	
}


