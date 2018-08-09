#pragma once

#include "Engine/Texture2D.h"

#include "Scenario_InspectionTest.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FScenario_InspectionTest
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Caption;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) UTexture2D* Icon;
};