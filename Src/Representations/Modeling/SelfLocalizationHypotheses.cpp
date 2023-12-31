/**
 * @file SelfLocalizationHypotheses.cpp
 *
 * List of robot pose hypotheses that are currently evaluated by the self-localization module.
 * This information is not used as input for further computations but is logged and
 * helps during the debugging of localization problems.
 *
 * @author Tim Laue
 */

#include "SelfLocalizationHypotheses.h"
#include "Tools/Debugging/DebugDrawings.h"

void SelfLocalizationHypotheses::draw() const
{
  DEBUG_DRAWING("representation:SelfLocalizationHypotheses:plain", "drawingOnField")
  {
    for(const auto& h : hypotheses)
    {
      float stdDev = std::sqrt(h.rotVariance);
      DRAW_ROBOT_POSE_ROTATIONAL_STANDARD_DEVIATION("representation:SelfLocalizationHypotheses:plain",
                                                    h.pose, stdDev, ColorRGBA(200, 200, 0));
    }
  }
  DEBUG_DRAWING("representation:SelfLocalizationHypotheses:covariance", "drawingOnField")
  {
    for(const auto& h : hypotheses)
    {
      float stdDev = std::sqrt(h.rotVariance);
      DRAW_ROBOT_POSE_ROTATIONAL_STANDARD_DEVIATION("representation:SelfLocalizationHypotheses:covariance",
                                                    h.pose, stdDev, ColorRGBA(100, 100, 100, 100));
      Matrix2f cov;
      cov(0, 0) = h.xVariance;
      cov(1, 1) = h.yVariance;
      cov(1, 0) = h.xyCovariance;
      cov(0, 1) = h.xyCovariance;
      COVARIANCE_ELLIPSES_2D("representation:SelfLocalizationHypotheses:covariance", cov, h.pose.translation);
    }
  }
}
