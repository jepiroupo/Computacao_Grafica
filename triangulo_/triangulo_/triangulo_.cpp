#include <gl/glut.h>

GLfloat xf, yf, win;
GLint view_w, view_h;

typedef GLfloat triangulo[3][2];
triangulo coordenadas;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
                   
     glClear(GL_COLOR_BUFFER_BIT);

	 
	glPointSize(5.0);
		glColor3f(1.0, 0.0, 1.0);
		glBegin(GL_POINTS);
		glVertex2fv(coordenadas[0]);
		glVertex2fv(coordenadas[1]);
		glVertex2fv(coordenadas[2]);
	glEnd();

     glFlush();
}

// Inicializa parâmetros de rendering
void init (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    xf=50.0f;
    yf=50.0f;
    win=250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{ 
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                   

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
			case 'B': 
            case 'b':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 1.0f, 1.0f);
                     break;
            case 'R': 
            case 'r':// muda a cor corrente para vermelho
                     glColor3f(1.0f, 0.0f, 0.0f);
                     break;
            case 'V':
            case 'v':// muda a cor corrente para verde
                     glColor3f(0.0f, 1.0f, 0.0f);
                     break;
            case 'A':
            case 'a':// muda a cor corrente para azul
                     glColor3f(0.0f, 0.0f, 1.0f);
                     break;
    }
    glutPostRedisplay();
}
           
// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	int i = 0, j = 0;
	for (i = 0; i <= 2; i++){
		if (button == GLUT_LEFT_BUTTON){
				if (state == GLUT_DOWN) {
				coordenadas[i][0] = ( (2 * win * x) / view_w) - win;
				coordenadas[i][1] = ( ( (2 * win) * (y-view_h) ) / -view_h) - win;
			}
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