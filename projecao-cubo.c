
#include <GL/glut.h>

static GLfloat vertices[30] = {
	0.0, 30.0, 30.0, //Vertice 0
	20.0, 30.0, 30.0, //Vertice 1
	30.0, 20.0, 30.0, //Vertice 2
	30.0, 0.0, 30.0, //Vertice 3
	0.0, 0.0, 30.0, //Vertice 4
	0.0, 30.0, 0.0, //Vertice 5
	30.0, 30.0, 0.0, //Vertice 6
	30.0, 0.0, 0.0, //Vertice 7
	0.0, 0.0, 0.0, //Vertice 8
	30.0, 30.0, 20.0 //Vertice 9
};

static GLubyte frente[] = {0, 4, 3, 2, 1};
static GLubyte tras[] = {5, 6, 7, 8};
static GLubyte esquerda[] = {0, 5, 8, 4};
static GLubyte direita[] = {2, 7, 6, 9};
static GLubyte topo[] = {0,1,9,6,5};
static GLubyte fundo[] = {3,4,8,7};
static GLubyte triangulo[] = {1, 2, 9};

void Desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	
	glColor3f(1.0,1.0,.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frente);
	
	glColor3f(0.0,0.0,1.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, tras);
	
	glColor3f(0.0,1.0,0.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerda);
	
	glColor3f(0.0,0.9,1.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, direita);
	
	glColor3f(0.9,0.0,1.0);
	glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topo);
	
	glColor3f(0.3,0.0,1.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, fundo);
	
	glColor3f(0.9,1.0,1.0);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, triangulo);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	//glutSwapBuffers;
	glFlush();
}

void Inicializa(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);
	//gluPerspective(43, 1.33,.1, 20);

}

void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(256, 256);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cubo");
	
	Inicializa();
	glutDisplayFunc(Desenha);
	glutMainLoop();
}



