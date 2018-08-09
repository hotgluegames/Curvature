#pragma once

#include "Scenario_Score.h"
#include "UtilityAiSystem/Consideration.h"

#include "Scenario_ConsiderationScore.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FScenario_ConsiderationScores
{
    GENERATED_BODY()
public:
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite) *///TMap<FConsideration, FScenario_Score> Considerations;
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite) */float InitialWeight = 0.f;
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite) */float FinalScore = 0.f;

    FString ToString() const
    {
        auto ret = FString::Format(TEXT("Initial weight: {0}\r\nFinal score: {1} \r\n\r\n"), {InitialWeight, FinalScore});
        /*for(const auto& pair : Considerations)
        {
            ret += FString::Format(TEXT("{0}\r\nInput {1}\r\n"
            "\tRaw Input: {2}\r\n"
            "\tNormalized Input: {3}\r\n"
            "\tResponse curve score: {4}\r\n"), {
                pair.Key.ReadableName.ToString(), 
//                pair.Key.Input.ReadableName.ToString(),
                pair.Value.InputRawValue,
                pair.Value.InputValue,
                pair.Value.FinalScore
            });
        }*/
        return ret;
    }
};