#pragma once

#include "HGUtilities/EnumUtils.h"

#include "KnowledgeBase.generated.h"

UENUM(BlueprintType)
enum class EPrefabs : uint8
{
    NoPrefab,
    Distance,
    SimulationTime
};
DEFINE_ENUM_TO_STRING(EPrefabs);

UENUM(BlueprintType)
enum class EParameterization : uint8
{
    FixedRange,
    ConfigurableRange,
    Enumeration
};

DEFINE_ENUM_TO_STRING(EParameterization);

USTRUCT(BlueprintType)
struct CURVATURE_API FKnowledgeBase_Record
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) bool Computed;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float MinimumValue = 0.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float MaximumValue = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) EPrefabs Prefab = EPrefabs::NoPrefab;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) EParameterization Parameters = EParameterization::FixedRange;

    FKnowledgeBase_Record() = default;
    FKnowledgeBase_Record(FName name, bool computed, EParameterization param) : ReadableName(name), Computed(computed), Parameters(param) {}

    FString ToString() const {return ReadableName.ToString();}

    bool operator==(const FKnowledgeBase_Record& other) const
    {
        return ReadableName == other.ReadableName 
            && Computed == other.Computed
            && FMath::IsNearlyEqual(MinimumValue, other.MinimumValue)
            && FMath::IsNearlyEqual(MaximumValue, other.MaximumValue)
            && Prefab == other.Prefab
            && Parameters == other.Parameters;
    }

    friend FORCEINLINE static uint32 GetTypeHash(const FKnowledgeBase_Record& kb_record)
	{
        const auto nameHash = GetTypeHash(kb_record.ReadableName);
        const auto computedHash = GetTypeHash(kb_record.Computed);
        const auto minValHash = GetTypeHash(kb_record.MinimumValue);
        const auto maxValHash = GetTypeHash(kb_record.MaximumValue);
        const auto prefabHash = GetTypeHash(static_cast<uint8>(kb_record.Prefab));
        const auto paramsHash = GetTypeHash(static_cast<uint8>(kb_record.Parameters));
		return HashCombine(HashCombine(HashCombine(HashCombine(HashCombine(nameHash, computedHash), minValHash), maxValHash), prefabHash), paramsHash) ;
	}
};



USTRUCT(BlueprintType)
struct CURVATURE_API FKnowledgeBase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TArray<FKnowledgeBase_Record> Records;
    
};