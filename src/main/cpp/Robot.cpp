// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>

#include "../include/subsystems/DriveTrain.hpp"
#include "../include/Constants.h"

using namespace IO;

class Robot : public frc::TimedRobot {
 public:
  Robot() { /* Put any init code here if needed */ }

  void AutonomousInit() override {}

  void AutonomousPeriodic() override {}

  void TeleopInit() override {}

  void TeleopPeriodic() override 
  {
    DRIVE.drive(-Joystick.GetY(), -Joystick.GetX());
  }

  void TestInit() override {}

  void TestPeriodic() override {}

 private:
  /* Declare all of subsystems */
  DriveTrain DRIVE;
  frc::Joystick Joystick { DRIVER_CONTROLLER };
};

int main() {
  return frc::StartRobot<Robot>();
}