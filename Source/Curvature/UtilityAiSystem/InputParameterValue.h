#pragma once

#include "InputParameter.h"

#include "InputParameterValue.generated.h"

USTRUCT()
struct FInputParameterValue
{
	GENERATED_BODY()

    virtual FInputParameter GetControllingParameter() const {return FInputParameter();}
};

USTRUCT(BlueprintType)
struct CURVATURE_API FInputParameterValueNumeric : public FInputParameterValue
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FInputParameterNumeric ControllingParameter;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float Value;


	FInputParameterValueNumeric() = default;


	FInputParameterValueNumeric(const FInputParameterNumeric& controllingParameter, float value)
		: ControllingParameter(controllingParameter),
		  Value(value)
	{
	}

	FInputParameter GetControllingParameter() const override
    {
        return ControllingParameter;
    }
};