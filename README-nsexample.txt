
$Id: README-nsexample.txt,v 1.2 2003/11/01 12:12:48 vasiljevic Exp $

Example AOLserver Module
------------------------

This module demonstrates some guidelines to follow when creating an
AOLserver module.  Here they are in a nutshell:

  1) Each module has a README file.  The file can be named
     README-modulename.txt or readme.txt (the first form is preferred).

  2) Each file has an entry called "$Id: README-nsexample.txt,v 1.2 2003/11/01 12:12:48 vasiljevic Exp $" near the top of the
     document.  This includes html, adp, tcl, java, c, as well
     as any plain text file.

  3) The Makefile follows the format of the nsexample Makefile in this
     directory.

  4) A ChangeLog file reflects the changes made to the code. This can 
     be a simple cut-and-paste of your CVS log entry. Emacs users can
     type "C-x 4 a" to automatically create ChangeLog entries.

  5) Modules follow the AOLserver Engineering Manual guidelines. You
     can find it at http://aolserver.com/docs/devel/tech/standards.html

  6) CVS tags include the name of the module followed by the version.
     This is typically "nsmodulename3_0" or "nsmodulename_v3_0" (or 
     even just "nsmodulename_v3").  Major/minor numbers are delimited
     by underscores since CVS doesn't allow the use of the period char.

# EOF $RCSfile: README-nsexample.txt,v $

