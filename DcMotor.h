/*Copyright (C) 2019  DcMotor

DcMotor is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

DcMotor is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

/** DcMotor
 *  By: JulioCDeT
 *  Description:
 *      Library that facilitates the manipulation of Dc motors both 
 *      those that require control direction of rotation, as those 
 *      that just need to turn on or off.
 *
 *      Also thought to move robotic cars was added the class, Tire,
 *      which inherits from DcMotor and renames the methods turnRight,
 *      turnLeft, to moveForward and moveBackward.
 * 
 *      The objective of this library is to provide greater readability
 *      at the time of writing the code to handle these actuators.
 *
 *  Version:
 *      1.0.1
 *  Date:
 *      07/04/2019
 */
#pragma once

class DcMotor
{
  protected:
    uint8_t m_pin1;
    uint8_t m_pin2;
    bool m_monoPin;
    bool m_state;

  public:
    //Generate an instance of DcMotor class, for rotation control
    //motor.
    DcMotor(uint8_t pin1, uint8_t pin2);

    //Generate an instance of DcMotor class, for simple turn on/off control.
    DcMotor(uint8_t pin1);

    //Destructor
    ~DcMotor() {}

    //Move the motor clockwise. 
    //Note: Use only 2 pins motors
    void turnRight();

    //Moves the motor counterclockwise
    //Note: Use only 2 pins motors
    void turnLeft();

    //Start the single-pin motor
    void turnOn(); 

    //Stop the motor
    void turnOff();

    //Return true if the Motor is working, else false
    bool isWorking();
};


class Tire : public DcMotor
{
  public:
    //Generate an instance of Tire class,
    //which inherits from DcMotor.
    Tire (uint8_t pin1, uint8_t pin2);

    //MoveForward the car, clockwise direction
    void moveForward();   

    //MoveForward the car, counterclockwise direction
    void moveBackward();

    //Destructor
    ~Tire() {}
};