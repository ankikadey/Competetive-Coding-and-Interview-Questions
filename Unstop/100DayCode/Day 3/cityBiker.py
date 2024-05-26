# Read input values
n = int(input())
gains = list(map(int, input().split()))

# Initial altitude and highest altitude
current_altitude = 0
highest_altitude = 0

# Calculate the altitude at each point and track the highest altitude
for gain in gains:
    current_altitude += gain
    if current_altitude > highest_altitude:
        highest_altitude = current_altitude

# Print the highest altitude reached
print(highest_altitude)