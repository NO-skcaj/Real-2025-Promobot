// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include "include/Headers.h"

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
  WestCoast DRIVE;
  frc::Joystick Joystick { CONTROLLER_ID };
};

int main() {
  return frc::StartRobot<Robot>();
}