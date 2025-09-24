# add_executable(ExecutableApp0 main.cpp)
# target_link_libraries(ExecutableApp0 PUBLIC LibraryBoilerplateCPP)

# add_executable(ExecutableApp1 main.cpp)
# target_link_libraries(ExecutableApp1 PUBLIC LibraryBoilerplateC)

add_executable(ExecutableSquareDigits mainSquareDigits.cpp app_logic_SquareDigits.cpp)
target_link_libraries(ExecutableSquareDigits PUBLIC LibrarySquareDigits)

