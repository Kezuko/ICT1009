# ICT1009
1. Installation steps:


Pre-requisites:
Mingw, Qt creator


Delete folder (stated below) to solve executable crash bug (delete folder, then build project, then run the project in QT Creator):
ICT1009\C++\build-qtgui-Desktop_Qt_5_14_1_MinGW_64_bit-Debug

Open qt creator (at directory below) to modify the gui:
ICT1009\C++\qtgui




2. OOP principles used:


Inheritance: MainWindow.h (Parent class), MyModel.h, CNAModel.h (Child class) 
Explaination: Usage of super-sub class, and what files to #include

Encapsulation: All variables in MyModel.h, CNAModel.h (Child class) are in private access modifier
File level: using *.h and *.cpp for each class, together with #ifndef, #define, #endif header guards
variable level: using private/protected/public when necessary

Overriding: MyModel.h, CNAModel.h (Child class) overidding rowCount, ColumnCount, data, headerData method in QAbstractTableModel.h (Parent class)




3. Resources:



3 CSV files for CNA, TheGuardian and Twitter crawled recently with Java Project.





4. API





C++11 version only CSV parser. Header file only (.h), no Source file (.cpp). Source: https://github.com/AriaFallah/csv-parser
QCharts API. Usage of Display widgets to display aesthetic GUI.







