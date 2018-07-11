/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkAdjacency_h
#define itkAdjacency_h

#include "DigitalTopologyExport.h"
#include "itkConnectedImageNeighborhoodShape.h"

namespace itk
{
namespace Experimental
{

/** \class Adjacency
 *
 * \brief Type to define an adjacency relationship of a spel with its
 * neighborhood.
 *
 * Its template parameters are enough to instantiate a
 * \ref itk::Experimental::ConnectedImageNeighborhoodShape
 *
 * \sa itk::Experimental::ConnectedImageNeighborhoodShape
 * \ingroup DigitalTopology
 *
 */
template< unsigned int VImageDimension, unsigned int VCityBlockDistance >
class DigitalTopology_EXPORT Adjacency
{
public:
  static constexpr unsigned int ImageDimension = VImageDimension;
  static constexpr unsigned int CityBlockDistance = VCityBlockDistance;

  /** Standard class typedefs. */
  using Self = Adjacency< VImageDimension, VCityBlockDistance >;
};
} // end namespace experimental
} // end namespace itk

#endif // itkAdjacency
