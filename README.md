qt-experiments
==============

An attempt to build a simple file database system, a bank account manager, the main aim of the project being 
learning the Qt framework(and C++ programming) myself and introducing Qt to those few who are here for it.

Instructions : Fire up the Qt creator --> open project --> bank.pro

Note(to those who are interested :P ) : The bank.cpp and bank.h contain plain C++ code(no Qt involved). It contains 
the core functionality to carry out operations like creating a record and searching etc . There is no user interaction in there.
The functions get the required data as parameters, save or retrieve them in a file and return the requested data.
So this should be the first piece of code that should be written. 

You can then create the GUI for user interaction and call the functions of bank class with the data obtained from GUI
as arguments.

This way the GUI and the core functionality remain separate and multiple people can work separately on different components of the project parallely.
