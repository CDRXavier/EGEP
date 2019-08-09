XXXX     X                  *
    X  X                    *
    XX      ***** ***** ***** *****
  X  X      *     *   * *   * *****
X     XXXX  ***** ***** ***** *****

Experimental Graphical Entertainment Program

An attempt at making a independent program featuring basic graphics and animations.
Avialiable for both the Arduboy platform and Windows.
Supporting Windows 2000 Professional SP4 or later.
____
Instructions(and explainations):
For VerArd (arduboy) version, things are pretty straightforward.
You have a '.ino' file which is the source code, and you have the '.hex' file for the compiled binary

For VerWin (windows) version, things are not straightforward at all.
The '.h' files are the header files that are heads of the '.cpp' C Plus Plus source code files.
You need all of those.
The '.rc' files are the resource script files (which are also needed) because there are modified content
that are different from the default resource scripts. Without those, the About box and the language of the
application will not work (if you compile it yourself)

You will also need the '.ico' icon files, because that is how it works ... (yeah).

The 'targetver.h' is relatively unimportant, as it defined the platform the program can run on.
(which is a non-issue because most Windows program runs on all windows platforms)

The 'stdafx.h' is the default, so you may or may not need to download that.

The 'EGEP_Original.cpp' is the original (uncleaned) sourcecode file. It is functional identical to the
'EGEP.cpp'.

Why do I not include the entire Visual Studio Project?
Because everything beside the source files (the ones I posted) have a cobweb of directories (especially the .sln)

What I suggest you to do, is that you create a project (Windows Desktop Program type), called EGEP.
They you copy-paste the downloaded files into that place, because the other irrelevant stuff
will have the right directory.


All right that is all. Enjoy and if any questions (or suggestions, or just want to say something):
E-mail at xavier194152@aol.com or drop me a message right on Github.
