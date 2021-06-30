#ifndef COWDIA_COMMON_HPP
#define COWDIA_COMMON_HPP

#ifndef COWDIA_API
#ifdef COWDIA_PLATFORM_WIN32
#ifdef COWDIA_API_EXPORT
#define COWDIA_API __declspec(dllexport)
#else
#define COWDIA_API __declspec(dllimport)
#endif
#else
#define COWDIA_API
#endif
#endif

#define SAFE_DELETE(ptr)   \
    do                     \
    {                      \
        if (ptr)           \
        {                  \
            delete ptr;    \
            ptr = nullptr; \
        }                  \
    } while (false)

#endif  // COWDIA_COMMON_HPP
