#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display( void )
{
/* definicao do tipo ponto */
typedef GLfloat point2[2];
/* triangulo */
point2 vertices[3]={{0.0,0.0},
{250.0,500.0}, {500.0,0.0}};
int i, j, k;
point2 p ={75.0,50.0}; /* ponto inicial
arbitrario */
glClear(GL_COLOR_BUFFER_BIT); /* limpar a
janela */
/* computar e desenhar 5000 novos pontos */
for( k=0; k<60000; k++)
{
/* escolher um vertice aleatoriamente */
j=rand()%3;
/* determinar o ponto medio entre p e o
vertice escolhido */
p[0] = (p[0]+vertices[j][0])/2.0;
p[1] = (p[1]+vertices[j][1])/2.0;
/* desenhar o novo ponto */
glBegin(GL_POINTS);
glVertex2fv(p);
glEnd();
}
glFlush(); /* forca a exibicao do que ja
foi mandado desenhar */
}

#include <GL/glut.h>
void iniciaOpenGL(void)
{
/* atributos */
/* fundo branco, desenho vermelho */
glClearColor(1.0, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
/* parâmetros de visualização */
/* janela do mundo 500 x 500, com origem no
canto inferior esquerdo */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 500.0, 0.0, 500.0);
glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char** argv)
{
/* Inicializacao padrao da GLUT */
glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE |
GLUT_RGB); /*default (desnecessario)*/
/* janela da tela 400 x 400 */
glutInitWindowSize(400,400);
/* posição do canto sup. esq. da janela */
glutInitWindowPosition(0,0);
/* titulo da janela */
glutCreateWindow("Triângulo de Sierpinski");
/* registro da funcao de exibicao */
glutDisplayFunc(display);
iniciaOpenGL();
/* entrada no loop de eventos */
glutMainLoop();
}