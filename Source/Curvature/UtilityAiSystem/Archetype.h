#pragma once

#include "BehaviorSet.h"
#include "Archetype.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FArchetype
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TArray<FBehaviorSet> BehaviorSets;

    FArchetype() = default;
    FArchetype(FName name) : ReadableName(name) {}

    FString ToString() const {return ReadableName.ToString();}
};