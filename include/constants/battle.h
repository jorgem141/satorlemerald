#ifndef GUARD_CONSTANTS_BATTLE_H
#define GUARD_CONSTANTS_BATTLE_H

/*
 * A battler may be in one of four positions on the field. The first bit determines
 * what side the battler is on, either the player's side or the opponent's side.
 * The second bit determines what flank the battler is on, either the left or right.
 * Note that the opponent's flanks are drawn corresponding to their perspective, so
 * their right mon appears on the left, and their left mon appears on the right.
 * The battler ID is usually the same as the position, except in the case of link battles.
 *
 *   + ------------------------- +
 *   |           Opponent's side |
 *   |            Right    Left  |
 *   |              3       1    |
 *   |                           |
 *   | Player's side             |
 *   |  Left   Right             |
 *   |   0       2               |
 *   ----------------------------+
 *   |                           |
 *   |                           |
 *   +---------------------------+
 */

#define MAX_BATTLERS_COUNT  4

#define B_POSITION_PLAYER_LEFT        0
#define B_POSITION_OPPONENT_LEFT      1
#define B_POSITION_PLAYER_RIGHT       2
#define B_POSITION_OPPONENT_RIGHT     3

// These macros can be used with either battler ID or positions to get the partner or the opposite mon
#define BATTLE_OPPOSITE(id) ((id) ^ BIT_SIDE)
#define BATTLE_PARTNER(id) ((id) ^ BIT_FLANK)

#define B_SIDE_PLAYER     0
#define B_SIDE_OPPONENT   1
#define NUM_BATTLE_SIDES  2

#define B_FLANK_LEFT  0
#define B_FLANK_RIGHT 1

#define BIT_SIDE        1
#define BIT_FLANK       2

// Battle Type Flags
#define BATTLE_TYPE_DOUBLE             (1 << 0)
#define BATTLE_TYPE_LINK               (1 << 1)
#define BATTLE_TYPE_IS_MASTER          (1 << 2) // In not-link battles, it's always set.
#define BATTLE_TYPE_TRAINER            (1 << 3)
#define BATTLE_TYPE_FIRST_BATTLE       (1 << 4)
#define BATTLE_TYPE_LINK_IN_BATTLE     (1 << 5) // Set on battle entry, cleared on exit. Checked rarely
#define BATTLE_TYPE_MULTI              (1 << 6)
#define BATTLE_TYPE_SAFARI             (1 << 7)
#define BATTLE_TYPE_BATTLE_TOWER       (1 << 8)
#define BATTLE_TYPE_WALLY_TUTORIAL     (1 << 9) // Used in pokefirered as BATTLE_TYPE_OLD_MAN_TUTORIAL.
#define BATTLE_TYPE_ROAMER             (1 << 10)
#define BATTLE_TYPE_EREADER_TRAINER    (1 << 11)
#define BATTLE_TYPE_KYOGRE_GROUDON     (1 << 12)
#define BATTLE_TYPE_LEGENDARY          (1 << 13)
#define BATTLE_TYPE_REGI               (1 << 14)
#define BATTLE_TYPE_TWO_OPPONENTS      (1 << 15) // Used in pokefirered as BATTLE_TYPE_GHOST.
#define BATTLE_TYPE_DOME               (1 << 16) // Used in pokefirered as BATTLE_TYPE_POKEDUDE.
#define BATTLE_TYPE_PALACE             (1 << 17) // Used in pokefirered as BATTLE_TYPE_WILD_SCRIPTED.
#define BATTLE_TYPE_ARENA              (1 << 18) // Used in pokefirered as BATTLE_TYPE_LEGENDARY_FRLG.
#define BATTLE_TYPE_FACTORY            (1 << 19) // Used in pokefirered as BATTLE_TYPE_TRAINER_TOWER.
#define BATTLE_TYPE_PIKE               (1 << 20)
#define BATTLE_TYPE_PYRAMID            (1 << 21)
#define BATTLE_TYPE_INGAME_PARTNER     (1 << 22)
#define BATTLE_TYPE_TOWER_LINK_MULTI   (1 << 23)
#define BATTLE_TYPE_RECORDED           (1 << 24)
#define BATTLE_TYPE_RECORDED_LINK      (1 << 25)
#define BATTLE_TYPE_TRAINER_HILL       (1 << 26)
#define BATTLE_TYPE_SECRET_BASE        (1 << 27)
#define BATTLE_TYPE_GROUDON            (1 << 28)
#define BATTLE_TYPE_KYOGRE             (1 << 29)
#define BATTLE_TYPE_RAYQUAZA           (1 << 30)
#define BATTLE_TYPE_RECORDED_IS_MASTER (1 << 31)
#define BATTLE_TYPE_FRONTIER                (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID)
#define BATTLE_TYPE_FRONTIER_NO_PYRAMID     (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_PIKE)
#define BATTLE_TYPE_RECORDED_INVALID        ((BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_FIRST_BATTLE                  \
                                             | BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_ROAMER | BATTLE_TYPE_EREADER_TRAINER    \
                                             | BATTLE_TYPE_KYOGRE_GROUDON | BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_REGI            \
                                             | BATTLE_TYPE_RECORDED | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE        \
                                             | BATTLE_TYPE_GROUDON | BATTLE_TYPE_KYOGRE | BATTLE_TYPE_RAYQUAZA))

