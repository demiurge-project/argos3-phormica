/**
 * @file <argos3/plugins/robots/arena/simulator/block_entity.h>
 *
 *David Garzon-Ramos - <dgarzonr@ulb.ac.be>
 */

#ifndef BLOCK_ENTITY_H
#define BLOCK_ENTITY_H

namespace argos {
   class CBlockEntity;
}

#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/simulator/entities/led_equipped_entity.h>

namespace argos {

   class CBlockEntity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

      CBlockEntity();

      CBlockEntity(const std::string& str_id,
                   const CVector3& c_position,
                   const CQuaternion& c_orientation,
                   bool b_movable,
                   const CVector3& c_size,
                   Real f_mass = 1.0f);

      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();

      /*
       * Enables the LEDs for this entity.
       * Adds the LED equipped entity to the given medium.
       * If you don't call this method, the LEDs added with
       * CBlockEntity::AddLED() won't be update correctly.
       * @param c_medium The medium to which the LEDs must be associated.
       * @see CBlockEntity::AddLED()
       */
      void EnableLEDs(CLEDMedium& c_medium);

      /*
       * Disables the LEDs for this entity.
       */
      void DisableLEDs();

      /**
       * Adds an LED to this entity.
       * For the LEDs to be updated correctly, you must first call
       * CBlockEntity::EnableLEDs().
       * @param c_offset The position of the LED wrt the origin anchor.
       * @param c_color The color of the LED.
       * @see CBlockEntity::EnableLEDs()
       */
      void AddLED(const CVector3& c_offset,
                  const CColor& c_color = CColor::BLACK);

      inline CEmbodiedEntity& GetEmbodiedEntity() {
         return *m_pcEmbodiedEntity;
      }

      inline const CEmbodiedEntity& GetEmbodiedEntity() const {
         return *m_pcEmbodiedEntity;
      }

      inline CLEDEquippedEntity& GetLEDEquippedEntity() {
         return *m_pcLEDEquippedEntity;
      }

      inline const CLEDEquippedEntity& GetLEDEquippedEntity() const {
         return *m_pcLEDEquippedEntity;
      }

      inline const CVector3& GetSize() const {
         return m_cSize;
      }

      inline void SetSize(const CVector3& c_size) {
         m_cSize = c_size;
      }

      inline Real GetMass() const {
         return m_fMass;
      }

      inline void SetMass(Real f_mass) {
         m_fMass = f_mass;
      }

      virtual std::string GetTypeDescription() const {
         return "block";
      }

   private:

      CEmbodiedEntity*    m_pcEmbodiedEntity;
      CLEDEquippedEntity* m_pcLEDEquippedEntity;
      CVector3            m_cSize;
      Real                m_fMass;
      CLEDMedium*         m_pcLEDMedium;

   };

}

#endif
