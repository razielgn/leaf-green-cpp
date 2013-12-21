SET(SDL2_IMAGE_SEARCH_PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
)

FIND_PATH(SDL2_IMAGE_INCLUDE_DIR SDL.h
  HINTS
  $ENV{SDL2_IMAGEDIR}
  PATH_SUFFIXES include/SDL2 include
  PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

FIND_LIBRARY(SDL2_IMAGE_LIBRARY_TEMP
  NAMES SDL2_IMAGE
  HINTS
  $ENV{SDL2_IMAGEDIR}
  PATH_SUFFIXES lib64 lib
  PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

IF(NOT SDL2_IMAGE_BUILDING_LIBRARY)
  IF(NOT ${SDL2_IMAGE_INCLUDE_DIR} MATCHES ".framework")
    # Non-OS X framework versions expect you to also dynamically link to
    # SDL2_IMAGEmain. This is mainly for Windows and OS X. Other (Unix) platforms
    # seem to provide SDL2_IMAGEmain for compatibility even though they don't
    # necessarily need it.
    FIND_LIBRARY(SDL2_IMAGEMAIN_LIBRARY
      NAMES SDL2_IMAGEmain
      HINTS
      $ENV{SDL2_IMAGEDIR}
      PATH_SUFFIXES lib64 lib
      PATHS ${SDL2_IMAGE_SEARCH_PATHS}
    )
  ENDIF(NOT ${SDL2_IMAGE_INCLUDE_DIR} MATCHES ".framework")
ENDIF(NOT SDL2_IMAGE_BUILDING_LIBRARY)

# SDL2_IMAGE may require threads on your system.
# The Apple build may not need an explicit flag because one of the
# frameworks may already provide it.
# But for non-OSX systems, I will use the CMake Threads package.
IF(NOT APPLE)
  FIND_PACKAGE(Threads)
ENDIF(NOT APPLE)

# MinGW needs an additional library, mwindows
# It's total link flags should look like -lmingw32 -lSDL2_IMAGEmain -lSDL2_IMAGE -lmwindows
# (Actually on second look, I think it only needs one of the m* libraries.)
IF(MINGW)
  SET(MINGW32_LIBRARY mingw32 CACHE STRING "mwindows for MinGW")
ENDIF(MINGW)

IF(SDL2_IMAGE_LIBRARY_TEMP)
  # For SDL2_IMAGEmain
  IF(NOT SDL2_IMAGE_BUILDING_LIBRARY)
    IF(SDL2_IMAGEMAIN_LIBRARY)
      SET(SDL2_IMAGE_LIBRARY_TEMP ${SDL2_IMAGEMAIN_LIBRARY} ${SDL2_IMAGE_LIBRARY_TEMP})
    ENDIF(SDL2_IMAGEMAIN_LIBRARY)
  ENDIF(NOT SDL2_IMAGE_BUILDING_LIBRARY)

  # For OS X, SDL2_IMAGE uses Cocoa as a backend so it must link to Cocoa.
  # CMake doesn't display the -framework Cocoa string in the UI even
  # though it actually is there if I modify a pre-used variable.
  # I think it has something to do with the CACHE STRING.
  # So I use a temporary variable until the end so I can set the
  # "real" variable in one-shot.
  IF(APPLE)
    SET(SDL2_IMAGE_LIBRARY_TEMP ${SDL2_IMAGE_LIBRARY_TEMP} "-framework Cocoa")
  ENDIF(APPLE)

  # For threads, as mentioned Apple doesn't need this.
  # In fact, there seems to be a problem if I used the Threads package
  # and try using this line, so I'm just skipping it entirely for OS X.
  IF(NOT APPLE)
    SET(SDL2_IMAGE_LIBRARY_TEMP ${SDL2_IMAGE_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
  ENDIF(NOT APPLE)

  # For MinGW library
  IF(MINGW)
    SET(SDL2_IMAGE_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_IMAGE_LIBRARY_TEMP})
  ENDIF(MINGW)

  # Set the final string here so the GUI reflects the final state.
  SET(SDL2_IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARY_TEMP} CACHE STRING "Where the SDL2_Image Library can be found")
  # Set the temp variable to INTERNAL so it is not seen in the CMake GUI
  SET(SDL2_IMAGE_LIBRARY_TEMP "${SDL2_IMAGE_LIBRARY_TEMP}" CACHE INTERNAL "")
ENDIF(SDL2_IMAGE_LIBRARY_TEMP)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_IMAGE REQUIRED_VARS SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)