#define WILD_DOUBLE_BATTLE ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER))))
#define BATTLE_TWO_VS_ONE_OPPONENT ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gTrainerBattleOpponent_B == 0xFFFF))
#define BATTLE_TYPE_HAS_AI          (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_SAFARI | BATTLE_TYPE_ROAMER | BATTLE_TYPE_INGAME_PARTNER)


// Battle Outcome defines
#define B_OUTCOME_WON                  1
#define B_OUTCOME_LOST                 2
#define B_OUTCOME_DREW                 3
#define B_OUTCOME_RAN                  4
#define B_OUTCOME_PLAYER_TELEPORTED    5
#define B_OUTCOME_MON_FLED             6
#define B_OUTCOME_CAUGHT               7
#define B_OUTCOME_NO_SAFARI_BALLS      8
#define B_OUTCOME_FORFEITED            9
#define B_OUTCOME_MON_TELEPORTED       10
#define B_OUTCOME_LINK_BATTLE_RAN      (1 << 7) // 128

// Non-volatile status conditions
// These persist remain outside of battle and after switching out
#define STATUS1_NONE             0
#define STATUS1_SLEEP            (1 << 0 | 1 << 1 | 1 << 2) // First 3 bits (Number of turns to sleep)
#define STATUS1_SLEEP_TURN(num)  ((num) << 0) // Just for readability (or if rearranging statuses)
#define STATUS1_POISON           (1 << 3)
#define STATUS1_BURN             (1 << 4)
#define STATUS1_FREEZE           (1 << 5)
#define STATUS1_PARALYSIS        (1 << 6)
#define STATUS1_TOXIC_POISON     (1 << 7)
#define STATUS1_TOXIC_COUNTER    (1 << 8 | 1 << 9 | 1 << 10 | 1 << 11)
#define STATUS1_TOXIC_TURN(num)  ((num) << 8)
#define STATUS1_FROSTBITE        (1 << 12)
#define STATUS1_PSN_ANY          (STATUS1_POISON | STATUS1_TOXIC_POISON)
#define STATUS1_ANY              (STATUS1_SLEEP | STATUS1_POISON | STATUS1_BURN | STATUS1_FREEZE | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE)

