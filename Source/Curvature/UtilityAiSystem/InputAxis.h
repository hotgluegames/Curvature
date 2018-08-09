#pragma once

#include "HGUtilities/EnumUtils.h"

#include "InputParameter.h"
#include "InputParameterValue.h"
#include "KnowledgeBase.h"
#include "InputAxis.generated.h"

UENUM(BlueprintType)
enum class EOriginType : uint8
{
    PropertyOfSelf,
    PropertyOfTarget,
    ComputedValue
};

DEFINE_ENUM_TO_STRING(EOriginType);

USTRUCT(BlueprintType)
struct CURVATURE_API FInputAxis
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utitlity) FName ReadableName;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utitlity) EOriginType Origin;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utitlity) TArray<FInputParameter> Parameters;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utitlity) FKnowledgeBase_Record KBRecord;

    void set_KBRecord(const FKnowledgeBase_Record& kbRecord)
    {
        if(kbRecord == KBRecord)
        {
            return;
        }
        //todo: consider eventing
        KBRecord = kbRecord;
    }

    FInputAxis() = default;

    FInputAxis(FName name, EOriginType origin) : ReadableName(name), Origin(origin) {}

    FString ToString() const {return ReadableName.ToString();}

	FInputAxis Clamp(const TArray<FInputParameterValueNumeric>& parameters);

	FInputAxis Union(const FInputAxis& other);

    void GenerateParametersFromKBRecord()
    {
        Parameters.Reset();
        unimplemented();
    }
};