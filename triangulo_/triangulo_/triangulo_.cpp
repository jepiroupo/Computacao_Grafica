#include <gl/glut.h>

GLfloat xf, yf, win;
GLint view_w, view_h;

typedef GLfloat triangulo[3][2];
triangulo coordenadas;
int i;

// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT);

	if (i >= 3){
		glBegin(GL_TRIANGLES);
			glVertex2fv(coordenadas[0]);
			glVertex2fv(coordenadas[1]);
			glVertex2fv(coordenadas[2]);
		glEnd();
	}
     glFlush();
}

// Inicializa par�metros de rendering
void init (void)
{   
    // Define a cor de fundo da janela de visualiza��o como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    win=250.0f;
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{ 
    // Especifica as dimens�es da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

// Fun��o callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
			case 'B': 
            case 'b':// muda a cor corrente para branco
                     glColor3f(1.0, 1.0, 1.0);
                     break;
            case 'R': 
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0, 0.0, 0.0);
                     break;
            case 'V':
            case 'v':// muda a cor corrente para verde
                     glColor3f(0.0, 1.0, 0.0);
                     break;
            case 'A':
            case 'a':// muda a cor corrente para azul
                     glColor3f(0.0, 0.0, 1.0);
                     break;
    }
    glutPostRedisplay();
}
           
// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && i < 3){
			if (state == GLUT_DOWN) {
			coordenadas[i][0] = ( (2 * win * x) / view_w) - win;
			coordenadas[i][1] = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
			i++;
		}
	}
		
    glutPostRedisplay();
}
                      
// Programa Principal 
int main(void)
{
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(600,420);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Triangulo");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutKeyboardFunc(GerenciaTeclado);
     glutMouseFunc(GerenciaMouse);   
	 init();
     glutMainLoop();
}