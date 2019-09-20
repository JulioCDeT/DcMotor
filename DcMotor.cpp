/*Copyright (C) 2019  DcMotor

This is part of DcMotor

DcMotor is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

#include "Arduino.h"
#include "DcMotor.h"

//Generate an instance of DcMotor class, for rotation control
//motor.
DcMotor::DcMotor(uint8_t pin1, uint8_t pin2) 
    : m_pin1(pin1), m_pin2(pin2), m_monoPin(false)
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    m_state = false;
}

//Generate an instance of DcMotor class, for simple turn on/off control.
DcMotor::DcMotor(uint8_t pin1)
    : m_pin1(pin1), m_pin2(254), m_monoPin(true)
{
    pinMode(pin1, OUTPUT);
    digitalWrite(pin1, LOW);
    m_state = false;
}

//Move the motor clockwise. 
//Note: Use only 2 pins motors
void DcMotor::turnRight()
{
    if (!m_monoPin)
    {
        digitalWrite(m_pin1, HIGH);
        digitalWrite(m_pin2, LOW);
        m_state = true;
    }
}

//Moves the motor counterclockwise
//Note: Use only 2 pins motors
void DcMotor::turnLeft()
{
    if (!m_monoPin)
    {
        digitalWrite(m_pin1, LOW);
        digitalWrite(m_pin2, HIGH);
        m_state = true;
    }
}

//Start the single-pin motor
void DcMotor::turnOn()
{
    if (m_monoPin) 
    {
        digitalWrite(m_pin1, HIGH);
        m_state = true;
    }    
}

//Stop the motor
void DcMotor::turnOff()
{
    digitalWrite(m_pin1, LOW);
    if (!m_monoPin)
    {
        digitalWrite(m_pin2, LOW);
        m_state = false;
    }    
}

//Return true if the Motor is working, else false
bool DcMotor::isWorking()
{
    return m_state;
}

//Generate an instance of Tire class,
//which inherits from DcMotor.
Tire::Tire(uint8_t pin1, uint8_t pin2)
    : DcMotor(pin1, pin2) {}


//MoveForward the car, clockwise direction
void Tire::moveForward()
{
    turnRight();
}

//MoveForward the car, counterclockwise direction
void Tire::moveBackward()
{
    turnLeft();
}
