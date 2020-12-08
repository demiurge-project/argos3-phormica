/**
 * @file <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_box_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef DYNAMICS2D_PHORMICA_MODEL_H
#define DYNAMICS2D_PHORMICA_MODEL_H

namespace argos {
   class CDynamics2DStretchableObjectModel;
   class CDynamics2DPhormicaModel;
}

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_stretchable_object_model.h>
#include "phormica_entity.h"

namespace argos {

   class CDynamics2DPhormicaModel : public CDynamics2DStretchableObjectModel {

   public:

      CDynamics2DPhormicaModel(CDynamics2DEngine& c_engine,
                          CPhormicaEntity& c_entity);
      virtual ~CDynamics2DPhormicaModel() {}
   };

}

#endif
