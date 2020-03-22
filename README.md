# ICT1009
1. Installation steps:


Pre-requisites:
Mingw, Qt creator


Delete folder (stated below) to solve executable crash bug (delete folder, then build project, then run the project in QT Creator):
ICT1009\C++\build-qtgui-Desktop_Qt_5_14_1_MinGW_64_bit-Debug

Open qt creator (at directory below) to modify the gui:
ICT1009\C++\qtgui




2. OOP principles used:


Inheritance: SharedResource.h (Parent class), Search.h (Child class) 
Explaination: Usage of super-sub class, and what files to #include

Encapsulation: 
File level: using *.h and *.cpp for each class, together with #ifndef, #define, #endif header guards
variable level: using private/protected/public when necessary

Overriding: Display.h (Child class) overidding DisplayTable() method in SharedResource.h (Parent class)
