message("-- linking freeglut")
add_library(FREEGLUT freeglut.dll)
set_target_properties(FREEGLUT PROPERTIES LINKER_LANGUAGE C)