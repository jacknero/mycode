PROJECT(GetDeformationField)
cmake_minimum_required(VERSION 2.6)
INCLUDE_REGULAR_EXPRESSION("^.*$")
# Find ITK.
FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

find_package(Boost 1.35.0 COMPONENTS asio system regex filesystem)
if (Boost_FOUND)
  link_directories(${Boost_LIBRARY_DIRS})
  include_directories(${Boost_INCLUDE_DIRS})
endif(Boost_FOUND)

ADD_EXECUTABLE(ImageReadWrite test.cxx)
TARGET_LINK_LIBRARIES(ImageReadWrite ITKNumerics  ITKIO ${Boost_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

