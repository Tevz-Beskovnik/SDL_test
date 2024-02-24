#pragma once

#define SHIFT(x) (1 << x)

enum object_type {
    PLAYER = SHIFT(0),
    ENEMY = SHIFT(1),
    BULLET = SHIFT(2),
    BACKGROUND = SHIFT(3),
    TILE = SHIFT(4),
    WALL = SHIFT(5),
};