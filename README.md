Easy "clone and go" repository for a libopencm3 based project.

# Instructions
 1. git clone --recurse-submodules https://github.com/libopencm3/libopencm3-template.git your-project
 2. cd your-project
 3. make -C libopencm3 # (Only needed once)
 4. bear -- make -C V=1 src # used to create compile_commands.json for clangd
 5. make -C src
 6. make -C src flash

If you have an older git, or got ahead of yourself and skipped the ```--recurse-submodules```
you can fix things by running ```git submodule update --init``` (This is only needed once)

# Directories
* src contains your application

# As a template
You should replace this with your _own_ README if you are using this
as a template.
