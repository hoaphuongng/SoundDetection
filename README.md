# SOUND DETECTION APPLICATION
Latest update 2015.12.25 by Phuong Nguyen.
Original source code by Gao Chao.

Contact: hoaphuong310596@gmail.com

I. DESCRIPTION
-----------
Sound Detection Application allows users to recognize sounds through microphone. This application determines users' sound and displays soundwave in the output screen. Our project uses Raspberry Pi Model B+. 

II. HARDWARE AND SOFTWARE USING
-------------------------------
This application has been built using Raspberry Pi with Raspbian Operating System WHEZZY and written in C programming language.

* For more information, see: https://portal.vamk.fi/course/view.php?id=4143 

III. INSTALLATION
-----------------
Save sound_detection.tar file and extract to install this application.
The .tar file contains:
	screen.h
		This header file is for screen-displaying section where contains some user-defined data and function declarations (screen-clearing, colour setting and resetting, graph wave).
	appdevWav.h
		This header file contains some constant and function declaration for sound information and graph display.
	screen.c
		This C file processes screen functions, flushes out UI of this application.
	appdevWav.c
		This C file contains function definition about soundwave information.
	testmain.c
		This C file has call main functions.
	makefile
		Containing compiling command gcc.

IV. USAGE INSTRUCTION
----------------------
* This application can be run on various OS.

On Terminals, go to the path of containing folder (which you extracted the above folder), enter:
	make
	./testmain.a

This will run the application.

V. CONTRIBUTING
---------------
Contact: hoaphuong310596@gmail.com

VI. LICENSE
-----------
Copyright ©2015 | Vaasa University of Applied Sciences.
