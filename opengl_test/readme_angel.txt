
This directory includes the programs from Angel: Interactive Computer Graphics,
Addison-Wesley, Second Edition, 2000 as listed in Appendix A and other
programs referred to in the text.  All are in the tar file programs.tar. 

The Makefile can be used on most standard SGI installations. It should require
only slight modification for other linux and unix installations.

The programs that follow use the GLUT library for interfacing with
the window system. The naming of the functions follow
the OpenGL Programmer's Guide and  the GLUT Users Guide.
These programs share much of the same code. You should find functions,
such as the reshape callback, the initialization function, and the main
function, almost identical across the programs. Consequently, only
the first instance of each function contains extensive comments.

In all these programs, illustration of graphical principles, other than
efficiency, was the most important design criteria. You should find
numerous ways both to extend these programs and to make them
run more efficiently. In some instances, the same visual results can be
generated in a completely different manner, using OpenGL capabilities
other than the ones we used in the sample program.

______________________________

Programs with listings in Appendix A:

gasket.c: A program that generates 5000 points on the Sierpinski gasket
from Section 2.7

gasket2.c: Generates the Sierpinski gasket by recursive subdivision. The
depth of recursion is entered as a command line argument.

gasket3d.c: Three-dimensional version of gasket.c. Uses the mouse
to start (left button) and stop (middle button) the generation of
points. The right button exits the program.

tetra.c: Three-dimensional version of gasket2.c.

square.c: A program that illustrates the use of mouse with GLUT, as
discussed in Section 3.5. Note as compared to the book, this program
has a display routine added to it that is required by GLUT3.0.

newpaint.c:  The simple paint program developed in Chapter 3.

single_double.c: Program demonstrates both single and double
buffering using two windows. Rotation can be started and
stopped with the mouse.

cube.c: The rotating--cube program from Chapter 4.

cubev.c: Rotating cube using vertex arrays.

demo2.c: Rotating cube with virtual trackball.

cubeview.c: The walk--through program from Chapter 5.

sphere.c: The program that generates approximations to a sphere
by recursive subdivision generation from Chapter 6.

____________________________________________

Other programs referred to in the book.

cubes.c: Shadow generation using projection from Chapter 5.

cubevs.c: Same as cubes.c but uses vertex arrays.

robot.c: A program that moves the  simple robot from Chapter 8.

figure.c: Program that moves the figure from Chapter 8.

figuretree.c: Same as figure.c bvut using static nodes and
a general traversal algorithm

dynamic.c: Same as figuretree.c but uses dynamic nodes.

teapot.c: A program that generates approximations to  the Utah teapot by
recursive subdivision as discussed in Chapter 10. File teapot.data
contains the vertex data.

bteapot.c: Generates shaded teapot using OpenGL evaluators. 
Data for vertices is in vertex.h and for patches on patches.h

mandelbrot.c: A program that generates approximations to the Mandelbrot
set as discussed in Chapter 11.

contour2.c: Contour generating program from Chapter 12.

