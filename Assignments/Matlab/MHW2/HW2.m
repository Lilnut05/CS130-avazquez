% Put your name here: Adriel Vazquez
%
% Note: Problems will be scored just like homework is scored, using
%       the "Homework Mandatory Requirements" document.

%% Problem 1
%
% The formula for radioactive decay is:
%
% A = A0 * ( 1 / 2 ) ^ ( t / h)
%
% where:
%
% A0 is the orginal amount of the substance (at t = 0).
% A is the amount after time "t" has elapsed.
% h is the half life of the substance.
% t is the elapsed time.
%
% The half life of Carbon-14 is about 5730 years.  A sample contains
% 64 grams of Carbon-14 at time t = 0.  Write a MATLAB script that will
% produce a table showing the amount of Carbon-14 remaining every 1000
% years until 20000 years has elapsed.
%
% Choose an output format that shows the amount of Carbon-14 remaining
% to AT LEAST a hundredth of a gram.
%
% Use the "disp(...)" function to label your column headings "Years" and
% "Amount" respectively.  Optionally, you may use the "table(...)" function
% but, if you do, you must use it correctly.

% Constants
A0 = 64;
h = 5730;
time_interval = 1500;
max_time = 24000;

% Display column headings
disp('Years     Amount (grams)');

% Loop through each time interval and calculate the remaining Carbon-14
for t = 0:time_interval:max_time
    A = A0 * (1 / 2) ^ (t / h);  % Decay formula for calculations of half life
    fprintf('%5d     %10.2f\n', t, A);  % Displays results
end
