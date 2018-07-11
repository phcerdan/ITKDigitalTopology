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
#ifndef itkDigitalTopology_h
#define itkDigitalTopology_h

#include "DigitalTopologyExport.h"
#include "itkImageToImageFilter.h"

namespace itk
{
namespace Experimental
{

/** \class DigitalTopology
 *
 * \brief Digital topology defined by Foreground and Background adjacency
 * relationships.
 *
 * Digital topology defines the connectivity of the spels of an image.
 *
 * @tparam TForegroundAdjacency
 * @tparam TBackgroundAdjacency
 *
 * \sa itk::Experimental::Adjacency
 * \sa itk::Experimental::ConnectedImageNeighborhoodShape
 * TODO move to appropiate class
 * You have Adjacencies (that store parameters to instantiate NeighborhoodShapes). 26 in 3D, 8, 4 in 2D, etc.
 * You have DigitalTopology, requiring Foreground and Bacground Adjacencies.
 * You now have to create the Object that use this topology.
 * One case is an object that stores CELLS,vtk style. Where CELLS might be EDGES, FACES, VOXELS... and POINTS.
 * So, the defined adjacencies are about spels, but the inner structures are created only in this object.
 * Two foreground adjacent voxels share 1 face, 4 edges, 4 points. And more examples like this.
 * DGtal store a map of these CELLS.
 * VTK must do the same or similar.
 *
 * Do we always want the inner structures though?
 * Voxel: ImageIndex.
 * Face: 2 Voxels.
 * Edge: Face, +4 options (N, S, E, O) in 3D
 * Point: Face, +4 too. Or ImageIndex +26
 * I think Khalemsky Space idea: a large 1D index to store them all, takes adventage of the hierarchical relationship of these cells.
 *
 *
 *
 * \ingroup DigitalTopology
 *
 */
template< typename TForegroundAdjacency, typename TBackgroundAdjacency >
class DigitalTopology_EXPORT DigitalTopology
{
public:
  /* ITK_DISALLOW_COPY_AND_ASSIGN(DigitalTopology); */

  /** Standard class typedefs. */
  using Self = DigitalTopology< TForegroundAdjacency, TBackgroundAdjacency >;
  using ReverseDigitalTopology = DigitalTopology< TBackgroundAdjacencygroundAdjacency, TForegroundAdjacency >;

private:

#ifdef ITK_USE_CONCEPT_CHECKING
  // TODO Check that FG and BG are compatibles.
  // Add concept checking such as
  // itkConceptMacro( FloatingPointPixel, ( itk::Concept::IsFloatingPoint< typename InputImageType::PixelType > ) );
#endif
};
} // end namespace experimental
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkDigitalTopology.hxx"
#endif

#endif // itkDigitalTopology
