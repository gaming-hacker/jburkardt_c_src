These are the example programs which are featured in the OpenGL
Programming Guide, Version 1.2.  To compile these programs, you
need OpenGL development libraries for your machine and Mark Kilgard's
GLUT (Graphics Library Utility Toolkit). 

There is a simple Imakefile in this directory, which can be used to 
create a Makefile to compile the example programs.  There is also 
a simple Makefile, which can be used to compile the programs
(in case your support doesn't support imake, or you just don't want 
to be bothered).  There is also a Makefile.win, which has been tested
on Windows-based PCs.

When using either the Imakefile or the Makefile,
you will probably need to modify some of the variables inside the
files to make sure that GLUT headers and libraries are correctly
included and linked.

The Imakefile should generate a good Makefile with a simple
command such as:
% imake -DUseInstalled -I/usr/lib/X11/config

There are a handful of modifications from the code which is
printed in the OpenGL Programming Guide.  Most noticeably, every
program (except for hello.c and double.c, which are featured in
the first chapter) has a keyboard callback function to exit the
program when the ESCape key is pressed.

* Changes between this directory and the examples printed in the book

Also, after the book went to press, a couple of discrepancies
between the UNIX and MS Windows compilers became noticeable, requiring
changes to the source code.  Most obviously, all PC programs had to
include <windows.h> before <gl.h> or <glu.h>.  GLUT already does
this in the correct order, so the simplest solution was to only
include <GL/glut.h> and to let it include (if needed) the windows.h,
gl.h, and glu.h files, in the correct order.

The torus.c program refers to a symbolic constant M_PI, which may
not be found on MS Windows based systems.  A new constant PI_ 
has replaced it and is defined within the program.

Several programs use callback functions.  The method of casting
those callback functions worked fine on UNIX based systems, but
not on PCs.  The programs quadric.c, surface.c, trim.c, tess.c,
and tesswind.c have been modified.  References to (GLvoid (*))
cast have been removed, and a reference to the CALLBACK type 
has been added to the declaration of the callback functions.
Where CALLBACK is undefined (for instance, in UNIX systems),
it is stubbed out by use of #ifndef.

The programs accpersp.c and dof.c used the variable names "near"
and "far" which are reserved words for PC compilers.  If needed,
these variables names are now redefined during pre-processing 
(by using #ifdef).

* OpenGL 1.0 to 1.1 compatibility issues

Most of these programs also run well on OpenGL 1.0.  There are
nine programs which use features not found in OpenGL 1.0.  The 
four programs checker.c, mipmap.c, texgen.c, and wrap.c use
texture objects, and have been modified so that they will avoid
the use of texture objects on OpenGL 1.1 machines.  So these
programs will still run well on OpenGL 1.0.

The five programs polyoff.c, texbind.c, texprox.c, texsub.c,
and varray.c demonstrate features which are new in OpenGL 1.1.
On OpenGL 1.0, these five programs will not run; instead an error
message will be printed out.  If your implementation of OpenGL 1.0
supports polygon offset, vertex array, and/or texture extensions,
you may be able to modify the code to run on your implementation.

* OpenGL 1.1 to 1.2 compatiblity issues

Most of the programs included in this distribution will work with
OpenGL 1.1.

* Notes for programs demonstrating the ARB Imaging Subset

With the introduction of OpenGL 1.2, the OpenGL Architecture Review
Board added the ARB Imaging Subset.  The imaging subset is not part of
the core OpenGL functionality, and as such, your implementation may not
support it.  For simplicity's sake, the programs included in this set of
programs do not check for support of the imaging subset; production
applications should.  These programs are: colormatrix.c, colortable.c,
convolution.c, histogram.c, minmax.c, and blendeqn.c.  These programs
may not compile, if your client library doesn't support the ARB Imaging
Subset.  Likewise, if your server (or hardware driver) does not export
the string, "GL_ARB_imaging" when you query for extensions, these
programs will not execute.
	   

Thank you.

Mason Woo - mason@woo.com
Dave Shreiner - shreiner@sgi.com
Co-authors of the OpenGL Programming Guide, Version 1.2
