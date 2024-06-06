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

Outputs: LEDs, Play Tone, Rainbow Cycle.  


GAME END CONDITIONS

Incorrect Button Press: Ends the game and plays a game over tone. 

Timeout: If no button is pressed within the reaction time limit, the game ends and plays a game over tone. 

Completion: If all levels are completed successfully, the game ends with a celebration (rainbow cycle). 
