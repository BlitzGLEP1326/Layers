#pragma once

#if defined(LAYERS_MANAGER_DLL_EXPORT)
#  define LAYERS_MANAGER_EXPORT Q_DECL_EXPORT
#else
#  define LAYERS_MANAGER_EXPORT Q_DECL_IMPORT
#endif