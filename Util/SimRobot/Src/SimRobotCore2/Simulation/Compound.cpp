/**
 * @file Simulation/Compound.cpp
 * Implementation of class Compound
 * @author Colin Graf
 */

#include "Compound.h"
#include "Platform/Assert.h"
#include "Platform/OpenGL.h"
#include "Simulation/Geometries/Geometry.h"
#include "Simulation/Simulation.h"
#include "Tools/ODETools.h"
#include "Tools/OpenGLTools.h"
#include <ode/collision.h>

void Compound::addParent(Element& element)
{
  ::PhysicalObject::addParent(element);
  GraphicalObject::addParent(element);
}

void Compound::createPhysics()
{
  // create geometry
  for(::PhysicalObject* iter : physicalDrawings)
  {
    Geometry* geometry = dynamic_cast<Geometry*>(iter);
    if(geometry)
      addGeometry(pose, *geometry, nullptr);
  }

  //
  ::PhysicalObject::createPhysics();

  OpenGLTools::convertTransformation(rotation, translation, transformation);
}

void Compound::addGeometry(const Pose3f& parentPose, Geometry& geometry, SimRobotCore2::CollisionCallback* callback)
{
  // compute pose
  Pose3f geomPose = parentPose;
  if(geometry.translation)
    geomPose.translate(*geometry.translation);
  if(geometry.rotation)
    geomPose.rotate(*geometry.rotation);

  // create geometry
  dGeomID geom = geometry.createGeometry(Simulation::simulation->staticSpace);
  if(geom)
  {
    dGeomSetData(geom, &geometry);

    // set pose
    dGeomSetPosition(geom, geomPose.translation.x(), geomPose.translation.y(), geomPose.translation.z());
    dMatrix3 matrix3;
    ODETools::convertMatrix(geomPose.rotation, matrix3);
    dGeomSetRotation(geom, matrix3);
  }

  // handle nested geometries
  for(::PhysicalObject* iter : geometry.physicalDrawings)
  {
    Geometry* geometry = dynamic_cast<Geometry*>(iter);
    if(geometry)
      addGeometry(geomPose, *geometry, callback);
  }
}

void Compound::assembleAppearances(SurfaceColor color) const
{
  glPushMatrix();
  glMultMatrixf(transformation);
  GraphicalObject::assembleAppearances(color);
  glPopMatrix();
}

void Compound::drawPhysics(unsigned int flags) const
{
  glPushMatrix();
  glMultMatrixf(transformation);
  ::PhysicalObject::drawPhysics(flags);
  glPopMatrix();
}
