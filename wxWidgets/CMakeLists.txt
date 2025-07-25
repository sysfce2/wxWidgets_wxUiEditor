cmake_minimum_required(VERSION 3.20)

project(wxWidgets33
    LANGUAGES
    CXX C
    VERSION 3.3.0.0
    DESCRIPTION "wxWidgets 3.3.0"  # see ../include/wx/version.h
    HOMEPAGE_URL "https://github.com/wxWidgets/wxWidgets"
)

####################### Options #######################

option(BUILD_SHARED_LIBS "Build wxWidgets shared libraries" OFF)

if (BUILD_SHARED_LIBS)
    message(NOTICE "Building wxWidgets shared libraries")
else()
    message(NOTICE "Building wxWidgets static libraries")
endif()

####################### Check for Multi-Config Generator #######################

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if (NOT isMultiConfig)
    message("\nBecause you are using a single target generator, you MUST specify")
    message("    a \"--config [Debug|Release]\" option with the cmake --build command\n")

    set(allowedBuildTypes Debug Release)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if (NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    elseif (NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

####################### General Settings #######################

set(CMAKE_CXX_STANDARD 17)  # Note that official build is using C++11
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    # /O1 often results in faster code than /O2 due to CPU caching
    string(REPLACE "/O2" "/O1" cl_optimize ${CMAKE_CXX_FLAGS_RELEASE})
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)

    string(REPLACE "/O2" "/O1" cl_optimize ${CMAKE_C_FLAGS_RELEASE})
    set(CMAKE_C_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C Release flags" FORCE)

    # Using /Z7 instead of /Zi to avoid blocking while parallel compilers write to the pdb file.
    # This can considerably speed up build times at the cost of larger object files.
    string(REPLACE "/Zi" "/Z7" z_seven ${CMAKE_CXX_FLAGS_DEBUG})
    set(CMAKE_CXX_FLAGS_DEBUG ${z_seven} CACHE STRING "C++ Debug flags" FORCE)

    string(REPLACE "/Zi" "/Z7" z_seven ${CMAKE_C_FLAGS_DEBUG})
    set(CMAKE_C_FLAGS_DEBUG ${z_seven} CACHE STRING "C Debug flags" FORCE)

    # Use static runtime for Release builds to run with Wine without needing to install the dlls
    if (NOT BUILD_SHARED_LIBS)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
elseif(UNIX)
    # This should work for gcc and clang (including xcode which is based on clang)
    # -O2 can result in faster code than -O3 due to CPU caching.
    string(REPLACE "-O3" "-O2" cl_optimize ${CMAKE_CXX_FLAGS_RELEASE})
    set(CMAKE_CXX_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C++ Release flags" FORCE)
    string(REPLACE "-O3" "-O2" cl_optimize ${CMAKE_C_FLAGS_RELEASE})
    set(CMAKE_C_FLAGS_RELEASE ${cl_optimize} CACHE STRING "C Release flags" FORCE)
endif()

include( wxWidgets.cmake )  # This will set ${common_sources}, ${msw_sources}, ${unix_sources} and ${osx_sources}
include( wxCLib.cmake )     # This will set ${wxCLib_sources} with list of files

if (WIN32)
    list(APPEND wxCLib_sources src/tiff/libtiff/tif_win32.c)
endif()

if (WIN32)
    add_library(wxWidgets33 ${common_sources} ${msw_sources} )
elseif (APPLE)
    add_library(wxWidgets33 ${common_sources} ${osx_sources} )
elseif (UNIX)
    add_library(wxWidgets33 ${common_sources} ${unix_sources} )
endif()

if (UNIX)
    set (wxCLib_platform_files
        src/tiff/libtiff/tif_unix.c
        src/tiff/libtiff/libtiff.def
    )
else()
    set (wxCLib_platform_files src/tiff/libtiff/tif_win32.c)
endif()

add_library(wxCLib STATIC
    ${wxCLib_sources}
    ${wxCLib_platform_files}
)

if (BUILD_SHARED_LIBS)
    target_compile_definitions(wxWidgets33 PRIVATE WXMAKINGDLL)
endif()

if (MSVC)
    # /GL -- combined with the Linker flag /LTCG allows whole program optimization in Release build
    target_compile_options(wxWidgets33 PRIVATE "$<$<CONFIG:Release>:/GL>")
elseif(UNIX)
    target_compile_options(wxWidgets33 PRIVATE "-fPIC")
    target_compile_options(wxCLib PRIVATE "-fPIC")
endif()

if (WIN32)
    target_compile_definitions(wxWidgets33 PRIVATE
        __WXMSW__
        WIN32
    )
elseif (UNIX)
    target_compile_definitions(wxWidgets33 PRIVATE
        __WXGTK3__
        __WXGTK220__  # required for activityindicator.cpp to be pulled in
        __UNIX__
    )
endif()

target_compile_definitions(wxWidgets33 PRIVATE
    WXBUILDING
    _CRT_SECURE_NO_DEPRECATE=1
    _CRT_NON_CONFORMING_SWPRINTFS=1
    _SCL_SECURE_NO_WARNINGS=1
    SCI_LEXER
    NO_CXX11_REGEX
    LINK_LEXERS
)

if (WIN32)
    target_compile_definitions(wxCLib PRIVATE
        PCRE2_CODE_UNIT_WIDTH=16
        NEWLINE_DEFAULT=2
        LINK_SIZE=2
        PARENS_NEST_LIMIT=250
        HEAP_LIMIT=20000000
        MATCH_LIMIT=10000000
        MATCH_LIMIT_DEPTH=10000000
        MAX_NAME_COUNT=10000
        MAX_NAME_SIZE=32
    )
else()
    target_compile_definitions(wxCLib PRIVATE
        PCRE2_CODE_UNIT_WIDTH=8
        NEWLINE_DEFAULT=2
        LINK_SIZE=2
        PARENS_NEST_LIMIT=250
        HEAP_LIMIT=20000000
        MATCH_LIMIT=10000000
        MATCH_LIMIT_DEPTH=10000000
        MAX_NAME_COUNT=10000
        MAX_NAME_SIZE=32
    )

endif()

target_precompile_headers(wxWidgets33 PRIVATE "include/wx/wxprec.h")

if (WIN32)
    set(setup_dir win)
elseif (UNIX)
    set(setup_dir unix)
endif()

target_include_directories(wxWidgets33 PRIVATE
    ${setup_dir}
    include
    src/tiff/libtiff
    src/jpeg
    src/png
    src/zlib
    3rdparty/pcre/src/wx
    src/expat/expat/lib

    # Needed for the wx_stc library
    src/stc/scintilla/include
    src/stc/lexilla/include
    src/stc/lexilla/access
    src/stc/lexilla/lexlib
    src/stc/scintilla/src

    3rdparty/lunasvg/include
    3rdparty/lunasvg/plutovg/include
)

target_include_directories(wxCLib PRIVATE
    ${setup_dir}
    include
    src/tiff/libtiff
    src/jpeg
    src/zlib
    3rdparty/pcre/src/wx
    src/expat/expat/lib
    3rdparty/lunasvg/plutovg/include
)

if (BUILD_SHARED_LIBS)
    if (WIN32)
        target_link_libraries(wxWidgets33 PRIVATE wxCLib Winmm Ws2_32 Rpcrt4 Comctl32)
    endif()
endif()

include(CMakePackageConfigHelpers)
configure_file(
    "${CMAKE_CURRENT_LIST_DIR}/cmake/wxWidgetsConfig.cmake.in"
    "${CMAKE_CURRENT_LIST_DIR}/wxWidgetsConfig.cmake"
    @ONLY
)
