# ndi_tracker_and_error_metrics
Examples of using the NDI polaris optical tracker and computing error metrics

## Downloading Code
(Assumes you already have the polaris code installed)
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/ndi_tracker_and_error_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
1. Connect the polaris tracker to your computer
2. Navigate to polaris workspace: `cd ~/workspaces/polaris_ws`
3. Source the polaris workspace: `source install/setup.bash`
4. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
5. Source the examples workspace: `source install/setup.bash`
6. Run the code: `ros2 launch polaris_example polaris_example.launch.yaml`
7. On the GUI, press Connect and wait for connection message
8. Press Track
9. Move trackers around in tracker workspace