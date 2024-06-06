#include <Adafruit_CircuitPlayground.h>


void resetGame();
void startGame();
void playLevel(int level);
void endGame();
void rainbowCycle(int currentSpeed, int stripLen);
void playGameOverTone();

int score = 0; //track player score initialized to 0
int level = 1; //track game level initialized to 1
int reactionTimeLimit = 1000; // Initial time limit in milliseconds
int maxLevels = 8; // total number of levels 
int pressesPerLevel = 5; // Number of correct presses per level

bool gameActive = false; // flag to track if game is active
bool gameStarted = false; // flag to track if the game has started
bool lastSlideSwitchState = false; // track last state of the slide switch

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  Serial.println("Welcome to Reaction Time Challenge. Move the slide switch to start the game.");
}

void loop() {
  bool currentSlideSwitchState = CircuitPlayground.slideSwitch();//check current slide switch state

  if (currentSlideSwitchState != lastSlideSwitchState) { //checks if slide switch state has changed
    lastSlideSwitchState = currentSlideSwitchState; //updates slide switch to the current state

    if (!gameActive) {
      resetGame();//if game not active calls reset game function
    }
  }

  if (score >= 40) {
    rainbowCycle(5, 10); 
  }
}

void startGame() { 
  gameActive = true;//sets game to active
  level = 1;//resets level to 1
  reactionTimeLimit = 1000; // Reset to initial time limit
  score = 0;//resets score to 0
  Serial.println("Press the correct button when the LED lights up. Let's start!");

  while (level <= maxLevels && gameActive) {//loops through each level
    playLevel(level);//play curernt level
    level++;//increases the level
  }

  if (gameActive) {//ends game after completing all levels 
    endGame();//end the game 
  }
}

void playLevel(int level) {
  Serial.print("Level ");
  Serial.println(level);
  int successfulPresses = 0;//initialize the successful press counter 
  
  // Set the reaction time limit based on the level
  reactionTimeLimit = 1000 - ((level - 1) * 100); // Reduce by 100ms each level

  while (successfulPresses < pressesPerLevel && gameActive) {//loops until player has finished the game or becomes inactive
    int ledIndex = random(0, 11); // Randomly selected LED between 0 and 10, 10 being the special case for both sides
    CircuitPlayground.clearPixels();//clears any active LEDs
    
    if (ledIndex < 10) {
      CircuitPlayground.setPixelColor(ledIndex, 255, 0, 0); // Light up the LED in red
    } else {
      for (int i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, 0, 0, 255); // Light up all LEDs in blue
      }
    }
    
    unsigned long startTime = millis();//records start time
    bool buttonPressed = false;//initializes flag to track if button was pressed
    
    while (millis() - startTime < reactionTimeLimit) {//waits for button press within the reaction time limit
      if (CircuitPlayground.leftButton() && CircuitPlayground.rightButton() && ledIndex == 10) {
        buttonPressed = true;//sets flag to indicate button was pressed
        CircuitPlayground.clearPixels();//clears all LEDs
        successfulPresses++;//increment the counter for succesful presses
        score++;//increment the score
        Serial.println("Good job! Both buttons pressed.");
        break;//exit the inner while loop
      } else if (CircuitPlayground.leftButton() && ledIndex < 5) {
        buttonPressed = true;
        CircuitPlayground.clearPixels();
        successfulPresses++;
        score++;
        Serial.println("Good job! Left button pressed.");
        break;
      } else if (CircuitPlayground.rightButton() && ledIndex >= 5 && ledIndex < 10) {
        buttonPressed = true;
        CircuitPlayground.clearPixels();
        successfulPresses++;
        score++;
        Serial.println("Good job! Right button pressed.");
        break;
      } else if ((CircuitPlayground.leftButton() && ledIndex >= 5 && ledIndex < 10) || (CircuitPlayground.rightButton() && ledIndex < 5)) {
        buttonPressed = true;
        CircuitPlayground.clearPixels();
        Serial.println("Wrong button! Game over.");
        playGameOverTone();//play game over tone
        gameActive = false;//set gameActive to false
        Serial.print("Your final score is: ");
        Serial.println(score);//print the final score
        return;//exit function
      }
    }
    
    if (!buttonPressed) {//if no button was pressed within the time limit
      CircuitPlayground.clearPixels();//clear all LEDs
      Serial.println("Time's up! Game over.");
      playGameOverTone();
      gameActive = false;
      Serial.print("Your final score is: ");
      Serial.println(score);
      return;
    }
    
    delay(500); // Short pause before next attempt
  }

  if (gameActive) {//if game still active after completing level
    Serial.println("Level passed!");
  }
  delay(1000); // Short pause before next level
}

void endGame() {
  Serial.print("Game over. Your final score is: ");
  Serial.println(score);
  gameActive = false;//set gameActive to false to end game
}

void resetGame() {
  score = 0;//reset score to 0
  level = 1;//reset to level 1
  reactionTimeLimit = 1000; // Reset to initial time limit
  Serial.println("Game reset. Press the correct button when the LED lights up. Let's start!");
  delay(2000);
  startGame();//calls start game to restart the game
}

void rainbowCycle(int currentSpeed, int stripLen) {
  uint32_t offset = millis() / currentSpeed;
  for (int i = 0; i < 10; ++i) {
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / stripLen) + offset) & 255));
  }
}

void playGameOverTone() {
  CircuitPlayground.playTone(300, 200); 
  delay(50);
  CircuitPlayground.playTone(250, 200); 
  delay(50);
  CircuitPlayground.playTone(200, 200); 
}