#pragma once

#include "resource.h"
#include <unordered_map>

enum class MethodType
{
    GroundWater,
    Thermal
};

static const std::unordered_map<MethodType, UINT> MethodOptionsMap =
{
    { MethodType::GroundWater, IDS_GROUND_METHODS },
    { MethodType::Thermal, IDS_THERMAL_METHODS }
};

static const std::unordered_map<MethodType, UINT> MethodTitleMap =
{
    { MethodType::GroundWater, IDS_GROUND_TITLE},
    { MethodType::Thermal, IDS_THERMAL_TITLE}
};

static const std::unordered_map<MethodType, UINT> MethodSeletionLabelMap =
{
    { MethodType::GroundWater, IDS_GROUND_SELECTION_LABEL },
    { MethodType::Thermal, IDS_THERMAL_SELECTION_LABEL }
};

inline UINT MethodTypeToOptionsStringID(MethodType type)
{
    auto it = MethodOptionsMap.find(type);
    return (it != MethodOptionsMap.end()) ? it->second : 0;
}

inline UINT MethodTypeToTitleStringID(MethodType type)
{
    auto it = MethodTitleMap.find(type);
    return (it != MethodTitleMap.end()) ? it->second : 0;
}

inline UINT MethodTypeToSelectionLabelStringID(MethodType type)
{
    auto it = MethodSeletionLabelMap.find(type);
    return (it != MethodSeletionLabelMap.end()) ? it->second : 0;
}