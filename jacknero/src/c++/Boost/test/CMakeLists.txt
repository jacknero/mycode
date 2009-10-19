PROJECT(GetDeformationField)
cmake_minimum_required(VERSION 2.6)
INCLUDE_REGULAR_EXPRESSION("^.*$")
# Find ITK.
FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
  INCLUDE(${ITK_USE_FILE})
ENDIF(ITK_FOUND)

find_package(Boost 1.34.0)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif(Boost_FOUND)

ADD_EXECUTABLE(ImageReadWrite test.cxx)
TARGET_LINK_LIBRARIES(ImageReadWrite ITKNumerics  ITKIO)

