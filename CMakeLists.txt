cmake_minimum_required(VERSION 3.15)

include(cmake/HunterGate.cmake)

HunterGate(
        URL "https://github.com/nxxm/hunter/archive/feature/fix-boost-1.72-cmake-package-configs.zip"
        SHA1 "3092ec022af99e70bb4b11973ec48f1818e3bc51"
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