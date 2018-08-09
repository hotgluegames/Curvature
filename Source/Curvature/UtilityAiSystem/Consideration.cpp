#include "Consideration.h"
#include "Curvature.h"
#include "InputEnumeration.h"
#include "Interfaces/InputBrokerInterface.h"


FConsideration::FConsideration() : ReadableName(NAME_None), Curve(ECurveType::Linear, 1.f, 1.f, 0.f, 0.f)
{

}

FConsideration::FConsideration(const FName& readableName, FInputAxis&& input, const FResponseCurve& curve,
                               const TArray<FInputParameterValue>& parameterValues, bool wrapInput):
	ReadableName(readableName),
	Input(input),
	Curve(curve),
	ParameterValues(parameterValues),
	WrapInput(wrapInput)
{
}

void FConsideration::GenerateParameterValuesFromInput()
{
	const auto oldParams = ParameterValues;
	ParameterValues.Reset();

	auto i = 0;
	for (auto&& p : Input.Parameters)
	{
		if (oldParams.Num() > i)
		{
			ParameterValues.Add(oldParams[i]);
		}
		else
		{
			//todo: super unhappy about this casting business, should find a different implementation that adapts or somehow avoids this dynamic type checking.
			if (const auto pnum = (FInputParameterNumeric*)(&p))
			{
				auto&& v = FInputParameterValueNumeric(
					*pnum, ParameterValues.Num() > 0 ? pnum->MaximumValue : pnum->MinimumValue);
				ParameterValues.Add(v);
			}
			else if (const auto penum = (FInputParameterEnumeration*)(&p))
			{
				auto&& v = FInputParameterValueEnumeration(*penum, TEXT(""));
				ParameterValues.Add(v);
			}
			else
			{
				checkNoEntry();
			}
		}
		++i;
	}
}

FScenario_Score FConsideration::Score(IInputBrokerInterface& broker, const FScenario_Context& context)
{
	FScenario_Score score;
	score.InputRawValue = broker.GetInputValue(*this, context);
	score.InputValue = NormalizeInput(score.InputRawValue);
	score.FinalScore = Curve.ComputeValue(score.InputValue);
	return score;
}

float FConsideration::NormalizeInput(float raw)
{
	if (ParameterValues.Num() == 1)
	{
		//todo: super unhappy about this casting business, should find a different implementation that adapts or somehow avoids this dynamic type checking.
		if ((FInputParameterValueEnumeration*)(&ParameterValues[0]) != nullptr)
		{
			return FMath::Clamp(raw, 0.f, 1.f);
		}
		else if (const auto pnum = (FInputParameterValueNumeric*)(&ParameterValues[0]))
		{
			auto max = pnum->Value;
			if (max == 0.f) return 0.f;

			if (WrapInput)
			{
				//raw = raw % max;
			}
			else
			{
				raw = FMath::Clamp(raw, 0.f, max);
			}
			return raw / max;
		}
		else
		{
			checkNoEntry();
			return 0.f;
		}
	}
	else if (ParameterValues.Num() == 2)
	{
		unimplemented();
	}
	else
	{
		return WrapInput ? raw - FGenericPlatformMath::TruncToInt(raw) : FMath::Clamp(raw, 0.f, 1.f);
	}
	return 0.f;
}
