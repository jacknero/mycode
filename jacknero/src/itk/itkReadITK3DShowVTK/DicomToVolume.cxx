

#include "vtkRenderer.h"
#include "vtkImageWriter.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include <vtkDICOMImageReader.h>
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkOutlineFilter.h"
#include "vtkCamera.h"
#include "vtkProperty.h"
#include "vtkPolyDataNormals.h"
#include "vtkContourFilter.h"

//for transform
#include "vtkTransform.h"
#include "vtkTransformPolyDataFilter.h"
#include "vtkImageReslice.h"
#include "vtkPolyDataWriter.h"
//end for transform 
//for Capture
#include "vtkWindowToImageFilter.h"
#include "vtkPNGWriter.h"
//for Capture
#include "vtkStructuredPointsWriter.h"

int main(int argc, char * argv[]){

  vtkRenderer *aRenderer = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer(aRenderer);

  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  vtkDICOMImageReader *reader = vtkDICOMImageReader::New();
  reader->SetDirectoryName(argv[1]);
  reader->Update();

  vtkContourFilter *skinExtractor = vtkContourFilter::New();
  skinExtractor->SetInputConnection(reader->GetOutputPort());
  skinExtractor->SetValue(0, 500);
  

  vtkPolyDataNormals *skinNormals = vtkPolyDataNormals::New();
  skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
  skinNormals->SetFeatureAngle(60.0);

  vtkPolyDataMapper *skinMapper = vtkPolyDataMapper::New();
  skinMapper->SetInputConnection(skinNormals->GetOutputPort());
  skinMapper->ScalarVisibilityOff();

  vtkActor *skin = vtkActor::New();
  skin->SetMapper(skinMapper);

  vtkOutlineFilter *outlineData = vtkOutlineFilter::New();
  outlineData->SetInputConnection(reader->GetOutputPort());

  vtkPolyDataMapper *mapOutline = vtkPolyDataMapper::New();
  mapOutline->SetInputConnection(outlineData->GetOutputPort());

  vtkActor *outline = vtkActor::New();
  outline->SetMapper(mapOutline);
  outline->GetProperty()->SetColor(0,0,0);

  //for transform

  vtkTransform *transform = vtkTransform::New();
  transform->Identity();
  transform->Translate(atof(argv[3]),0,atof(argv[4]));


  mapOutline->Update();
  //vtkTransformPolyDataFilter *filter = vtkTransformPolyDataFilter::New();
  vtkImageReslice *filter = vtkImageReslice::New();
  //filter->SetTransform(transform);
  filter->SetResliceTransform(transform);
  //filter->SetInputConnection(mapOutline->GetOutputPort());
  //filter->SetInput(mapOutline->GetOutput());
  //filter->SetInput(reader->GetOutput());
  filter->SetInput(reader->GetOutput());
  filter->Update();

  //for transform

  vtkCamera *aCamera = vtkCamera::New();
  aCamera->SetViewUp (0, 0, -1);
  aCamera->SetPosition (0, 1, 0);
  aCamera->SetFocalPoint (0, 0, 0);
  aCamera->ComputeViewPlaneNormal();

  aRenderer->AddActor(outline);
  aRenderer->AddActor(skin);
  aRenderer->SetActiveCamera(aCamera);
  aRenderer->ResetCamera ();
  aCamera->Dolly(1.5);

  aRenderer->SetBackground(1,1,1);
  renWin->SetSize(640, 480);

  aRenderer->ResetCameraClippingRange ();

  iren->Initialize();
  iren->Start(); 

  //for Capture
  //vtkWindowToImageFilter *w2if=vtkWindowToImageFiter::New();
  //w2if->SetInput(renWin);
  //vtkPNGWriter *wr=vtkPNGWriter::New();
  //wr->SetInputConnection(w2if->GetOutputPort());
  //wr->SetFileName("Capture.png");
  //wr->Write();
  //w2if->Delete();
  //wr->Delete();
  //for Capture

  //for volume
  //vtkImageWriter *writer = vtkImageWriter::New();
  vtkStructuredPointsWriter *writer = vtkStructuredPointsWriter::New();
  //vtkPolyDataWriter *writer = vtkPolyDataWriter::New();
  writer->SetInput(filter->GetOutput());
  writer->SetFileName(argv[2]);
  writer->Write();

  //for volume
  skinExtractor->Delete();
  skinNormals->Delete();
  skinMapper->Delete();
  skin->Delete();
  outlineData->Delete();
  mapOutline->Delete();
  outline->Delete();
  aCamera->Delete();
  iren->Delete();
  renWin->Delete();
  aRenderer->Delete();
  reader->Delete();
  //int hoge;
  //std::cin >> hoge  ;
  return 0;
}

