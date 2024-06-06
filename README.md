# Reaction-Master

GAME RULES 

Objective: React to the LED lights by pressing the correct buttons within a time limit to advance through levels. 

Scoring: Each correct reaction increases the score by 1. The score is displayed via the serial monitor. 

Levels: The game has 8 levels, each with increasing difficulty by reducing the reaction time limit. 

Presses Per Level: Each level requires 5 correct button presses to advance to the next level. 

Game Over: The game ends if the player presses the wrong button or fails to press any button within the time limit. 


USER INPUT CONTROLS 

Slide Switch: 

Function: Starts and resets the game. 

Control: When the slide switch state changes, the game resets and starts from the beginning. 

Left Button: 

Function: Player input to react to the left-side LED indicators. 

Control: When a left-side LED (index 0-4) is lit, pressing this button counts as a correct reaction. 

Right Button: 

Function: Player input to react to the right-side LED indicators. 

Control: When a right-side LED (index 5-9) is lit, pressing this button counts as a correct reaction. 

Both Buttons: 

Function: Player input to react to all LEDs being lit. 

Control: When all LEDs (index 10) are lit, pressing both buttons simultaneously counts as a correct reaction. 


SENSORS AND THEIR FUNCTIONS

Slide Switch: 

Raw Range: 0 (left) or 1 (right) 

Function: Starts and resets the game. 

Mapping: When the state changes, the game is reset and started. 

Buttons: 

Left Button: 

Raw Range: 0 (not pressed) or 1 (pressed) 

Function: Reacts to left-side LEDs (0-4). 

Right Button: 

Raw Range: 0 (not pressed) or 1 (pressed) 

Function: Reacts to right-side LEDs (5-9). 

Both Buttons: 

Raw Range: 0 (not pressed) or 1 (pressed simultaneously) 

Function: Reacts to all LEDs being lit (10). 

LED Indicators 

LED Indexes: 

0-4: Left-side LEDs (Red). 

5-9: Right-side LEDs (Red). 

10: All LEDs (Blue). 

REACTION TIME AND MAPPING

Initial Reaction Time Limit: 1000 milliseconds. 

Reaction Time Reduction: Each level reduces the reaction time limit by 100 milliseconds. 

Level 1: 1000 ms 

Level 2: 900 ms 

Level 3: 800 ms 

Level 4: 700 ms 

Level 5: 600 ms 

Level 6: 500 ms 

Level 7: 400 ms 

Level 8: 300 ms 

Mapping Functions 

Button Press Mapping: 

Left Button: Maps to LEDs 0-4. 

Right Button: Maps to LEDs 5-9. 

Both Buttons: Maps to all LEDs (index 10). 

Score Tracking: Each successful reaction increments the score by 1. 

Level Advancement: After 5 successful reactions, the level advances, and the reaction time limit decreases. 


GAME END CONDITIONS

Incorrect Button Press: Ends the game and plays a game over tone. 

Timeout: If no button is pressed within the reaction time limit, the game ends and plays a game over tone. 

Completion: If all levels are completed successfully, the game ends with a celebration (rainbow cycle). 
