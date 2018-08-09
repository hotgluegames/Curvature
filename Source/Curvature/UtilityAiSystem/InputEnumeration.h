#pragma once

#include "InputParameter.h"
#include "InputParameterValue.h"

#include "InputEnumeration.generated.h"

USTRUCT(BlueprintType)
struct CURVATURE_API FInputParameterEnumeration : public FInputParameter
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) bool ScoreOnMatch;
	virtual ~FInputParameterEnumeration() = default;
};

USTRUCT(BlueprintType)
struct FInputParameterValueEnumeration : public FInputParameterValue
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FInputParameterEnumeration ControllingParameter;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FString Key;


	FInputParameterValueEnumeration() = default;
	virtual ~FInputParameterValueEnumeration() = default;

	FInputParameterValueEnumeration(const FInputParameterEnumeration& controllingParameter, const FString& key)
		: ControllingParameter(controllingParameter),
		  Key(key)
	{
	}

	FInputParameter GetControllingParameter() const override {return ControllingParameter;}
	
};