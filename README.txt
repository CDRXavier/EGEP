XXXX     X                  *
    X  X                    *
    XX      ***** ***** ***** *****
  X  X      *     *   * *   * *****
X     XXXX  ***** ***** ***** *****

Experimental Graphical Entertainment Program

An attempt at making a independent program featuring basic graphics and animations.
Avialiable for both the Arduboy platform and Windows.
Supporting Windows 7 or later.
____
Instructions(and explainations):
For Arduboy version (verArd), things are pretty straightforward.
You have a '.ino' file which is the source code, and you have the '.hex' file for the compiled binary

For Windows version (VerWin), It's a bit more complicated.
* The '.rc' files are the resource script files (which are also needed) because there are modified content
that are different from the default resource scripts. Without those, various UI elements of the
application will not work
* You will also need the '.ico' icon files.
* The 'targetver.h' defines the platform the program can run on. You might be able to get away without it.
* The 'stdafx.h' is the default, so I did not include that.
* The 'EGEP_Original.cpp' is the original (uncleaned) sourcecode file. It is functional identical to the
'EGEP.cpp'.
You will need Visual Studio (the purple one), and have "Desktop Development for Win32".
What I suggest you to do, is that you create a project (Windows Desktop Program type), called EGEP.
They you copy-paste the downloaded files into that place, because the other irrelevant stuff
will have the right directory. (upon creation)

If you are editing the '.rc' file, make sure you make the changes referenced elsewhere as well -- Visual Studio will not error-check the resource file, and it can't fix it for you if something goes wrong.
