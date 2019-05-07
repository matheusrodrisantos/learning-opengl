#include <GL/glut.h>

//Função callback chamada para fazer o desenho 
void Desenha (void)
{
	//limpa a janela de visualizaçõa com a cor de fundo especificação
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Executa os comandos OpenGL
	glFlush();
}
	// Inicializa parametros de rendering
	void Inicializa(void)
	{
		//Defina a cor de fundo da janela de visualização como preta
		glClearColor(0.0,0.0,0.0,1.0);
		
	}


//Programa Principal

int main (int argc,char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Primeiro Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
}
