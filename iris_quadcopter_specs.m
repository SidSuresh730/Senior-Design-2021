%% IRIS+ Physical Properties (from Fum)

g = 9.8; % acceleration due to gravity (m/s^2)
rho = 1.225; % nominal air density value (kg/m^3)

%Measured characteristics
M = 1.37; % mass of quadcopter
D = .2540; % rotor diameter (m)
LxF = .0923; % Front moment arm length along x-axis (m)
LyF = .2537; % Front moment arm length along y-axis (m)
LxB = 0.13; % back x (m)
LyB = .2252; % back y (m)
lx = (LxF+LxB)/2;
ly = (LyF+LyB)/2;

% Moments of Inertia
Ixx = 0.0219; % mass moment of inertia x-axis (kgm^2)
Iyy = 0.0109; % y-axis (kg.m^2)
Izz = 0.0306; % z-axis (kg.m^2)

% Propeller coefficients
Kt = 0.12*rho*D^4*4*pi^4;
Kd = 1;

wo = sqrt(M*g/(4*Kt));

% Matrix rotor speeds to torques
Gamma = [    -Kt, -Kt, -Kt, -Kt; ...
             -Kt*ly, -Kt*ly, Kt*ly, Kt*ly; ...
             Kt*lx, -Kt*lx, -Kt*lx, Kt*lx; ...
             Kd, -Kd, Kd, -Kd];
%% From Simulink plant
%   Copyright 2020 The MathWorks, Inc.

%Based on the quadcopter model used in jMAVSim

Ixx = 0.005; %Kgm^2
Iyy = 0.005;
Izz = 0.009;


inertia = diag([Ixx, Iyy, Izz]);

mass = 0.8; %Kg
g = 9.81; %m/s^2

armLength = 0.33/2; % length of Arm measured from center in m

rotorThrustMax = 4; %N

rotorTorqueMax = 0.05 %Nm

rotorTimeConst = 0.005 ;% time constant of rotor (motor + propeller)

%rotorOffset = [0 0 0]; % Rotors position offsets from Gravity center

dragCoeffMov = 0.01; %drag coefficient for linear motion of quadcopter
windVel = [0 0 0]';

% Initial states
init.posNED = [0, 0, -5]; % m
init.vb = [0 0 0]'; %m/s
init.euler = [0, 0, 0]'; %Roll Pitch Yaw Rads
init.angRates = [0, 0, 0]; %rad/s 


%Computed from above values
rotorPositions = zeros(3,4);
axisD = armLength/sqrt(2);
rotorPositions(:,1) = [axisD, axisD, 0]';
rotorPositions(:,2) = [-axisD, -axisD, 0]';
rotorPositions(:,3) = [+axisD, -axisD, 0]';
rotorPositions(:,4) = [-axisD, axisD, 0]';
rotorDir = [-1, -1, 1, 1]; %rotation direction. +ve = clockwise

% Sample Time
%SampleTime = 0.004;
SampleTime = 0.001;
%Gain to convert m to mm
m_to_mm = 1000;

%Gain to convert m/s^2 to mG
ms2_to_mg = (1/9.80665)*1000;

%Gain to convert m/s to cm/s
ms_to_cms = 100;

%Reference height for 'Flat Earth to LLA'
ref_height = -71.3232;

altToPrsGain = 12.0173;
altToPrsBias = 101270.95;

tau_thrust = Simulink.Signal;
tau_thrust.CoderInfo.StorageClass = 'ExportedGlobal';
tau_thrust.InitialValue = '0';

tau_pitch = Simulink.Signal;
tau_pitch.CoderInfo.StorageClass = 'ExportedGlobal';
tau_pitch.InitialValue = '0';

tau_roll = Simulink.Signal;
tau_roll.CoderInfo.StorageClass = 'ExportedGlobal';
tau_roll.InitialValue = '0';