#pragma once

#if defined(MAP_LAYER_DLL_EXPORT)
#  define MAP_LAYER_EXPORT Q_DECL_EXPORT
#else
#  define MAP_LAYER_EXPORT Q_DECL_IMPORT
#endif
