#include "InputAxis.h"
#include "Curvature.h"

FInputAxis FInputAxis::Clamp(const TArray<FInputParameterValueNumeric>& parameters)
{
	if (parameters.Num() == 0)
	{
		return *this;
	}
	
	if (parameters.Num() == 1)
	{
		/* if(dynamic_cast<FInputParameterValueEnumeration*>(&parameters[0]) != nullptr)
		 {
		     return *this;
		 }*/

		auto ret = FInputAxis(ReadableName, Origin);
		ret.KBRecord = KBRecord;
		//todo: super unhappy about this casting business, should find a different implementation that adapts or somehow avoids this dynamic type checking.
		const auto thisNumericParameterPtr = (FInputParameterNumeric*)(&Parameters[0]);
		check(thisNumericParameterPtr != nullptr);
		auto&& thisNumericParameter = *thisNumericParameterPtr;

		const auto otherNumericParameterPtr = (FInputParameterValueNumeric*)(&parameters[0]);
		check(otherNumericParameterPtr != nullptr);
		auto&& otherNumericParameter = *otherNumericParameterPtr;

		const auto newMin = thisNumericParameter.MinimumValue;
		const auto newMax = FMath::Min(thisNumericParameter.MaximumValue, otherNumericParameter.Value);

		auto&& param = FInputParameterNumeric{thisNumericParameter.ReadableName, newMin, newMax};
		ret.Parameters.Add(param);
		return ret;
	}
	
	if (parameters.Num() == 2)
	{
		auto ret = FInputAxis(ReadableName, Origin);
		ret.KBRecord = KBRecord;
		//todo: super unhappy about this casting business, should find a different implementation that adapts or somehow avoids this dynamic type checking.

		const auto thisNumericParameterPtr0 = (FInputParameterNumeric*)(&Parameters[0]);
		check(thisNumericParameterPtr0 != nullptr);
		auto&& thisNumericParameter0 = *thisNumericParameterPtr0;

		const auto thisNumericParameterPtr1 = (FInputParameterNumeric*)(&Parameters[1]);
		check(thisNumericParameterPtr1 != nullptr);
		auto&& thisNumericParameter1 = *thisNumericParameterPtr1;

		const auto otherNumericParameterPtr0 = (FInputParameterValueNumeric*)(&parameters[0]);
		check(otherNumericParameterPtr0 != nullptr);
		auto&& otherNumericParameter0 = *otherNumericParameterPtr0;

		const auto otherNumericParameterPtr1 = (FInputParameterValueNumeric*)(&parameters[1]);
		check(otherNumericParameterPtr1 != nullptr);
		auto&& otherNumericParameter1 = *otherNumericParameterPtr1;

		const auto newMin = FMath::Max(thisNumericParameter0.MinimumValue, otherNumericParameter0.Value);
		const auto newMax = FMath::Min(thisNumericParameter1.MaximumValue, otherNumericParameter1.Value);

		auto&& param = FInputParameterNumeric{thisNumericParameter0.ReadableName, newMin, newMax};
		ret.Parameters.Add(param);
		return ret;
	}
	ensure(false);
	return *this;
}

FInputAxis FInputAxis::Union(const FInputAxis& other)
{
	if (other.Parameters.Num() == 0)
	{
		return *this;
	}
	
	if (other.Parameters.Num() == 1)
	{
		/* if(dynamic_cast<FInputParameterEnumer*>(&other.Parameters[0]) == nullptr)
		 {
		     return *this;
		 }*/

		auto ret = FInputAxis(ReadableName, Origin);
		ret.KBRecord = KBRecord;

		//todo: super unhappy about this casting business, should find a different implementation that adapts or somehow avoids this dynamic type checking.
		const auto thisNumericParameterPtr0 = (FInputParameterNumeric*)(&Parameters[0]);
		check(thisNumericParameterPtr0 != nullptr);
		auto&& thisNumericParameter0 = *thisNumericParameterPtr0;

		const auto otherNumericParameterPtr0 = (FInputParameterNumeric*)(&other.Parameters[0]);
		check(otherNumericParameterPtr0 != nullptr);
		auto&& otherNumericParameter0 = *otherNumericParameterPtr0;

		const auto newMin = FMath::Min(thisNumericParameter0.MinimumValue, otherNumericParameter0.MinimumValue);
		const auto newMax = FMath::Max(thisNumericParameter0.MaximumValue, otherNumericParameter0.MaximumValue);

		auto&& param = FInputParameterNumeric(thisNumericParameter0.ReadableName, newMin, newMax);
		ret.Parameters.Add(param);
		return ret;
	}
	checkNoEntry();
	return *this;
}
