#ifndef FALCON_CORE_C_API_EXPORT_H
#define FALCON_CORE_C_API_EXPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
/* Windows DLL export/import */
#ifdef falcon_core_c_api_EXPORTS
#define FALCON_CORE_C_API __declspec(dllexport)
#else
#define FALCON_CORE_C_API __declspec(dllimport)
#endif
#else
/* Unix/Linux - use visibility attributes */
#if defined(__GNUC__) || defined(__clang__)
#define FALCON_CORE_C_API __attribute__((visibility("default")))
#else
#define FALCON_CORE_C_API
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* FALCON_CORE_C_API_EXPORT_H */
