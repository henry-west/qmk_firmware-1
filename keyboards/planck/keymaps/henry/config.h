#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(ZELDA_PUZZLE)

    #define DEFAULT_LAYER_SONGS { SONG(UNDERGROUND), \
                                  SONG(UNDERGROUND_TWO),  \
                                  SONG(COIN_SOUND), \
                                  SONG(SONIC_RING)  \
                                }
#endif

#endif