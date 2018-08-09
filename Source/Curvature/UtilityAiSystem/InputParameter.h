#pragma once

#include "InputParameter.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FInputParameter
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName ReadableName;

	FInputParameter() = default;
    FInputParameter(FName name) : ReadableName(name) {}
};

USTRUCT(BlueprintType)
struct CURVATURE_API FInputParameterNumeric : public FInputParameter
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float MinimumValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float MaximumValue;

    FInputParameterNumeric() = default;
	FInputParameterNumeric(FName name, float minValue, float maxValue) : FInputParameter(name), MinimumValue(minValue), MaximumValue(maxValue){}
};