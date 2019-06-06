#include <stdio.h>
#include <GL/glut.h>

int xLightSaberJedi=55, xLightSaberSith=545, vidaJedi = 200, vidaSith = 420;


void lightSaberJedi()
{
	xLightSaberJedi=xLightSaberJedi+35;
	glClear(GL_COLOR_BUFFER_BIT);
	Desenha();
	glLineWidth (2.0);
    glBegin(GL_LINES);
    	//variavel x 
        glVertex2f(xLightSaberJedi, 25.0);
        glVertex2f(xLightSaberJedi+35, 25.0);   
    glEnd();
    glFlush();
    
	if(xLightSaberJedi<=550)
	{
    	glutTimerFunc(100, lightSaberJedi, 0);
    	
	}
	else
	{
		vidaSith = vidaSith+10;
		xLightSaberJedi=35;
	}
    
}
void lightSaberSith()
{
	xLightSaberSith=xLightSaberSith-35;
	glClear(GL_COLOR_BUFFER_BIT);
	Desenha();
	glLineWidth (2.0);
	glBegin(GL_LINES);
    	//variavel x 
        glVertex2f(xLightSaberSith, 25.0);
        glVertex2f(xLightSaberSith-35, 25.0);
    glEnd();
    glFlush();
    
    if(xLightSaberSith>=50)
	{
    	glutTimerFunc(100, lightSaberSith, 0);
	}
	else{
		xLightSaberSith=545;
		vidaJedi = vidaJedi-10;
	}
    
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
		case 's':
			glutTimerFunc(100, lightSaberJedi, 1);
			break;

		case 'S':
			glutTimerFunc(100, lightSaberJedi, 0);
			break;

		case 'l':
			glutTimerFunc(100, lightSaberSith, 0);
			break;

		case 'L':
			glutTimerFunc(100, lightSaberSith, 0);
			break;

		default: break;

	}
}

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
 	glColor3f (0.1, 0.31, 0.59);	 
 	glBegin(GL_QUADS);
 		glVertex2f(600,0);
 		glVertex2f(550,0);
 		glVertex2f(550,50);
 		glVertex2f(600,50);
 	glEnd();
 	
 	//vida jedi
 	//contorno
 	glColor3f (0, 0, 0);
 	glLineWidth (12.0);
    glBegin(GL_LINES);
        glVertex2f(19.5, 269.5);
        glVertex2f(201.5, 269.5);   
    glEnd();
 	//vida
 	glColor3f (0, 1, 0);
 	glLineWidth (10.0);
    glBegin(GL_LINES);
        glVertex2f(20, 270);
        glVertex2f(vidaJedi, 270);  //200 
    glEnd();
    
    //vida sith
 	//contorno
 	glColor3f (0, 0, 0);
 	glLineWidth (12.0);
    glBegin(GL_LINES);
        glVertex2f(419.5, 269.5);
        glVertex2f(581.5, 269.5);   
    glEnd();
 	//vida
 	glColor3f (0, 1, 0);
 	glLineWidth (10.0);
    glBegin(GL_LINES);
        glVertex2f(vidaSith, 270); //420
        glVertex2f(580, 270);  
    glEnd();
 	
 	//
 	glColor3f (0, 0, 0);
 	glLineWidth (1.0);
    glBegin(GL_LINES);
        glVertex2f(0, 250);
        glVertex2f(600, 250);   
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

 


	
