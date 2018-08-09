#pragma once

#include "Scenario_Score.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FScenario_Score
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float InputRawValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float InputValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float FinalScore;
    FScenario_Score() : InputRawValue(0), InputValue(0), FinalScore(0) {}
    FScenario_Score(float inputRawValue, float inputValue, float finalScore) : InputRawValue(inputRawValue), InputValue(inputValue), FinalScore(finalScore)
    {}
};