// Volatile status ailments
// These are removed after exiting the battle or switching out
#define STATUS2_CONFUSION             (1 << 0 | 1 << 1 | 1 << 2)
#define STATUS2_CONFUSION_TURN(num)   ((num) << 0)
#define STATUS2_FLINCHED              (1 << 3)
#define STATUS2_UPROAR                (1 << 4 | 1 << 5 | 1 << 6)
#define STATUS2_UPROAR_TURN(num)      ((num) << 4)
#define STATUS2_UNUSED                (1 << 7)
#define STATUS2_BIDE                  (1 << 8 | 1 << 9)
#define STATUS2_BIDE_TURN(num)        (((num) << 8) & STATUS2_BIDE)
#define STATUS2_LOCK_CONFUSE          (1 << 10 | 1 << 11) // e.g. Thrash
#define STATUS2_LOCK_CONFUSE_TURN(num)((num) << 10)
#define STATUS2_MULTIPLETURNS         (1 << 12)
#define STATUS2_WRAPPED               (1 << 13)
#define STATUS2_POWDER                (1 << 14)
#define STATUS2_INFATUATION           (1 << 16 | 1 << 17 | 1 << 18 | 1 << 19)  // 4 bits, one for every battler
#define STATUS2_INFATUATED_WITH(battler) (gBitTable[battler] << 16)
#define STATUS2_FOCUS_ENERGY          (1 << 20)
#define STATUS2_TRANSFORMED           (1 << 21)
#define STATUS2_RECHARGE              (1 << 22)
#define STATUS2_RAGE                  (1 << 23)
#define STATUS2_SUBSTITUTE            (1 << 24)
#define STATUS2_DESTINY_BOND          (1 << 25)
#define STATUS2_ESCAPE_PREVENTION     (1 << 26)
#define STATUS2_NIGHTMARE             (1 << 27)
#define STATUS2_CURSED                (1 << 28)
#define STATUS2_FORESIGHT             (1 << 29)
#define STATUS2_DEFENSE_CURL          (1 << 30)
#define STATUS2_TORMENT               (1 << 31)

#define STATUS3_LEECHSEED_BATTLER       (1 << 0 | 1 << 1) // The battler to receive HP from Leech Seed
#define STATUS3_LEECHSEED               (1 << 2)
#define STATUS3_ALWAYS_HITS             (1 << 3 | 1 << 4)
#define STATUS3_ALWAYS_HITS_TURN(num)   (((num) << 3) & STATUS3_ALWAYS_HITS) // "Always Hits" is set as a 2 turn timer, i.e. next turn is the last turn when it's active
#define STATUS3_PERISH_SONG             (1 << 5)
#define STATUS3_ON_AIR                  (1 << 6)
#define STATUS3_UNDERGROUND             (1 << 7)
#define STATUS3_MINIMIZED               (1 << 8)
#define STATUS3_CHARGED_UP              (1 << 9)
#define STATUS3_ROOTED                  (1 << 10)
#define STATUS3_YAWN                    (1 << 11 | 1 << 12) // Number of turns to sleep
#define STATUS3_YAWN_TURN(num)          (((num) << 11) & STATUS3_YAWN)
#define STATUS3_IMPRISONED_OTHERS       (1 << 13)
#define STATUS3_GRUDGE                  (1 << 14)
#define STATUS3_CANT_SCORE_A_CRIT       (1 << 15)
#define STATUS3_GASTRO_ACID             (1 << 16)
#define STATUS3_EMBARGO                 (1 << 17)
#define STATUS3_UNDERWATER              (1 << 18)
#define STATUS3_INTIMIDATE_POKES        (1 << 19)
#define STATUS3_TRACE                   (1 << 20)
#define STATUS3_SMACKED_DOWN            (1 << 21)
#define STATUS3_ME_FIRST                (1 << 22)
#define STATUS3_TELEKINESIS             (1 << 23)
#define STATUS3_PHANTOM_FORCE           (1 << 24)
#define STATUS3_MIRACLE_EYED            (1 << 25)
#define STATUS3_MAGNET_RISE             (1 << 26)
#define STATUS3_HEAL_BLOCK              (1 << 27)
#define STATUS3_AQUA_RING               (1 << 28)
#define STATUS3_LASER_FOCUS             (1 << 29)
#define STATUS3_POWER_TRICK             (1 << 30)
#define STATUS3_SKY_DROPPED             (1 << 31) // Target of Sky Drop
#define STATUS3_SEMI_INVULNERABLE       (STATUS3_UNDERGROUND | STATUS3_ON_AIR | STATUS3_UNDERWATER | STATUS3_PHANTOM_FORCE)

#define STATUS4_ELECTRIFIED             (1 << 0)
#define STATUS4_PLASMA_FISTS            (1 << 1)
#define STATUS4_MUD_SPORT               (1 << 2)    // Only used if B_SPORT_TURNS < GEN_6
#define STATUS4_WATER_SPORT             (1 << 3)    // Only used if B_SPORT_TURNS < GEN_6
#define STATUS4_INFINITE_CONFUSION      (1 << 4)    // Used for Berserk Gene
#define STATUS4_SALT_CURE               (1 << 5)

