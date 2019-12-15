cmake_minimum_required(VERSION 3.15)
project(Bubble_Movies)

set(CMAKE_CXX_STANDARD 17)

include_directories(header)
include_directories(header/datastructures)
include_directories(header/interfaces)
include_directories(header/model)
include_directories(header/utils)
include_directories(source)

add_executable(Bubble_Movies
        header/utils/intHC.h
        header/utils/stringHashable.h
        header/utils/sort.h
        header/datastructures/hash.h
        header/datastructures/tst.h
        header/interfaces/comparable.h
        header/interfaces/hashable.h
        header/model/movie.h
        header/model/rating.h
        header/model/user.h
        header/utils/utils.h
        source/utils/intHC.cpp
        source/utils/stringHashable.cpp
        source/utils/sort.ipp
        source/datastructures/hash.ipp
        source/datastructures/tst.cpp
        source/model/movie.cpp
        source/model/rating.cpp
        source/model/user.cpp
        source/utils/utils.cpp
        source/main.cpp
        header/utils/intHC.h source/utils/intHC.cpp header/model/tag.h source/model/tag.cpp source/api.cpp header/api.h)
