set(ARGOS3_HEADERS_PLUGINS_ROBOTS_PHORMICA_SIMULATOR
  simulator/dynamics2d_phormica_model.h
  simulator/phormica_entity.h
  simulator/dynamics2d_block_model.h
  simulator/block_entity.h)

if(ARGOS_COMPILE_QTOPENGL)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_PHORMICA_SIMULATOR
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_PHORMICA_SIMULATOR}
    simulator/qtopengl_phormica.h
    simulator/qtopengl_block.h)
endif(ARGOS_COMPILE_QTOPENGL)

# Install location for the arena simulator headers
install(
  FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_PHORMICA_SIMULATOR}
  DESTINATION include/argos3/plugins/robots/phormica/simulator)

set(ARGOS3_SOURCES_PLUGINS_ROBOTS_PHORMICA_SIMULATOR
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_PHORMICA_SIMULATOR}
  simulator/dynamics2d_phormica_model.cpp
  simulator/phormica_entity.cpp
  simulator/dynamics2d_block_model.cpp
  simulator/block_entity.cpp)

if(ARGOS_COMPILE_QTOPENGL)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_PHORMICA_SIMULATOR
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_PHORMICA_SIMULATOR}
    simulator/qtopengl_phormica.cpp
    simulator/qtopengl_block.cpp)
endif(ARGOS_COMPILE_QTOPENGL)

add_library(argos3plugin_${ARGOS_BUILD_FOR}_phormica SHARED
  ${ARGOS3_SOURCES_PLUGINS_ROBOTS_PHORMICA_SIMULATOR})

target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_phormica
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_dynamics2d
  argos3plugin_${ARGOS_BUILD_FOR}_entities)

if(ARGOS_COMPILE_QTOPENGL)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_phormica
    argos3plugin_${ARGOS_BUILD_FOR}_qtopengl)
endif(ARGOS_COMPILE_QTOPENGL)

# Install location for the arena plugin
install(TARGETS argos3plugin_${ARGOS_BUILD_FOR}_phormica
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
