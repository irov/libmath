cmake_minimum_required(VERSION 3.0)

PROJECT(math)

OPTION(LIBMATH_EXTERNAL_BUILD "LIBMATH_EXTERNAL_BUILD" OFF)
OPTION(LIBMATH_EXAMPLES_BUILD "LIBMATH_EXAMPLES_BUILD" ON)
OPTION(LIBMATH_INSTALL "LIBMATH_INSTALL" OFF )

IF(NOT LIBMATH_EXTERNAL_BUILD)
    set(CMAKE_CXX_STANDARD 17)
    
    if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL Intel)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
    elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4710") #function not inlined 
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4738") #storing 32-bit float result in memory, possible loss of performance
    endif()
ENDIF()

MACRO( ADD_FILTER group_name )
	SOURCE_GROUP( ${group_name} FILES ${ARGN} )
	SET( SRC_FILES ${SRC_FILES} ${ARGN} )
ENDMACRO()

ADD_FILTER(
utils
	include/math/utils.h
)

ADD_FILTER(
isometric
    src/isometric.cpp
	include/math/isometric.h
    include/math/isometric_inline.h
)

ADD_FILTER(
rect
    src/rect.cpp
	include/math/rect.h
    include/math/rect_inline.h
)

ADD_FILTER(
uv4
    src/uv4.cpp
	include/math/uv4.h
    include/math/uv4_inline.h
)

ADD_FILTER(
angle
	src/angle.cpp
	include/math/angle.h
	include/math/angle_inline.h
)

ADD_FILTER(
box2
	src/box2.cpp
	include/math/box2.h
	include/math/box2_inline.h
)

ADD_FILTER(
box3
	src/box3.cpp
	include/math/box3.h
	include/math/box3_inline.h
)

ADD_FILTER(
clamp
	include/math/clamp.h
)

ADD_FILTER(
line2
	src/line2.cpp
	include/math/line2.h
	include/math/line2_inline.h
)

ADD_FILTER(
segment2
	src/segment2.cpp
	include/math/segment2.h
	include/math/segment2_inline.h
)

ADD_FILTER(
sphere2
	src/sphere2.cpp
	include/math/sphere2.h
	include/math/sphere2_inline.h
)


ADD_FILTER(
capsule2
	src/capsule2.cpp
	include/math/capsule2.h
	include/math/capsule2_inline.h
)

ADD_FILTER(
triangle
	src/triangle.cpp
	include/math/triangle.h
	include/math/triangle_inline.h
)

ADD_FILTER(
mat2
	src/mat2.cpp
	include/math/mat2.h
	include/math/mat2_inline.h
)

ADD_FILTER(
mat3
	src/mat3.cpp
	include/math/mat3.h
	include/math/mat3_inline.h
)

ADD_FILTER(
mat4
	src/mat4.cpp
	include/math/mat4.h
	include/math/mat4_inline.h
)

ADD_FILTER(
plane
	src/plane.cpp
	include/math/plane.h
	include/math/plane_inline.h
)

ADD_FILTER(
quat
	src/quat.cpp
	include/math/quat.h
	include/math/quat_inline.h
)

ADD_FILTER(
simplex
	src/simplex.cpp
	include/math/simplex.h
	include/math/simplex_inline.h
)

ADD_FILTER(
vec2
	src/vec2.cpp
	include/math/vec2.h
	include/math/vec2_inline.h
)

ADD_FILTER(
vec3
	src/vec3.cpp
	include/math/vec3.h
	include/math/vec3_inline.h
)

ADD_FILTER(
vec4
	src/vec4.cpp
	include/math/vec4.h
	include/math/vec4_inline.h
)

ADD_FILTER(
ccd
    src/ccd.cpp
    include/math/ccd.h
    include/math/ccd_inline.h
)

ADD_FILTER(
parabola
    src/parabola.cpp
    include/math/parabola.h
    include/math/parabola_inline.h
)

ADD_FILTER(
convex8
    src/convex8.cpp
    include/math/convex8.h
    include/math/convex8_inline.h
)

ADD_FILTER(
constant
    include/math/constant.h
)

ADD_FILTER(
config
	include/math/config.h    
)

INCLUDE_DIRECTORIES( ${PROJECT_NAME} include ) 

ADD_LIBRARY( ${PROJECT_NAME} STATIC ${SRC_FILES} )

if(LIBMATH_INSTALL)
    install(DIRECTORY include
        DESTINATION .
        FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h")

    install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
endif()


if(LIBMATH_EXAMPLES_BUILD)
    set(
    Sandbox_SOURCES
        sandbox/main.cpp
    )
    
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE -D_SCL_SECURE_NO_WARNINGS)

    INCLUDE_DIRECTORIES( Sandbox ../include )

    ADD_EXECUTABLE( Sandbox ${Sandbox_SOURCES} )

    TARGET_LINK_LIBRARIES( Sandbox math )
endif()