#配置需要编译的boost所用的库
set(BUILD_BOOST_LIBS "filesystem,program_options,stacktrace,test")

ExternalProject_Add(libboost
        EXCLUDE_FROM_ALL 1
        URL ${PROJECT_SOURCE_DIR}/tar/boost_1_67_0.tar.gz
        #URL https://dl.bintray.com/boostorg/release/1.69.0/source/boost_1_69_0.tar.gz
        CONFIGURE_COMMAND ./bootstrap.sh --with-libraries=${BUILD_BOOST_LIBS}
        BUILD_IN_SOURCE 1
        BUILD_COMMAND ""
        INSTALL_COMMAND ./b2 cxxflags="-std=c++11" link=static install --prefix=${PROJECT_BINARY_DIR}
        )