type Planet = 'mercury' | 'venus' | 'earth' | 'mars' | 'jupiter' | 'saturn' | 'uranus' | 'neptune';

const earhYearInSeconds =  31557600;

function yearLength(planet: Planet): number {
  switch (planet) {
    case 'mercury': return 0.2408467;
    case 'venus': return 0.61519726;
    case 'earth': return 1.0;
    case 'mars': return 1.8808158;
    case 'jupiter': return 11.862615;
    case 'saturn': return 29.447498;
    case 'uranus': return 84.016846;
    case 'neptune': return 164.79132;
  };
}


console.log(yearLength);


export function age(planet: Planet, seconds: number): number {
  const age = (seconds / earhYearInSeconds) * ( 1 / yearLength(planet));
  return Math.round(age * 100) / 100;
}
