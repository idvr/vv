/*=========================================================================
  Program:   vv                     http://www.creatis.insa-lyon.fr/rio/vv

  Authors belong to: 
  - University of LYON              http://www.universite-lyon.fr/
  - Léon Bérard cancer center       http://www.centreleonberard.fr
  - CREATIS CNRS laboratory         http://www.creatis.insa-lyon.fr

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the copyright notices for more information.

  It is distributed under dual licence

  - BSD        See included LICENSE.txt file
  - CeCILL-B   http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
===========================================================================**/
#ifndef clitkNVectorImageTo4DImageFilter_h
#define clitkNVectorImageTo4DImageFilter_h

/* =================================================
 * @file   clitkNVectorImageTo4DImageFilter.h
 * @author 
 * @date   
 * 
 * @brief 
 * 
 ===================================================*/


// clitk include
#include "clitkIO.h"
#include "clitkCommon.h"

//itk include
#include "itkImageToImageFilter.h"

namespace clitk 
{

  template <class InputImageType, class OutputImageType>
  class ITK_EXPORT NVectorImageTo4DImageFilter :
    public itk::ImageToImageFilter<InputImageType, OutputImageType>
  {
  public:
    //----------------------------------------
    // ITK
    //----------------------------------------
    typedef NVectorImageTo4DImageFilter                                                 Self;
    typedef itk::ImageToImageFilter<InputImageType, OutputImageType>  Superclass;
    typedef itk::SmartPointer<Self>                                   Pointer;
    typedef itk::SmartPointer<const Self>                             ConstPointer;
   
    // Method for creation through the object factory
    itkNewMacro(Self);  

    // Run-time type information (and related methods)
    itkTypeMacro( NVectorImageTo4DImageFilter, ImageToImageFilter );

    /** Dimension of the domain space. */
    itkStaticConstMacro(InputImageDimension, unsigned int, Superclass::InputImageDimension);
    itkStaticConstMacro(OutputImageDimension, unsigned int, Superclass::OutputImageDimension);

    //----------------------------------------
    // Typedefs
    //----------------------------------------
    typedef typename OutputImageType::RegionType OutputImageRegionType;

    //----------------------------------------
    // Set & Get
    //----------------------------------------    
    itkBooleanMacro(Verbose);
    itkSetMacro( Verbose, bool);
    itkGetConstReferenceMacro( Verbose, bool);
    itkSetMacro(ComponentIndex, unsigned int);
    itkGetConstMacro(ComponentIndex, unsigned int);   

  protected:

    //----------------------------------------  
    // Constructor & Destructor
    //----------------------------------------  
    NVectorImageTo4DImageFilter();
    ~NVectorImageTo4DImageFilter() {};

    //----------------------------------------  
    // Update
    //----------------------------------------  
    void ThreadedGenerateData(const OutputImageRegionType & outputRegionForThread, itk::ThreadIdType threadId );
   
    //----------------------------------------  
    // Data members
    //----------------------------------------
    bool m_Verbose;
    unsigned int m_ComponentIndex;

  };


} // end namespace clitk

#ifndef ITK_MANUAL_INSTANTIATION
#include "clitkNVectorImageTo4DImageFilter.txx"
#endif

#endif // #define clitkNVectorImageTo4DImageFilter_h


