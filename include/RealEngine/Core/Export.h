#pragma once

#ifdef RE_COMPILE
#define RE_CORE_API __declspec(dllexport)
#else
#define RE_CORE_API __declspec(dllimport)
#endif