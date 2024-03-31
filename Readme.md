## Naming style

#### lower_case
Used by functions, variables, and members in structures.

#### camelBack
Used by static global variables.

#### CamelCase
Used by functions from raylib, custom type names.

#### UPPER_CASE
Used by constants, define of constants, members of enums, and *global variables which should be immutable except for loading and unloading*. **The variables should be immutable during the main program logic.**
```c
// global variables which should be immutable except for loading and unloading
Image background;
// the variable should only be modified in these two functions
void background_img_load();
void background_img_unload();
```
