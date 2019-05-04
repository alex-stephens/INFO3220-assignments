# Flying Stickman Game

# Style Guide

The style for this project is based on the Google [C++ style guide](https://google.github.io/styleguide/cppguide.html). There are some variations:

## Headers:

  - System headers includes come before local header includes
  - All headers are included in the respective header file

## Indentation:

  Indent your code with 4 spaces. Never use tabs or mix tabs and spaces. In cases of implied line continuation you should align wrapped elements vertically:

    <Class> foo(var_one,
                var_two,
                var_three,
                var_four)

## Naming:

  - ClassName, methodName, ui_action_functions, global_var_name, instance_var_name,
    function_parameter_name, local_var_name

  - Function names, variable names, and filenames should be descriptive; avoid abbreviation. In particular, do not use abbreviations that are ambiguous to the readers. Do not abbreviate by deleting letters within a word.

  ** Names to Avoid: single character names except for counters or iterators **

# Extensions (Stage 1)

  1. Main Menu screen where the user can select which background they would like to play the game in
  2. Parallax background to establish a scrolling background (stickman is stationary everything else is moving)
  3. Pause menu
    - User can change x position of the stickman as well as the size
    - Can resume play with the selected options
    - Options altered in real-time
  4. Background Music that has a infinite loop
  5. Animation of stickman, stickman is running.
  
# Design Patterns (Stage 1)

## Factory method

The game dialog is created by a factory to allow for easy extension. The separation of object construction from object use allows new game dialogs to be created without tight coupling of the start dialog and the game dialog.

# Extensions (Stage 2)

  1. Double jump - easily configurable as "multi-jump" (e.g. triple jump) as well.
  2. Sound effect on jump.

# Design Patterns (Stage 2) 

## Decorator

Decorators are used to dynamically extend functionality of various objects. For example, for the stickman object (`Stage2Stickman`) we provide a decorator (abstract class `StickmanDecorator`) implemented in `MotionDecorator` to add the jump sound effect. 
