% MAtlab HW1
% ADRIEL VAZQUEZ
% 12/3/24
% Program calculates projectile distance and time and height of a projectile

% Clear all
clear;
clc;
close all;

% Gravity
g = 9.81;

% Ask the user if they want to use meters or feet
unit_choice = input('Enter 1 for Meters or 2 for Feet: ');

% Set conversion factors based on unit choice
if unit_choice == 1
    conversion = 1; % No conversion needed for meters
    unit = 'meters';
else
    conversion = 0.3048; % Converts feet to meters
    unit = 'feet';
end

% Get the initial velocity input
V0 = input(['Enter the initial velocity in ', unit, '/s: ']);
V0 = V0 * conversion; % Convert to meters if needed

% Get the angle of launch input
angle_deg = input('Enter the angle of launch in degrees (between 0 and 90): ');
angle_rad = angle_deg * pi / 180; % Conversion between degrees to radians

% Get the target distance input
target_distance = input(['Enter the target distance in ', unit, ': ']);
target_distance = target_distance * conversion; % Convert to meters

% Calculate velocities
V_vertical = V0 * sin(angle_rad);
V_horizontal = V0 * cos(angle_rad);

% Calculate the max height
h_max = (V_vertical^2) / (2 * g);

% Calculate the total time
t_flight = (2 * V_vertical) / g;

% Calculate the distance
x_distance = (V0^2 * sin(2 * angle_rad)) / g;

% Display the results
disp(' ');
disp('Results:');
disp(['Max Height: ', num2str(h_max, '%.2f'), ' meters (', num2str(h_max / 0.3048, '%.2f'), ' feet)']);
disp(['Flight Time: ', num2str(t_flight, '%.2f'), ' seconds']);
disp(['Horizontal distance: ', num2str(x_distance, '%.2f'), ' meters (', num2str(x_distance / 0.3048, '%.2f'), ' feet)']);

% Check if the projectile will hit the target
if x_distance >= target_distance
    disp('The target is in range.');
else
    disp('The target isnt in range.');
end

% Plot height vs. time
t = linspace(0, t_flight, 100);
y_distance = V_vertical * t - 0.5 * g * t.^2;
x_distance_t = V_horizontal * t;

figure;
subplot(2, 1, 1);
plot(t, y_distance);
title('Height vs. Time');
xlabel('Time (seconds)');
ylabel(['Height (', unit, ')']);

subplot(2, 1, 2);
plot(t, x_distance_t);
title('Distance vs. Time'); 
xlabel('Time (seconds)');
ylabel(['Distance (', unit, ')']); 