#define HITMARKER_WAKE_UP_CLEAR         (1 << 4) // Cleared when waking up. Never set or checked.
#define HITMARKER_SKIP_DMG_TRACK        (1 << 5)
#define HITMARKER_DESTINYBOND           (1 << 6)
#define HITMARKER_NO_ANIMATIONS         (1 << 7)
#define HITMARKER_IGNORE_SUBSTITUTE     (1 << 8)
#define HITMARKER_NO_ATTACKSTRING       (1 << 9)
#define HITMARKER_ATTACKSTRING_PRINTED  (1 << 10)
#define HITMARKER_NO_PPDEDUCT           (1 << 11)
#define HITMARKER_SWAP_ATTACKER_TARGET  (1 << 12)
#define HITMARKER_IGNORE_SAFEGUARD      (1 << 13)
#define HITMARKER_SYNCHRONISE_EFFECT    (1 << 14)
#define HITMARKER_RUN                   (1 << 15)
#define HITMARKER_IGNORE_DISGUISE       (1 << 16)
// 3 free spots because of change in handling of UNDERGROUND/UNDERWATER/ON AIR
#define HITMARKER_UNABLE_TO_USE_MOVE    (1 << 19)
#define HITMARKER_PASSIVE_DAMAGE        (1 << 20)
#define HITMARKER_DISOBEDIENT_MOVE      (1 << 21)
#define HITMARKER_PLAYER_FAINTED        (1 << 22)
#define HITMARKER_ALLOW_NO_PP           (1 << 23)
#define HITMARKER_GRUDGE                (1 << 24)
#define HITMARKER_OBEYS                 (1 << 25)
#define HITMARKER_NEVER_SET             (1 << 26) // Cleared as part of a large group. Never set or checked
#define HITMARKER_CHARGING              (1 << 27)
#define HITMARKER_FAINTED(battler)      (gBitTable[battler] << 28)
#define HITMARKER_FAINTED2(battler)     ((1 << 28) << battler)
#define HITMARKER_STRING_PRINTED        (1 << 29)

// Per-side statuses that affect an entire party
#define SIDE_STATUS_REFLECT                 (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN             (1 << 1)
#define SIDE_STATUS_STICKY_WEB              (1 << 2)
#define SIDE_STATUS_SPIKES                  (1 << 4)
#define SIDE_STATUS_SAFEGUARD               (1 << 5)
#define SIDE_STATUS_FUTUREATTACK            (1 << 6)
#define SIDE_STATUS_MIST                    (1 << 8)
// (1 << 9) previously was SIDE_STATUS_SPIKES_DAMAGED
#define SIDE_STATUS_TAILWIND                (1 << 10)
#define SIDE_STATUS_AURORA_VEIL             (1 << 11)
#define SIDE_STATUS_LUCKY_CHANT             (1 << 12)
#define SIDE_STATUS_TOXIC_SPIKES            (1 << 13)
#define SIDE_STATUS_STEALTH_ROCK            (1 << 14)
// Missing flags previously were SIDE_STATUS_TOXIC_SPIKES_DAMAGED, SIDE_STATUS_STEALTH_ROCK_DAMAGED, SIDE_STATUS_STICKY_WEB_DAMAGED
#define SIDE_STATUS_QUICK_GUARD             (1 << 18)
#define SIDE_STATUS_WIDE_GUARD              (1 << 19)
#define SIDE_STATUS_CRAFTY_SHIELD           (1 << 20)
#define SIDE_STATUS_MAT_BLOCK               (1 << 21)

#define SIDE_STATUS_HAZARDS_ANY    (SIDE_STATUS_SPIKES | SIDE_STATUS_STICKY_WEB | SIDE_STATUS_TOXIC_SPIKES | SIDE_STATUS_STEALTH_ROCK)
#define SIDE_STATUS_SCREEN_ANY     (SIDE_STATUS_REFLECT | SIDE_STATUS_LIGHTSCREEN | SIDE_STATUS_AURORA_VEIL)

