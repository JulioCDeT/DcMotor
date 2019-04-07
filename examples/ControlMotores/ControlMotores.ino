/** ControlMotores
 *  Description: 
 *      This code exemplifies the use of the DcMotor library,
 *      Showing the use of the available methods.
 *
 *      This example shows how to control the motor of
 *      a fan, which only needs to turn on
 *      or turn off. Without controlling its direction of rotation.
 *
 *      As well as a conveyor belt driven by a Dc gear motor,
 *      which does require a change of direction,
 *      This requires invoking the second constructor of the class.
 *      Give as an argument the pins where the pin of the motor is connected.
 *
 *      In addition to showing how to control the advance and retreat of a
 *      car or robot, thinking that the engine was connected to a tire,
 *      for this particular case the class, "Tire" whose
 *      Unique functionality would be to provide greater readability at the time
 *      to use Dc motors connected to tires, in a project.
 *
 *  Version: 1.0.0
 *  Date: 03/04/2019
 */


#include "DcMotor.h"

/*Pins definition*/
const uint8_t PIN1_TIRE = 2;
const uint8_t PIN2_TIRE = 3;
const uint8_t PIN1_CONVEYOR_BELT = 4;
const uint8_t PIN2_CONVEYOR_BELT = 5;
const uint8_t PIN_FAN = 6;

/*Objects*/
Tire tire = Tire(PIN1_TIRE, PIN2_TIRE);
DcMotor convBelt(PIN1_CONVEYOR_BELT, PIN2_CONVEYOR_BELT);
DcMotor fan(PIN_FAN);

/*Main*/
void setup()
{
    //Control of simple step
    fan.turnOn();
    delay(5000);
    fan.turnOff();


    convBelt.turnRight();
    delay(3000);
    convBelt.turnLeft();
    delay(3000);
    convBelt.turnOff();

    tire.moveForward();
    delay(3000);
    tire.moveBackward();
    delay(3000);
    tire.turnOff();
}

void loop()
{

}
