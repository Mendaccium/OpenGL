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

	glMatrixMode(GL_MODELVIEW); //Informa que as operações seguintes serão executadas na matrix modelview
	glLoadIdentity(); //Carrega a matriz identidade

	glPointSize(50); //Define quantos pixels representarão um vértice na tela
	glLineWidth(5);
	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.294, 0.498, 0.686); //Define a cor do desenho em formato RGB
		glVertex2f(-0.77, -0.89); //Especifica pontos no espaço bidimensional (pixels)
		glVertex2f(-0.52, -0.67);	
		glVertex2f(-0.26, -0.67);
		glVertex2f(-0.38, -0.89);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.694, 0.192, 0.290); //Define a cor do desenho em formato RGB
		glVertex2f(-0.64, -0.67);
		glVertex2f(-0.64, -0.15);
		glVertex2f(-0.12, -0.15);
		glVertex2f(-0.12, -0.67);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.694, 0.196, 0.894); //Define a cor do desenho em formato RGB
		glVertex2f(-0.52, -0.67);
		glVertex2f(-0.52, -0.30);
		glVertex2f(-0.26, -0.30);
		glVertex2f(-0.26, -0.67);
	glEnd();//Encerra a criação de pontos

	glPointSize(10.0);
	glBegin(GL_POINTS);
		glColor3f(0.278, 0.690, 0.890);
		glVertex2f(-0.48, -0.5);
	glEnd();

	glPointSize(50);
	glBegin(GL_TRIANGLES); //Indica que serão desenhados somente pontos
		glColor3f(0.078, 0.505, 0); //Define a cor do desenho em formato RGB
		glVertex2f(-0.64, -0.15);
		glVertex2f(-0.36, 0.1);
		glVertex2f(-0.12, -0.15);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.090, 0.2, 0.286); //Define a cor do desenho em formato RGB
		glVertex2f(-0.12, -0.67);
		glVertex2f(-0.12, -0.15);
		glVertex2f(0.70, -0.15);
		glVertex2f(0.70, -0.67);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.290, 0.498, 0.796); //Define a cor do desenho em formato RGB
		glVertex2f(-0.12, -0.15);
		glVertex2f(-0.36, 0.1);
		glVertex2f(0.50, 0.1);
		glVertex2f(0.70, -0.15);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.188, 0.396, 0.286); //Define a cor do desenho em formato RGB
		glVertex2f(-0.05, -0.40);
		glVertex2f(-0.05, -0.20);
		glVertex2f(0.20, -0.20);
		glVertex2f(0.20, -0.40);
	glEnd();//Encerra a criação de pontos

	glBegin(GL_QUADS); //Indica que serão desenhados somente pontos
		glColor3f(0.188, 0.396, 0.286); //Define a cor do desenho em formato RGB
		glVertex2f(0.38, -0.40);
		glVertex2f(0.38, -0.20);
		glVertex2f(0.63, -0.20);
		glVertex2f(0.63, -0.40);
	glEnd();//Encerra a criação de pontos

	glPointSize(5.0);
	glBegin(GL_LINES);
		glColor3f(0.117, 0.631, 0.443);
		glVertex2f(0.08, -0.2);
		glVertex2f(0.08, -0.4);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.117, 0.631, 0.443);
		glVertex2f(-0.05, -0.3);
		glVertex2f(0.2, -0.3);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.117, 0.631, 0.443);
		glVertex2f(0.51, -0.2);
		glVertex2f(0.51, -0.4);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.117, 0.631, 0.443);
		glVertex2f(0.38, -0.3);
		glVertex2f(0.63, -0.3);
	glEnd();

	glFlush(); //Informa que as operações devem ser processadas imediatamente e exibidas na tela
}


/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
		break;
	default:
		printf("Código tecla: %i. Mouse em (%i,%i)\n", key, x, y);
		break;
	}
	glutPostRedisplay(); //Informa que a janela atual deve ser redesenhada
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); //Inicializa a OpenGL
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Configura os modos de exibição (mais detalhes no futuro)
	glutInitWindowSize(1080, 720); //Define o tamanho da janela em pixels
	glutInitWindowPosition(0, 0); //Define a posição inicial da janela
	glutCreateWindow("Primeiro Exemplo"); //Cria a janela especificando seu título
	glutDisplayFunc(display); //Especifica a função de rendering (exibe a cena no loop)
	glutReshapeFunc(resize); //Especifica função a ser executada quando a janela é redimensionada
	glutKeyboardFunc(keyboard); //Especifica função a ser executada quando uma tecla é pressionada

	glutMainLoop(); //Executa o loop de renderização
	return 0;
}