// Field affecting statuses.
#define STATUS_FIELD_MAGIC_ROOM                     (1 << 0)
#define STATUS_FIELD_TRICK_ROOM                     (1 << 1)
#define STATUS_FIELD_WONDER_ROOM                    (1 << 2)
#define STATUS_FIELD_MUDSPORT                       (1 << 3)
#define STATUS_FIELD_WATERSPORT                     (1 << 4)
#define STATUS_FIELD_GRAVITY                        (1 << 5)
#define STATUS_FIELD_GRASSY_TERRAIN                 (1 << 6)
#define STATUS_FIELD_MISTY_TERRAIN                  (1 << 7)
#define STATUS_FIELD_ELECTRIC_TERRAIN               (1 << 8)
#define STATUS_FIELD_PSYCHIC_TERRAIN                (1 << 9)
#define STATUS_FIELD_ION_DELUGE                     (1 << 10)
#define STATUS_FIELD_FAIRY_LOCK                     (1 << 11)
#define STATUS_FIELD_TERRAIN_PERMANENT              (1 << 12)   // Overworld thunderstorm generates electric terrain

#define STATUS_FIELD_TERRAIN_ANY        (STATUS_FIELD_GRASSY_TERRAIN | STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_PSYCHIC_TERRAIN)
// sticky web ?

// Flags describing move's result
#define MOVE_RESULT_MISSED                (1 << 0)
#define MOVE_RESULT_SUPER_EFFECTIVE       (1 << 1)
#define MOVE_RESULT_NOT_VERY_EFFECTIVE    (1 << 2)
#define MOVE_RESULT_DOESNT_AFFECT_FOE     (1 << 3)
#define MOVE_RESULT_ONE_HIT_KO            (1 << 4)
#define MOVE_RESULT_FAILED                (1 << 5)
#define MOVE_RESULT_FOE_ENDURED           (1 << 6)
#define MOVE_RESULT_FOE_HUNG_ON           (1 << 7)
#define MOVE_RESULT_STURDIED              (1 << 8)
#define MOVE_RESULT_FOE_ENDURED_AFFECTION (1 << 9)
#define MOVE_RESULT_NO_EFFECT             (MOVE_RESULT_MISSED | MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)

// Battle Weather flags
#define B_WEATHER_NONE                0
#define B_WEATHER_RAIN_TEMPORARY      (1 << 0)
#define B_WEATHER_RAIN_DOWNPOUR       (1 << 1)  // unused
#define B_WEATHER_RAIN_PERMANENT      (1 << 2)
#define B_WEATHER_RAIN_PRIMAL         (1 << 3)
#define B_WEATHER_RAIN                (B_WEATHER_RAIN_TEMPORARY | B_WEATHER_RAIN_DOWNPOUR | B_WEATHER_RAIN_PERMANENT | B_WEATHER_RAIN_PRIMAL)
#define B_WEATHER_SANDSTORM_TEMPORARY (1 << 4)
#define B_WEATHER_SANDSTORM_PERMANENT (1 << 5)
#define B_WEATHER_SANDSTORM           (B_WEATHER_SANDSTORM_TEMPORARY | B_WEATHER_SANDSTORM_PERMANENT)
#define B_WEATHER_SUN_TEMPORARY       (1 << 6)
#define B_WEATHER_SUN_PERMANENT       (1 << 7)
#define B_WEATHER_SUN_PRIMAL          (1 << 8)
#define B_WEATHER_SUN                 (B_WEATHER_SUN_TEMPORARY | B_WEATHER_SUN_PERMANENT | B_WEATHER_SUN_PRIMAL)
#define B_WEATHER_HAIL_TEMPORARY      (1 << 9)
#define B_WEATHER_HAIL_PERMANENT      (1 << 10)
#define B_WEATHER_HAIL                (B_WEATHER_HAIL_TEMPORARY | B_WEATHER_HAIL_PERMANENT)
#define B_WEATHER_STRONG_WINDS        (1 << 11)
#define B_WEATHER_ANY                 (B_WEATHER_RAIN | B_WEATHER_SANDSTORM | B_WEATHER_SUN | B_WEATHER_HAIL | B_WEATHER_STRONG_WINDS | B_WEATHER_SNOW)
#define B_WEATHER_PRIMAL_ANY          (B_WEATHER_RAIN_PRIMAL | B_WEATHER_SUN_PRIMAL | B_WEATHER_STRONG_WINDS)
#define B_WEATHER_SNOW_TEMPORARY      (1 << 12)
#define B_WEATHER_SNOW_PERMANENT      (1 << 13)
#define B_WEATHER_SNOW                (B_WEATHER_SNOW_TEMPORARY | B_WEATHER_SNOW_PERMANENT)

