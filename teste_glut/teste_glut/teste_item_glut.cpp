/*
 * Copyright (c) 2009 University of Michigan, Ann Arbor.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of Michigan, Ann Arbor. The name of the University 
 * may not be used to endorse or promote products derived from this 
 * software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Authors: Manoj Rajagopalan, Sugih Jamin
*/
#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define NENDS 4           /* number of end "points" to draw */

GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
int ends[NENDS][2];       /* array of 2D points */

/* Program initialization NOT OpenGL/GLUT dependent,
   as we haven't created a GLUT window yet */
void
init(void)
{
  width  = 1280.0;                 /* initial window width and height, */
  height = 800.0;                  /* within which we draw. */

  ends[0][0] = (int)(0.25*width);  /* (0,0) is the lower left corner */
  ends[0][1] = (int)(0.25*height);
  ends[1][0] = (int)(0.75*width);
  ends[1][1] = (int)(0.25*height);

}

/* Callback functions for GLUT */

/* Draw the window - this is where all the GL actions are */
void
display(void)
{
  int i;

  /* clear the screen to white */
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black line */
  glColor3f(0.0, 0.0, 0.0);
 
  // glBegin(GL_LINES);
   // for (i = 0; i < NENDS; ++i) {
     // glVertex2iv((GLint *) ends[i]);
    //}

	glBegin(GL_POINTS);
    //for (i = 0; i < NENDS; ++i) {
	  glVertex2f(289.0, 190.0);
	  glVertex2f(320.0, 123.0);
	  glVertex2f(74.0, 74.0);
	  glVertex2f(239.0, 67.0);
	  glVertex2f(194.0, 101.0);
	  glVertex2f(20.0, 10.0);
	  glVertex2f(129.0, 83.0);
	  glVertex2f(75.0, 73.0);
    //}

	glEnd();
  glFlush();
}

/* Called when window is resized,
   also when window is first created,
   before the first call to display(). */
void
reshape(int w, int h)
{
  /* save new screen dimensions */
  width = (GLdouble) w;
  height = (GLdouble) h;

  /* tell OpenGL to use the whole window for drawing */
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  /* do an orthographic parallel projection with the coordinate
     system set to first quadrant, limited by screen/window size */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, width, 0.0, height);
}

int
main(int argc, char *argv[])
{
  /* perform initialization NOT OpenGL/GLUT dependent,
     as we haven't created a GLUT window yet */
  init();

  /* initialize GLUT, let it extract command-line 
     GLUT options that you may provide 
     - NOTE THE '&' BEFORE argc */
  glutInit(&argc, argv); //inicializa tudo que for relativo a janela de inicialização

  /* specify the display to be single 
     buffered and color as RGBA values */
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); //qd cria a janela que mostra a linha, pode ter várias formas de trabalhar com ela. Diz qe a janela pode ser colorida.. // GLUT Single = Somente um buffer de display

  /* set the initial window size */
  glutInitWindowSize((int) width, (int) height); //inicializa uma janela com a largura e altura definidas no init

  /* create the window and store the handle to it */
  wd = glutCreateWindow("Experiment with line drawing" /* title */ ); //janela criada, com título e pans

  /* --- register callbacks with GLUT --- */

  /* register function to handle window resizes */
  glutReshapeFunc(reshape); //função de modificar o tamanho da janela: reshape

  /* register function that draws in the window */
  glutDisplayFunc(display); //cuida da janela onde está desenhando

  glPointSize(5.0);

  /* start the GLUT main loop */
  glutMainLoop();

  return 0;
}