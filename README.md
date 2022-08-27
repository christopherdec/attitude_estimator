# Attitude Estimator

This is an attitude estimator written in cpp. It reads accelerometer data from a ```.log``` file, calculates the roll and pitch angles and writes the result in an output file. Each data line must be in the format:

    <time_stamp_ms; accel_x_axis; accel_y_axis; accel_z_axis>,
where the timestamp is in milliseconds and the following terms correspond to axis acceleration in millig-unit.

The output file ```results.txt``` will be created or rewritten and each line will follow the format 

    <time_stamp_ms; roll_angle; pitch_angle>,

where the angles are in radians.

Example of operation: assuming an input file which contains the line ```"54741; 27; -22; -982"```, the program will output ```"54741; -3.11919; -0.0274811"``` in the ```results.txt``` file.

## How it was made

The .cpp file was developed in Visual Studio Code, using the MinGW64 gcc C++ compiler. The mathematical formulas are withdrawn from the document [Tilt Sensing Using a Three-Axis
Accelerometer](https://www.nxp.com/docs/en/application-note/AN3461.pdf).

## How to run it

To run this file, you'll need to have an input file containing the accelerometer data in the previously mentioned format. **Beware:** depending on the name of the input file, you may have to adjust the inputFile variable name, or else an IO exception may be thrown.

You also need a C++ compiler in order to compile the .cpp file and run it. If you don't have one, you can follow [this guide](https://code.visualstudio.com/docs/languages/cpp) as I did.