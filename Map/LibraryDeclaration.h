#pragma once

#if defined(MAP_DLL_EXPORT)
#  define MAP_EXPORT Q_DECL_EXPORT
#else
#  define MAP_EXPORT Q_DECL_IMPORT
#endif