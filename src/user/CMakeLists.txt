add_library(user OBJECT user.cpp)

install (TARGETS user DESTINATION
/home/dmitry/workspace/git/six_degrees_separation_theory/test)
install (FILES user.h DESTINATION
/home/dmitry/workspace/git/six_degrees_separation_theory/test)
