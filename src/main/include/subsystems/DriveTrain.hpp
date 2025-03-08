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
        DriveTrain();
        void drive(double xSpeed, double zRotation);
    private:
        /* TalonSRX's do not have a callable constructor, meaning they must constructs once declared, such as below */
        TalonSRX       LEFT_MASTER { L_MASTER_ID };
        TalonSRX       LEFT_SLAVE  { L_SLAVE_ID  };
        TalonSRX       RIGHT_MASTER{ R_MASTER_ID };
        TalonSRX       RIGHT_SLAVE { R_SLAVE_ID  };
};

#endif // DRIVETRAIN_H