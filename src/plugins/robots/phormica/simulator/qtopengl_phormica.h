/**
 * @file <argos3/plugins/simulator/visualizations/qt-opengl/models/qtopengl_box.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef QTOPENGL_PHORMICA_H
#define QTOPENGL_PHORMICA_H

namespace argos {
   class CQTOpenGLPhormica;
   class CPhormicaEntity;
}

#ifdef __APPLE__
#include <gl.h>
#else
#include <GL/gl.h>
#endif

namespace argos {

   class CQTOpenGLPhormica {

   public:

      CQTOpenGLPhormica();

      virtual ~CQTOpenGLPhormica();

      virtual void DrawLEDs(CPhormicaEntity& c_entity);
      virtual void Draw(const CPhormicaEntity& c_entity);

   private:

      void MakeBody();
      void MakeLED();

   private:

      GLuint m_unBaseList;
      GLuint m_unBodyList;
      GLuint m_unLEDList;
      GLuint m_unVertices;

   };

}

#endif
