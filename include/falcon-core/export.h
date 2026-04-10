#ifndef FALCON_CORE_EXPORT_H
#define FALCON_CORE_EXPORT_H

#ifdef _WIN32
// Building the DLL
#ifdef falcon_core_EXPORTS
#define FALCON_CORE_CPP_API __declspec(dllexport)
#else
// Using the DLL
#define FALCON_CORE_CPP_API __declspec(dllimport)
#endif
#else
// Unix/Linux - use visibility attributes for better control
#if defined(__GNUC__) || defined(__clang__)
#define FALCON_CORE_CPP_API __attribute__((visibility("default")))
#else
#define FALCON_CORE_CPP_API
#endif
#endif

#endif  // FALCON_CORE_EXPORT_H
