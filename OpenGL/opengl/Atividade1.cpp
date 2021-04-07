#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

void display(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
	glClear(GL_COLOR_BUFFER_BIT);//Inicializa o buffer de cores antes de ele ser alterado

	glMatrixMode(GL_MODELVIEW); //Informa que as opera��es seguintes ser�o executadas na matrix modelview
	glLoadIdentity(); //Carrega a matriz identidade

	glPointSize(50); //Define quantos pixels representar�o um v�rtice na tela
	glLineWidth(5);
	glBegin(GL_LINE_STRIP); //Indica que ser�o desenhados somente pontos

	glColor3f(1.0f, 0.0f, 0.0f); //Define a cor do desenho em formato RGB
	glVertex2f(0, 0); //Especifica pontos no espa�o bidimensional (pixels)

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, 0);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, 0.5f);

	glEnd();//Encerra a cria��o de pontos

	glFlush(); //Informa que as opera��es devem ser processadas imediatamente e exibidas na tela
}


/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um c�digo para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
		break;
	default:
		printf("C�digo tecla: %i. Mouse em (%i,%i)\n", key, x, y);
		break;
	}
	glutPostRedisplay(); //Informa que a janela atual deve ser redesenhada
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); //Inicializa a OpenGL
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Configura os modos de exibi��o (mais detalhes no futuro)
	glutInitWindowSize(500, 500); //Define o tamanho da janela em pixels
	glutInitWindowPosition(0, 0); //Define a posi��o inicial da janela
	glutCreateWindow("Primeiro Exemplo"); //Cria a janela especificando seu t�tulo
	glutDisplayFunc(display); //Especifica a fun��o de rendering (exibe a cena no loop)
	glutReshapeFunc(resize); //Especifica fun��o a ser executada quando a janela � redimensionada
	glutKeyboardFunc(keyboard); //Especifica fun��o a ser executada quando uma tecla � pressionada

	glutMainLoop(); //Executa o loop de renderiza��o
	return 0;
}