#include "ResponseCurve.h"

#include "Curvature.h"

float FResponseCurve::ComputeValue(float x) const
{
    switch(Type)
        {
        case ECurveType::Linear:
            return Sanitize(Slope * (x-XShift) + YShift);
        case ECurveType::Polynomial:
            return Sanitize(Slope * FMath::Pow(x-XShift, Exponent) + YShift);
        case ECurveType::Logistic:
            return Sanitize(Slope / (1.f + FMath::Exp(-10.f * Exponent *(x - 0.5f - XShift))) + YShift);
        case ECurveType::Logit:
            return Sanitize(Slope * FMath::Loge((x - XShift) / (1.0 - (x - XShift))) / 5.0 + 0.5 + YShift);
        case ECurveType::Normal:
            return Sanitize(Slope * FMath::Exp(-30.0 * Exponent * (x - XShift - 0.5) * (x - XShift - 0.5)) + YShift);
        case ECurveType::Sine:
            return Sanitize(0.5 * Slope * FMath::Sin(2.0 * PI * (x - XShift)) + 0.5 + YShift);
        default:
            checkNoEntry();
            return 0.f;
        }
}

float FResponseCurve::Sanitize(float y)
{
    return FMath::IsFinite(y) ? FMath::Clamp(y, 0.f, 1.f) : 0.f;
}
