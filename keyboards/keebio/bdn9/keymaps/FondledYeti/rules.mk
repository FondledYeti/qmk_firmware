TAP_DANCE_ENABLE = yes #Required for tap dance buttons
MOUSEKEY_ENABLE = yes #Needed to make encoder work like mouse button
LTO_ENABLE = yes #Saves memory but makes compiling take longer, but not really noticable
BOOTLOADER = atmel-dfu  #Elite C uses DFU
COMMAND_ENABLE = no #Save quite a lot of memory by dissabling, but makes more difficult to troubleshoot
CONSOLE_ENABLE = no #same note as COMMAND_ENABLE
