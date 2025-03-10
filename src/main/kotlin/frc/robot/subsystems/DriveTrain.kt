package frc.robot.subsystems

import edu.wpi.first.wpilibj2.command.SubsystemBase
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min
import kotlin.math.sign

import com.ctre.phoenix.motorcontrol.can.WPI_TalonSRX;
import com.ctre.phoenix.motorcontrol.TalonSRXControlMode;
import frc.robot.DriveTrainVariables

class DriveTrain : SubsystemBase()
{
    init{};

    fun drive(speedInput: Double, rotationInput: Double)
    {
        var xSpeed   : Double = speedInput.coerceIn(-1.0, 1.0);
        var zRotation: Double = rotationInput.coerceIn(-1.0, 1.0);

        // Square the inputs (while preserving the sign) to increase fine control
        // while permitting full power.
        xSpeed    = sign(xSpeed) *    (xSpeed * xSpeed);
        zRotation = sign(zRotation) * (zRotation * zRotation);

        var leftSpeed : Double = xSpeed - zRotation;
        var rightSpeed: Double = xSpeed + zRotation;

        // Find the maximum possible value of (throttle + turn) along the vector that
        // the joystick is pointing, then desaturate the wheel speeds
        val greaterInput = max(abs(xSpeed), abs(zRotation));
        val lesserInput = min(abs(xSpeed), abs(zRotation));

        if (greaterInput == 0.0) {
            return;
        }

        val saturatedInput = (greaterInput + lesserInput) / greaterInput;
        leftSpeed /= saturatedInput;
        rightSpeed /= saturatedInput;


        LEFT_MASTER. set(TalonSRXControlMode.PercentOutput, leftSpeed);
        LEFT_SLAVE.  set(TalonSRXControlMode.PercentOutput, leftSpeed);

        RIGHT_MASTER.set(TalonSRXControlMode.PercentOutput, -rightSpeed);
        RIGHT_SLAVE. set(TalonSRXControlMode.PercentOutput, -rightSpeed);
    };
    /* TalonSRX's do not have a callable constructor, meaning they must constructs once declared, such as below */
    private val LEFT_MASTER : WPI_TalonSRX = WPI_TalonSRX(DriveTrainVariables.L_MASTER_ID);
    private val LEFT_SLAVE  : WPI_TalonSRX = WPI_TalonSRX(DriveTrainVariables.L_SLAVE_ID);
    private val RIGHT_MASTER: WPI_TalonSRX = WPI_TalonSRX(DriveTrainVariables.R_MASTER_ID);
    private val RIGHT_SLAVE : WPI_TalonSRX = WPI_TalonSRX(DriveTrainVariables.R_SLAVE_ID);
};