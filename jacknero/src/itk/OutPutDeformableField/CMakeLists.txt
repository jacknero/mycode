PROJECT(ImageRegistration)
INCLUDE_REGULAR_EXPRESSION("^.*$")
 # Find ITK.
 FIND_PACKAGE(ITK REQUIRED)
 IF(ITK_FOUND)
     INCLUDE(${ITK_USE_FILE})
     ENDIF(ITK_FOUND)




IF(NOT BORLAND)

  ADD_EXECUTABLE(OutPutDeformableField OutPutDeformableField.cxx )
  TARGET_LINK_LIBRARIES(OutPutDeformableField ITKIO ITKNumerics)

ENDIF(NOT BORLAND)

