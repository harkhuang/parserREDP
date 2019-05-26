

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

add_executable(parser redisparser.cpp redisvalue.cpp test.cpp)
#target_include_directories(test   ${BOOST_INCLUDE_DIRS})
#target_link_libraries(test   ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#

target_link_libraries(parser
        boost_system
        boost_filesystem
        boost_program_options
        boost_unit_test_framework
        )