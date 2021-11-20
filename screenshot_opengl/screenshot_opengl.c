# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
/*
  OpenGL include statement on MAC OSX:
*/
/*
# include <GLUT/glut.h>
*/
/*
  OpenGL include statement on normal systems.
*/
# include <GL/glut.h>
# include <GL/freeglut.h>

int main ( int argc, char *argv[] );
void display ( );
void myinit ( );
bool save_screenshot ( char *filename, int w, int h );

typedef GLfloat point2[2];

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for the SCREENSHOT program.

  Discussion:

    This program demonstrates how to save the current OpenGL graphics
    image in a screenshot file.

    This program draws the Barnsley fractal fern by plotting points.

    The main program calls GLUT functions to set up the windows,
    name the required callbacks and callback functions, in particular
    the DISPLAY callback.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2017

  Reference:

    Edward Angel,
    Interactive Computer Graphics:
    A Top-Down Approach with OpenGL,
    Second Edition,
    Addison Wesley, 2000.

    Michael Barnsley,
    Fractals Everywhere,
    Academic Press, 1988,
    ISBN: 0120790696,
    LC: QA614.86.B37.

    Cleve Moler,
    Experiments with MATLAB,
    ebook: http:www.mathworks.com/moler/exm/index.html
*/
{
  printf ( "\n" );
  printf ( "SCREENSHOT:\n" );
  printf ( "  C version\n" );
  printf ( "  Create OpenGL graphics, save as a screenshot file.\n" );

  glutInit ( &argc, argv );
  glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize ( 400, 600 );
  glutInitWindowPosition ( 0, 0 );
  glutCreateWindow ( "Barnsley Fractal Fern" );
  glutDisplayFunc ( display );

  myinit ( );

  glutMainLoop ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "SCREENSHOT:\n" );
  printf ( "  Normal end of execution.\n" );

  return 0;
}
/******************************************************************************/

void display ( )

/******************************************************************************/
/*
  Purpose:

    DISPLAY generates the graphics output.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 May 2011

  Reference:

    Edward Angel,
    Interactive Computer Graphics:
    A Top-Down Approach with OpenGL,
    Second Edition,
    Addison Wesley, 2000.

    Michael Barnsley,
    Fractals Everywhere,
    Academic Press, 1988,
    ISBN: 0120790696,
    LC: QA614.86.B37.

    Cleve Moler,
    Experiments with MATLAB,
    ebook: http:www.mathworks.com/moler/exm/index.html
*/
{
  int i;
  point2 p;
  int point_num = 500000;
  double prob[4] = { 0.85, 0.92, 0.99, 1.00 };
  double r;
  double x;
  double y;
/*
  Clear the window.
*/
  glClear ( GL_COLOR_BUFFER_BIT );
/*
  Compute and plot the points.
*/
  p[0] = drand48 ( );
  p[1] = drand48 ( );

  for ( i = 0; i < point_num; i++ )
  {
    r = drand48 ( );

    if ( r < prob[0] )
    {
      x =   0.85 * p[0] + 0.04 * p[1] + 0.0;
      y = - 0.04 * p[0] + 0.85 * p[1] + 1.6;
    }
    else if ( r < prob[1] )
    {
      x =   0.20 * p[0] - 0.26 * p[1] + 0.0;
      y =   0.23 * p[0] + 0.22 * p[1] + 1.6;
    }
    else if ( r < prob[2] )
    {
      x = - 0.15 * p[0] + 0.28 * p[1] + 0.0;
      y =   0.26 * p[0] + 0.24 * p[1] + 0.44;
    }
    else
    {
      x =   0.00 * p[0] + 0.00 * p[1] + 0.0;
      y =   0.00 * p[0] + 0.16 * p[1] + 0.0;
    }

    p[0] = x;
    p[1] = y;
/*
  Plot the new point.
*/
    glBegin ( GL_POINTS );
      glVertex2fv ( p );
    glEnd ( );
  }
/*
  Clear all buffers.
*/
  glFlush ( );
/*
  Save a screenshot.
*/
  save_screenshot ( "screenshot.tga", 400, 600 );

  return;
}
/******************************************************************************/

void myinit ( )

/******************************************************************************/
/*
  Purpose:

    MYINIT initializes OpenGL state variables dealing with viewing and attributes.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    09 May 2011

  Reference:

    Edward Angel,
    Interactive Computer Graphics:
    A Top-Down Approach with OpenGL,
    Second Edition,
    Addison Wesley, 2000.

    Michael Barnsley,
    Fractals Everywhere,
    Academic Press, 1988,
    ISBN: 0120790696,
    LC: QA614.86.B37.
*/
{
/*
  Set the background to WHITE.
*/
  glClearColor ( 1.0, 1.0, 1.0, 1.0 );
/*
  Draw in FOREST GREEN.
*/
  glColor3f ( 0.133, 0.545, 0.133 );
/*
  Set up a viewing window with origin at the lower left.
*/
  glMatrixMode ( GL_PROJECTION );
  glLoadIdentity ( );
  gluOrtho2D ( -4.0, 4.0, -1.0, 11.0 );
  glMatrixMode ( GL_MODELVIEW );

  return;
}
/******************************************************************************/

bool save_screenshot ( char *filename, int w, int h )

/******************************************************************************/
/*
  Purpose:

    SAVE_SCREENSHOT saves a screenshot of the current OpenGL image.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    06 March 2017

  Parameters:

    Input, string FILENAME, the name of the file to contain the screenshot.

    Input, int W, H, the width and height of the image.

    Output, bool SAVE_SCREENSHOT, is TRUE if the operation succeeded.
*/
{
/*
  Prevent the images from getting padded 
  when the width multiplied by 3 is not a multiple of 4.
*/
  glPixelStorei ( GL_PACK_ALIGNMENT, 1 );
/*
  Create the buffer, 3 channels per pixel.
*/
  char *dataBuffer = ( char * ) malloc ( 3 * w * h * sizeof ( char ) );
 
  if  ( ! dataBuffer ) 
  {
    return false;
   }
/*
  Fetch them from the backbuffer.
  We request the pixels in GL_BGR format, thanks to Berzeger for the tip.
*/
  glReadPixels ( (GLint)0, (GLint)0, (GLint)w, (GLint)h, GL_BGR, 
    GL_UNSIGNED_BYTE, dataBuffer );
/* 
  Create the file.
*/
  FILE *filePtr = fopen ( filename, "wb" );

  if ( ! filePtr ) 
  {
    return false;
  }
/*
  Set the header for the TARGA file.
*/
  unsigned char TGAheader[12] = { 0,0,2,0,0,0,0,0,0,0,0,0 };

  unsigned char header[6] = { w%256, w/256, h%256, h/256, 24, 0 };
/*
  Write the headers.
*/
  fwrite ( TGAheader, sizeof ( unsigned char ), 12, filePtr );
  fwrite ( header, sizeof ( unsigned char ), 6, filePtr );
/*
  Write the image data.
*/
  fwrite ( dataBuffer, sizeof ( GLubyte ), 3 * w * h, filePtr );
/*
  Close the file.
*/
  fclose ( filePtr );
/*
  Free memory.
*/
  free ( dataBuffer );
 
  printf ( "\n" );
  printf ( "Screenshot saved as '%s'\n", filename );

  return true;
}

