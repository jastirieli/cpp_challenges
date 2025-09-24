add_library(LibraryBoilerplateCppFortran STATIC fortran_wrapper.cpp helloworld.f90)


target_include_directories(LibraryBoilerplateCppFortran PUBLIC "./")
