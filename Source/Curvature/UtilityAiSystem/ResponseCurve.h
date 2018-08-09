#pragma once

#include "HGUtilities/EnumUtils.h"
#include "ResponseCurve.generated.h"

UENUM(BlueprintType)
enum class ECurveType : uint8
{
    Linear,
    Polynomial,
    Logistic,
    Logit,
    Normal,
    Sine
};

DEFINE_ENUM_TO_STRING(ECurveType);

USTRUCT(BlueprintType)
struct CURVATURE_API FResponseCurve
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) ECurveType Type;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float Slope;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float Exponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float XShift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float YShift;

    FResponseCurve() = default;


	FResponseCurve(ECurveType type, float slope, float exponent, float xShift, float yShift)
		: Type(type),
		  Slope(slope),
		  Exponent(exponent),
		  XShift(xShift),
		  YShift(yShift)
	{
	}

    float ComputeValue(float x) const;
private:
	static float Sanitize(float y);
};