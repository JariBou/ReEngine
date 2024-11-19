#pragma once

#ifdef RE_COMPILE
#define RE_CORE_API __declspec(dllexport)
#else
#define RE_CORE_API __declspec(dllimport)
#endif

#ifndef TEMPLATE_MACROS
#define TEMPLATE_MACROS
#include <concepts>

template<typename T, typename U>
concept DerivedFrom = std::derived_from<T, U>;

template<typename T, typename U>
concept BaseOf = std::derived_from<U, T>;

#define ReObjectTemplate template<DerivedFrom<class ReObject> T>

#define IWorldObjectTemplate template<DerivedFrom<class IWorldObject> T>

#endif