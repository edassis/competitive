::-D CMAKE_C_COMPILER=C:/dev/TDM-GCC-32/bin/mingw32-gcc.exe -D CMAKE_CXX_COMPILER=C:/dev/TDM-GCC-32/bin/mingw32-g++.exe
@REM cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_C_COMPILER=c:/Users/eduar/scoop/apps/gcc/current/bin/gcc.exe -D CMAKE_CXX_COMPILER=c:/Users/eduar/scoop/apps/gcc/current/bin/g++.exe -Hd:/Repositorios/competitive -Bd:/Repositorios/competitive/build -G "Unix Makefiles"
cmake -D CMAKE_BUILD_TYPE=Debug -D CMAKE_C_COMPILER=c:/Users/eduar/scoop/apps/gcc/current/bin/gcc.exe -D CMAKE_CXX_COMPILER=c:/Users/eduar/scoop/apps/gcc/current/bin/g++.exe -B build -G "Unix Makefiles"
