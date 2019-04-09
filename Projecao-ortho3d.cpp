#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>

void Desenha()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	//camera que mostra o cenario 	
	gluLookAt(0.0,0.0,-5.0,//posicao da camera 
			  0.0,0.0,0.0,//ponto onde a camera vai apontar
			  0.0,1.0,0.0);//topo do cenario 
	glColor3f(1.0f,1.0f,1.0f);
	glutWireCube(2);
	glutWireSphere(0.5,100,100);
	glFlush();
}


void Inicializa()
{
	glClearColor(0.0,0.0,0.0,0.0);
	
	//esses são as perspectivas  das acameras 
	 glOrtho(-2.0,2.0,-2.0,2.0,-1.5,1.5);
	
	//glFrustum(-1.0,1.0,-1.0,1.0,1.0,20.0);//
	//gluPerspective(43,//angulo em Y 
	//1.33,//proporção em X
	//.1,20);//distancia minima e maxima no z 
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
