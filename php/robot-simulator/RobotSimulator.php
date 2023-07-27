<?php

/*
 * By adding type hints and enabling strict type checking, code can become
 * easier to read, self-documenting and reduce the number of potential bugs.
 * By default, type declarations are non-strict, which means they will attempt
 * to change the original type to match the type specified by the
 * type-declaration.
 *
 * In other words, if you pass a string to a function requiring a float,
 * it will attempt to convert the string value to a float.
 *
 * To enable strict mode, a single declare directive must be placed at the top
 * of the file.
 * This means that the strictness of typing is configured on a per-file basis.
 * This directive not only affects the type declarations of parameters, but also
 * a function's return type.
 *
 * For more info review the Concept on strict type checking in the PHP track
 * <link>.
 *
 * To disable strict typing, comment out the directive below.
 */

declare(strict_types=1);

class Robot
{
    const DIRECTION_NORTH = 0;
    const DIRECTION_EAST = 1;
    const DIRECTION_SOUTH = 2;
    const DIRECTION_WEST = 3;

    public function __construct(public array $position, public int $direction)
    {
    }

    public function turnRight(): self
    {
        $this->direction += 1;
        $this->direction %= 4;
        return $this;
    }

    public function turnLeft(): self
    {
        $this->direction += 3;
        $this->direction %= 4;
        return $this;
    }

    public function advance(): self
    {
        if ($this->direction == Robot::DIRECTION_NORTH) {
            $this->position[1]++;
        }
        if ($this->direction == Robot::DIRECTION_WEST) {
            $this->position[0]--;
        }
        if ($this->direction == Robot::DIRECTION_SOUTH) {
            $this->position[1]--;
        }
        if ($this->direction == Robot::DIRECTION_EAST) {
            $this->position[0]++;
        }
        return $this;
    }

    public function instructions(string $instructions): self
    {
        for ($i = 0; $i < strlen($instructions); $i++) {
            match($instructions[$i]) {
                'R' => $this->turnRight(),
                'L' => $this->turnLeft(),
                'A' => $this->advance(),
                default => throw new InvalidArgumentException,
            };
        }
        return $this;
    }
}
