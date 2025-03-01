#ifndef WESTCOAST_H
#define WESTCOAST_H

#include "../Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

using namespace ctre::phoenix::motorcontrol::can;

class WestCoast : frc2::SubsystemBase
{
    public:
        WestCoast();
        void drive(double y, double x);
    private:
        /* TalonSRX's do not have a callable constructor, meaning they must constructs once declared, such as below */
        TalonSRX       LEFT_MASTER { L_MASTER_ID };
        TalonSRX       LEFT_SLAVE  { L_SLAVE_ID  };
        TalonSRX       RIGHT_MASTER{ R_MASTER_ID };
        TalonSRX       RIGHT_SLAVE { R_SLAVE_ID  };
};

#endif