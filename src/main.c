#include "modding.h"
#include "ultra64.h"
#include "enums.h"
#include "common_structs.h"

extern Maps current_map;
u8 byte_offsets[] = {
    22, 12, 15, 12
};
u8 new_values[] = {
    120, 90, 80, 60
};

RECOMP_CALLBACK("*", recomp_on_map_load) void changeWindowTimings(void) {
    s32 i;
    u8 *ptr;

    if (current_map != MAP_KROOL_FIGHT_DK_PHASE) return;
    for (i = 0; i < 4; i++) {
        ptr = *(u8 **)(0x80035A50 + (i * 4)); // Can't use the signature since it's static in decomp
        ptr[byte_offsets[i]] = new_values[i];
    }
}

// extern u16 newly_pressed_input[];
// void func_global_asm_805FF378(Maps nextMap, s32 nextExit); 
// RECOMP_CALLBACK("*", dk64recomp_every_frame) void cheatyWarp(void) {
//     if (newly_pressed_input[0] & 0x0800) {
//         func_global_asm_805FF378(MAP_KROOL_FIGHT_DK_PHASE, 0);
//     }
// }