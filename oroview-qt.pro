VPATH += ../shared
INCLUDEPATH += ../shared /usr/include/freetype2 /home/skadge/openrobots/include/liboro ./external

HEADERS       = glwidget.h \
                window.h \
    src/oroview/constants.h \
    src/oroview/edge.h \
    src/oroview/edge_renderer.h \
    src/oroview/graph.h \
    src/oroview/macros.h \
    src/oroview/node.h \
    src/oroview/node_relation.h \
    src/oroview/node_renderer.h \
    src/oroview/oro_connector.h \
    src/oroview/oroview.h \
    src/oroview/oroview_exceptions.h \
    src/oroview/spline.h \
    src/oroview/styles.h \
    src/oroview/zoomcamera.h \
    src/oroview/core/bounds.h \
    src/oroview/core/camera.h \
    src/oroview/core/frustum.h \
    src/oroview/core/fxfont.h \
    src/oroview/core/pi.h \
    src/oroview/core/plane.h \
    src/oroview/core/quadtree.h \
    src/oroview/core/resource.h \
    src/oroview/core/stringhash.h \
    src/oroview/core/texture.h \
    src/oroview/core/vectors.h \
    src/oroview/core/utf8/checked.h \
    src/oroview/core/utf8/core.h \
    src/oroview/core/utf8/unchecked.h \
    src/oroview/core/utf8/utf8.h
SOURCES       = main.cpp \
                window.cpp \
                glwidget.cpp \
    src/oroview/graph.cpp \
    src/oroview/node.cpp \
    src/oroview/node_relation.cpp \
    src/oroview/node_renderer.cpp \
    src/oroview/oro_connector.cpp \
    src/oroview/spline.cpp \
    src/oroview/zoomcamera.cpp \
    src/oroview/edge.cpp \
    src/oroview/edge_renderer.cpp \
    src/oroview/core/camera.cpp \
    src/oroview/core/frustum.cpp \
    src/oroview/core/fxfont.cpp \
    src/oroview/core/plane.cpp \
    src/oroview/core/quadtree.cpp \
    src/oroview/core/resource.cpp \
    src/oroview/core/stringhash.cpp \
    src/oroview/core/texture.cpp \
    src/oroview/oroview.cpp
QT           += opengl

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/oroview-qt
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS oroview-qt.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/opengl/oroview-qt
INSTALLS += target sources

RESOURCES += \
    textures.qrc
