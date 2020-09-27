#pragma once

typedef enum
{
    WAVEBANK_LOOP_WAVCTLOOPED_0_3_1R = 0,
    WAVEBANK_LOOP_WAVCTLOOPED_0_6_1R = 1,
    WAVEBANK_LOOP_WAVCTLOOPED_1_5_1R = 2,
    WAVEBANK_LOOP_WAVCTLOOPED_3_6_1R = 3,
    WAVEBANK_LOOP_SHOOT = 4,
    WAVEBANK_LOOP_DIALOG = 5,
    WAVEBANK_LOOP_EXPLO1 = 6,
    WAVEBANK_LOOP_LOOP_EMBEDDED = 7,
    WAVEBANK_LOOP_LOOP_ENDTOEND = 8,
    WAVEBANK_LOOP_MUSLOOP = 9,
} WAVEBANK_LOOP;

#define WAVEBANK_LOOP_ENTRY_COUNT 10
