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
For VerArd (arduboy) version, things are pretty straightforward.
You have a '.ino' file which is the source code, and you have the '.hex' file for the compiled binary

For VerWin (windows) version, things are not straightforward at all.
First, download all of them:
* The '.rc' files are the resource script files (which are also needed) because there are modified content
that are different from the default resource scripts. Without those, the About box and the language of the
application will not work
* You will also need the '.ico' icon files.
* The 'targetver.h' is relatively unimportant, as it defined the platform the program can run on. You might be able to get away without it.
* The 'stdafx.h' is the default, so I did not include that.
* The 'EGEP_Original.cpp' is the original (uncleaned) sourcecode file. It is functional identical to the
'EGEP.cpp'.

Why do I not include the entire Visual Studio Project?
Because everything beside the source files (the ones I posted) have a cobweb of directories (especially the .sln)

What I suggest you to do, is that you create a project (Windows Desktop Program type), called EGEP.
They you copy-paste the downloaded files into that place, because the other irrelevant stuff
will have the right directory. (upon creation)

If you are editing the '.rc' file, make sure you don't change stuff you are not supposed to change --- Visual Studio
will have no idea why the are wrong, and it can't fix it for you. You have to open those files in a separate text editor.
Wordpad recommended.

YOU DO NOT NEED ANY RESOURCE FILE IF YOU RUN THE '.EXE' FILE, BECAUSE THE '.EXE' EXECUTABLE FILES ARE COMPILED.
THEY ONLY NEED THE FILES COMING WITH YOUR WINDOWS INSTALLATION. IF THEY DO NOT WORK THEN ... TRY ANOTHER COMPUTER.
NOTE: THE DEBUG VERSION NEED A FILE ONLY IF YOU INSTALLED VISUAL STUDIO (to debug) AND THEREFORE WILL NOT WORK ON ALL MACHINES
THE RELEASE VERSION SHOULD (SHOULD) WORK ON ALL.

