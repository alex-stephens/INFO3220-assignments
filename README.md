# INFO32200-assignment1

## Style guide

This project aims to follow the [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines). The emphasis of this style guide is in writing effective, modern C++ code. The guide is not especially restrictive, designed for gradual adoption and customisation to suit the needs of a particular company or codebase. Its focus is not necessarily on lower-level behaviours such as naming conventions and formatting, so we adopt the following formatting patterns:

+ Variable names in lower case, words separated by underscores
+ Method names in camel case, with the first letter in lower case
+ Class names in camel case, with the first letter also capitalised
+ 4 spaces per tab


## Extensions 

I have included four small extensions to the assignment specification as follows:

### Pause Button 

User can press P to bring up a pause screen, and press P again to resume the game. The code rendering the pause screen is in `pause.h`, `pause.c` and the logic is implemented in `Game::paintEvent` and `Game::keyPressEvent`.

### Soundtrack

The game has background music which starts playing as soon as the game loads. This is implemented in the `Game` class, in particular through the `setSoundtrack`, `playSoundtrack` and `pauseSoundtrack` methods -- this extension integrates with the previous one, such that the soundtrack stops playing on the pause screen and resumes once the user exits the pause screen. 

The soundtrack  is configurable by the user, with its path specified in the `resources/config.xml` file under the `<soundtrack>` tag, which must specify a `.wav` file in the `resources` directory. 

### Night Mode

User can press N to toggle the game background to a darkened, "night mode" version of the original background. Like the main background file, this is configurable in the `<nightbackground>` tag in `resources/config.xml`. The logic for this is implemented in `Game::paintEvent` class, making use also of the additional parameter in the `Config` class.

### Walking Stickman

Rather than using a static image, the game uses a stickman which is rendered from individual `.gif` frames provided in `resources`. This is implemented as part of the `Sprite` class which handles implementation and rendering of the stickman, and offers configurability of the number of frames provided in the stickman animation. This also offers the possibility of being extended with additional logic and additional frames in later stages, in order to have the stickman animation change dynamically as it speeds up, slows down and turns around. 
