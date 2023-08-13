# Attitude Estimator

This is a simple sensor data log processor. It reads accelerometer output from a ```.log``` file, calculates the roll and pitch angles and writes the result (attitude estimate) in an output file. It expects data in the following format:

    <time_stamp_ms; accel_x_axis; accel_y_axis; accel_z_axis>

where the timestamp is in milliseconds and the remaining values correspond to axis acceleration in millig-unit. \
An output file ```results.txt``` will be created/overwritten, where each line will follow the format:

    <time_stamp_ms; roll_angle; pitch_angle>

where the angles are in radians.

## Example of operation
Assuming an input file which contains the line ```"54741; 27; -22; -982"```, the program will write ```"54741; -3.11919; -0.0274811"``` in the results file.

## How it was made

The mathematical formulas were withdrawn from this document: [Tilt Sensing Using a Three-Axis Accelerometer](https://www.nxp.com/docs/en/application-note/AN3461.pdf).\

## How to run it

To run this file, you'll need to have an input file containing the accelerometer data in the previously mentioned format.\
**Beware:** depending on the name of the input file, you may have to adjust the inputFile variable name, or else an IO exception may be thrown.

You also need a C++ compiler in order to compile the .cpp file and [run it](https://code.visualstudio.com/docs/languages/cpp).
