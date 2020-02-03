cmake_minimum_required(VERSION 3.15)

include(cmake/HunterGate.cmake)

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.245.tar.gz"
        SHA1 "36e7f44ee4b3f8e25683e9d700f05a27ecb0a848"
)

project(LatestHunter)

hunter_add_package(Boost COMPONENTS system filesystem iostreams thread log)
hunter_add_package(OpenSSL)

find_package(Boost CONFIG COMPONENTS system filesystem iostreams thread log)
find_package(OpenSSL)
find_package(Threads)

file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp")
add_executable(check ${src_files})
target_include_directories(check PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(check PRIVATE
        Boost::system Boost::filesystem Boost::iostreams Boost::thread Boost::log
        OpenSSL::Crypto OpenSSL::SSL Threads::Threads)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(check PRIVATE -Werror -Wall -Wextra -pedantic)
endif()