module SpaceAge (Planet(..), ageOn) where

import Prelude hiding (lookup)

data Planet = Mercury
            | Venus
            | Earth
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune

earthYearLength :: Float;
earthYearLength = 31557600;

yearLength:: Planet -> Float
yearLength Mercury= 0.2408467;
yearLength Venus= 0.61519726;
yearLength Earth= 1.0;
yearLength Mars= 1.8808158;
yearLength Jupiter= 11.862615;
yearLength Saturn= 29.447498;
yearLength Uranus= 84.016846;
yearLength Neptune= 164.79132;

ageOn :: Planet -> Float -> Float
ageOn Earth seconds = seconds / earthYearLength;
ageOn planet seconds = (1 / yearLength planet) * ageOn Earth seconds
