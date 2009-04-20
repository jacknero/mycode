/*=========================================================================

Program:   Insight Segmentation & Registration Toolkit
Module:    $RCSfile: ImageRegistration6o.cxx,v $
Language:  C++
Date:      $Date: 2007-11-22 00:30:16 $
Version:   $Revision: 1.4 $

Copyright (c) Insight Software Consortium. All rights reserved.
See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even 
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif


#include "itkOrientedImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkSquaredDifferenceImageFilter.h"



int main( int argc, char *argv[] )
{
  if( argc < 4 )
  {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " fixedImageFile  movingImageFile ";
    std::cerr << " outputImagefile" << std::endl;
    return EXIT_FAILURE;
  }

  const    unsigned int    Dimension = 2;
  typedef  unsigned int           PixelType;

  typedef itk::OrientedImage< PixelType, Dimension >  FixedImageType;
  typedef itk::OrientedImage< PixelType, Dimension >  MovingImageType;



  typedef itk::ImageFileReader< FixedImageType  > FixedImageReaderType;
  typedef itk::ImageFileReader< MovingImageType > MovingImageReaderType;
  FixedImageReaderType::Pointer  fixedImageReader  = FixedImageReaderType::New();
  MovingImageReaderType::Pointer movingImageReader = MovingImageReaderType::New();

  fixedImageReader->SetFileName(  argv[1] );
  movingImageReader->SetFileName( argv[2] );



  typedef itk::OrientedImage< PixelType, Dimension > OutputImageType;


  typedef itk::SquaredDifferenceImageFilter< 
    FixedImageType, 
    FixedImageType, 
    OutputImageType > DifferenceFilterType;

  DifferenceFilterType::Pointer difference = DifferenceFilterType::New();

  typedef itk::ImageFileWriter< OutputImageType >  WriterType;
  WriterType::Pointer writer2 = WriterType::New();
  writer2->SetInput( difference->GetOutput() );  


  difference->SetInput1( fixedImageReader->GetOutput() );
  difference->SetInput2( movingImageReader->GetOutput() );
  writer2->SetFileName( argv[3] );
  writer2->Update();



  return EXIT_SUCCESS;
}

