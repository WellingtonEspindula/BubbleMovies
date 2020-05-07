cmake_minimum_required(VERSION 3.15)
project(Bubble_Movies)

set(CMAKE_CXX_STANDARD 17)

include_directories(source/datastructures)
include_directories(source/interfaces)
include_directories(source/model)
include_directories(source/utils)
include_directories(source)

add_executable(Bubble_Movies
        source/utils/intHC.h
        source/utils/stringHashable.h
        source/utils/sort.h
        source/datastructures/hash.h
        source/datastructures/tst.h
        source/interfaces/comparable.h
        source/interfaces/hashable.h
        source/model/movie.h
        source/model/rating.h
        source/model/user.h
        source/utils/utils.h
        source/utils/intHC.cpp
        source/utils/stringHashable.cpp
        source/utils/sort.ipp
        source/datastructures/hash.ipp
        source/datastructures/tst.cpp
        source/model/movie.cpp
        source/model/rating.cpp
        source/model/user.cpp
        source/utils/utils.cpp
        source/utils/intHC.h
        source/utils/intHC.cpp
        source/model/tag.h
        source/model/tag.cpp
        source/api.cpp
        source/api.h
        source/main.cpp)