// Battle Weather as enum
#define ENUM_WEATHER_NONE                 0
#define ENUM_WEATHER_RAIN                 1
#define ENUM_WEATHER_SUN                  2
#define ENUM_WEATHER_SANDSTORM            3
#define ENUM_WEATHER_HAIL                 4
#define ENUM_WEATHER_SUN_PRIMAL           5
#define ENUM_WEATHER_RAIN_PRIMAL          6
#define ENUM_WEATHER_STRONG_WINDS         7
#define ENUM_WEATHER_SNOW                 8

// Move Effects
#define MOVE_EFFECT_SLEEP               1
#define MOVE_EFFECT_POISON              2
#define MOVE_EFFECT_BURN                3
#define MOVE_EFFECT_FREEZE              4
#define MOVE_EFFECT_PARALYSIS           5
#define MOVE_EFFECT_TOXIC               6
#define MOVE_EFFECT_FROSTBITE           7
#define PRIMARY_STATUS_MOVE_EFFECT      MOVE_EFFECT_FROSTBITE // All above move effects apply primary status
#define MOVE_EFFECT_CONFUSION           8
#define MOVE_EFFECT_FLINCH              9
#define MOVE_EFFECT_TRI_ATTACK          10
#define MOVE_EFFECT_UPROAR              11
#define MOVE_EFFECT_PAYDAY              12
#define MOVE_EFFECT_CHARGING            13
#define MOVE_EFFECT_WRAP                14
#define MOVE_EFFECT_ATK_PLUS_1          15
#define MOVE_EFFECT_DEF_PLUS_1          16
#define MOVE_EFFECT_SPD_PLUS_1          17
#define MOVE_EFFECT_SP_ATK_PLUS_1       18
#define MOVE_EFFECT_SP_DEF_PLUS_1       19
#define MOVE_EFFECT_ACC_PLUS_1          20
#define MOVE_EFFECT_EVS_PLUS_1          21
#define MOVE_EFFECT_ATK_MINUS_1         22
#define MOVE_EFFECT_DEF_MINUS_1         23
#define MOVE_EFFECT_SPD_MINUS_1         24
#define MOVE_EFFECT_SP_ATK_MINUS_1      25
#define MOVE_EFFECT_SP_DEF_MINUS_1      26
#define MOVE_EFFECT_ACC_MINUS_1         27
#define MOVE_EFFECT_EVS_MINUS_1         28
#define MOVE_EFFECT_BURN_UP             29
#define MOVE_EFFECT_RECHARGE            30
#define MOVE_EFFECT_RAGE                31
#define MOVE_EFFECT_STEAL_ITEM          32
#define MOVE_EFFECT_PREVENT_ESCAPE      33
#define MOVE_EFFECT_NIGHTMARE           34
#define MOVE_EFFECT_ALL_STATS_UP        35
#define MOVE_EFFECT_RAPIDSPIN           36
#define MOVE_EFFECT_REMOVE_STATUS       37
#define MOVE_EFFECT_ATK_DEF_DOWN        38
#define MOVE_EFFECT_ATK_PLUS_2          39
#define MOVE_EFFECT_DEF_PLUS_2          40
#define MOVE_EFFECT_SPD_PLUS_2          41
#define MOVE_EFFECT_SP_ATK_PLUS_2       42
#define MOVE_EFFECT_SP_DEF_PLUS_2       43
#define MOVE_EFFECT_ACC_PLUS_2          44
#define MOVE_EFFECT_EVS_PLUS_2          45
#define MOVE_EFFECT_ATK_MINUS_2         46
#define MOVE_EFFECT_DEF_MINUS_2         47
#define MOVE_EFFECT_SPD_MINUS_2         48
#define MOVE_EFFECT_SP_ATK_MINUS_2      49
#define MOVE_EFFECT_SP_DEF_MINUS_2      50
#define MOVE_EFFECT_ACC_MINUS_2         51
#define MOVE_EFFECT_EVS_MINUS_2         52
#define MOVE_EFFECT_SCALE_SHOT          53
#define MOVE_EFFECT_THRASH              54
#define MOVE_EFFECT_KNOCK_OFF           55
#define MOVE_EFFECT_DEF_SPDEF_DOWN      56
#define MOVE_EFFECT_CLEAR_SMOG          57
#define MOVE_EFFECT_SP_ATK_TWO_DOWN     58
#define MOVE_EFFECT_SMACK_DOWN          59
#define MOVE_EFFECT_FLAME_BURST         60
#define MOVE_EFFECT_FEINT               61
#define MOVE_EFFECT_SPECTRAL_THIEF      62
#define MOVE_EFFECT_V_CREATE            63
#define MOVE_EFFECT_HAPPY_HOUR          64
#define MOVE_EFFECT_CORE_ENFORCER       65
#define MOVE_EFFECT_THROAT_CHOP         66
#define MOVE_EFFECT_INCINERATE          67
#define MOVE_EFFECT_BUG_BITE            68
#define MOVE_EFFECT_RECOIL_HP_25        69
#define MOVE_EFFECT_RELIC_SONG          70
#define MOVE_EFFECT_TRAP_BOTH           71
#define MOVE_EFFECT_DOUBLE_SHOCK        72
#define MOVE_EFFECT_ROUND               73
#define MOVE_EFFECT_STOCKPILE_WORE_OFF  74
#define MOVE_EFFECT_DIRE_CLAW           75
#define MOVE_EFFECT_STEALTH_ROCK        76
#define MOVE_EFFECT_SPIKES              77
#define MOVE_EFFECT_TRIPLE_ARROWS       78
#define MOVE_EFFECT_FLORAL_HEALING      79

