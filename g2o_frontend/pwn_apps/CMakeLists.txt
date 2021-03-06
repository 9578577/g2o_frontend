INCLUDE_DIRECTORIES(${EIGEN_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS} ${QGLVIEWER_INCLUDE_DIR} ${QT_INCLUDES})
LINK_DIRECTORIES(${OpenCV_LIBRARY_DIRS})

ADD_EXECUTABLE(pwn_cloud_aligner pwn_cloud_aligner.cpp)
SET_TARGET_PROPERTIES(pwn_cloud_aligner PROPERTIES OUTPUT_NAME pwn_cloud_aligner)
INCLUDE_DIRECTORIES(
  ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} 
  ${QGLVIEWER_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR}/..)
TARGET_LINK_LIBRARIES(pwn_cloud_aligner 
  pwn_viewer pwn_core pwn_utils
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
  ${G2O_STUFF_LIBRARY} ${G2O_OPENGL_HELPER_LIBRARY}
)

ADD_EXECUTABLE(pwn_simpleViewer pwn_simpleViewer.cpp )
INCLUDE_DIRECTORIES(
  ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} 
  ${QGLVIEWER_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR}/..)
TARGET_LINK_LIBRARIES(pwn_simpleViewer pwn_viewer pwn_core 
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} 
  ${G2O_STUFF_LIBRARY} ${G2O_OPENGL_HELPER_LIBRARY}
)

ADD_EXECUTABLE(pwn_dtcovariance_test pwn_dtcovariance_test.cpp )
INCLUDE_DIRECTORIES(
  ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} 
  ${QGLVIEWER_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR} ${QT_QTCORE_INCLUDE_DIR}/..
)
TARGET_LINK_LIBRARIES(pwn_dtcovariance_test 
  pwn_viewer pwn_boss
  ${QGLVIEWER_LIBRARY} ${QT_QTXML_LIBRARY} ${QT_QTOPENGL_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTCORE_LIBRARY} 
  ${OpenCV_LIBS}
  ${G2O_STUFF_LIBRARY}
)

# ADD_EXECUTABLE(pwn_merger pwn_merger.cpp )
# TARGET_LINK_LIBRARIES(pwn_merger pwn_core)