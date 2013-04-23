#pragma once

#if defined(MAIN_WINDOW_DLL_EXPORT)
#  define MAIN_WINDOW_EXPORT Q_DECL_EXPORT
#else
#  define MAIN_WINDOW_EXPORT Q_DECL_IMPORT
#endif