#define NUM_MOVE_EFFECTS                80

#define MOVE_EFFECT_AFFECTS_USER        0x4000
#define MOVE_EFFECT_CERTAIN             0x8000

// Battle terrain defines for gBattleTerrain.
#define BATTLE_TERRAIN_GRASS            0
#define BATTLE_TERRAIN_LONG_GRASS       1
#define BATTLE_TERRAIN_SAND             2
#define BATTLE_TERRAIN_UNDERWATER       3
#define BATTLE_TERRAIN_WATER            4
#define BATTLE_TERRAIN_POND             5
#define BATTLE_TERRAIN_MOUNTAIN         6
#define BATTLE_TERRAIN_CAVE             7
#define BATTLE_TERRAIN_BUILDING         8
#define BATTLE_TERRAIN_PLAIN            9
// New battle terrains are used for Secret Power but not fully implemented.
#define BATTLE_TERRAIN_SOARING          10
#define BATTLE_TERRAIN_SKY_PILLAR       11
#define BATTLE_TERRAIN_BURIAL_GROUND    12
#define BATTLE_TERRAIN_PUDDLE           13
#define BATTLE_TERRAIN_MARSH            14
#define BATTLE_TERRAIN_SWAMP            15
#define BATTLE_TERRAIN_SNOW             16
#define BATTLE_TERRAIN_ICE              17
#define BATTLE_TERRAIN_VOLCANO          18
#define BATTLE_TERRAIN_DISTORTION_WORLD 19
#define BATTLE_TERRAIN_SPACE            20
#define BATTLE_TERRAIN_ULTRA_SPACE      21

#define BATTLE_TERRAIN_COUNT            22

#define B_WAIT_TIME_LONG        (B_WAIT_TIME_MULTIPLIER * 4)
#define B_WAIT_TIME_MED         (B_WAIT_TIME_MULTIPLIER * 3)
#define B_WAIT_TIME_SHORT       (B_WAIT_TIME_MULTIPLIER * 2)
#define B_WAIT_TIME_SHORTEST    (B_WAIT_TIME_MULTIPLIER)

