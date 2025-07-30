# HEATER-COOLER-SYSTEM-USING-AVR

At system startup, the set temperature is initialized to 60°C by default. As a result, the heater is activated, causing the actual temperature to gradually increase until it matches the desired setpoint, at which point the system becomes stable.

When the heating button is pressed, the set temperature increases by 5°C. Consequently, the heater turns ON to raise the actual temperature until it equals the new setpoint.

Since Proteus does not physically simulate changes in environmental temperature, the sensor temperature must be manually adjusted in the simulation to reflect the expected behavior. In a real-world scenario, activating the heater naturally causes the water temperature to rise, which the sensor detects accordingly.

If there is any malfunction — whether in the heater or the temperature sensor — and the actual temperature does not change within a specified time frame, the system will display a "Heating Failure" message, indicating a fault in the heating mechanism or sensor.

Similarly, when the cooling button is pressed, the set temperature decreases by 5°C. The cooler is activated until the actual temperature drops and matches the new setpoint. Again, if the temperature does not change within a defined period, a "Cooling Failure" message will be displayed.

The system includes two LED indicators:

A blinking red LED indicates active heating.

A blinking blue LED indicates active cooling.

For simulation purposes, both the heater and cooler have been replaced with red and blue LEDs, respectively. In real-world applications, these would be replaced by the actual heater and cooling units.

Finally, the last set temperature is stored in the internal EEPROM of the microcontroller to retain system memory across power cycles.
<img width="1465" height="822" alt="Image" src="https://github.com/user-attachments/assets/3b852fb1-8aa8-4e84-bc6f-9631a2fdece4" />
