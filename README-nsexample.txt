
$Header: /cvsroot/aolserver/nsexample/README-nsexample.txt,v 1.1 2000/08/20 19:12:26 kriston Exp $


Example AOLserver Module
------------------------

This module demonstrates some guidelines to follow when creating an
AOLserver module.  Here they are in a nutshell:

  1) Each module has a readme file.  The file can be named
  README-modulename.txt or readme.txt (the first form is preferred).

  2) Each file has an entry called "$Header: /cvsroot/aolserver/nsexample/README-nsexample.txt,v 1.1 2000/08/20 19:12:26 kriston Exp $" near the top of the
  document.  This includes html, adp, tcl, java, c, as well as any
  plain text file.  Data files directly read by a module may be
  excluded.

  3) The Makefile follows the format of the nsexample Makefile in this
  directory.

  4) A ChangeLog file reflects the changes made to the code.  This can
  be a simple cut-and-paste of your CVS log entry.  This is absolutely
  essential!  Emacs users can type "C-x 4 a" to automatically create
  ChangeLog entries.

  5) Modules follow the AOLserver Engineering Manual guidelines at
  http://aolserver.com/doc/.

  6) CVS tags include the name of the module followed by the version.
  This is typically "nsmodulename3_0" or "nsmodulename_v3_0" (or even
  just "nsmodulename_v3").  Major and minor numbers are delimited by
  underscores since CVS doesn't allow the use of the period character.
  Tags should be done with care.  Feel free to contact
  feedback@aolserver.com for assistance.

  7) Try not to type cvs commands in your $TOP directory.  Always work
  from the subdirectory.  The only exception to this is "cvs update"
  and "cvs checkout".


Thanks for reading, and contribute away!

