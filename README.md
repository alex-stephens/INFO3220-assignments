# INFO32200-assignment-1

## Style guide

This project aims to follow the [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines). The emphasis of this style guide is in writing effective, modern C++ code. The guide is not especially restrictive, designed for gradual adoption and customisation to suit the needs of a particular company or codebase. Its focus is not necessarily on lower-level behaviours such as naming conventions and formatting, so we adopt the following formatting patterns:

+ Variable names in lower case, words separated by underscores
+ Method names in camel case, with the first letter in lower case
+ Class names in camel case, with the first letter also capitalised
+ 4 spaces per tab

## OOD overview

The most important classes in terms of the overall design are as follows

+ **`Game`**: this is a subclass of `QDialog`, through which the main graphical user interface is implemented. This class interfaces with most of the other classes described here, as it represents the core of our game. 
+ **`Graphics`**: an abstract class for graphics objects.
+ **`Background`**: graphics object (subclass of `Graphics`) implementing the side-scrolling background of the game
+ **`Sprite`**: graphics object (subclass of `Graphics`) implementing the stickman itself
+ **`Config`**: handles the parsing of a `config.xml` file storing game parameters
+ **`Coordinate`**: implements a Cartesian coordinate system with the x-axis pointing to the right and y-axis pointing up, origin at the bottom-left of the screen, over the top of QDialog's coordinate system. Adapted from the first INFO3220 tutorial. 

A few other classes are used but they are mostly quite straightforward, with the exception of the Builder classes discussed below. 

## Design pattern

The code makes use of a Builder design pattern, specifically for the `Game` class which implements the main dialog window that the user interfaces with during the game. 

In this first stage of the assignment, the design pattern has limited utility, since we have only implemented a single `QDialog` subclass (which we have named `Game`) and thus the abstract `Builder` class only has one concrete implementation `GameBuilder`. However, this design pattern provides a lot of potential utility in the later stages of the assignment and more generally for the broad task of game design, for the following reasons:

+ Initialisation of the `Game` class is quite complex and involves many parameters and configuration steps. In the event that we require more instances of this class (e.g. re-opening a *new* `Game` window after the user saves and quits), the construction process can be much simplified using the `GameBuilder`
+ In later iterations of the implementation, there might conceivably be other variants of the game present, in the form of new gameplay modes or feature skins over the existing implementations. If these require different `Config` objects or other parameters, new subclasses of `Builder` could be very helpful in instantiating these new `Game`-like objects cleanly.
+ In line with the general purpose of the Builder design pattern, it allows the possibility of implementing improved versions of the `Game` class without affecting the existing interface.  

## Extensions 

I have included **four small extensions** to the assignment specification as follows:

### Pause Button 

User can press P to bring up a pause screen, and press P again to resume the game. The code rendering the pause screen is in `pause.h`, `pause.c` and the logic is implemented in `Game::paintEvent` and `Game::keyPressEvent`.

### Soundtrack

The game has background music which starts playing as soon as the game loads. This is implemented in the `Game` class, in particular through the `setSoundtrack`, `playSoundtrack` and `pauseSoundtrack` methods -- this extension integrates with the pause button extension, such that the soundtrack stops playing when the game is paused, and resumes once unpaused. 

The soundtrack  is configurable by the user, with its path specified in the `resources/config.xml` file under the `<soundtrack>` tag, which must specify a `.wav` file in the `resources` directory. This is implemented using Qt's `QSound` library. 

### Night Mode

User can press N to toggle the game background to a darkened, "night mode" version of the original background. Like the main background file, this is configurable in the `<nightbackground>` tag in `resources/config.xml`. The logic for this is implemented in `Game::paintEvent` class, making use also of the additional parameter in the `Config` class.

### Walking Stickman

Rather than using a static image, the game uses a stickman which is rendered from individual `.gif` frames provided in `resources`. This is implemented as part of the `Sprite` class which handles implementation and rendering of the stickman, and offers configurability of the number of frames provided in the stickman animation. This also offers the possibility of being extended with additional logic and additional frames in later stages, in order to have the stickman animation change dynamically as it speeds up, slows down and turns around. 
