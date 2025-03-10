#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

#include "Constants.h"

using namespace ctre::phoenix::motorcontrol::can;
using namespace DriveTrainVariables;

class DriveTrain : frc2::SubsystemBase
{
    public:
        DriveTrain() {};

        void drive(double xSpeed, double zRotation)
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
        };
    private:
        /* TalonSRX's do not have a callable constructor, meaning they must constructs once declared, such as below */
        TalonSRX       LEFT_MASTER { L_MASTER_ID };
        TalonSRX       LEFT_SLAVE  { L_SLAVE_ID  };
        TalonSRX       RIGHT_MASTER{ R_MASTER_ID };
        TalonSRX       RIGHT_SLAVE { R_SLAVE_ID  };
};

#endif // DRIVETRAIN_H