# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             subdir-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             subdir-lib.cpp)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       subdir-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )