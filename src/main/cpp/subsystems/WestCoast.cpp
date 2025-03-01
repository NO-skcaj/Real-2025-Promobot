#include "../include/subsytems/WestCoast.hpp"

/* All init code for our subsystem is called in the constructor, this saves us from writing a 'init()' function */
WestCoast::WestCoast()
{
}

void WestCoast::drive(double xSpeed, double zRotation)
{
    xSpeed = std::clamp(xSpeed, -1.0, 1.0);
    zRotation = std::clamp(zRotation, -1.0, 1.0);

    // Square the inputs (while preserving the sign) to increase fine control
    // while permitting full power.
    xSpeed = std::copysign(xSpeed * xSpeed, xSpeed);
    zRotation = std::copysign(zRotation * zRotation, zRotation);

    double leftSpeed = xSpeed - zRotation;
    double rightSpeed = xSpeed + zRotation;

    // Find the maximum possible value of (throttle + turn) along the vector that
    // the joystick is pointing, then desaturate the wheel speeds
    double greaterInput = (std::max)(std::abs(xSpeed), std::abs(zRotation));
    double lesserInput = (std::min)(std::abs(xSpeed), std::abs(zRotation));
    
    if (greaterInput == 0.0) {
    return;
    }

    double saturatedInput = (greaterInput + lesserInput) / greaterInput;
    leftSpeed /= saturatedInput;
    rightSpeed /= saturatedInput;


    this->LEFT_MASTER.Set (ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, leftSpeed);   
    this->LEFT_SLAVE.Set  (ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, leftSpeed);
    
    this->RIGHT_MASTER.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, -rightSpeed);
    this->RIGHT_SLAVE.Set (ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, -rightSpeed);
}   