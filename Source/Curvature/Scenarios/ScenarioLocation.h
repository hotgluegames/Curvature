#pragma once
#include "UtilityAiSystem/Knowledgebase.h"
#include "Interfaces/ScenarioMemberInterface.h"

#include "ScenarioLocation.generated.h"

UCLASS(BlueprintType)
class UScenarioLocation : public UObject, public IScenarioMemberInterface
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FName Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) FVector Position;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) float Radius = 2.5f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TMap<FKnowledgeBase_Record, UObject*> Properties;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Utility) TMap<FKnowledgeBase_Record, UObject*> StartProperties;

	FName GetName() const override {return Name;}
    FVector GetPosition() const override{return Position;}
    UObject* GetProperty(const FKnowledgeBase_Record& kbrec) const{
        return Properties.Contains(kbrec) ? Properties[kbrec] : nullptr;
    }

    float GetRadius() const {return Radius;}

    void GenerateStartProperties(const FKnowledgeBase& kb)
    {
        const auto oldStarts = StartProperties;
        Properties = TMap<FKnowledgeBase_Record, UObject*>();

        for(auto&& rec : kb.Records)
        {
            if(rec.Computed)
            {
                continue;
            }

            if(oldStarts.Contains(rec))
            {
                StartProperties.Add(rec, oldStarts[rec]);
            }
            else 
            {
                
                if (rec.Parameters == EParameterization::Enumeration) {
                    //StartProperties.Add(rec, rec.EnumerationValues.First());
                    unimplemented();
                }
                else 
				{
//                    StartProperties.Add(rec, rec.MinimumValue);
					unimplemented();
                }
            }
        }
    }
};