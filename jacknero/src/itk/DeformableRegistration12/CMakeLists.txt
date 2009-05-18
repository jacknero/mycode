PROJECT(ImageRegistration)
INCLUDE_REGULAR_EXPRESSION("^.*$")
 # Find ITK.
 FIND_PACKAGE(ITK REQUIRED)
 IF(ITK_FOUND)
     INCLUDE(${ITK_USE_FILE})
     ENDIF(ITK_FOUND)




IF(NOT BORLAND)

  ADD_EXECUTABLE(DeformableRegistration12 DeformableRegistration12.cxx )
  TARGET_LINK_LIBRARIES(DeformableRegistration12 ITKIO ITKNumerics)

ENDIF(NOT BORLAND)

