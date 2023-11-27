# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
CAPS_WORD_ENABLE = yes
LEADER_ENABLE = no
ORYX_ENABLE = yes # This tricks Live Training and Keymapp into working
SRC = matrix.c

UNICODE_COMMON = yes
UNICODE_ENABLE = yes