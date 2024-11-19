#pragma once

#ifdef RE_COMPILE
#define RE_CORE_API __declspec(dllexport)
#else
#define RE_CORE_API __declspec(dllimport)
#endif

#ifndef TEMPLATE_MACROS
#define TEMPLATE_MACROS

#include <type_traits>
template<typename T, typename U>
concept Derived = std::is_base_of_v<U, T>;

#define ReObjectTemplate template<Derived<class ReObject> T>

#define IWorldObjectTemplate template<Derived<class IWorldObject> T>

#endif