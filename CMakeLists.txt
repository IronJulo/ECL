# This cmake file is used to generate the EmbeddedCoreLibrary

add_library(EmbeddedCoreLibrary INTERFACE)
target_include_directories(EmbeddedCoreLibrary INTERFACE .)
target_include_directories(EmbeddedCoreLibrary INTERFACE src)
target_include_directories(EmbeddedCoreLibrary INTERFACE include)