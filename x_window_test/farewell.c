# include <stdio.h>
# include <stdlib.h>

# include <X11/Intrinsic.h>
# include <X11/StringDefs.h>
# include <X11/Xaw/Command.h>

int main ( int argc, char *argv[] );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
/*
  Purpose:

    MAIN is the main program for FAREWELL.

  Discussion:

    FAREWELL puts up an X window which is dismissed when the mouse button 
    is pressed.

  Compilation:

    gcc farewell.cc -lXaw -lXt

  Reference:

    Theo Pavlidis,
    Fundamentals of X Programming: Graphical User Interfaces and Beyond,
    Kluwer Academic/Plenum Publishers, 1999

  Modified:

    31 January 2003
*/
{
  XtAppContext app;
  Widget button;
  Widget toplevel;

  printf ( "\n" );
  printf ( "FAREWELL:\n" );
  printf ( "  X-Window/C++ version.\n" );
/*
  Create a top level shell widget;
*/
  toplevel = XtAppInitialize ( &app, "Farewell", NULL,
    0, &argc, argv, NULL, NULL, 0 );
/*
  Create the button widget.
*/
  button = XtVaCreateManagedWidget ( "button", commandWidgetClass,
    toplevel, XtNlabel, "Hello World!", XtNwidth, 256, XtNheight, 256, NULL );
/*
  Associate the callback function.
*/
  XtAddCallback ( button, XtNcallback, (XtCallbackProc) exit, NULL );
/*
  Realize the widgets.
*/
  XtRealizeWidget ( toplevel );
/*
  Enter the event loop.
*/
  XtAppMainLoop ( app );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "FAREWELL:\n" );
  printf ( " Normal end of execution.\n" );

  return 0;
}
