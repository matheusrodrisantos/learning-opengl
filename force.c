#include <stdio.h>
#include <GL/glut.h>


void Desenha(void)
{
 	//Limpa a janela de visualização com a cor de fundo especifica
 	glClear(GL_COLOR_BUFFER_BIT);

 	glColor3f (0.1, 0.1, 0.44);	 
	
	//quadrado da jedi
 	glBegin(GL_QUADS);
 		glVertex2f(0,0);
 		glVertex2f(50,0);
 		glVertex2f(50,50);
 		glVertex2f(0,50);
 	glEnd();
 		
 	//quadrado da sith
 	glBegin(GL_QUADS);
 		glVertex2f(600,0);
 		glVertex2f(550,0);
 		glVertex2f(550,50);
 		glVertex2f(600,50);
 	glEnd();
 	
 		
	glFlush();
 }
 	//Inicializa parâmetros de rendering
 	void Inicializa(void)
 	{
 		//Define a cor de fundo da janela de visualização
		 glClearColor(1.0, 1.0, 1.0, 1.0); 
		 gluOrtho2D(0, 600, 0, 300);
	}	
	//Programa Principal
	int main(int argc, char **argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(600, 300);
		glutCreateWindow("Matheus Rodrigues,Natália Cipolli, Luiz Felipe");		
		glutDisplayFunc(Desenha);
		Inicializa();
		glutMainLoop();
	}

 


	
