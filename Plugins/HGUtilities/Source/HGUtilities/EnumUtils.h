#pragma once
#include "EngineMinimal.h"

namespace HGUtilities
{
	template<typename T>
	auto EnumToString(const TCHAR* enumName, T value)
	{
	    auto&& pEnum = FindObject<UEnum>(ANY_PACKAGE, enumName, true);
	    return pEnum
	        ? pEnum->GetNameByIndex(static_cast<uint8>(value)).ToString()
	        : TEXT("Invalid");
	}
}
#define DEFINE_ENUM_TO_STRING(enumName) inline auto to_string(enumName x) { return HGUtilities::EnumToString<enumName>(TEXT(#enumName), x);}