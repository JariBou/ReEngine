#pragma once

#ifdef RE_COMPILE
#define RE_RENDERER_API __declspec(dllexport)
#else
#define RE_RENDERER_API __declspec(dllimport)
#endif