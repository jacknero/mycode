 
FIND_PACKAGE(ITK REQUIRED)
  IF(ITK_FOUND)
         INCLUDE(${ITK_USE_FILE})
              ENDIF(ITK_FOUND)

               FIND_PACKAGE(VTK)
                IF(VTK_FOUND)
                       INCLUDE(${USE_VTK_FILE})
                            ENDIF(VTK_FOUND)

FOREACH(exe itkReadITKImageShowVTK
            )
  ADD_EXECUTABLE(${exe} ${exe}.cxx)
  INSTALL_TARGETS(/bin ${exe})

  # Stuff was moved from vtkHybrid to vtkWidgets
  # Link against vtkWidgets if it is found, otherwise link against the older
  # library, vtkHybrid .
  IF(VTK_KITS MATCHES WIDGETS)
    TARGET_LINK_LIBRARIES(${exe} ITKBasicFilters ITKIO vtkRendering vtkIO vtkWidgets)
  ELSE(VTK_KITS MATCHES WIDGETS)
    TARGET_LINK_LIBRARIES(${exe} ITKBasicFilters ITKIO vtkRendering vtkIO vtkHybrid)
  ENDIF(VTK_KITS MATCHES WIDGETS)
ENDFOREACH(exe)




