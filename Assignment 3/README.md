# README Stage 3

## Marking overview

I have not implemented all of the assignment requirements. To (maybe) save you a bit of time with marking, here's an overview of what I have and haven't done:

### Implemented

* Compiles and runs
* Behavioural Design Pattern (Observer - see below)
* Configurable number of lives (`numLives` config param)
* Losing a life and level restart on collision
* Display score (score is based on distance travelled but also affected by powerups and obstacles)
* Preserve stage 2 functionality
* User control (left-right motion)
* Power ups 
* Testing framework (preserved from Stage 2, now also shows power-ups / coins) 
* Extensions (see below)

### Not implemented

* Multiple levels
* Checkpoints / reaching the end of a level


## Extensions 

1. Stickman sprite now walks in the correct direction, and stops moving when velocity is zero (**small-medium** extension)
2. Scoring mechanism - user gains score from any of the following actions (**medium** extension)
    * Distance travelled to the right (+1 per ten pixels travelled)
    * Pickup up coins (+1000 points)
    * Destroying an obstacle while `giant` size (+5000 points)
    
    
    
## Design Pattern (Observer)

Used to implement the **scoring** mechanism. 

Implemented using the `Observer` base class, with the ConcreteObserver extending from this in the `ScoreObserver` class. The Subject being observed is the `Stickman`. Whenever the Stickman moves horizontally, or collects a coin, or destroys an obstacle, the Observer receives a ping and uses this to update the score that is rendered to the user. 

The use of this design pattern provides extensibility and encapsulation in the scoring mechanism, making it convenient for the scoring information to be updated and accessed by new observers should the information be desirable for other purposes (e.g. a global scoreboard, online scoring, etc.).