#define FLEE_ITEM    1
#define FLEE_ABILITY 2

// Return value for IsRunningFromBattleImpossible.
#define BATTLE_RUN_SUCCESS        0
#define BATTLE_RUN_FORBIDDEN      1
#define BATTLE_RUN_FAILURE        2

#define B_WIN_TYPE_NORMAL 0
#define B_WIN_TYPE_ARENA  1

// Window Ids for sStandardBattleWindowTemplates / sBattleArenaWindowTemplates
#define B_WIN_MSG                 0
#define B_WIN_ACTION_PROMPT       1 // "What will {x} do?"
#define B_WIN_ACTION_MENU         2 // "Fight/Pokémon/Bag/Run" menu
#define B_WIN_MOVE_NAME_1         3 // Top left
#define B_WIN_MOVE_NAME_2         4 // Top right
#define B_WIN_MOVE_NAME_3         5 // Bottom left
#define B_WIN_MOVE_NAME_4         6 // Bottom right
#define B_WIN_PP                  7
#define B_WIN_DUMMY               8
#define B_WIN_PP_REMAINING        9
#define B_WIN_MOVE_TYPE          10
#define B_WIN_SWITCH_PROMPT      11 // "Switch which?"
#define B_WIN_YESNO              12
#define B_WIN_LEVEL_UP_BOX       13
#define B_WIN_LEVEL_UP_BANNER    14
#define B_WIN_VS_PLAYER          15
#define B_WIN_VS_OPPONENT        16
#define B_WIN_VS_MULTI_PLAYER_1  17
#define B_WIN_VS_MULTI_PLAYER_2  18
#define B_WIN_VS_MULTI_PLAYER_3  19
#define B_WIN_VS_MULTI_PLAYER_4  20
#define B_WIN_VS_OUTCOME_DRAW    21
#define B_WIN_VS_OUTCOME_LEFT    22
#define B_WIN_VS_OUTCOME_RIGHT   23

// The following are duplicate id values for windows that Battle Arena uses differently.
#define ARENA_WIN_PLAYER_NAME      15
#define ARENA_WIN_VS               16
#define ARENA_WIN_OPPONENT_NAME    17
#define ARENA_WIN_MIND             18
#define ARENA_WIN_SKILL            19
#define ARENA_WIN_BODY             20
#define ARENA_WIN_JUDGMENT_TITLE   21
#define ARENA_WIN_JUDGMENT_TEXT    22

// Flag for BattlePutTextOnWindow. Never set
#define B_WIN_COPYTOVRAM (1 << 7)

// Indicator for the party summary bar to display an empty slot.
#define HP_EMPTY_SLOT 0xFFFF

#define MOVE_TARGET_SELECTED            0
#define MOVE_TARGET_DEPENDS             (1 << 0)
#define MOVE_TARGET_USER_OR_SELECTED    (1 << 1)
#define MOVE_TARGET_RANDOM              (1 << 2)
#define MOVE_TARGET_BOTH                (1 << 3)
#define MOVE_TARGET_USER                (1 << 4)
#define MOVE_TARGET_FOES_AND_ALLY       (1 << 5)
#define MOVE_TARGET_OPPONENTS_FIELD     (1 << 6)
#define MOVE_TARGET_ALLY                (1 << 7)
#define MOVE_TARGET_ALL_BATTLERS        ((1 << 8) | MOVE_TARGET_USER)

// For the second argument of GetMoveTarget, when no target override is needed
#define NO_TARGET_OVERRIDE 0

// Constants for Parental Bond
#define PARENTAL_BOND_1ST_HIT 2
#define PARENTAL_BOND_2ND_HIT 1
#define PARENTAL_BOND_OFF     0

// Constants for if HandleScriptMegaPrimalBurst should handle Mega Evolution, Primal Reversion, or Ultra Burst.
#define HANDLE_TYPE_MEGA_EVOLUTION 0
#define HANDLE_TYPE_PRIMAL_REVERSION 1
#define HANDLE_TYPE_ULTRA_BURST 2

#endif // GUARD_CONSTANTS_BATTLE_H
