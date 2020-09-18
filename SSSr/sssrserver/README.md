**SSSr** (**S**ystem **S**imulation **S**erve**r**) 
===============================
System Simulation Server And Client Project
-------------------------------------------



Installation
============

For building server example "ssserver" your compliler must support C++17 and std::filesystem (for example, gcc version 8 and higher). 

For compilation execute in the higest directory of repository:  <br>
    cmake CMAKE_C_FLAGS="-lstdc++fs" .            
    cmake --build .     

For ubuntu 18.04 by default you have to additionally install g++-8 and gcc-8 package and correct first command next way:
    cmake -D CMAKE_C_COMPILER=gcc-8 -D CMAKE_CXX_COMPILER=g++-8 -D CMAKE_C_FLAGS="-lstdc++fs" .  
since default compiler is gcc-7/g++-7.

More detailed information on content of project you can see at   <br> 
https://paulokoelio.github.io/.../  


LICENSE 
--------

Project in total (excluding 3rd party libraries) provided under license:  <br>
Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International Public License  <br>
License conditions and full wording you can get from:  <br>
https://creativecommons.org/licenses/by-nc-nd/4.0/  <br>
https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode  <br>
Or in the attached file License-BY-NC-ND-4.pdf
